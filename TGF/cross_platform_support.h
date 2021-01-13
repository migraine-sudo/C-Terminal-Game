#ifndef __CROSS_PLATFORM_SUPPORT__
#define __CROSS_PLATFORM_SUPPORT__

/**
 *  Provide support for cross-platform
 *  Platform Support: WIN32 Linux MACOS
*/

#include <iostream>
using namespace std;

//kbhit Support
#ifdef _WIN32
#include <conio.h>
#elif __linux__
inline int _kbhit()
{
}
#elif __APPLE__
#include <termios.h>
#include <sys/ioctl.h>
inline int _kbhit() //link：https://blog.csdn.net/wainiwann/article/details/38977991
{
    static const int STDIN = 0;
    static bool initialized = false;
    if (!initialized)
    {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }
    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}
#endif

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define clear_term() system("cls")
#define sleep() Sleep(5 * 100);
#elif __linux__
#include <unistd.h>
#define clear_term() system("clear")
#define sleep() usleep(100000)
//#define setwindow() system("resize -s 28 95")
#include <unistd.h>
#include<sstream>
#include <string>
#define clear_term() system("clear")
#define sleep() usleep(100000)
void setwindow(int x, int y)
{
    stringstream sstream;
    string wid,high;
    sstream << x;
    sstream >> high;
    sstream.clear();
    sstream << y;
    sstream >> wid;
    string resize("resize -s ");
    string cmd = resize + high +" "+ wid;
    system(cmd.c_str());
}
#elif __APPLE__
#include <unistd.h>
#include<sstream>
#include <string>
#define clear_term() system("clear")
#define sleep() usleep(100000)
void setwindow(int x, int y)
{
    stringstream sstream;
    string wid,high;
    sstream << x;
    sstream >> high;
    sstream.clear();
    sstream << y;
    sstream >> wid;
    string resize("resize -s ");
    string cmd = resize + high +" "+ wid;
    system(cmd.c_str());
}

#endif

#endif