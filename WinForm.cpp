#include "LoginForm.h"
#include "UserForm.h"
#include "RegistrationForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	User^ user = nullptr;
	while (true) {
		WinFormLogin::LoginForm loginForm;
		loginForm.ShowDialog();

		if (loginForm.switchToRegister) {
			WinFormLogin::RegistrationForm registerForm;
			registerForm.ShowDialog();

			if(registerForm.switchToLogin) {
				continue;
			}
			else {
				user = registerForm.user;
				break;
			}
		}
		else {
			user = loginForm.user;
			break;
		}
	}

	if (user != nullptr) {
		WinFormLogin::UserForm userForm(user);
		Application::Run(% userForm);
	}
	else {
		MessageBox::Show("Authentication Canceled", "WinForm.cpp", MessageBoxButtons::OK);
	}
}
