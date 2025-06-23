#include "Title.h"

unique_ptr<Title> Title::instance = nullptr;
Title* Title::getInstance() 
{
	static Title instance;  
	return &instance;
}

/* ���� ���� ȭ��*/
string Title::GameStart()
{
	while (true)
	{
		system("cls");
		cout << endl;
		cout << " _______   ______   __      ___   ________     " << endl;
		cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " << endl;
		cout << "   | |    | |__     \\\\ \\//   /      | |     " << endl;
		cout << "   | |    |  __|     \\\\     /       | |      " << endl;
		cout << "   | |    | |____    // /\\\\ \\       | |     " << endl;
		cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << endl;
		cout << endl;
		cout << "            R          P         G             " << endl;
		cout << endl;;
		cout << endl;;
		cout << "       >>> PRESS ANY KEY TO NAMING <<<         " << endl;
		cout << endl;;
		if (false == LoginCheck)
		{
			_getch();
			LoginCheck = true;
		}
		cout << "           less 3 word in english              "  << endl;
		cout << "          Name : ";
		
		/*�̸� ����*/
		cin >> Name;

		if (Name.length() < 5)
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore();
			system("cls");
		}

	}
	return Name;
}

void Title::GameEnd()
{
	system("cls");
	cout << endl;
	cout << " _______   ______   __      ___   ________     " << endl;
	cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " << endl;
	cout << "   | |    | |__     \\\\ \\//   /      | |     " << endl;
	cout << "   | |    |  __|     \\\\     /       | |      " << endl;
	cout << "   | |    | |____    // /\\\\ \\       | |     " << endl;
	cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << endl;
	cout << endl;
	cout << "            R          P         G             " << endl;
	cout << endl;
	cout << endl;
	cout << "         >>> SEE YOU TEXT TIME!!!! <<<         " << endl;
	cout << "         >>> SEE YOU TEXT TIME!!!! <<<         " << endl;
	cout << "         >>> SEE YOU TEXT TIME!!!! <<<         " << endl;
	cout << endl;
	cout << endl;


}

/* ���� ���� ȭ��*/
void Title::GameOver()
{
	system("cls");
	cout << endl;
	cout << " _______   ______   __      ___   ________     " << endl;
	cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " << endl;
	cout << "   | |    | |__     \\\\ \\//   /      | |     " << endl;
	cout << "   | |    |  __|     \\\\     /       | |      " << endl;
	cout << "   | |    | |____    // /\\\\ \\       | |     " << endl;
	cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << endl;
	cout << endl;
	cout << "            R          P         G             " << endl;
	cout << endl;
	cout << endl;;
	cout << "       >>>        YOU ARE DIE    <<<         " << endl;
	cout << "       >>>        YOU ARE DIE    <<<         " << endl;
	cout << "       >>>        YOU ARE DIE    <<<         " << endl;
	cout << "       >>>        YOU ARE DIE    <<<         " << endl;
	cout << endl;
	cout << endl;
}

/* ���� �¸� ȭ��*/
void Title::Victory()
{
	system("cls");
	cout << endl;
	cout << " _______   ______   __      ___   ________     " << endl;
	cout << "|__   __| |  ____| \\\\ \\  //   /  |__   __|  " << endl;
	cout << "   | |    | |__     \\\\ \\//   /      | |     " << endl;
	cout << "   | |    |  __|     \\\\     /       | |      " << endl;
	cout << "   | |    | |____    // /\\\\ \\       | |     " << endl;
	cout << "   |_|    |______|  //_/  \\\\ \\      |_|     " << endl;
	cout << endl;
	cout << "            R          P         G             " << endl;
	cout << endl;
	cout << endl;;
	cout << "       >>>      WIN! WINER! CHICKE! DINER!    <<<         " << endl;
	cout << "       >>>      WIN! WINER! CHICKE! DINER!    <<<         " << endl;
	cout << endl;
	cout << endl;
}





