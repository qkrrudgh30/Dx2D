// <hide/>

// Color.hlsl

cbuffer TransformData : register(b0)
{
    float4 LocalPosition;
    float4 LocalRotation;
    float4 LocalScaling;

    float4 WorldPosition;
    float4 WorldRotation;
    float4 WorldScaling;

    float4x4 LocalPositionMatrix;
    float4x4 LocalRotationMatrix;
    float4x4 LocalScalingMatrix;

    float4x4 LocalWorldMatrix;
    float4x4 WorldWorldMatrix;
    float4x4 View;
    float4x4 Projection;

    float4x4 WorldView;
    float4x4 WorldViewProjection;
};

struct Input
{
    float4 Pos : POSITION;
    float4 Color : COLOR;
};

struct Output
{
    float4 Pos : SV_POSITION;
    float4 Color : COLOR;
};

/*
    InputAssembler1
    - InputLayout���� ������� ������ ������ �ۼ���.
      "POSITION", "COLOR" �ø�ƽ �ۼ� ��, �������� POSITION�� COLOR��� �� ���� ������ �ִٴ� ��Ʈ
    - ������ ����(GameEngineCore_Resources.cpp)
    - Buffer�� ������ ����.
    - �Ʒ� Input ����ü�� ���� ��?
*/

Output Color_VS(Input _Input)       
{
/*
    Vertex Shader
    - �� ������ ������ŭ �����.
    - World View Projection�� ���⼭ �����.
    - �� ������ � ������ ������ �����ϴ� �ܰ�.
*/
    Output NewOutPut = (Output)0;
    NewOutPut.Pos = _Input.Pos;
    NewOutPut.Pos.w = 1.f;
    NewOutPut.Pos = mul(NewOutPut.Pos, WorldViewProjection);

    NewOutPut.Color = _Input.Color;

    return NewOutPut;
}

/*
    InputAssembler2
    - ������ ó���� ������ ��Ȱ���ϱ����� Index Buffer�� ����. 
      �̸� �����ϴ� �ܰ�.
    - Topology�� �̶� ��������, �⺻ ���� ������ �����ϰ� ��.
      �츮�� �ﰢ������ �����ؼ� �ۼ��� ����.
*/

/*
    Tesselation (Hull Shader, Tessellator, Domain Shader) & Geometry Shader
    - �� ������ ��� ����.
*/

/*
    Rasterizer
    - viewport transformation�� �� �ܰ迡�� �����.
    - w��(z���� ����Ǿ� ����)���� ������ ���ٰ��� ǥ���ϴ� �͵� ����.
*/
cbuffer ResultColor : register(b0)
{
    float4 Color;
}


float4 Color_PS(Output _Input) : SV_Target0
{
    return Color;
}

/*
    Output Merser
    - Depth Stencil�� ���� ó�� ����.

*/