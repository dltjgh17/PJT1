#pragma once

#ifndef TITLE_H_
#define TITLE_H_
#include <iostream>
class Title
{

private:
	Title() = default;
	static std::unique_ptr <Title> instance;

public:
	
	static Title* getInstance();
	Title(const Title&) = delete;
	Title& operator=(const Title&) = delete;
	~Title() = default;

	/* ���� ���� ȭ��*/
	void GameStart();

	/* ���� ���� ȭ��*/
	void GameOver();

	/* ���� �¸� ȭ��*/
	void Victory();

};


#endif