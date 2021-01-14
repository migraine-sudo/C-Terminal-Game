#ifndef __TGF_MAP__
#define __TGF_MAP__
/**
 * You can Inherit this class with your own Map Class or just use it. 
 *      such as class Snake_Map:public TGF_Map{...};
 * To Use this Class,you neend to declaration your class, 
 *      such as Snake_Map<T> map(20,20); 
 * Meanwhile,before using this class,you need to use vector<T=your member typename>,to store you Array。
 * Warning: your class need to contain xaxi() and yaxi() to return x and y.
 *      for example , vector<Snake> snake;(Snake is another class)
 *  and if you want to insert vector<Snake> into your map,use
 *      TGF_MAP::insert(snake,'X');
*/
#include <vector>
#include "TGF_MemberList.h"

template <class T>
class TGF_Map
{
public:
    TGF_Map(int len = 20, int wid = 20) : map_len(len), map_wid(wid)
    {
        bitmap = new char *[map_len];
        for (int i = 0; i < map_len; i++)
        {
            bitmap[i] = new char[map_wid];
        }
    };
    ~TGF_Map()
    {
        for (int i = 0; i < map_len; i++)
        {
            delete[] bitmap[i];
            bitmap[i] = NULL;
        }
        delete[] bitmap;
    }
    TGF_Map<T> &operator=(TGF_Map<T> &);
    int length() const { return map_len; }
    int width() const { return map_wid; }
    //Create a iterator？
    //...//
    /*control bitmap*/
    char **getbitmap() { return bitmap; }
    //virtual void insert(TGF_UserList<T> &member, char bit){};
    virtual void insert(Player &member, char bit);
    virtual void clearmap();

protected:
    char **bitmap; //store the bits of map

private:
    int map_len, map_wid;
};
template <class T>
inline void TGF_Map<T>::insert(Player &member, char bit)
{
    clearmap();
    vector<T> body = member.getPlayer();
    int i = 0;
    while (i < body.size())
    {
        if (body[i].xaxi() >= 0 && body[i].yaxi() >= 0)
            TGF_Map<T>::bitmap[body[i].xaxi()][body[i].yaxi()] = bit;
        i++;
    }
}
template <class T>
inline void TGF_Map<T>::clearmap()
{
    for (int i = 0; i < TGF_Map<T>::length(); i++)
        for (int j = 0; j < TGF_Map<T>::width(); j++)
            if (i == TGF_Map<T>::length() - 1 || j == TGF_Map<T>::length() - 1 || i == 0 || j == 0)
                TGF_Map<T>::bitmap[i][j] = 'E';
            else
                TGF_Map<T>::bitmap[i][j] = ' ';
}

/*Example of interitance Class*/
template <class T>
class Snake_Map : public TGF_Map<T>
{
public:
    Snake_Map(int len = 20) : TGF_Map<T>(len, len) { TGF_Map<T>::clearmap(); }
};

//FOR DEBUG
#include <iostream>
template <class T>
ostream &operator<<(ostream &os, TGF_Map<T> &map)
{
    for (int i = 0; i < map.length(); i++)
    {
        for (int j = 0; j < map.width(); j++)
        {
            os << map.getbitmap()[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

#endif