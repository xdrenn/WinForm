#pragma once
#include "User.h"

namespace WinFormLogin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for RegistrationForm
	/// </summary>
	public ref class RegistrationForm : public System::Windows::Forms::Form
	{
	public:
		RegistrationForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegistrationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ rgName;
	private: System::Windows::Forms::Label^ rgEmail;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbUsername;
	private: System::Windows::Forms::TextBox^ tbEmail;
	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::TextBox^ tbConfPassword;
	private: System::Windows::Forms::Label^ rgPassword;
	private: System::Windows::Forms::Label^ confPassword;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::Label^ rgPhone;
	private: System::Windows::Forms::TextBox^ tbPhone;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->rgName = (gcnew System::Windows::Forms::Label());
			this->rgEmail = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbUsername = (gcnew System::Windows::Forms::TextBox());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->tbConfPassword = (gcnew System::Windows::Forms::TextBox());
			this->rgPassword = (gcnew System::Windows::Forms::Label());
			this->confPassword = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->rgPhone = (gcnew System::Windows::Forms::Label());
			this->tbPhone = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// rgName
			// 
			this->rgName->AutoSize = true;
			this->rgName->Location = System::Drawing::Point(5, 57);
			this->rgName->Name = L"rgName";
			this->rgName->Size = System::Drawing::Size(55, 13);
			this->rgName->TabIndex = 0;
			this->rgName->Text = L"Username";
			// 
			// rgEmail
			// 
			this->rgEmail->AutoSize = true;
			this->rgEmail->Location = System::Drawing::Point(7, 89);
			this->rgEmail->Name = L"rgEmail";
			this->rgEmail->Size = System::Drawing::Size(32, 13);
			this->rgEmail->TabIndex = 1;
			this->rgEmail->Text = L"Email";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(100, 18);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Registration";
			// 
			// tbUsername
			// 
			this->tbUsername->Location = System::Drawing::Point(103, 54);
			this->tbUsername->Name = L"tbUsername";
			this->tbUsername->Size = System::Drawing::Size(158, 20);
			this->tbUsername->TabIndex = 3;
			// 
			// tbEmail
			// 
			this->tbEmail->Location = System::Drawing::Point(103, 86);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(158, 20);
			this->tbEmail->TabIndex = 4;
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(103, 150);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->Size = System::Drawing::Size(158, 20);
			this->tbPassword->TabIndex = 5;
			this->tbPassword->UseSystemPasswordChar = true;
			// 
			// tbConfPassword
			// 
			this->tbConfPassword->Location = System::Drawing::Point(103, 183);
			this->tbConfPassword->Name = L"tbConfPassword";
			this->tbConfPassword->Size = System::Drawing::Size(158, 20);
			this->tbConfPassword->TabIndex = 6;
			this->tbConfPassword->UseSystemPasswordChar = true;
			// 
			// rgPassword
			// 
			this->rgPassword->AutoSize = true;
			this->rgPassword->Location = System::Drawing::Point(5, 153);
			this->rgPassword->Name = L"rgPassword";
			this->rgPassword->Size = System::Drawing::Size(53, 13);
			this->rgPassword->TabIndex = 7;
			this->rgPassword->Text = L"Password";
			// 
			// confPassword
			// 
			this->confPassword->AutoSize = true;
			this->confPassword->Location = System::Drawing::Point(5, 186);
			this->confPassword->Name = L"confPassword";
			this->confPassword->Size = System::Drawing::Size(90, 13);
			this->confPassword->TabIndex = 8;
			this->confPassword->Text = L"Confirm password";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(236, 249);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RegistrationForm::button1_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(191, 215);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(70, 13);
			this->linkLabel1->TabIndex = 10;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Login instead";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegistrationForm::linkLabel1_LinkClicked);
			// 
			// rgPhone
			// 
			this->rgPhone->AutoSize = true;
			this->rgPhone->Location = System::Drawing::Point(7, 122);
			this->rgPhone->Name = L"rgPhone";
			this->rgPhone->Size = System::Drawing::Size(38, 13);
			this->rgPhone->TabIndex = 11;
			this->rgPhone->Text = L"Phone";
			// 
			// tbPhone
			// 
			this->tbPhone->Location = System::Drawing::Point(103, 119);
			this->tbPhone->Name = L"tbPhone";
			this->tbPhone->Size = System::Drawing::Size(158, 20);
			this->tbPhone->TabIndex = 12;
			// 
			// RegistrationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(323, 284);
			this->Controls->Add(this->tbPhone);
			this->Controls->Add(this->rgPhone);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->confPassword);
			this->Controls->Add(this->rgPassword);
			this->Controls->Add(this->tbConfPassword);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->tbUsername);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->rgEmail);
			this->Controls->Add(this->rgName);
			this->Name = L"RegistrationForm";
			this->Text = L"RegistrationForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ name = tbUsername->Text;
		String^ email = tbEmail->Text;
		String^ phone = tbPhone->Text;
		String^ password = tbPassword->Text;
		String^ confPassword = tbConfPassword->Text;

		if (name->Length == 0 || email->Length == 0 || phone->Length == 0 || password->Length == 0 || confPassword->Length == 0) {
			MessageBox::Show("Please, fill in all the fields", "On or more field is empty", MessageBoxButtons::OK);
			return;
		}

		if (String::Compare(password, confPassword) != 0) {
			MessageBox::Show("Passwords mismatch", "Password Error", MessageBoxButtons::OK);
			return;
		}

		try {
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=users;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "INSERT INTO users " +
				"(name, email, phone, password) VALUES " +
				"(@name, @email, @phone, @password);";

			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@name", name);
			command.Parameters->AddWithValue("@email", email);
			command.Parameters->AddWithValue("@phone", phone);
			command.Parameters->AddWithValue("@password", password);
			command.ExecuteNonQuery();

			user = gcnew User;
			user->name = name;
			user->email = email;
			user->phone = phone;
			user->password = password;
		}
		catch (Exception^ e) {
			MessageBox::Show("Failed to register user", "Register Failure", MessageBoxButtons::OK);
		}
	}
	public: bool switchToLogin = false; 
	public: User^ user = nullptr;
    private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->switchToLogin = true;
		this->Close();
	}
};
}
