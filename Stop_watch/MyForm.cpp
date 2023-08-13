#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


int main()
{
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    Stop_watch::MyForm form;
    Application::Run(% form);
    return 0;
}