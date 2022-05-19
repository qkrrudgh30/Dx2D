#include "GameEngineLevel.h"
#include "GameEngineActor.h"
#include "GameEngineRenderer.h"

GameEngineLevel::GameEngineLevel() 
{
}

GameEngineLevel::~GameEngineLevel() 
{
    for (const std::pair<int, std::list<GameEngineActor*>>& Group : AllActors)
    {
        for (GameEngineActor* const Actor : Group.second)
        {
            if (nullptr == Actor)
            {
                continue;
            }

            delete Actor;
        }
    }
}

void GameEngineLevel::ActorUpdate(float _DeltaTime)
{
    for (const std::pair<int, std::list<GameEngineActor*>>& Group : AllActors)
    {
        // Group.first;

        float ScaleTime = GameEngineTime::GetInst()->GetDeltaTime(Group.first);

        for (GameEngineActor* const Actor : Group.second)
        {
            Actor->AddAccTime(_DeltaTime);
            Actor->ComponentUpdate(ScaleTime, _DeltaTime);
            Actor->Update(_DeltaTime);
        }
    }
}

void GameEngineLevel::PushRenderer(GameEngineRenderer* _Renderer)
{
    AllRenderer_[_Renderer->GetOrder()].push_back(_Renderer);
}

void GameEngineLevel::Render(float _DeltaTime)
{
    for (const std::pair<int, std::list<GameEngineRenderer*>>& Group : AllRenderer_)
    {
        float ScaleTime = GameEngineTime::GetInst()->GetDeltaTime(Group.first);
        for (GameEngineRenderer* const Actor : Group.second)
        {
            Actor->Render(ScaleTime);
        }
    }
}

