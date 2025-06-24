#pragma once
#include <iostream>

class Title
{

private:
	bool LoginCheck = false;
	std::string Name="";
	Title() = default;
	static std::unique_ptr <Title> instance;

public:
	
	static Title* getInstance();
	Title(const Title&) = delete;
	Title& operator=(const Title&) = delete;
	~Title() = default;

	/* ���� ���� ȭ��*/
	std::string GameStart();

	/* ���� ���� ȭ��*/
	void GameEnd();

	/* ���� ���� ȭ��*/
	void GameOver();

	/* ���� �¸� ȭ��*/
	void Victory();

	/* ���� �����¸� ȭ��*/
	void EndVictory();

};