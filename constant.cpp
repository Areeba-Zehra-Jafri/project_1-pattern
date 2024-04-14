#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "functions.h"

int main()
{
    constants_screen();
}

void constants_screen(void)
{
    char c;
    int count = 0, choice, rows;
    std::cout << "Enter D to move forward and A to move backward S to select and W to go back " << std::endl;
    std::cin >> c;
    while (1)
    {
        if (c == 'A' && count > 0)
        {
            count = (count - 1) % 6;
        }
        if (c == 'D')
        {
            count = (count + 1) % 6;
        }
        if (c == 'S')
        {
            break;
        }
        if (c == 'W')
        {
            exit(0);
        } //{start_screen();}
        switch (count)
        {
        case 0:
            std::cout << "pascal's triangle: " << count << std::endl;
            pascal_triangle(5);
            break;
        case 1:
            std::cout << "Floyd's triangle: " << count << std::endl;
            floyd_triangle(5);
            break;
        case 2:
            std::cout << "number pyramid 1: " << count << std::endl;
            palindrome_pyramid(5);
            break;
        case 3:
            std::cout << "number pyramid 2: " << count << std::endl;
            number_pyramid(5);
            break;
        case 4:
            std::cout << "Alphabet's pattern: " << count << std::endl;
            alphabets_pattern(5);
            break;
        case 5:
            std::cout << "number square: " << count << std::endl;
            number_square(5);
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
        }
        std::cin >> c;
    }
    std::cout << "Enter the number of pattern you wanted:" << std::endl;
    std::cin >> choice;
    std::cout << "Enter the number of rows you want in the output:" << std::endl;
    std::cin >> rows;
    switch (choice)
    {
    case 0:
        std::cout << "pascal's triangle" << count << std::endl;
        pascal_triangle(rows);
        break;
    case 1:
        std::cout << "Floyd's triangle" << count << std::endl;
        floyd_triangle(rows);
        break;
    case 2:
        std::cout << "number pyramid 1" << count << std::endl;
        palindrome_pyramid(rows);
        break;
    case 3:
        std::cout << "number pyramid 2" << count << std::endl;
        number_pyramid(rows);
        break;
    case 4:
        std::cout << "Alphabet's pattern" << count << std::endl;
        alphabets_pattern(rows);
        break;
    case 5:
        std::cout << "number square" << count << std::endl;
        number_square(rows);
        break;
    default:
        std::cout << "Invalid input" << std::endl;
        break;
    }
    constants_screen();
}
void pascal_triangle(int r)
{
    int coef = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 1; j <= r - i; j++)
        {
            std::cout << std::setw(3) << "   ";
        }
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 || j == 0)
                coef = 1;
            else
                coef = coef * (i - j + 1) / j;
            std::cout << std::setw(3) << coef << "   ";
        }
        std::cout << std::endl;
    }
    std::cin.get();
}
void floyd_triangle(int r)
{
    int count = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cout << std::setw(3) << count << " ";
            count++;
        }
        std::cout << std::endl;
    }
    std::cin.get();
}
void palindrome_pyramid(int r)
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= 2 * (r - i); j++)
        {
            std::cout << std::setw(3) << "   ";
        }
        for (int j = i; j <= i + i - 1; j++)
        {
            std::cout << std::setw(3) << j << "   ";
        }
        for (int j = i + i - 2; j >= i; j--)
        {
            std::cout << std::setw(3) << j << "   ";
        }
        std::cout << std::endl;
    }
    std::cin.get();
}
void number_pyramid(int r)
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 0; j <= (r - i) * 2; j++)
        {
            std::cout << std::setw(3) << "   ";
        }
        for (int j = i; j >= 1; j--)
        {
            std::cout << std::setw(3) << j << "   ";
        }
        for (int j = 2; j <= i; j++)
        {
            std::cout << std::setw(3) << j << "   ";
        }
        std::cout << std::endl;
    }
    std::cin.get();
}
void number_square(int r)
{
    for (int i = 0; i < 2 * r - 1; i++)
    {
        // Step 2: Focus on the number of columns: 2*n - 1 columns
        for (int j = 0; j < 2 * r - 1; j++)
        {
            int top = i;
            int bottom = j;
            int right = (2 * r - 2) - j;
            int left = (2 * r - 2) - i;

            // Step 3: Printing the minimum distance of 4 directions after subtracting it from n
            std::cout << std::setw(3) << (r - std::min(std::min(top, bottom), std::min(left, right))) << "   "; // As min takes only 2 args at a time
        }
        std::cout << std::endl;
    }
    std::cin.get();
}
void alphabets_pattern(int r)
{
    for (int i = r; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            std::cout << std::setw(2) << char('A' + (j - 1) % 26); 
        }
        for (int j = 1; j <= 2 * (r - i); j++)
        {
            std::cout << std::setw(2) << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            std::cout << std::setw(2) << char('A' + (j - 1) % 26);
        }
        std::cout << std::endl;
    }
    std::cin.get();
}