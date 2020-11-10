#include "MyForm.h"
#include "Settings.h"

#include <Windows.h>

using namespace SnakeGame;

[System::STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

SnakeGame::MyForm::MyForm(void)
{
	InitializeComponent();

	fruit = gcnew PictureBox();
	NewGame();
}

void SnakeGame::MyForm::NewGame() 
{
	score = 0;
	UpdateScore();

	for (int i = 0; i < snake.Count; ++i) 
	{
		this->Controls->Remove(snake[i]);
	}
	snake.Clear();

	snake.Add(gcnew PictureBox());
	snake[0]->Location = Point(200, 200);
	snake[0]->BackColor = snakeHeadColor;
	snake[0]->Width = step;
	snake[0]->Height = step;
	this->Controls->Add(snake[0]);

	AddSnakeChain();

	fruit->Location = GenerateFruitPos();
	fruit->BackColor = fruitColor;
	fruit->Width = step;
	fruit->Height = step;
	this->Controls->Add(fruit);

	snakeKeyDirection = Keys::Right;
	KeysToDirection();

	timer->Interval = startGameSpeed;
	timer->Start();
}

void SnakeGame::MyForm::KeysToDirection()
{
	if (snakeKeyDirection == Keys::Right) 
	{
		snakeDirection.X = 1;
		snakeDirection.Y = 0;
	}
	else if (snakeKeyDirection == Keys::Left) 
	{
		snakeDirection.X = -1;
		snakeDirection.Y = 0;
	}
	else if (snakeKeyDirection == Keys::Up) 
	{
		snakeDirection.Y = -1;
		snakeDirection.X = 0;
	}
	else if (snakeKeyDirection == Keys::Down) 
	{
		snakeDirection.Y = 1;
		snakeDirection.X = 0;
	}
}

Point SnakeGame::MyForm::GenerateFruitPos()
{
	Random^ rand = gcnew Random();
	int x, y;
	do
	{
		x = rand->Next(topLeftGameArea.X + 10, lowerRightGameArea.X - 10);
		y = rand->Next(topLeftGameArea.Y + 10, lowerRightGameArea.Y - 10);
		x -= x % 10;
		y -= y % 10;
	} while (CheckSnakeIntersection(Point(x, y), 0));

	return Point(x, y);
}

bool SnakeGame::MyForm::CheckSnakeIntersection(Point point, int start_ind)
{
	for (int i = start_ind; i < snake.Count; ++i) 
	{
		if (point == snake[i]->Location) 
		{
			return true;
		}
	}
	return false;
}

void SnakeGame::MyForm::Eating() 
{
	if (snake[0]->Location == fruit->Location) 
	{
		snake[0]->BackColor = fruitColor;

		++score;
		UpdateScore();
		fruit->Location = GenerateFruitPos();
	}
}

void SnakeGame::MyForm::UpdateScore()
{
	scoreLable->Text = Convert::ToString(score);
}

void SnakeGame::MyForm::AddSnakeChain()
{
	int ind = snake.Count;
	snake.Add(gcnew PictureBox());

	snake[ind]->Location = Point(snake[ind - 1]->Location.X + snakeDirection.X * step, snake[ind - 1]->Location.Y - snakeDirection.Y * step);

	snake[ind]->BackColor = snakeBodyColor;
	snake[ind]->Width = step;
	snake[ind]->Height = step;
	this->Controls->Add(snake[ind]);
}

void SnakeGame::MyForm::MoveSnake()
{
	if (snake[snake.Count - 1]->BackColor == fruitColor) 
	{
		snake[snake.Count - 1]->BackColor = snakeBodyColor;
		AddSnakeChain();
	}
	for (int i = snake.Count - 1; i > 0; --i) 
	{
		snake[i]->Location = snake[i - 1]->Location;
		snake[i]->BackColor = snake[i - 1]->BackColor;
	}
	if (snake[1]->BackColor == snakeHeadColor) 
	{
		snake[1]->BackColor = snakeBodyColor;
	}
	snake[0]->BackColor = snakeHeadColor;
	snake[0]->Location = Point(snake[0]->Location.X + snakeDirection.X * step, snake[0]->Location.Y + snakeDirection.Y * step);
}

void SnakeGame::MyForm::CheckSnake()
{
	if (CheckSnakeIntersection(snake[0]->Location, 1)) 
	{
		GameOver();
	}
}

void SnakeGame::MyForm::CheckBorder()
{
	Point snakeHead = snake[0]->Location;
	if (snakeHead.Y <= topLeftGameArea.Y
		|| snakeHead.Y >= lowerRightGameArea.Y - 10
		|| snakeHead.X <= topLeftGameArea.X
		|| snakeHead.X >= lowerRightGameArea.X - 10) 
	{
		GameOver();
	}
}

void SnakeGame::MyForm::GameOver()
{
	timer->Stop();
	auto result = MessageBox::Show("’ÓÚËÚÂ Ì‡˜‡Ú¸ ÌÓ‚Û˛ Ë„Û?", "»„‡ ÓÍÓÌ˜ÂÌ‡!", MessageBoxButtons::YesNo);
	
	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		NewGame();
	}

}

System::Void SnakeGame::MyForm::MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	auto key = e->KeyCode;

	if (key == Keys::Left) 
	{
		if (snakeKeyDirection != Keys::Right) 
		{
			snakeKeyDirection = key;
		}
	}
	else if (key == Keys::Right) 
	{
		if (snakeKeyDirection != Keys::Left)
		{
			snakeKeyDirection = key;
		}
	}
	else if (key == Keys::Down) 
	{
		if (snakeKeyDirection != Keys::Up)
		{
			snakeKeyDirection = key;
		}
	}
	else if (key == Keys::Up)
	{
		if (snakeKeyDirection != Keys::Down)
		{
			snakeKeyDirection = key;
		}
	}

	KeysToDirection();
	return System::Void();
}

System::Void SnakeGame::MyForm::Ì‡ÒÚÓÈÍËToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	timer->Stop();
	Settings^ settings = gcnew Settings(this);
	settings->Show();
}

System::Void SnakeGame::MyForm::Ô‡ÛÁ‡ÔÓ‰ÓÎÊËÚ¸ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	timer->Enabled ? timer->Stop() : timer->Start();
}

System::Void SnakeGame::MyForm::timer_Tick(System::Object^ sender, System::EventArgs^ e)
{
	MoveSnake();
	Eating();
	CheckBorder();
	CheckSnake();
}

System::Void SnakeGame::MyForm::ÌÓ‚‡ˇ»„‡ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	NewGame();
}

System::Void SnakeGame::MyForm::‚˚ıÓ‰ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}
