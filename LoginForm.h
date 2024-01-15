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
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ password;

	private: System::Windows::Forms::TextBox^ passwordBox;
	private: System::Windows::Forms::Button^ button;
	private: System::Windows::Forms::LinkLabel^ link;
	private: System::Windows::Forms::Label^ header;
	private: System::Windows::Forms::Label^ email;
	private: System::Windows::Forms::TextBox^ emailBox;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->password = (gcnew System::Windows::Forms::Label());
			this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			this->button = (gcnew System::Windows::Forms::Button());
			this->link = (gcnew System::Windows::Forms::LinkLabel());
			this->header = (gcnew System::Windows::Forms::Label());
			this->email = (gcnew System::Windows::Forms::Label());
			this->emailBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// password
			// 
			this->password->AutoSize = true;
			this->password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->password->Location = System::Drawing::Point(12, 108);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(61, 15);
			this->password->TabIndex = 1;
			this->password->Text = L"Password";
			// 
			// passwordBox
			// 
			this->passwordBox->Location = System::Drawing::Point(92, 103);
			this->passwordBox->Name = L"passwordBox";
			this->passwordBox->Size = System::Drawing::Size(158, 20);
			this->passwordBox->TabIndex = 3;
			this->passwordBox->UseSystemPasswordChar = true;
			// 
			// button
			// 
			this->button->Location = System::Drawing::Point(251, 224);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(75, 23);
			this->button->TabIndex = 4;
			this->button->Text = L"Submit";
			this->button->UseVisualStyleBackColor = true;
			this->button->Click += gcnew System::EventHandler(this, &LoginForm::button_Click);
			// 
			// link
			// 
			this->link->AutoSize = true;
			this->link->Location = System::Drawing::Point(167, 143);
			this->link->Name = L"link";
			this->link->Size = System::Drawing::Size(83, 13);
			this->link->TabIndex = 5;
			this->link->TabStop = true;
			this->link->Text = L"Register instead";
			this->link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::link_LinkClicked);
			// 
			// header
			// 
			this->header->AutoSize = true;
			this->header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->header->Location = System::Drawing::Point(89, 21);
			this->header->Name = L"header";
			this->header->Size = System::Drawing::Size(181, 16);
			this->header->TabIndex = 6;
			this->header->Text = L"Please, log in to your account";
			// 
			// email
			// 
			this->email->AutoSize = true;
			this->email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->email->Location = System::Drawing::Point(12, 78);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(39, 15);
			this->email->TabIndex = 7;
			this->email->Text = L"Email";
			// 
			// emailBox
			// 
			this->emailBox->Location = System::Drawing::Point(92, 73);
			this->emailBox->Name = L"emailBox";
			this->emailBox->Size = System::Drawing::Size(158, 20);
			this->emailBox->TabIndex = 8;
			// 
			// WinForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(338, 259);
			this->Controls->Add(this->emailBox);
			this->Controls->Add(this->email);
			this->Controls->Add(this->header);
			this->Controls->Add(this->link);
			this->Controls->Add(this->button);
			this->Controls->Add(this->passwordBox);
			this->Controls->Add(this->password);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Name = L"WinForm";
			this->Text = L"WinForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: User^ user = nullptr; 
	public: bool switchToRegister = false;
	private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = this->emailBox->Text;
		String^ password = this->passwordBox->Text;

		if (email->Length == 0 || password->Length == 0)
		{
			MessageBox::Show("Please, enter email or password", "Email or Password empty", MessageBoxButtons::OK);
			return;
		}

		try {
			String^ connectionString = "Data Source=localhost\\sqlexpress;Initial Catalog=users;Integrated Security=True";
			SqlConnection sqlConn(connectionString);
			sqlConn.Open();

			String^ sqlQuery = "SELECT * FROM users WHERE email=@email AND password=@password;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@email", email);
			command.Parameters->AddWithValue("@password", password);

			SqlDataReader^ reader = command.ExecuteReader();
			if (reader->Read()) {
				user = gcnew User;
				user->id = reader->GetInt32(0);
				user->name = reader->GetString(1);
				user->email = reader->GetString(2);
				user->phone = reader->GetString(3);
				user->password = reader->GetString(4);

				this->Close();
			}
			else {
				MessageBox::Show("Email or password is incorrect", "Email or Password error", MessageBoxButtons::OK);
			}
		}
		catch (Exception^ e) {
			MessageBox::Show("Failed to connect to database", "Database Connection Error", MessageBoxButtons::OK);
		}
	}
private: System::Void link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	this->switchToRegister = true;
	this->Close();
}
};
}
