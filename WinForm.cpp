#include "WinForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	WinFormLogin::WinForm form;
	Application::Run(% form);

	User^ user = form.user;

	if (user != nullptr) {
		MessageBox::Show("Successful Authentication of " + user->name, "WinForm.cpp", MessageBoxButtons::OK);
	}
	else {
		MessageBox::Show("Authentication Canceled", "WinForm.cpp", MessageBoxButtons::OK);
	}
}
