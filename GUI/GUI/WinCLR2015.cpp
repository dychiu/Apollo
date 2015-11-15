#include "PlayerForm.h"

using namespace GUI; // needed for STATThreadAttribute
[STAThreadAttribute] // needed for folder dialog

int main(array<System::String ^> ^args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew PlayerForm());
	return 0;
}