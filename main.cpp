﻿#include <cstdio>
#include <iostream>
#include <unistd.h>
using namespace std;
#include "timer.h"
#include <thread>
#include "Beobachter.h"


void funktion()
{
    for(int i=0;i<10;i++)
    {
        cout << "tack\n";
        sleep(1);
    }

}
class Tack : public Beobachter
{
public:
    virtual ~Tack(){}
    void aktualisiere(Subjekt* s);
};
void Tack::aktualisiere(Subjekt* s)
{
    cout << "tack\n";
}
class Tick : public Beobachter
{
public:
    virtual ~Tick(){}
    void aktualisiere(Subjekt* s);
};
void Tick::aktualisiere(Subjekt* s)
{
    cout << "tick\n";
}
int main()
{
    int a;
    Timer t1,t2(5);
    Tack tack;
    Tick tick;

    t1.anmelden(&tick);
    t2.anmelden(&tack);

    t1.start();
    t2.start();



    while(t1.getBusy() || t2.getBusy())
        sleep(1);
    cout << "t1 und t2 fertig\n";

    t1.setStopZeit(5);
    t1.start();
    while(t1.getBusy())
        sleep(1);
    cout << "t1 fertig\n";
    cin >> a;

//    int a;
//    cin >> a;
//    std::thread th(funktion);
//    cout << "Hauptthread\n";
//    while(th.joinable())
//    {
//        cout << "tick\n";
//        sleep(1);
//    }
//    cout << "fertig\n";

    return 0;
}
