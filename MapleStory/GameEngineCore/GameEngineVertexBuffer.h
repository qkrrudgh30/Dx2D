// <hide/>

// GameEngineVertexBuffer.h

#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineRes.h"
#include <vector>
#include <string>
#include <map>
#include <list>

// ���� :
class GameEngineVertexBuffer : public GameEngineRes<GameEngineVertexBuffer>
{
public:
    friend GameEngineRes<GameEngineVertexBuffer>;

public:
    template<typename VertexType> // �������� ���� ����ü���� �ޱ����� ���ø� �Լ��� ����.
    static GameEngineVertexBuffer* Create(const std::string& _Name, const std::vector<VertexType>& _Vertex)
    {
        return Create(_Name, &_Vertex[0], _Vertex.size() * sizeof(VertexType));
    }

    static GameEngineVertexBuffer* Create(const std::string& _Name, const void* _Data, size_t _Size);

private:
    // constrcuter destructer
    GameEngineVertexBuffer();
    ~GameEngineVertexBuffer();

    // delete Function
    GameEngineVertexBuffer(const GameEngineVertexBuffer& _Other) = delete;
    GameEngineVertexBuffer(GameEngineVertexBuffer&& _Other) noexcept = delete;
    GameEngineVertexBuffer& operator=(const GameEngineVertexBuffer& _Other) = delete;
    GameEngineVertexBuffer& operator=(GameEngineVertexBuffer&& _Other) noexcept = delete;

protected:

private:
    ID3D11Buffer*          Buffer;
    D3D11_BUFFER_DESC      BufferDesc;
    D3D11_SUBRESOURCE_DATA Data;

};