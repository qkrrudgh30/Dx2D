// <hide/>

// GameEngineVertexBuffer.h

#pragma once
#include <string>
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineRes.h"
#include "GameEngineVertexs.h"

// ���� :
class GameEngineVertexBuffer : public GameEngineRes<GameEngineVertexBuffer>
{
    friend GameEngineRes<GameEngineVertexBuffer>;

private:
    D3D11_BUFFER_DESC           BufferDesc;  // ������ ����
    ID3D11Buffer*               Buffer;      // ���� �ڵ鷯
    UINT                        VertexCount; // ���� ����
    UINT                        VertexSize;  // ������ ũ��
    UINT                        OffSet;      // 
    const GameEngineLayOutDesc* LayOutDesc;  // ������ ����

public:
    template<typename VertexType>
    static GameEngineVertexBuffer* Create(const std::string& _Name, const std::vector<VertexType>& _Vertex)
    {
        //           �����̸�   �����ּ�               ������ ũ��                           ������ ����                   ������ ����    
        return Create(_Name, &_Vertex[0], static_cast<UINT>(sizeof(VertexType)), static_cast<UINT>(_Vertex.size()), VertexType::LayOut);
    }

    static GameEngineVertexBuffer* Create(const std::string& _Name, const void* _Data, UINT _VertexSize, UINT _VertexCount, const GameEngineLayOutDesc& _LayOut);

    const GameEngineLayOutDesc* GetLayOutDesc()
    {
        return LayOutDesc;
    }

    void Setting();                                                            // ���� ���� ���۸� �׷��� ī�忡 �ȱ� ���� �Լ�.

protected:
    void BufferCreate(const void* _Data, UINT _VertexSize, UINT _VertexCount); // �׷��� ī�忡 ���� ���� ���� �Լ�.

private:
    GameEngineVertexBuffer();
    ~GameEngineVertexBuffer();

    // delete Function
    GameEngineVertexBuffer(const GameEngineVertexBuffer& _Other) = delete;
    GameEngineVertexBuffer(GameEngineVertexBuffer&& _Other) noexcept = delete;
    GameEngineVertexBuffer& operator=(const GameEngineVertexBuffer& _Other) = delete;
    GameEngineVertexBuffer& operator=(GameEngineVertexBuffer&& _Other) noexcept = delete;
};

