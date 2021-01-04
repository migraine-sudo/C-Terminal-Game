#ifndef __CMAP__
#define __CMAP__
#define  scope  500
#include"CSnake.h"



class CMap{
public:
	CMap(int length=20):len(length),wid(length){} 
	int length() const {return len;}
	int width() const {return wid;}
	char bitmap[scope][scope]; 
private:
	int len,wid;	
	friend CSnake randnum(const CMap&);
};

#include<ctime>
#include<cstdlib>
using namespace std;
inline CSnake randnum(const CMap &map){
	//use time as seed
	srand(time(NULL));
	int len=0,wid=0;
	while(len==0||len==map.len||wid==0||wid==map.wid){
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

inline  void traverse(const CMap& map){
	for(int i=0;i<map.length();i++){
		for (int j=0;j<map.width();j++){
			if(map.bitmap[i][j]) cout<< map.bitmap[i][j]<<" ";
			else cout << " ";
		}
		cout<<endl;
	}
}
#include<vector>
/*Insert Snake into bitMap according to vector snake*/
inline void insertSnake(CMap& map,vector<CSnake> &snake){
	int i=1;//Element 0 is for Direction not the site
	while(i<snake.size()){
		if(snake[i].xaxi()>=0&&snake[i].yaxi()>=0) 
			map.bitmap[snake[i].xaxi()][snake[i].yaxi()]='X';
		i++;
	}
}
/*Judge the Game*/
inline bool Judge(CMap& map,vector<CSnake> &snake){
	int i=1;//Element 0 is for Direction not the site
	if(snake[i].xaxi()==0||snake[i].xaxi()==map.width()||snake[i].yaxi()==0||snake[i].yaxi()==map.length()){
		return false;
	}
	return true;
}

#endif
