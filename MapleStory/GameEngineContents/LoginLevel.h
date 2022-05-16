// LoginLevel.h

#pragma once

#include <GameEngineCore/GameEngineLevel.h>

// ���� :
class LoginLevel : GameEngineLevel
{
public:
    // constrcuter destructer
    LoginLevel();
    ~LoginLevel();

    // delete Function
    LoginLevel(const LoginLevel& _Other) = delete;
    LoginLevel(LoginLevel&& _Other) noexcept = delete;
    LoginLevel& operator=(const LoginLevel& _Other) = delete;
    LoginLevel& operator=(LoginLevel&& _Other) noexcept = delete;

protected:

private:

};

