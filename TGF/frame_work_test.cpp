#include <iostream>
#include "TGF_lib.h"
/**
 *  test script for terminal-game-famework(TGF)
 *  Compile:g++-9 frame_work_test.cpp -o test -std=c++11
 */

using namespace std;

int main()
{

    //Demo:Snake
    int len = 20;

    //Init
    setwindow(28, 95); //set window's size
    clear_term();      //clean the terminal

    /*create a player*/
    Player_Unit unit(10, 12); //Create One Player's Unit（Player_Unit <-- TGF_Member）
    Player players(unit);     //Assemble the Player's Body(Player <-- TGF_MemberList)
    //or TGF_UserList<TGF_User> userlist(unit);
    players.GeneralModel(Line);

    /*create a map*/
    Snake_Map<Player_Unit> snake_map(len); //Create a Map (Snake_Map <-- TGF_Map)
    snake_map.insert(players, 'X');        //Insert your Player into Map

    /*init keyboard*/
    Keyboard k;

    /*init Metronome*/
    TGF_Metrononme &metro = TGF_Metrononme::getInstance();
    metro.setinterval(20);

    while (1)
    {
        /*
        if(k.recv() == UP)
            cout<< "UP";
        if(k.recv() == RIGHT)
            cout<< "RIGHT";
        if(k.recv() == LEFT)
            cout<< "LEFT";
        if(k.recv() == DOWN)
            cout<< "DOWN";
            */
        if (metro.pat()) //control the action frame
        {
            players.MoveModel(Linear);
            snake_map.insert(players, 'X');
            metro.quicker();
        }

        players.MoveModel(ROTATE);
        snake_map.insert(players, 'X');

        clear_term();
        cout << snake_map; //Debug
    }
}