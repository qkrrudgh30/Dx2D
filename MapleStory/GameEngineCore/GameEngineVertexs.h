// <hide/>

// GameEngineVertex.h

#pragma once

#include <GameEngineBase/GameEngineMath.h>

class GameEngineLayOutDesc
{
    friend class GameEngineInputLayOut;

public:
    unsigned int                          LayOutOffset;      // ���� ������ ũ��. �� ũ�⸦ �������� ���ĵ�.
    std::map<const char*, int>            SemanticIndexData; // "POSITION1", "POSITION2", ...�� ��������.
    std::vector<D3D11_INPUT_ELEMENT_DESC> InputLayOutDesc;   // ���� ������.

public:
    GameEngineLayOutDesc()
        : LayOutOffset(0)
    {
    }

    void AddInputLayOut(
        const char*                _SemanticName,
        DXGI_FORMAT                _Format,
        unsigned int               _Index = -1,
        D3D11_INPUT_CLASSIFICATION _inputClass = D3D11_INPUT_PER_VERTEX_DATA,
        unsigned int               _InputSlot = 0,
        unsigned int               _InstanceDataStepRate = 0
    );

};

struct GameEngineVertex
{
public:
    static GameEngineLayOutDesc LayOut; // ������ �������� ������ ���� ���.

public:
    float4 POSITION;
    float4 COLOR;
};
