// <hide/>

// Color.hlsl

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

float4 Color_PS(Output _Input) : SV_Target0
{
    return _Input.Color;
}

/*
    Output Merser
    - Depth Stencil�� ���� ó�� ����.

*/