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
    const std::string&          _Name,
    const void*                 _Data, 
    UINT                        _VertexSize,
    UINT                        _VertexCount,
    const GameEngineLayOutDesc& _LayOut
)
{
    GameEngineVertexBuffer* NewRes = CreateResName(_Name);  // �츮�� ������ ���� ���� ����.
    NewRes->LayOutDesc = &_LayOut;                          // ���� ������ ���� ���ۿ��� ����.
    NewRes->BufferCreate(_Data, _VertexSize, _VertexCount); // �׷��� ī�尡 ������ ���� ���� ����.
    return NewRes;
}

void GameEngineVertexBuffer::BufferCreate(const void* _Data, UINT _VertexSize, UINT _VertexCount)
{
    VertexSize = _VertexSize;
    VertexCount = _VertexCount;

    // ��ġ �׷��� ī�� �� ������ �����ϴ� �ڵ�.
    D3D11_SUBRESOURCE_DATA Data; // ���� Ȥ�� �ؽ��� ���۸� ������ ��, SUBRESOURCE_DATA ����ü ������ �����ؼ� �׷��� ī�忡 �����ؾ���.
    Data.pSysMem = _Data;                                // ������
    BufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;     // ���� �뵵
    BufferDesc.ByteWidth = _VertexSize * _VertexCount;   // ���� ũ��
    BufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT; // ���� �뵵���� ���
    BufferDesc.CPUAccessFlags = 0;

    // ������� �ʴ� �ɼ�.
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
        1, 
        &Buffer,
        &VertexSize,
        &OffSet);
}