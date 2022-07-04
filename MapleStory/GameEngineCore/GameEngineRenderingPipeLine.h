// <hide/>

// GameEngineRenderingPipeLine.h

#pragma once

#include "GameEngineRes.h"

// ���� :
class GameEngineRenderingPipeLine : public GameEngineRes<GameEngineRenderingPipeLine>
{
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

    void Draw();

protected:

private:
    // ���� �Է� ����

    // ���� ó�� ����

    // ������ ���� ������ �ȼ� ó�� ����

};

