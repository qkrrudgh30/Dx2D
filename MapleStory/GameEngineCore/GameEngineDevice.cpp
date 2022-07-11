// <hide/>

// GameEngineDevice.cpp

#include "PreCompile.h"
#include "GameEngineDevice.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GameEngineRenderTarget.h"

ID3D11Device* GameEngineDevice::Device_ = nullptr;
ID3D11DeviceContext* GameEngineDevice::Context_ = nullptr;
IDXGISwapChain* GameEngineDevice::SwapChain_ = nullptr;
GameEngineRenderTarget* GameEngineDevice::BackBufferTarget = nullptr;

GameEngineDevice::~GameEngineDevice() 
{

}

void GameEngineDevice::CreateDevice()
{
    if (nullptr == GameEngineWindow::GetHWND())
    {
        MsgBoxAssert("�����찡 ��������� �ʾҴµ� ����̽��� �ʱ�ȭ �Ϸ��� �߽��ϴ�.");
        return;
    }

    int iFlag = 0;

#ifdef _DEBUG
    iFlag = D3D11_CREATE_DEVICE_DEBUG;
#endif

    D3D_FEATURE_LEVEL Level = D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_0;

    if (
        S_OK != D3D11CreateDevice(
            nullptr,
            D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE,
            nullptr,
            iFlag,
            nullptr,
            0,
            D3D11_SDK_VERSION,
            &Device_,
            &Level,
            &Context_
        )
        )
    {
        MsgBoxAssert("����̽� ������ �����߽��ϴ�.");
    }

    if (Level != D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_0)
    {
        MsgBoxAssert("11�� �������� �ʴ� ����̽� �Դϴ�.");
    }

    // ��Ƽ������ �ε��� �ɼ�.
    HRESULT Hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
}

void GameEngineDevice::CreateSwapChain()
{
    float4 ScreenSize = GameEngineWindow::GetScale();

    DXGI_SWAP_CHAIN_DESC ScInfo = { 0, };

    ScInfo.BufferCount = 2;
    ScInfo.BufferDesc.Width = ScreenSize.uix();
    ScInfo.BufferDesc.Height = ScreenSize.uiy();
    ScInfo.OutputWindow = GameEngineWindow::GetHWND();

    ScInfo.BufferDesc.RefreshRate.Denominator = 1;
    ScInfo.BufferDesc.RefreshRate.Numerator = 60;

    ScInfo.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    ScInfo.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    ScInfo.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

    ScInfo.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT | DXGI_USAGE_SHADER_INPUT;

    ScInfo.SampleDesc.Quality = 0;
    ScInfo.SampleDesc.Count = 1;

    ScInfo.SwapEffect = DXGI_SWAP_EFFECT::DXGI_SWAP_EFFECT_FLIP_DISCARD;

    ScInfo.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

    ScInfo.Windowed = true;

    IDXGIDevice* pD = nullptr;
    IDXGIAdapter* pA = nullptr;
    IDXGIFactory* pF = nullptr;

    Device_->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&pD));
    if (nullptr == pD)
    {
        MsgBoxAssert("����̽� ���⿡ �����߽��ϴ�.");
    }

    pD->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&pA));
    if (nullptr == pA)
    {
        MsgBoxAssert("��� ���⿡ �����߽��ϴ�.");
    }

    pA->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&pF));
    if (nullptr == pF)
    {
        MsgBoxAssert("���丮 ���⿡ �����߽��ϴ�.");
    }

    if (S_OK != pF->CreateSwapChain(Device_, &ScInfo, &SwapChain_))
    {
        MsgBoxAssert("����ü�� ������ �����߽��ϴ�.");
    }

    pF->Release();
    pA->Release();
    pD->Release();

    ID3D11Texture2D* BackBufferTexture = nullptr;
    if (S_OK != SwapChain_->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&BackBufferTexture)))
    {
        MsgBoxAssert("����� �ؽ�ó�� ������ ���߽��ϴ�.");
    }

    BackBufferTarget = GameEngineRenderTarget::Create("BackBuffer");
    BackBufferTarget->CreateRenderTargetTexture(BackBufferTexture, float4::BLUE);
}

void GameEngineDevice::Initialize()
{
    CreateDevice();
    CreateSwapChain();
}

void GameEngineDevice::Destroy()
{
    if (nullptr != SwapChain_)
    {
        SwapChain_->Release();
        SwapChain_ = nullptr;
    }

    if (nullptr != Context_)
    {
        Context_->Release();
        Context_ = nullptr;
    }

    if (nullptr != Device_)
    {
        Device_->Release();
        Device_ = nullptr;
    }
}

void GameEngineDevice::RenderStart()
{
    BackBufferTarget->Clear();

    BackBufferTarget->Setting();
}

void GameEngineDevice::RenderEnd()
{
    HRESULT Result = SwapChain_->Present(0, 0);
    if (Result == DXGI_ERROR_DEVICE_REMOVED || Result == DXGI_ERROR_DEVICE_RESET)
    {
        MsgBoxAssert("����̽� ������Ʈ�� �̻��� ������ϴ�.");
    }
}
