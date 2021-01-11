#ifndef __CMAP__
#define __CMAP__
#define  scope  500
#include"CSnake.h"
#include"CScore.h"

class CMap{
public:
	CMap(int length=20):len(length),wid(length){} 
	int length() const {return len;}
	int width() const {return wid;}
	char bitmap[scope][scope]; 
private:
	int len,wid;	
	friend CSnake randnum(const CMap&);
	friend CSnake generate(vector<CSnake> &snake,CMap &map); 		//generate food
};


#include<ctime>
#include<cstdlib>
using namespace std;
inline CSnake randnum(const CMap &map){
	//use time as seed
	srand((unsigned)time(NULL));
	int len=0,wid=0;
	while(len==0||len==map.len-1||wid==0||wid==map.wid-1){
		len=rand()%map.len;
		wid=rand()%map.wid;
	}
	return CSnake(len,wid);
}

inline CSnake generate(vector<CSnake> &snake,CMap &map){
	bool isempty=false;
	CSnake food;
	/*
	while(!isempty){
		isempty=true;
		food=randnum(map);
		for(vector<CSnake>::iterator iter=snake.begin();iter !=snake.end();iter++){
			if(food.xaxi()==(*iter).xaxi()||food.yaxi()==(*iter).yaxi()){
				isempty=false;
			}
		}
	}
	*/
	srand((unsigned)time(NULL)/2);
	int len=0,wid=0;
	while(len==0||len==map.len-1||wid==0||wid==map.wid-1){
		len=rand()%map.len;
		wid=rand()%map.wid;
	}
	return CSnake(len,wid);
}

inline void InitMap(CMap& map){
	cout<< "[+] Game Map Building ..."<<endl;
	for(int i=0;i<map.length();i++){
		for (int j=0;j<map.width();j++){
			if(i==0||i==map.length()-1) map.bitmap[i][j]='E';
			else if(j==0||j==map.width()-1) map.bitmap[i][j]='E';
			else map.bitmap[i][j]=' ';
		}
	}
}
inline void ClearMap(CMap& map){
	for(int i=0;i<map.length();i++){
		for (int j=0;j<map.width();j++){
			if(i==0||i==map.length()-1) map.bitmap[i][j]='E';
			else if(j==0||j==map.width()-1) map.bitmap[i][j]='E';
			else map.bitmap[i][j]=' ';
		}
	}
}

inline  void traverse(const CMap& map,const CScore &score){
	cout<<"\t\t   CSNAKE"<<endl;
	for(int i=0;i<map.length();i++){
		for (int j=0;j<map.width();j++){
			if(map.bitmap[i][j]) cout<< map.bitmap[i][j]<<" ";
			else cout << " ";
			if(i==3&&j==map.width()-1)
				cout<<"		Your Score : "<<score.getscore();
			if(i==5&&j==map.width()-1)
				cout<<"	Usage : UP DOWN LEFT RIGHT to control";
		}
		cout<<endl;
	}
}
#include<vector>
/*Insert Snake into bitMap according to vector snake*/
inline void insertSnake(CMap& map,vector<CSnake> &snake){
	//int i=1;					//Attention:Element 0 is for Direction not the site
	int i=0;
	while(i<snake.size()){
		if(snake[i].xaxi()>=0&&snake[i].yaxi()>=0) 
			map.bitmap[snake[i].xaxi()][snake[i].yaxi()]='X';
		i++;
	}
}
/*Insert Snake into bitMap according to vector snake*/
inline void insertFood(CMap& map,vector<CSnake> &food){
	//int i=1;					//Attention:Element 0 is for Direction not the site
	int i=0;
	map.bitmap[food[i].xaxi()][food[i].yaxi()]='O';
}
/*check if the snake hint it self*/
inline bool hintcheck(vector<CSnake> &snake){
	for(vector<CSnake>::iterator iter=snake.begin()+1;iter!=snake.end();iter++){
		if(snake[0].xaxi()==(*iter).xaxi()&&snake[0].yaxi()==(*iter).yaxi())
			return true;
	}
	return false;
}

/*Judge the Game*/
bool ifeatfood=false;
inline bool Judge(CMap& map,vector<CSnake> &snake,vector<CSnake> &food,CScore &score){
	//int i=1;					//Attention:Element 0 is for Direction not the site
	int i=0;
	if(snake[i].xaxi()==0||snake[i].xaxi()==map.width()-1||snake[i].yaxi()==0||snake[i].yaxi()==map.length()-1){
		return false;
	}
	if(snake[0]==food[0]){
		score.changscore(score.getscore()+10);
		Addsnake(snake);
		ifeatfood=true;
	}
	
	if(hintcheck(snake)){
		//cout<<"hint your self"<<endl;
		return false;
	}
	
	return true;
}

#endif
