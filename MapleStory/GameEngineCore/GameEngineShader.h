// <hide/>

// GameEngineShader.h

#pragma once
#include <string>

// ���� :
class GameEngineShader
{
protected:
    ID3DBlob*   BinaryPtr;  // �����ϵ� ���̳ʸ� ���̴� ������ ����� ���� ����Ű�� ������.
    std::string Version;    // ���̴� ��� ����.

private:
    std::string EntryPoint; // ���̴��� �̸�.

public:
    // constrcuter destructer
    GameEngineShader();
    ~GameEngineShader();

    // delete Function
    GameEngineShader(const GameEngineShader& _Other) = delete;
    GameEngineShader(GameEngineShader&& _Other) noexcept = delete;
    GameEngineShader& operator=(const GameEngineShader& _Other) = delete;
    GameEngineShader& operator=(GameEngineShader&& _Other) noexcept = delete;

    static void AutoCompile(const std::string& _Path);

protected:
    void CreateVersion(const std::string& _ShaderType, UINT _VersionHigh, UINT _VersionLow);

    void SetEntryPoint(const std::string& _EntryPoint)
    {
        EntryPoint = _EntryPoint;
    }

};
