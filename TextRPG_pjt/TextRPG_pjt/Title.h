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

	/* 게임 시작 화면*/
	void GameStart();

	/* 게임 오버 화면*/
	void GameOver();

	/* 게임 승리 화면*/
	void Victory();

};


#endif