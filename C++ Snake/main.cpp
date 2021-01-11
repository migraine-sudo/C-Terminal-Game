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
#include"CScore.h"
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
	#define sleep() usleep(100000)
	#define setwindow() system("resize -s 28 95")
	
#endif

using namespace std;

const int sidescope = 25; //need to be asure sidescope <500
int CSnake::dirt=LEFT;   //static dirt test

int main(){
	cout << "[*]welcome to Snakes! Press Any keys to start!"<<endl;
	#ifdef  _WIN32
	getch();
	#elif __APPLE__
	setwindow();
	#endif
	//init Score
	CScore score(0);

	//Init Map and Snake
	CMap Map(sidescope); InitMap(Map);
	//vector<CSnake> snake={CSnake(0,0),randnum(Map)}; //the firest element is for direction
	vector<CSnake> snake={randnum(Map)}; 				//direction is static type
	//vector<CSnake> food={CSnake(0,0)};
	vector<CSnake> food;
	Drawsnake(snake,4);
	clear();
	insertSnake(Map,snake);
	//generate food 
	food.insert(food.begin(),generate(snake,Map));
	clear();
	insertFood(Map,food);
	traverse(Map,score);
	usleep(200000);
	

	//Running
	while(Judge(Map,snake,food,score)){
		sleep(); 

		vector<CSnake> store_snake=MoveSnake(snake);
		//Make snakes more sensitive instead of delayed（*）
		if(Control(snake,3)){						//if receive a input
			ReverseMoveSnake(snake,store_snake); 	//Restore the snake to its original state
			MoveSnake(snake); 						//use the new direction to move
		}
		//insert the snake into map
		ClearMap(Map);
		insertFood(Map,food);
		insertSnake(Map,snake);
		//if eat food,score++,delte the old_food,add new_food
		if(ifeatfood){
			food.insert(food.begin(),generate(snake,Map));
			ClearMap(Map);
			insertFood(Map,food);
			insertSnake(Map,snake);
			ifeatfood=false;
		}

		clear();
		//draw
		traverse(Map,score);		//Draw
	}

	//END
	usleep(2500000);
	getchar();
	clear();
	if(score.getscore()>20)
		cout<<"Congratulation!"<<"your score : "<<score.getscore()<<endl;
	else
		cout<<"Work hard, it will be better next time！"<<endl;
	cout<<"Good Bye~"<<endl;
	
}
