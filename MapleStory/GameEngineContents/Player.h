// <hide/>

// Player.h

#pragma once
#include <GameEngineCore/CoreMinimal.h>

// ���� :
class GameEngineDefaultRenderer;
class Player : public GameEngineActor
{
private:
    GameEngineDefaultRenderer* Renderer;
    float                      Speed;
    float4                     Color;

public:
    // constrcuter destructer
    Player();
    ~Player();

    // delete Function
    Player(const Player& _Other) = delete;
    Player(Player&& _Other) noexcept = delete;
    Player& operator=(const Player& _Other) = delete;
    Player& operator=(Player&& _Other) noexcept = delete;

protected:
    void Start() override;
    void Update(float _DeltaTime);
    void End() {}

};

