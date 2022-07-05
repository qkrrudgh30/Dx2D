// <hide/>

// GameEngineVertexBuffer.cpp

#include "PreCompile.h"
#include "GameEngineVertexBuffer.h"
#include <GameEngineBase/GameEngineString.h>

GameEngineVertexBuffer::GameEngineVertexBuffer()
    : Buffer(nullptr)
    , BufferDesc{}
    , OffSet(0)
{
}

GameEngineVertexBuffer::~GameEngineVertexBuffer()
{
    if (nullptr != Buffer)
    {
        Buffer->Release();
    }
}

GameEngineVertexBuffer* GameEngineVertexBuffer::Create(
    const std::string& _Name,
    const void* _Data, UINT _VertexSize,
    UINT _VertexCount,
    const GameEngineLayOutDesc& _LayOut
)
{
    GameEngineVertexBuffer* NewRes = CreateResName(_Name);
    NewRes->LayOutDesc = &_LayOut;
    NewRes->BufferCreate(_Data, _VertexSize, _VertexCount);
    return NewRes;
}

void GameEngineVertexBuffer::BufferCreate(const void* _Data, UINT _VertexSize, UINT _VertexCount)
{
    VertexSize = _VertexSize;
    VertexCount = _VertexCount;

    D3D11_SUBRESOURCE_DATA Data;
    Data.pSysMem = _Data;
    BufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    BufferDesc.ByteWidth = _VertexSize * _VertexCount;
    BufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
    BufferDesc.CPUAccessFlags = 0;

    // �߰� �ɼ��ε� ���� ����.
    BufferDesc.MiscFlags = 0;
    BufferDesc.StructureByteStride = 0;

    if (S_OK != GameEngineDevice::GetDevice()->CreateBuffer(&BufferDesc, &Data, &Buffer))
    {
        MsgBoxAssert("���ؽ� ���� ������ �����߽��ϴ�.");
    }
}

void GameEngineVertexBuffer::Setting()
{
    if (nullptr == Buffer)
    {
        MsgBoxAssert("���ؽ� ���ۿ� ������ �ֽ��ϴ�.");
    }

    // �� ������ 1���� �Ž��� �׸��� ���� ����
    GameEngineDevice::GetContext()->IASetVertexBuffers(
        0, // ���ؽ� ���۸� ���������ͷ� �������������� ������ �ε���
        1, &Buffer, &VertexSize, &OffSet);
}
