#ifndef __CSANKE__
#define __CSANKE__
#include <vector>
using namespace std;

typedef int direct;

constexpr direct UP = 0;
constexpr direct DOWN = 1;
constexpr direct LEFT = 2;
constexpr direct RIGHT = 3;

class CSnake{
public:
	CSnake(int x=0,int y=0):xa(x),ya(y){}
	CSnake(int dir):direction(dir){}
	CSnake& operator = (const CSnake&);
	int xaxi() const{return xa;}
	int yaxi() const{return ya;}
	int getdir() const{return direction;}
	void chadir(int dir) {direction=dir;}
private:
	int xa,ya;
	int direction=LEFT;
}; 

inline CSnake& CSnake::operator = (const CSnake& r){
	this->xa=r.xa;
	this->ya=r.ya;
	return *this;
}

/*Make the snake longer,according the head of snake*/
inline void Drawsnake(vector<CSnake> &snake,const int len){
	int i=1;
	while(i<=len){ 
		CSnake tsnake(snake[1].xaxi(),snake[1].yaxi()+i);
		snake.insert(snake.end(),tsnake);
		i++;
	}
}

inline vector<CSnake> MoveSnake(vector<CSnake> &snake){
	vector<CSnake> store_snake;
	store_snake.assign(snake.begin(),snake.end());
	int direct=snake[0].getdir();
	if(direct==UP){
		CSnake tsnake(snake[1].xaxi()-1,snake[1].yaxi());
		snake.insert(snake.begin()+1,tsnake);
	}
	else if(direct==DOWN){
		CSnake tsnake(snake[1].xaxi()+1,snake[1].yaxi());
		snake.insert(snake.begin()+1,tsnake);
	}
	else if(direct==LEFT){
		CSnake tsnake(snake[1].xaxi(),snake[1].yaxi()-1);
		snake.insert(snake.begin()+1,tsnake);
	}
	else if(direct==RIGHT){
		CSnake tsnake(snake[1].xaxi(),snake[1].yaxi()+1); 
		snake.insert(snake.begin()+1,tsnake);
	}
	else{
		abort();
	}
	snake.erase(snake.end());
	return store_snake;
}

inline void ReverseMoveSnake(vector<CSnake> &snake,vector<CSnake> store_snake){
	snake.assign(store_snake.begin(),store_snake.end());
}

#ifdef _WIN32
#include <conio.h>
inline void Control(vector<CSnake> &snake){
	if(_kbhit()){
		char keyboard=_getche();
		switch(keyboard){
			case 72:snake[0].chadir(0);break;//UP
			case 80:snake[0].chadir(1);break;//DOWN
			case 75:snake[0].chadir(2);break;//LEFT
			case 77:snake[0].chadir(3);break;//RIGHT
			default:break;
		}
	}
}
#elif __linux__
inline void Control(vector<CSnake> &snake){}
#elif __APPLE__
#include <termios.h>
#include <sys/ioctl.h>
inline int _kbhit() //link：https://blog.csdn.net/wainiwann/article/details/38977991
 {
        static const int STDIN = 0;
        static bool initialized = false; if (! initialized)
        {
            // Use termios to turn off line buffering
            termios term;
            tcgetattr(STDIN, &term);
            term.c_lflag &= ~ICANON;
            tcsetattr(STDIN, TCSANOW, &term);
            setbuf(stdin, NULL);
            initialized = true;
        } int bytesWaiting;
        ioctl(STDIN, FIONREAD, &bytesWaiting);
        return bytesWaiting;
  }

inline bool Control(vector<CSnake> &snake,int time){
	char keyboard;
	int i=0;bool ifchange=false;
	system("stty -icanon");
	while(i<time){
		if(_kbhit()){
		keyboard=getchar();
		//cout<<"keyboard="<<keyboard<<endl;
		switch(keyboard){
			case 'A':snake[0].chadir(0);ifchange=true;break;//UP
			case 'B':snake[0].chadir(1);ifchange=true;break;//DOWN
			case 'D':snake[0].chadir(2);ifchange=true;break;//LEFT
			case 'C':snake[0].chadir(3);ifchange=true;break;//RIGHT
			default:break;
			}
		}
	i++;
	}
	return ifchange;
}

#endif

#include<iostream>

ostream&
operator << (ostream& os,const CSnake snake){
	return os<< '(' << snake.xaxi() << ',' << snake.yaxi() << ')'; 
}
#endif
