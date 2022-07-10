// <hide/>

// GameEngineRasterizer.h

#pragma once
#include "GameEngineRes.h"

// ���� :
class GameEngineRasterizer : public GameEngineRes<GameEngineRasterizer>
{
private:
    D3D11_RASTERIZER_DESC  Desc;
    ID3D11RasterizerState* State;

public:
    // constrcuter destructer
    GameEngineRasterizer();
    ~GameEngineRasterizer();

    // delete Function
    GameEngineRasterizer(const GameEngineRasterizer& _Other) = delete;
    GameEngineRasterizer(GameEngineRasterizer&& _Other) noexcept = delete;
    GameEngineRasterizer& operator=(const GameEngineRasterizer& _Other) = delete;
    GameEngineRasterizer& operator=(GameEngineRasterizer&& _Other) noexcept = delete;

    static GameEngineRasterizer* Create(const std::string& _Name, const D3D11_RASTERIZER_DESC& _Desc);
 
    void Setting();

protected:
    void Create(const D3D11_RASTERIZER_DESC& _Desc);

};
