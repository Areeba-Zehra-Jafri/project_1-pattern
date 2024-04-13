#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "functions.h"

int main()
{
    customizable_screen();
}

void customizable_screen(void)
{
    char move, c, ch;
    int count = 0, choice, rows;
    std::cout << "Enter D to move forward and A to move backward S to select and W to go back " << std::endl;
    std::cin >> move;
    while (1)
    {
        if (move == 'A' && count > 0)
        {
            count = (count - 1) % 4;
        }
        if (move == 'D')
        {
            count = (count + 1) % 4;
        }
        if (move == 'S')
        {
            break;
        }
        if (move == 'W')
        {
            exit(0);
        } //{start_screen();}
        switch (count)
        {
        case 0:
            std::cout << "pyramid: " << count << std::endl;
            pyramid(5, 'c', '*');
            break;
        case 1:
            std::cout << "rectangle: " << count << std::endl;
            rectangle(5, 'c', '*');
            break;
        case 2:
            std::cout << "diamond: " << count << std::endl;
            diamond(5, 'c', '*');
            break;
        case 3:
            std::cout << "hourglass: " << count << std::endl;
            hourglass(5, 'c', '*');
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
        }
        std::cin >> move;
    }
    std::cout << "Enter the number of pattern you wanted:" << std::endl;
    std::cin >> choice;
    std::cout << "Enter the number of rows you want in the output:" << std::endl;
    std::cin >> rows;
    std::cout << "If you want the pyramid to be of single character (press C/c) \n if you want it to be an increasing series (press S/s)" << std::endl;
    std::cin >> c;
    if (c == 'S' || c == 's')
    {
        std::cout << "Do you want the numbers (press N/n) or alphabets (press A/a) in increasing order:" << std::endl;
        std::cin >> ch;
    }
    else if (c == 'C' || c == 'c')
    {
        std::cout << "Enter the character you want: " << std::endl;
        std::cin >> ch;
    }
    switch (choice)
    {
    case 0:
        std::cout << "pyramid: " << count << std::endl;
        pyramid(rows, c, ch);
        break;
    case 1:
        std::cout << "rectangle: " << count << std::endl;
        rectangle(rows, c, ch);
        break;
    case 2:
        std::cout << "diamond: " << count << std::endl;
        diamond(rows, c, ch);
        break;
    case 3:
        std::cout << "hourglass: " << count << std::endl;
        hourglass(rows, c, ch);
        break;
    default:
        std::cout << "Invalid input" << std::endl;
        break;
    }
    customizable_screen();
}
void pyramid(int r, char c, char ch)
{
    if (isValidInput(c, ch))
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }
    int count = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r - 1 - i; j++)
        {
            std::cout << "  ";
        }
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            if (c == 'C' || c == 'c')
            {
                std::cout << ch << " ";
            }
            else if (c == 'S' || c == 's')
            {
                printChar(count, ch);
            }
            count++;
        }
        std::cout << std::endl;
    }
}
void rectangle(int r, char c, char ch)
{
    if (isValidInput(c, ch))
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }
    int count = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (c == 'C' || c == 'c')
            {
                std::cout << ch << " ";
            }
            else if (c == 'S' || c == 's')
            {
                printChar(count, ch);
            }
            count++;
        }
        std::cout << std::endl;
    }
}
void diamond(int r, char c, char ch)
{
    if (isValidInput(c, ch))
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }
    int count = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r - i - 1; j++)
        {
            std::cout << "  ";
        }
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            if (c == 'C' || c == 'c')
            {
                std::cout << ch << " ";
            }
            else if (c == 'S' || c == 's')
            {
                printChar(count, ch);
            }
            count++;
        }
        std::cout << std::endl;
    }
    r = r - 1;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << "  ";
        }
        for (int j = 0; j < (2 * r) - (2 * i) + 1; j++)
        {
            if (c == 'C' || c == 'c')
            {
                std::cout << ch << " ";
            }
            else if (c == 'S' || c == 's')
            {
                printChar(count, ch);
            }
            count++;
        }
        std::cout << std::endl;
    }
}
void hourglass(int r, char c, char ch)
{
    if (isValidInput(c, ch))
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }
    int count = 1;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << "  ";
        }
        for (int j = 0; j < (2 * r) - (2 * i) + 1; j++)
        {
            if (c == 'C' || c == 'c')
            {
                std::cout << ch << " ";
            }
            else if (c == 'S' || c == 's')
            {
                printChar(count, ch);
            }
            count++;
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r - i; j++)
        {
            std::cout << "  ";
        }
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            if (c == 'C' || c == 'c')
            {
                std::cout << ch << " ";
            }
            else if (c == 'S' || c == 's')
            {
                printChar(count, ch);
            }
            count++;
        }
        std::cout << std::endl;
    }
}

bool isValidInput(char c, char ch)
{
    return (c != 'C' && c != 'c' && c != 'S' && c != 's' && ch != 'N' && ch != 'n' && ch != 'A' && ch != 'a');
}

void printChar(int count, char ch)
{
    if (ch == 'A' || ch == 'a')
    {
        std::cout << char('A' + (count - 1) % 26) << " ";
    }
    else if (ch == 'n' || ch == 'N')
    {
        std::cout << count << " ";
    }
}
