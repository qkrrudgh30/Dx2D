// HillOfTheMapleTreeLevel.h

#pragma once

#include <GameEngineCore/GameEngineLevel.h>

// ���� :
class HillOfTheMapleTreeLevel : GameEngineLevel
{
public:
    // constrcuter destructer
    HillOfTheMapleTreeLevel();
    ~HillOfTheMapleTreeLevel();

    // delete Function
    HillOfTheMapleTreeLevel(const HillOfTheMapleTreeLevel& _Other) = delete;
    HillOfTheMapleTreeLevel(HillOfTheMapleTreeLevel&& _Other) noexcept = delete;
    HillOfTheMapleTreeLevel& operator=(const HillOfTheMapleTreeLevel& _Other) = delete;
    HillOfTheMapleTreeLevel& operator=(HillOfTheMapleTreeLevel&& _Other) noexcept = delete;

protected:

private:

};

