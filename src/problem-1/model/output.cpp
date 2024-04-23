#include "output.h"

void Console::printWithColor(std::string text, int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    nowide::cout << text << std::endl;
    SetConsoleTextAttribute(hConsole, BRIGHT_WHITE);
}