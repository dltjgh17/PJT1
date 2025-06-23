#pragma once

#ifndef TITLE_H_
#define TITLE_H_
#include <iostream>
#include <conio.h>

using namespace std;

class Title
{

private:
	bool LoginCheck = false;
	string Name="";
	Title() = default;
	static std::unique_ptr <Title> instance;

public:
	
	static Title* getInstance();
	Title(const Title&) = delete;
	Title& operator=(const Title&) = delete;
	~Title() = default;

	/* ���� ���� ȭ��*/
	string GameStart();

	/* ���� ���� ȭ��*/
	void GameEnd();

	/* ���� ���� ȭ��*/
	void GameOver();

	/* ���� �¸� ȭ��*/
	void Victory();

	/* ���� �����¸� ȭ��*/
	void EndVictory();

};


#endif