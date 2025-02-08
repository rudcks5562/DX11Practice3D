#include "pch.h"
#include "Main.h"
#include "Engine/Game.h"
#include "TriangleDemo.h"
#include "QuadDemo.h"
#include "ConstBufferDemo.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	GameDesc desc;
	desc.appName = L"gc";
	desc.hInstance = hInstance;
	desc.vsync = false;
	desc.hWnd = NULL;
	desc.width = 800;
	desc.height = 600;
	desc.clearColor = Color(0.5f, 0.5f, 0.5f, 0.5f);
	desc.app = make_shared<ConstBufferDemo>();

	GAME->Run(desc);

	return 0;
}