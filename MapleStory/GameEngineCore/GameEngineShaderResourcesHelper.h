// <hide/>

// GameEngineShaderResourcesHelper.h

#pragma once
#include "GameEngineRenderingPipeLine.h"
#include "GameEngineShader.h"

// ���� :
class GameEngineShader;
class GameEngineShaderResourcesHelper
{
    friend GameEngineShader;

    // ���ҽ� �����Լ��� ����

    // �� ������۰� �̳༮ �ȿ� �־�?

private:
    // �÷��� 
    // �ȼ� ���̴������� ���� Color(����Ʈ ���)�ε� ���带 �������ְ� �Ͱ�
    // ���ؽ� ���̴������� ���� Color(����Ʈ ���)�ε� ��縦 �������ְ� �Ͱ�
    // �װ� ���� �������� �ʰڽ��ϴ�.
    std::multimap<std::string, GameEngineConstantBufferSetter> ConstantBufferMap;

public:
    // constrcuter destructer
    GameEngineShaderResourcesHelper();
    ~GameEngineShaderResourcesHelper();

    // delete Function
    GameEngineShaderResourcesHelper(const GameEngineShaderResourcesHelper& _Other) = delete;
    GameEngineShaderResourcesHelper(GameEngineShaderResourcesHelper&& _Other) noexcept = delete;
    GameEngineShaderResourcesHelper& operator=(const GameEngineShaderResourcesHelper& _Other) = delete;
    GameEngineShaderResourcesHelper& operator=(GameEngineShaderResourcesHelper&& _Other) noexcept = delete;

    void AllResourcesSetting();

    void ResourcesCheck(GameEngineRenderingPipeLine* _Line);

    bool IsConstantBufferSetter(const std::string& _Name);

    template<typename Res>
    void SetConstantBufferLink(const std::string& _Name, const Res& Data)
    {
        SetConstantBufferLink(_Name, &Data, sizeof(Res));
    }

    void SetConstantBufferLink(const std::string& _Name, const void* Data, UINT _Size);

protected:
    void ShaderCheck(GameEngineShader* _Shader);

};

