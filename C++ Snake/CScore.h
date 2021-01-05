#ifndef __CSCORE__
#define __CSCORE__

class CScore{
public:
    CScore(int sc=0):score(sc){}
    int getscore()const{return score;}
    void changscore(int x){score=x;}
private:
    int score;
};

#endif