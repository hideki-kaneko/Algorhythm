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
        break;
    case 2:
        main2();
        break;
    case 3:
        main3();
        break;
    case 4:
        main4();
        break;
    case 5:
        main5();
        break;
    case 6:
        main6();
        break;
    case 7:
        main7();
        break;
    case 8:
        main8();
        break;
    case 9:
        main9();
        break;
    default:
        break;
    }

    system("PAUSE");
    return 0;
}