#pragma once
#include "User.h"

namespace WinFormLogin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UserForm
	/// </summary>
	public ref class UserForm : public System::Windows::Forms::Form
	{
	public:
		UserForm(User ^user)
		{
			InitializeComponent();
			userInfo->Text = "Id=" + user->id + "\n" + "Username=" + user->name + "\n" + "Email=" + user->email;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ userInfo;
	private: System::Windows::Forms::Label^ label;
	protected:


	protected:


	protected:

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
			this->userInfo = (gcnew System::Windows::Forms::Label());
			this->label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// userInfo
			// 
			this->userInfo->AutoSize = true;
			this->userInfo->Location = System::Drawing::Point(22, 70);
			this->userInfo->Name = L"userInfo";
			this->userInfo->Size = System::Drawing::Size(31, 13);
			this->userInfo->TabIndex = 0;
			this->userInfo->Text = L"none";
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label->Location = System::Drawing::Point(96, 20);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(64, 31);
			this->label->TabIndex = 1;
			this->label->Text = L"Info";
			this->label->Click += gcnew System::EventHandler(this, &UserForm::accountEmail_Click);
			// 
			// UserForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(271, 188);
			this->Controls->Add(this->label);
			this->Controls->Add(this->userInfo);
			this->Name = L"UserForm";
			this->Text = L"UserForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void accountEmail_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
