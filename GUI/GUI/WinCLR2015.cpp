#include "PlayerForm.h" 

using namespace GUI; 

[STAThreadAttribute] // needed for folder dialog

int main(array<System::String ^> ^args)
{
	//Application::EnableVisualStyles(); // removing this allows for more custom styles in the form components
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew PlayerForm());
	return 0;
}

