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

	/* 게임 시작 화면*/
	std::string GameStart();

	/* 게임 종료 화면*/
	void GameEnd();

	/* 게임 오버 화면*/
	void GameOver();

	/* 게임 승리 화면*/
	void Victory();

	/* 게임 최종승리 화면*/
	void EndVictory();

};