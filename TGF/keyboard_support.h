#ifndef __KEYBOARD_SUPPORT__
#define __KEYBOARD_SUPPORT__
#include "cross_platform_support.h"

enum keys
{
    UP = 0,
    DOWN,
    LEFT,
    RIGHT,
    OP1,
    OP2,
    OP3,
    OP4,
    OP5,
    OP6,
    NONE
};
//Link:https://www.runoob.com/w3cnote/c-get-keycode.html
enum KeyCode
{
    A=65,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
    a=97,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
};

class Keyboard
{
public:
    Keyboard() {}
    keys recv();
    char getbit(){return bit;}
private:
    virtual keys deal_keys();    //you can override this function to react to keyboard
    char bit;
};
inline keys Keyboard::deal_keys() /*needed to be overrided*/
{
    switch(Keyboard::bit){
			case 'A':case w:return UP;break;//UP
			case 'B':case s:return DOWN;break;//DOWN
			case 'D':case a:return LEFT;break;//LEFT
			case 'C':case d:return RIGHT;break;//RIGHT
			default:return NONE;break;
			}
}
inline keys Keyboard::recv()
{
    int i=1,time=3;
    system("stty -icanon");
	while(i<time){
		if(_kbhit()){
		Keyboard::bit = getwchar();
        keys check = deal_keys();
		if(check!=NONE) 
            return check;
        Keyboard::bit = ' ';
		}
	    i++;
    }
    return NONE;
}

#endif