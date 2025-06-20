#include "Title.h"
#include <conio.h>

using namespace std;

Title::Title()
{
}

Title::~Title()
{
}

/* 게임 시작 화면*/
void Title::GameStart()
{
	system("cls");

	cout << endl;
	cout << " _______   ______   __      ___   ________   " << endl;
	cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " << endl;
	cout << "   | |    | |__     \\\\ \\//   /      | |     " << endl;
	cout << "   | |    |  __|     \\\\     /       | |     " << endl;
	cout << "   | |    | |____    // /\\\\ \\       | |     " << endl;
	cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << endl;
	cout << endl;
	cout << "        R          P         G           " << endl;
	std::cout << std::endl;;
	std::cout << std::endl;;
	std::cout << " >>> PRESS ANY KEY TO NAMING <<<" << std::endl;
	std::cout << std::endl;;
	_getch();
}

/* 게임 오버 화면*/
void Title::GameOver()
{
	system("cls");
	std::cout << "____________________" << std::endl;
	std::cout << std::endl;
	std::cout << "     GAME OVER";
	std::cout << std::endl;
	std::cout << "____________________" << std::endl;
}

/* 게임 승리 화면*/
void Title::Victory()
{
	system("cls");
	std::cout << "____________________" << std::endl;
	std::cout << std::endl;
	std::cout << "      VICTORY";
	std::cout << std::endl;
	std::cout << "____________________" << std::endl;

}





