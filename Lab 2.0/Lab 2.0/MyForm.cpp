#include "MyForm.h"
#include <Windows.h>
using namespace Lab20;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}
// дана матрица все элементы увеличить на единицу

