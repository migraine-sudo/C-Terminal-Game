/*
A Sanke Game Written in C++ ,to review some features of this language...
author:Migraine-sudo
2021.1.1
Compile:g++-9 main.cpp -o snake -std=c++11(IF MAC_OS，do not use clang to complie)
Complate:Win32 MACOS Linux
*/ 
#include<iostream>
#include"CSnake.h"
#include"CMap.h"
#include<vector>

#ifdef _WIN32
	#include<windows.h>
	#include<conio.h>
	#define clear() system("cls")
	#define sleep() Sleep(5 * 100);
#elif __linux__
	#define clear() system("reset")
#elif __APPLE__
	#include <unistd.h>
	#define clear() system("clear")
	#define sleep() sleep(1);
	
#endif

using namespace std;

const int sidescope = 25; //need to be asure sidescope <500

int main(){
	cout << "[*]welcome to Snakes! Press Any keys to start!"<<endl;
	#ifdef  _WIN32
	getch();
	#endif
	//Init Map and Snake
	CMap Map(sidescope); InitMap(Map);
	vector<CSnake> snake={CSnake(0,0),randnum(Map)}; //the firest element is for direction
	Drawsnake(snake,4);
	clear();
	insertSnake(Map,snake);
	traverse(Map);

	//Running
	while(Judge(Map,snake)){
		sleep(); 
		vector<CSnake> store_snake=MoveSnake(snake);
		//Make snakes more sensitive instead of delayed（*）
		if(Control(snake,3)){//if receive a input
			ReverseMoveSnake(snake,store_snake); //Restore the snake to its original state
			MoveSnake(snake); //use the new direction to move
		}
		//insert the snake into map
		ClearMap(Map);
		insertSnake(Map,snake);
		clear();
		//draw
		traverse(Map);		//Draw
	}

	//END
	clear();
	cout<<"Good Bye~"<<endl;
	
}
