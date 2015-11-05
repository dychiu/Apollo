#include "PlayerForm.h" 

using namespace GUI; 

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	//Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew PlayerForm());
	return 0;
}