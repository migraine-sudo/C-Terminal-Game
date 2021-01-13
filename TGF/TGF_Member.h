#ifndef __TGF_MEMBER__
#define __TGF_MEMBER__
#include "keyboard_support.h"
/**
 *  User include administrator and Player
 *  Design Patterns : Composite
*/



class TGF_Member
{
public:
	TGF_Member(int x = 0, int y = 0) : xa(x), ya(y) {}
	int xaxi() const { return xa; }
	int yaxi() const { return ya; }
	void chagxa(int nx){xa=nx;}
	void chagya(int ny){ya=ny;}

private:
	int xa, ya;
};

class Player_Unit : public TGF_Member
{
public:
	Player_Unit(int x, int y) : TGF_Member(x, y) {}
};


#endif