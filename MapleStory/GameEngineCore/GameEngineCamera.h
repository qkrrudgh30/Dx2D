#pragma once
#include "GameEngineTransformComponent.h"
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineBase/GameEngineWindow.h>

enum class CAMERAPROJECTIONMODE
{
	PersPective,
	Orthographic,
};

// 설명 :
class GameEngineLevel;
class GameEngineCamera;
class GameEngineCamera : public GameEngineTransformComponent
{
	friend GameEngineLevel;

public:
	// constrcuter destructer
	GameEngineCamera();
	~GameEngineCamera();

	// delete Function
	GameEngineCamera(const GameEngineCamera& _Other) = delete;
	GameEngineCamera(GameEngineCamera&& _Other) noexcept = delete;
	GameEngineCamera& operator=(const GameEngineCamera& _Other) = delete;
	GameEngineCamera& operator=(GameEngineCamera&& _Other) noexcept = delete;

	CAMERAPROJECTIONMODE GetProjectionMode()
	{
		return Mode;
	}

	void SetProjectionMode(CAMERAPROJECTIONMODE _Mode)
	{
		Mode = _Mode;
	}

	// 왼쪽 위가 0,0
	float4 GetScreenPosition();

	float4 GetMouseWorldPosition();

	float4 GetMouseWorldPositionToActor();

	inline float4 GetMouseWorldDir() 
	{
		return MouseDir;
	}

	// 뷰포트는 계속 달라질수가 있으므로 다르게
	// float4 GetMouseViewPortPosition();


protected:
	void Start();

private:
	float4x4 View; // 바라보는것
	float4x4 ViewPort;
	float4x4 Projection;
	CAMERAPROJECTIONMODE Mode;

	float4 PrevMouse;
	float4 MouseDir;

	D3D11_VIEWPORT ViewPortDesc;

	// Projection Data
	float4 Size;
	float Near;
	float Far;

	// Perspective
	float Fov;

	std::map<int, std::list<class GameEngineRenderer*>> AllRenderer_;

	void Render(float _DeltaTime);

	void PushRenderer(GameEngineRenderer* _Renderer);

	void Release(float _DelataTime);

	void Update(float _DeltaTime) override;
};

