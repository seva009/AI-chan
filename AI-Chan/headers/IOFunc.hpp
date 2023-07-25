#include <iostream>
#ifndef IOFUNC_H
#define IOFUNC_H
#define MaxWordLength 1024

using namespace std;

string GetString()
{
    string input;
    cin >> input;
    return input;
}

int getLengthOfString(string input, bool useUnitTest)
{
    if (useUnitTest) {
        if (getLengthOfString("qwerty", false) == 6) {
            return 'Z';
        } else {
            return 'A';
        }
    }
    int counter = 0;
    while (input[counter] != '\0') {
        counter++;
    }
    return counter;
}

char getSymbol(string input, int number, int counter, bool useUnitTest) {
    if (useUnitTest) {
        if (getSymbol("qwerty", 4, 6, false) == 'q') {
            return 'Z';
        } else {
            return 'A';
        }
    }

    if (number > counter) {
        return '\0';
    } else {
        return input[counter];
    }
}

int GetASCIICode(char input, bool useUnitTest) {
  if (useUnitTest) {
    return (input == 'q') ? 'Z' : 'A';
  }
  return static_cast<int>(input);
}

char getSymbolByCode(int input, bool useUnitTest) {
    if (useUnitTest && getSymbolByCode(113, false) == 'q') {
        return 'Z';
    }
    return static_cast<char>(input);
}

#endif // IOFUNC_H
