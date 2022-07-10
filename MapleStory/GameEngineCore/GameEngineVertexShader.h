// <hide/>

// GameEngineVertexShader.h

#pragma once
#include "GameEngineShader.h"
#include "GameEngineRes.h"

// ���� :
class GameEngineInputLayOut;
class GameEngineVertexShader
    : public GameEngineShader
    , public GameEngineRes<GameEngineVertexShader>

{
    friend GameEngineInputLayOut;                 // ��ǲ ���̾ƿ��� �ۼ���, ���̴��� �˰��־�� ��.
    friend GameEngineShader;                      // �θ� Ŭ�������� ������ ����.
    friend GameEngineRes<GameEngineVertexShader>; // ���ҽ� ����.

private:
    ID3D11VertexShader* ShaderPtr;

public:
    void Setting();

protected:
    void ShaderCompile(std::string _Path, std::string _EntryPoint, UINT _VersionHigh, UINT _VersionLow);

private:
    // constrcuter destructer
    GameEngineVertexShader();
    ~GameEngineVertexShader();

    // delete Function
    GameEngineVertexShader(const GameEngineVertexShader& _Other) = delete;
    GameEngineVertexShader(GameEngineVertexShader&& _Other) noexcept = delete;
    GameEngineVertexShader& operator=(const GameEngineVertexShader& _Other) = delete;
    GameEngineVertexShader& operator=(GameEngineVertexShader&& _Other) noexcept = delete;

    static GameEngineVertexShader* Load(std::string _Path, std::string _EntryPoint, UINT _VersionHigh = 5, UINT _VersionLow = 0);

    static GameEngineVertexShader* Load(std::string _Path, std::string _Name, std::string _EntryPoint, UINT _VersionHigh, UINT _VersionLow);

};