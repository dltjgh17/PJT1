#include "Opening.h"
#include <iostream>
#include <Windows.h>

void Opening::OPone()
{							                                    
	std::cout << " _______                                       " << std::endl;
	std::cout << "|__   **|                                      " << std::endl;
	std::cout << "   | |                                         " << std::endl;
	std::cout << "   | |                                         " << std::endl;
	std::cout << "   | |                                         " << std::endl;
	std::cout << "   |_|                                         " << std::endl;
}

void Opening::OPtwo()
{
	std::cout << " _______   ___                                 " << std::endl;
	std::cout << "|__   **| |  *                                 " << std::endl;
	std::cout << "   | |    | |_                                 " << std::endl;
	std::cout << "   | |    |  _                                 " << std::endl;
	std::cout << "   | |    | |_                                 " << std::endl;
	std::cout << "   |_|    |___                                 " << std::endl;
}

void Opening::OPthree()
{
	std::cout << " _______   ______                              " << std::endl;
	std::cout << "|__   **| |  **__|                             " << std::endl;
	std::cout << "   | |    | |__                                " << std::endl;
	std::cout << "   | |    |  __|                               " << std::endl;
	std::cout << "   | |    | |____                              " << std::endl;
	std::cout << "   |_|    |______|                             " << std::endl;
}									                           
									                           
void Opening::OPfour()
{										                       
	std::cout << " _______   ______   **                         " << std::endl;
	std::cout << "|__   **| |  **__| \\\\                        " << std::endl;
	std::cout << "   | |    | |__     \\\\                       " << std::endl;
	std::cout << "   | |    |  __|     \\\                       " << std::endl;
	std::cout << "   | |    | |____    //                        " << std::endl;
	std::cout << "   |_|    |______|  //_/                       " << std::endl;
}										                       
										                       
void Opening::OPfive()
{												                
	std::cout << " _______   ______   **      **_                " << std::endl;
	std::cout << "|__   **| |  **__| \\\\ \\  //                 " << std::endl;
	std::cout << "   | |    | |__     \\\\ \\//                  " << std::endl;
	std::cout << "   | |    |  __|     \\\\     /                " << std::endl;
	std::cout << "   | |    | |____    // /\\\\ \\               " << std::endl;
	std::cout << "   |_|    |______|  //_/  \\\\ \               " << std::endl;
}												                
												                
void Opening::OPsix()
{
	std::cout << " _______   ______   **      **_   ________     " << std::endl;
	std::cout << "|__   **| |  **__| \\\\ \\  //   /  |__   __|  " << std::endl;
	std::cout << "   | |    | |__     \\\\ \\//   /      | |     " << std::endl;
	std::cout << "   | |    |  __|     \\\\     /       | |      " << std::endl;
	std::cout << "   | |    | |____    // /\\\\ \\       | |     " << std::endl;
	std::cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << std::endl;
}

void Opening::OPPlay()
{

	OPone();
	Sleep(100);
	system("cls");

	OPtwo();
	Sleep(100);
	system("cls");

	OPthree();
	Sleep(100);
	system("cls");

	OPfour();
	Sleep(100);
	system("cls");

	OPfive();
	Sleep(100);
	system("cls");

	OPsix();
	Sleep(1000);
	system("cls");
}
