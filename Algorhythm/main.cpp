#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include "main.h"

int main()
{
    const int mode = 1;

    switch (mode)
    {
    case 1:
        main1();
    case 2:
        main2();
    case 3:
        main3();
    case 4:
        main4();
    case 5:
        main5();
    case 6:
        main6();
    case 7:
        main7();
    case 8:
        main8();
    case 9:
        main9();
    default:
        break;
    }

    system("PAUSE");
    return 0;
}