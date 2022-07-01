// <hide/>

// GameEngineVertexBuffer.cpp

#include "PreCompile.h"
#include "GameEngineVertexBuffer.h"
#include <GameEngineBase/GameEngineString.h>

GameEngineVertexBuffer::GameEngineVertexBuffer()
    : Buffer(nullptr)
    , BufferDesc{}
{
}

GameEngineVertexBuffer::~GameEngineVertexBuffer()
{
}

GameEngineVertexBuffer* GameEngineVertexBuffer::Create(const std::string& _Name, const void* _Data, size_t _Size)
{
    GameEngineVertexBuffer* NewRes = CreateResName(_Name);

    D3D11_SUBRESOURCE_DATA Data;
    Data.pSysMem = _Data;                                        // �ʱ�ȭ�� ������
    NewRes->BufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;     // ������ �������� �뵵
    NewRes->BufferDesc.ByteWidth = static_cast<UINT>(_Size);     // �Ҵ� �Ϸ��� ������ ũ��
    NewRes->BufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT; // �Ҵ��Ϸ��� ������ �׼��� ���Ѱ� �뵵
    // BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_READ;
    NewRes->BufferDesc.CPUAccessFlags = 0;                       // CPU���� �׼��� �� �� �ִ���.
    NewRes->BufferDesc.MiscFlags = 0;
    NewRes->BufferDesc.StructureByteStride = 0;

    if (S_OK != GameEngineDevice::GetDevice()->CreateBuffer(&NewRes->BufferDesc, &Data, &NewRes->Buffer))
    {
        MsgBoxAssert("���ؽ� ���� ������ �����߽��ϴ�.");
    }

    return NewRes;
}
