// AppMain.cpp

#include <Windows.h>

#pragma comment(lib, "GameEngineBase.lib")

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngineBase/GameEngineSound.h>
#include <vector>

using namespace std;

int main()
{
    GameEngineDirectory Dir;

    /*
    1. ���� working dir�� Resources ���͸��� �ִ��� üũ
      1-1. ������ �ڷΰ���
      1-2. ������ ���� path ����
    */
    if (false == Dir.MoveParentToExitsChildDirectory("Resources"))
    {
        MsgBoxAssert("��θ� ã�� ���߽��ϴ�.");
        return 0;
    }

    Dir.Move("Resources"); // ���� �ڵ���ʹ� Dir�� ������ ����� ���ҽ��� ������ �� �� ����. 
    Dir.Move("Sound");

    // for (size_t i = 0; i < Dir.GetAllFile().size(); ++i) {} �ùٸ��� ���� �ڵ�. for�� ȸ������ GetAllFile() �Լ��� �ڵ���� �����.

    vector<GameEngineFile> Files = Dir.GetAllFile();
    for (auto& File : Files)
    {
        GameEngineSound::LoadRessource(File);
    }

    GameEngineSound::SoundPlayOneShot("TestBGM.mp3");

    while (true)
    {
        GameEngineSound::Update();
    }

    return 0;
}