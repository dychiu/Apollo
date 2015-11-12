#include "src/MusicPlayer.h"
#include "PlayerForm.h"

using namespace GUI; // needed for STATThreadAttribute
[STAThreadAttribute] // needed for folder dialog

int main(array<System::String ^> ^args)
{
	MusicPlayer* test = new MusicPlayer();
	test->~MusicPlayer();	//call the destructor? is this needd
	return 0;
}