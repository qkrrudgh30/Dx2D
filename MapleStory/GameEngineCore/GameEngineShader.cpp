// <hide/>

// GameEngineShader.cpp

#include "PreCompile.h"
#include "GameEngineShader.h"
#include "GameEngineVertexShader.h"
#include "GameEnginePixelShader.h"

void GameEngineShader::AutoCompile(const std::string& _Path)
{
    GameEngineFile File = GameEngineFile(_Path);
    File.Open(OpenMode::Read, FileMode::Text);

    std::string AllHlslCode = File.GetString();
    AllHlslCode.resize(File.GetFileSize());

    File.Read(&AllHlslCode[0], AllHlslCode.size(), AllHlslCode.size());

    size_t VSEntryIndex = AllHlslCode.find("_VS(");
    if (std::string::npos != VSEntryIndex)
    {
        size_t FirstIndex = AllHlslCode.find_last_of(" ", VSEntryIndex);
        std::string EntryName = AllHlslCode.substr(FirstIndex + 1, VSEntryIndex - FirstIndex - 1);
        EntryName += "_VS";
        GameEngineVertexShader::Load(_Path, EntryName);
    }

    size_t PSEntryIndex = AllHlslCode.find("_PS(");
    if (std::string::npos != PSEntryIndex)
    {
        size_t FirstIndex = AllHlslCode.find_last_of(" ", PSEntryIndex);
        std::string EntryName = AllHlslCode.substr(FirstIndex + 1, PSEntryIndex - FirstIndex - 1);
        EntryName += "_PS";
        GameEnginePixelShader::Load(_Path, EntryName);
    }
}

GameEngineShader::GameEngineShader()
    : Version("")
    , BinaryPtr(nullptr)
    , EntryPoint("")
{
}

GameEngineShader::~GameEngineShader() 
{
    if (nullptr != BinaryPtr)
    {
        BinaryPtr->Release();
        BinaryPtr = nullptr;
    }
}

void GameEngineShader::CreateVersion(const std::string& _ShaderType, UINT _VersionHigh, UINT _VersionLow)
{
    Version = "";
    Version += _ShaderType + "_"; // vs_
    Version += std::to_string(_VersionHigh); // vs_5
    Version += "_"; // vs_5_
    Version += std::to_string(_VersionLow); // vs_5_0
}

