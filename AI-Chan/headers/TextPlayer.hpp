#ifndef TEXTPLAYER_H
#define TEXTPLAYER_H
#include <cstdlib>
#include <iostream>
#include <thread>

using namespace std;

void play_sound(const char *filename)
{
    string command = "play -q ";
    command += filename;
    system(command.c_str());
}

void SoundStart(string text)
{
    FILE *fptr;
    fptr = fopen("output.wav", "wb");
    if (fptr == NULL) {
        cout << "Error opening file!" << endl;
    }
    string command = "espeak -w output.wav \"" + text + "\"";
    system(command.c_str());
    fclose(fptr);
    thread t(&play_sound, "output.wav");
    t.join();
    system("rm output.wav");
}

#endif // TEXTPLAYER_H
