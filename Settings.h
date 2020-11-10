#pragma once

#include "MyForm.h"

namespace SnakeGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	private:
		MyForm^ parent;
		int oldSpeed;
	public:
		Settings(MyForm^ parent_)
		{
			InitializeComponent();
			parent = parent_;
			oldSpeed = parent->GetSpeed();
			numericUpDownSnakeSpeed->Value = oldSpeed;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::NumericUpDown^ numericUpDownSnakeSpeed;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Button^ buttonApply;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownSnakeSpeed = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonApply = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSnakeSpeed))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Скорость";
			// 
			// numericUpDownSnakeSpeed
			// 
			this->numericUpDownSnakeSpeed->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDownSnakeSpeed->Location = System::Drawing::Point(138, 36);
			this->numericUpDownSnakeSpeed->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDownSnakeSpeed->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDownSnakeSpeed->Name = L"numericUpDownSnakeSpeed";
			this->numericUpDownSnakeSpeed->Size = System::Drawing::Size(179, 20);
			this->numericUpDownSnakeSpeed->TabIndex = 1;
			this->numericUpDownSnakeSpeed->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(16, 101);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(99, 35);
			this->buttonCancel->TabIndex = 2;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &Settings::buttonCancel_Click);
			// 
			// buttonApply
			// 
			this->buttonApply->Location = System::Drawing::Point(218, 101);
			this->buttonApply->Name = L"buttonApply";
			this->buttonApply->Size = System::Drawing::Size(99, 35);
			this->buttonApply->TabIndex = 2;
			this->buttonApply->Text = L"Apply";
			this->buttonApply->UseVisualStyleBackColor = true;
			this->buttonApply->Click += gcnew System::EventHandler(this, &Settings::buttonApply_Click);
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(345, 162);
			this->Controls->Add(this->buttonApply);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->numericUpDownSnakeSpeed);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Settings";
			this->ShowIcon = false;
			this->Text = L"Настройки";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSnakeSpeed))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			this->Close();
			parent->SetSettings(oldSpeed);
		}

		System::Void buttonApply_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			this->Close();
			parent->SetSettings(Convert::ToInt32(numericUpDownSnakeSpeed->Value));
		}
	};
}
