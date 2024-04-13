#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include "functions.h"

int main()
{
    surprise_screen();
}

void surprise_screen(void)
{
    char c;
    int choice, rows;
    while (1)
    {
        std::cout << "Enter S to select and W to go back " << std::endl;
        std::cin >> c;
        if (c == 'S')
        {
            std::cout << "Selecting a random pattern........" << std::endl;
            choice = rand() % 4;
            Sleep(2000);
            std::cout << "Selecting random numbe of lines........" << std::endl;
            rows = rand() % 26 + 5;
            Sleep(2000);
            switch (choice)
            {
            case 0:
                std::cout << "butterfly" << std::endl;
                butterfly(rows);
                break;
            case 1:
                std::cout << "christmas_tree" << std::endl;
                christmas_tree(rows);
                break;
            case 2:
                std::cout << "heart" << std::endl;
                heart(rows);
                break;
            case 3:
                std::cout << "mountain_range" << std::endl;
                mountain_range(rows);
                break;
            default:
                std::cout << "Invalid input" << std::endl;

                break;
            }
        }
        if (c == 'W')
        {
            exit(0);
        } //{start_screen();}
        std::cout << "Press any character key to continue:";
        std::cin >> c;
    }
}
void butterfly(int r)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cout << "* ";
        }
        for (int j = 0; j < r - i - 1; j++)
        {
            std::cout << "  ";
        }
        for (int j = 0; j < 2 + (r / 5); j++)
        {
            if (i >= r / 2)
            {
                std::cout << "|";
            }
            else
            {
                std::cout << " ";
            }
        }
        for (int j = 0; j < r - 1 - i; j++)
        {
            std::cout << "  ";
        }
        for (int j = 0; j <= i; j++)
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r - i - 1; j++)
        {
            std::cout << "* ";
        }
        for (int j = 0; j <= i; j++)
        {
            std::cout << "  ";
        }
        for (int j = 0; j < 2 + (r / 5); j++)
        {
            if (i < r / 2)
            {
                std::cout << "|";
            }
            else
            {
                std::cout << " ";
            }
        }
        for (int j = 0; j <= i; j++)
        {
            std::cout << "  ";
        }
        for (int j = 0; j < r - i - 1; j++)
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}
void christmas_tree(int r)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r - i - 1; j++)
        {
            std::cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r - (r / 5); j++)
        {
            std::cout << " ";
        }
        for (int j = 0; j < r / 5 + 2; j++)
        {
            std::cout << "|";
        }
        std::cout << std::endl;
    }
}
void heart(int r)
{
    for (int i = r / 2; i <= r; i += 2)
    {
        for (int j = 1; j < r - i; j += 2)
        {
            std::cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        for (int j = 1; j <= r - i; j++)
        {
            std::cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for (int i = r; i >= 1; i--)
    {
        for (int j = i; j < r; j++)
        {
            std::cout << " ";
        }
        for (int j = 1; j <= (i * 2) - 1; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
void mountain_range(int r)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r - i - 1; j++)
        {
            std::cout << "  ";
        }
        for (int j = 1; j <= (2 * i) - 1; j++)
        {
            std::cout << "* ";
        }
        for (int j = 1; j < r - i - 1; j++)
        {
            std::cout << "  ";
        }
        for (int j = 1; j < r - 1 - i; j++)
        {
            std::cout << "  ";
        }
        if (i > r - 2)
        {
            continue;
        }
        for (int j = 1; j <= (2 * i) - 1; j++)
        {
            std::cout << "* ";
        }

        std::cout << std::endl;
    }
}