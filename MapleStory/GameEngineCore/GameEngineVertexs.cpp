// <hide/>

// GameEngineVertex.cpp

#include "PreCompile.h"
#include "GameEngineVertexs.h"

GameEngineLayOutDesc GameEngineVertex::LayOut;

unsigned int FormatToByteScale(DXGI_FORMAT _Format)
{
    switch (_Format)
    {
    case DXGI_FORMAT_UNKNOWN:
        MsgBoxAssert("Error with DXGI_FORMAT_UNKNOWN.");
        return -1;
    case DXGI_FORMAT_R32G32B32A32_TYPELESS:
    case DXGI_FORMAT_R32G32B32A32_FLOAT:
    case DXGI_FORMAT_R32G32B32A32_UINT:
    case DXGI_FORMAT_R32G32B32A32_SINT:
        return 16;
    default:
        break;
    }

    MsgBoxAssert("Error with unknown _Format's value");
    return -1;
}

void GameEngineLayOutDesc::AddInputLayOut(
    const char*                _SemanticName, 
    DXGI_FORMAT                _Format, 
    unsigned int               _Index, 
    D3D11_INPUT_CLASSIFICATION _inputClass,
    unsigned int               _InputSlot,
    unsigned int               _InstanceDataStepRate)
{
    D3D11_INPUT_ELEMENT_DESC LayOutDesc = { 0, }; // ���� ������ ���� �ʱ�ȭ.

    int Index = _Index;

    if (-1 == Index)                                                          // 1. ���� �ش� �ø�ƽ �̸��� �ε����� �⺻������ ���´ٸ�,
    {
        if (SemanticIndexData.end() == SemanticIndexData.find(_SemanticName)) // 2. �Դٰ� �ش� �ø�ƽ �̸��� ������ �����ٸ�,
        {
            SemanticIndexData[_SemanticName] = -1;                            // 3. -1�� �����ؼ� ó���̶�� ���� ������.
        }

        Index = ++SemanticIndexData[_SemanticName];                           // 4. �̷ν�, POSITION0�� �ִٸ� �������� 1, 2, 3...
    }

    LayOutDesc.SemanticName = _SemanticName;     // ex. "POSITION", "COLOR", "TANGENT", "NORMAL", ...
    LayOutDesc.SemanticIndex = Index;            // ex. "POSITION0", "POSITION1", ...
    LayOutDesc.Format = _Format;                 // ex. DXGI_FORMAT_R32G32B32A32_FLOAT 
    LayOutDesc.AlignedByteOffset = LayOutOffset; // ���� �������� �� ũ��
    LayOutDesc.InputSlotClass = _inputClass;     // ���� ������ ũ��

    // �ν��Ͻ� ���� ���ÿ�
    LayOutDesc.InputSlot = _InputSlot;
    LayOutDesc.InstanceDataStepRate = _InstanceDataStepRate;

    LayOutOffset += FormatToByteScale(LayOutDesc.Format); // ���� ������ ������ ���� "���� �������� �� ũ��"�� ����.

    InputLayOutDesc.push_back(LayOutDesc);                // �ۼ� �Ϸ�� ������ ������ �߰���.
}
