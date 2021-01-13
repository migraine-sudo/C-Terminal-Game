#ifndef __TGF_MEMBER_LIST__
#define __TGF_MEMBER_LIST__

#include <vector>
#include "TGF_Member.h"

enum MMODEL{ //Move Mod
	Linear , FALL , OTHER
};
enum GMODEL{ //Generate Mod
	Line
};

class TGF_MemberList
{
public:
    TGF_MemberList() {}
};

class Player : public TGF_MemberList
{
public:
    Player(Player_Unit &user) : TGF_MemberList() { Player_List.insert(Player_List.begin(), user); }
    vector<Player_Unit> getPlayer() const { return Player_List; }
    keys getdirct()const {return dirction;}
	virtual void MoveModel(MMODEL mod);
	virtual void MoveModel_Expand(){};				//override this to add your own movemodel
	virtual void GeneralMode(GMODEL mod); 
    void Move_Linear();
    void Move_Fall();
    void General_Line();
private:
    vector<Player_Unit> Player_List;
	keys dirction = LEFT;
};
/*
class Admin : public TGF_Member
{
private:
    vector<vector<Player_Unit>> Admin_list;
};
*/

/*Generate Mode : Line*/
inline void Player::GeneralMode(GMODEL mod)
{
    if(mod == Line)General_Line();
}

inline void Player::General_Line()
{
    //vector<Player_Unit>::iterator iter=Player_List.begin();
    //int x=(*iter).xaxi();
    //int y=(*iter).yaxi();
    int x=Player_List[0].xaxi();
    int y=Player_List[0].yaxi();
    Player_List.clear();
    Player_List.insert(Player_List.begin(),Player_Unit(x,y));
    int i=1;
    while(i<=4)
    {
        //Player_List.insert(Player_List.end(),Player_Unit(x,y-i));
        Player_List.insert(Player_List.end(),Player_Unit(x,y+i));
        i++;
    }
}

/*Move Model : Linear FALL OTHER*/
inline void Player::MoveModel(MMODEL mod)
{
    sleep();
	if(mod==OTHER){
		MoveModel_Expand();
	}
	else{
		if(mod==Linear)Move_Linear();
        if(mod==FALL)Move_Fall();
	}
}
/*move like linear according to direction ,such as snakes*/
inline void Player::Move_Linear()
{
    clear_term();
    int x=Player_List[0].xaxi();
    int y=Player_List[0].yaxi();
    if(getdirct()==LEFT) y-=1;
    if(getdirct()==RIGHT) y+=1;
    if(getdirct()==UP) x-=1;
    if(getdirct()==DOWN) x+=1;
    //cout<<x <<" "<< y <<endl;
    Player_Unit unit=Player_Unit(x,y);
    Player_List.insert(Player_List.begin(),unit);
	Player_List.pop_back();
}
inline void Player::Move_Fall()
{
    clear_term();
    for(vector<Player_Unit>::iterator iter=Player_List.begin();iter!=Player_List.end();iter++)
    {
       (*iter).chagxa( (*iter).xaxi()+1);
    }
}

#endif