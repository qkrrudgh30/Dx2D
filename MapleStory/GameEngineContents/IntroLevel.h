// IntroLevel.h

#pragma once

#include <GameEngineCore/GameEngineLevel.h>

// ���� :
class IntroLevel : public GameEngineLevel
{
public:
    // constrcuter destructer
    IntroLevel();
    ~IntroLevel();

    // delete Function
    IntroLevel(const IntroLevel& _Other) = delete;
    IntroLevel(IntroLevel&& _Other) noexcept = delete;
    IntroLevel& operator=(const IntroLevel& _Other) = delete;
    IntroLevel& operator=(IntroLevel&& _Other) noexcept = delete;

protected:

private:

};

