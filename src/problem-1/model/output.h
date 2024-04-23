#ifndef __OUTPUT__
#define __OUTPUT__

#include <nowide/iostream.hpp>
#include <iostream>
#include <windows.h>
class Console
{
private:
    int BRIGHT_WHITE = 15;

public:
    void printWithColor(std::string text, int color);
};

#endif // __OUTPUT__
