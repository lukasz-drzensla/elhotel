#include "pch.h"
#include "MainWindow.h"
#include <Windows.h>
using namespace System;
using namespace ELHotel;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)

{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew MainWindow());

	return 0;

}