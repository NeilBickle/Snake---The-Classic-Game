// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
bool EndOfGame;
const int Widthofgame = 30;
const int Heightofgame = 30;
int a, b, fruitA, fruitB, score, lives;
int AddTailA[125], AddTailB[125];
int LengthOfTail;
enum eDirectionOfsnake { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirectionOfsnake DIRECTION; 
void Setupthegame() 
{	
	EndOfGame = false;
	DIRECTION = STOP;
	a = Widthofgame / 2;
	b = Heightofgame / 2;
	fruitA = rand() % Widthofgame;
	fruitB = rand() % Heightofgame;
	score = 0;
	lives = 3;

}
void DrawTheGame()
{	
	
	system("cls");
	for (int i = 0; i < Widthofgame+2; i++)
		cout << "#";
	cout << endl;

	for  (int i = 0; i < Heightofgame; i++)
	{
		for (int j = 0; j < Widthofgame; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == b && j == a)
				cout << "O";
			else if (i == fruitB && j == fruitA)
				cout << "F";
			else
			{
				bool TailPrint = false;
				for (int c = 0; c < LengthOfTail; c++) 
				{					
					if (AddTailA[c] == j && AddTailB[c] == i) 
					{
						cout << "o";
						TailPrint = true;
					}
					
				}				
				if (!TailPrint)
						cout << " ";
			}
				

			if (j == Widthofgame - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < Widthofgame+2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
	cout << "Lives:" << lives << endl;
	cout << "Welcome To Snake" << endl;
}
void InputForTheGame() 
{
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':			
			DIRECTION = LEFT;
			break;
		case 's':
			DIRECTION = DOWN;
			break;
		case 'd':
			DIRECTION = RIGHT;
			break;
		case 'w':
			DIRECTION = UP;
			break;
		case 'x':
			EndOfGame = true;
			break;
		}
	}
}
void GameLogic()
{
	int PastA = AddTailA[0];
	int PastB = AddTailB[0];
	int BeforeA, BeforeB;
	AddTailA[0] = a;
	AddTailB[0] = b;
	for (int i = 1; i < LengthOfTail; i++)
	{
		BeforeA = AddTailA[i];
		BeforeB = AddTailB[i];
		AddTailA[i] = PastA;
		AddTailB[i] = PastB;
		PastA = BeforeA;
		PastB = BeforeB;
	}
	switch (DIRECTION)
	{
	case LEFT:
		a--;
		break;
	case DOWN:
		b++;
		break;
	case UP:
		b--;
		break;
	case RIGHT:
		a++;
		break;
	default:
		break;
	}
	if (a >= Widthofgame) 
	{
		a = 0;
			lives -= 1;
	}
	
	else if (a < 0)
	{
		a = Widthofgame - 1;
		lives -= 1;
	}
	if (b >= Heightofgame) 
	{
		b = 0;
		lives -= 1;
	}
	else if (b < 0)
	{
		b = Heightofgame - 1;
		lives -= 1;
	}
	for (int i = 0; i < LengthOfTail; i++)
	{
		if (AddTailA[i] == a && AddTailB[i] == b)
			lives -= 1;
	}
	if (lives == 0)
		EndOfGame = true;
	if (a == fruitA && b == fruitB) {		
		score += 10;
		fruitA = rand() % Widthofgame;
		fruitB = rand() % Heightofgame;
		LengthOfTail++;
	}
		
}
int main()
{
		
	Setupthegame();	
	while (!EndOfGame)
	{	
		DrawTheGame();
		InputForTheGame();
		GameLogic();
	}
	return 0;
}

