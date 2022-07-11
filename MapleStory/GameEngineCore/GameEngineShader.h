// <hide/>

// GameEngineShader.h

#pragma once
#include <string>
#include <map>

enum class ShaderType
{
    Vertex,
    Pixel,
};

class ShaderResSetter
{
public:
    ShaderType   ShaderType;
    int          BindPoint;
    std::string* Name;
};

class GameEngineConstantBuffer;
class GameEngineConstantBufferSetter : public ShaderResSetter
{
public:
    GameEngineConstantBuffer* Res;
    const void*               SetData;         // ���ڰ� ���� ������ ���� �ּ�
    UINT                      Size;
    std::vector<char>         OriginalData;    // �ڱ�޸𸮷� �Ҵ��� ����.

public:
    GameEngineConstantBufferSetter()
        : Res(nullptr)
        , SetData(nullptr)
        , Size(-1)
    {
    }

    void Setting() const;
};

// ���� :
class GameEngineShader
{
    friend class GameEngineShaderResourcesHelper;

protected:
    ID3DBlob*   BinaryPtr;         // �����ϵ� ���̳ʸ� ���̴� ������ ����� ���� ����Ű�� ������.
    std::string Version;           // ���̴� ��� ����.
    ShaderType  ShaderSettingType; // ?

private:
    std::string                                           EntryPoint;        // ���̴��� �̸�.
    std::map<std::string, GameEngineConstantBufferSetter> ConstantBufferMap; // ��� ���� ������.

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

    GameEngineConstantBufferSetter& GetConstantBufferSetter(std::string _Name);

protected:
    void CreateVersion(const std::string& _ShaderType, UINT _VersionHigh, UINT _VersionLow);

    void SetEntryPoint(const std::string& _EntryPoint)
    {
        EntryPoint = _EntryPoint;
    }

    void ShaderResCheck(); // ���̴����� ������۸� ����ߴ��� �ؽ�ó�� ����� üũ�ϴ� �Լ�.

};
