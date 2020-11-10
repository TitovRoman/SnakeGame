#pragma once
#include <vector>
namespace SnakeGame {

	using namespace System;

	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� BaseForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);


	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBoxUpper;
	private: System::Windows::Forms::PictureBox^ pictureBoxLower;
	private: System::Windows::Forms::PictureBox^ pictureBoxLeft;
	private: System::Windows::Forms::PictureBox^ pictureBoxRight;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ scoreLable;

	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBoxUpper = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxLower = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxLeft = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxRight = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->scoreLable = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxUpper))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLower))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLeft))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxRight))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem,
					this->�����ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(519, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->���������ToolStripMenuItem,
					this->���������������ToolStripMenuItem, this->���������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(179, 22);
			this->���������ToolStripMenuItem->Text = L"����� ����";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������ToolStripMenuItem_Click);
			// 
			// ���������������ToolStripMenuItem
			// 
			this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			this->���������������ToolStripMenuItem->Size = System::Drawing::Size(179, 22);
			this->���������������ToolStripMenuItem->Text = L"�����/����������";
			this->���������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(179, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����ToolStripMenuItem_Click);
			// 
			// pictureBoxUpper
			// 
			this->pictureBoxUpper->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBoxUpper->Location = System::Drawing::Point(0, 90);
			this->pictureBoxUpper->Name = L"pictureBoxUpper";
			this->pictureBoxUpper->Size = System::Drawing::Size(520, 10);
			this->pictureBoxUpper->TabIndex = 2;
			this->pictureBoxUpper->TabStop = false;
			// 
			// pictureBoxLower
			// 
			this->pictureBoxLower->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBoxLower->Location = System::Drawing::Point(0, 510);
			this->pictureBoxLower->Name = L"pictureBoxLower";
			this->pictureBoxLower->Size = System::Drawing::Size(520, 10);
			this->pictureBoxLower->TabIndex = 2;
			this->pictureBoxLower->TabStop = false;
			// 
			// pictureBoxLeft
			// 
			this->pictureBoxLeft->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBoxLeft->Location = System::Drawing::Point(0, 90);
			this->pictureBoxLeft->Name = L"pictureBoxLeft";
			this->pictureBoxLeft->Size = System::Drawing::Size(10, 430);
			this->pictureBoxLeft->TabIndex = 3;
			this->pictureBoxLeft->TabStop = false;
			// 
			// pictureBoxRight
			// 
			this->pictureBoxRight->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBoxRight->Location = System::Drawing::Point(510, 90);
			this->pictureBoxRight->Name = L"pictureBoxRight";
			this->pictureBoxRight->Size = System::Drawing::Size(10, 430);
			this->pictureBoxRight->TabIndex = 4;
			this->pictureBoxRight->TabStop = false;
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 31);
			this->label1->TabIndex = 1;
			this->label1->Text = L"����:";
			// 
			// scoreLable
			// 
			this->scoreLable->AutoSize = true;
			this->scoreLable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->scoreLable->Location = System::Drawing::Point(101, 42);
			this->scoreLable->Name = L"scoreLable";
			this->scoreLable->Size = System::Drawing::Size(29, 31);
			this->scoreLable->TabIndex = 1;
			this->scoreLable->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(519, 519);
			this->Controls->Add(this->scoreLable);
			this->Controls->Add(this->pictureBoxRight);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBoxLeft);
			this->Controls->Add(this->pictureBoxLower);
			this->Controls->Add(this->pictureBoxUpper);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxUpper))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLower))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLeft))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxRight))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		ref struct Vector2 
		{
			int X, Y;
		};

		Vector2 snakeDirection;
		System::Windows::Forms::Keys snakeKeyDirection;
		Vector2 positionFruit;

		Color snakeHeadColor = Color::DarkGreen;
		Color snakeBodyColor = Color::SeaGreen;
		Color fruitColor = Color::OrangeRed;

		int step = 10;
		int startGameSpeed = 100;

		int score;

		Point topLeftGameArea = Point(0, 90);
		Point lowerRightGameArea = Point(520, 520);

		PictureBox^ fruit;

		Generic::List<PictureBox^> snake;

		void NewGame();
		void KeysToDirection();
		Point GenerateFruitPos();
		bool CheckSnakeIntersection(Point, int);
		void Eating();
		void UpdateScore();
		void AddSnakeChain();
		void MoveSnake();
		void CheckSnake();
		void CheckBorder();
		void GameOver();

	public:
		int GetSpeed() 
		{
			return timer->Interval;
		}

		void SetSpeed(int speed) 
		{
			timer->Interval = speed;
		}

		void SetSettings(int speed) 
		{
			timer->Interval = speed;
			timer->Start();
		}

	private: 
		System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e);

		System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
		System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void ���������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
