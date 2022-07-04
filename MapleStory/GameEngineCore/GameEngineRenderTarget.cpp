// <hide/>

// GameEngineRenderTarget.cpp

#include "PreCompile.h"
#include "GameEngineRenderTarget.h"

GameEngineRenderTarget::GameEngineRenderTarget()
    : DepthStencilView(nullptr)
{
}

GameEngineRenderTarget::~GameEngineRenderTarget()
{
}

GameEngineRenderTarget* GameEngineRenderTarget::Create(const std::string& _Name)
{
    return CreateResName(_Name);
}

void GameEngineRenderTarget::CreateRenderTargetTexture(ID3D11Texture2D* _Texture, float4 _Color)
{
    GameEngineTexture* NewTexture = GameEngineTexture::Create(_Texture);

    RenderTargets.push_back(NewTexture);
    RenderTargetViews.push_back(NewTexture->CreateRenderTargetView());
    ClearColors.push_back(_Color);
}

void GameEngineRenderTarget::Clear()
{
    for (size_t i = 0; i < RenderTargetViews.size(); i++)
    {
        GameEngineDevice::GetContext()->ClearRenderTargetView(RenderTargetViews[i], ClearColors[i].Arr1D);
    }

    if (nullptr != DepthStencilView)
    {
        // GameEngineDevice::GetContext()->ClearDepthStencilView();
    }
}

void GameEngineRenderTarget::Setting()
{
    if (0 == RenderTargetViews.size())
    {
        MsgBoxAssert("����Ÿ�ٺ䰡 �������� �ʴ� ����Ÿ���� �����Ϸ��� �߽��ϴ�.");
    }

    GameEngineDevice::GetContext()->OMSetRenderTargets((UINT)RenderTargetViews.size(), &RenderTargetViews[0], DepthStencilView);
}