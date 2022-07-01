// <hide/>

// GameEngineRenderer.h

#pragma once
#include "GameEngineTransformComponent.h"

// ���� :
class GameEngineRenderer : public GameEngineTransformComponent
{
    friend class GameEngineCamera;

public:
    // constrcuter destructer
    GameEngineRenderer();
    ~GameEngineRenderer();

    // delete Function
    GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
    GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
    GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
    GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

    // float4x4 ViewPort; ����Ʈ�� Rasterizer �ܰ迡�� �� ����.

protected:
    virtual void Start();
    virtual void Update(float _DeltaTime) {}
    virtual void End() {}

private:
    virtual void Render(float _DeltaTime) = 0; // ���� GameEngineRenderer Ŭ������ ������ ���� �ֻ��� �θ� Ŭ���� ����.

};

