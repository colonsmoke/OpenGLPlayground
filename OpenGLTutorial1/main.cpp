#include <iostream>

#include "display.h"

int main(int argc, char** argv)
{
    Display display(800,600, "Hello World");

    while (!display.IsClosed())
        display.Update();

    return 0;
}