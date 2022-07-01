// <hide/>

// GameEngineDefaultRenderer.cpp

#include "PreCompile.h"
#include "GameEngineDefaultRenderer.h"

GameEngineDefaultRenderer::GameEngineDefaultRenderer() 
    :PipeLine(nullptr)
{
}

GameEngineDefaultRenderer::~GameEngineDefaultRenderer() 
{
}

void GameEngineDefaultRenderer::Render(float _DeltaTime)
{
    GameEngineRenderer::Start(); // ��� �� �ڵ� �ܿ� ������ ���� ��.
}

void GameEngineDefaultRenderer::Start()
{
    // PipeLine->Draw(); ����� �ڵ尡 �ۼ��� ����. 
    // �ϳ��� ��ü�� �������Ƿ���, �׻� Pipe line�� ������ �ʿ���.
}

