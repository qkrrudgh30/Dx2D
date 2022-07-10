// <hide/>

// GameEngineRenderingPipeLine.h

#pragma once

#include "GameEngineRes.h"

// ���� :
class GameEngineVertexBuffer;
class GameEngineInputLayOut;
class GameEngineVertexShader;
class GameEngineIndexBuffer;
class GameEngineRasterizer;
class GameEnginePixelShader;
class GameEngineRenderingPipeLine : public GameEngineRes<GameEngineRenderingPipeLine>
{
private:
    // ���� �Է� ����
    GameEngineVertexBuffer* VertexBuffer;
    GameEngineInputLayOut*  InputLayOut;

    // ���� ó�� ����
    GameEngineVertexShader*  VertexShader;
    GameEngineIndexBuffer*   IndexBuffer;
    D3D11_PRIMITIVE_TOPOLOGY Topology;

    // ������ ���� ������ �ȼ� ó�� ����
    GameEngineRasterizer*    Rasterizer;
    GameEnginePixelShader*   PixelShader;

public:
    // constrcuter destructer
    GameEngineRenderingPipeLine();
    ~GameEngineRenderingPipeLine();

    // delete Function
    GameEngineRenderingPipeLine(const GameEngineRenderingPipeLine& _Other) = delete;
    GameEngineRenderingPipeLine(GameEngineRenderingPipeLine&& _Other) noexcept = delete;
    GameEngineRenderingPipeLine& operator=(const GameEngineRenderingPipeLine& _Other) = delete;
    GameEngineRenderingPipeLine& operator=(GameEngineRenderingPipeLine&& _Other) noexcept = delete;

    static GameEngineRenderingPipeLine* Create(const std::string& _Name);

    // ������ ���������� ��ü�� ���ҽ����� �����ϴ� �Լ�.
    void SetInputAssembler1VertexBuffer(const std::string& _Name);

    void SetVertexShader(const std::string& _Name);

    void SetInputAssembler2IndexBuffer(const std::string& _Name);

    void SetRasterizer(const std::string& _Name);

    void SetPixelShader(const std::string& _Name);

    // �׷��� ī�忡 ���� ���ҽ����� �̿��ؼ� �׸��� �Լ�.
    void Rendering();

private:
    // ������ ���������ο� ����� ���ҽ����� �׷��� ī�忡 �ȴ� �Լ�.(��, �� �Լ��� ȣ��� �ڷ� ��ȿ)
    void InputAssembler1VertexBufferSetting();

    void VertexShaderSetting();

    void InputAssembler2IndexBufferSetting();

    void RasterizerSetting();

    void PixelShaderSetting();

    void Draw();

};

