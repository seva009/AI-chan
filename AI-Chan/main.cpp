#include "headers/AI.hpp"
#include "headers/CalcFunc.hpp"
#include "headers/IOFunc.hpp"
#include "headers/TextPlayer.hpp"
//#include "headers/Vision.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string snt;
    for (int i = 0; i < argc; i++) {
        snt += argv[i];
    }
    SoundStart(snt);
}
