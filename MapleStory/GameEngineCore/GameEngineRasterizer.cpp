// <hide/>

// GameEngineRasterizer.cpp

#include "PreCompile.h"
#include "GameEngineRasterizer.h"

GameEngineRasterizer::GameEngineRasterizer()
    : Desc{}
{
}

GameEngineRasterizer::~GameEngineRasterizer()
{
    if (nullptr != State)
    {
        State->Release();
    }
}

GameEngineRasterizer* GameEngineRasterizer::Create(const std::string& _Name, const D3D11_RASTERIZER_DESC& _Desc)
{
    GameEngineRasterizer* NewRes = CreateResName(_Name);
    NewRes->Create(_Desc);
    return NewRes;
}

void GameEngineRasterizer::Create(const D3D11_RASTERIZER_DESC& _Desc)
{
    Desc = _Desc;

    if (S_OK != GameEngineDevice::GetDevice()->CreateRasterizerState(&Desc, &State))
    {
        MsgBoxAssert("���ؽ� ���� ������ �����߽��ϴ�.");
    }
}

void GameEngineRasterizer::Setting()
{
    if (nullptr == State)
    {
        MsgBoxAssert("�����Ͷ������� nullptr �Դϴ�. �����Ҽ� �����ϴ�.");
        return;
    }

    GameEngineDevice::GetContext()->RSSetState(State);
}