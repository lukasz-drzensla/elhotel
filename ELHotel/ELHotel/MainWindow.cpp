#include "pch.h"
#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    ELHotel::MainWindow form;
    Application::Run(% form);
}
