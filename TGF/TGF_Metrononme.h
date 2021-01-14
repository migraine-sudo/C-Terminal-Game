#ifndef __TGF_METRONONME__
#define __TGF_METRONONME__

/**
 * Block or slow control action frame.
 * Makes the operation of the program smoother, 
 * and can receive keyboard data input more stably
 * Pattern Design :Singleton 
*/

class TGF_Metrononme
{
public:
    static TGF_Metrononme &getInstance() { return Metro; }
    void set_Metrononme(unsigned int M) { Metrononme = M; }
    unsigned int get_Metronome() const { return Metrononme; }
    void setinterval(int inter) { interval = inter; }
    void quicker();
    void slower();
    bool pat(); /* this action must be use! to remind pg with pat after a constant time*/

private:
    static unsigned int Metrononme;
    int interval = 20;
    TGF_Metrononme() {}
    static TGF_Metrononme Metro;
};
TGF_Metrononme TGF_Metrononme::Metro; //static must be defined!
unsigned int TGF_Metrononme::Metrononme = 1;

inline bool TGF_Metrononme::pat()
{
    Metrononme++;
    if (Metrononme % interval == 1)
        return true;
    if (Metrononme >= 65530)
        Metrononme = 1;
    return false;
}
inline void TGF_Metrononme::slower()
{
    if (interval < 500)
        interval *= 2;
    else
        interval += 200;
}
inline void TGF_Metrononme::quicker()
{
    if (interval > 500)
        interval /= 2;
    else
    {
        if (interval > 40)
            interval -= 40;
        else
        {
            if (interval > 20)
                interval -= 20;
                else{
                    if(interval >5)
                        interval-=5;
                }
        }
    }
}

#endif