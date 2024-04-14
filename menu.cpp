#include<iostream>
#include<cstdlib>
#include<fstream>
#include<windows.h>
#include "functions.h"


void welcome_screen(void)
{
    system("cls");
    char login;
    std::cout<<"Pattern Project:"<<std::endl;
    std::cout<<"Enter S/s to start and E/e to exit"<<std::endl;
    std::cin>>login;
    if(login=='S'||login=='s')
    {
        system("cls");
        password_screen();
    }
    else if(login=='E'||login=='e')
    {
        std::exit(0);
    }
    else
    {
        std::cout<<"Invalid input"<<std::endl;
        welcome_screen();
    }
    std::cin.get();
}

void main_screen(void)
{
    system("cls");
    int choice;
    while(1)
    {
        std::cout<<"1-start"<<std::endl;
        std::cout<<"2-Instructions"<<std::endl;
        std::cout<<"3-exit"<<std::endl;
        std::cout<<"4-Change login id"<<std::endl;
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            std::cout<<"start"<<std::endl;
            start_screen();
            break;
        case 2:
            std::cout<<"instructions"<<std::endl;
            instructions();
            break;
        case 3:
            std::exit(0);
            break;
        case 4:
            password_screen();
            break;
        default:
            std::cout<<"Invalid input"<<std::endl;
            break;
        }
    }
    std::cin.get();
}

void start_screen(void)
{
    system("cls");
    int choice;
    while(1)
    {
        std::cout<<"1-Customizable Patterns"<<std::endl;
        std::cout<<"2-Constant patterns"<<std::endl;
        std::cout<<"3-Surprise Patterns"<<std::endl;
        std::cout<<"4-Go back to main"<<std::endl;
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            std::cout<<"Customizable Patterns"<<std::endl;
            customizable_screen();
            break;
        case 2:
            std::cout<<"Constant patterns"<<std::endl;
            constants_screen();
            break;
        case 3:
            std::cout<<"Surprise Patterns"<<std::endl;
            surprise_screen();
            break;
        case 4:
            main_screen();
            break;
        default:
            std::cout<<"Invalid input"<<std::endl;
            break;
        }
    }
    std::cin.get();
}

void instructions(void)
{
    system("cls");
    std::string line;
    std::ifstream in;
    in.open("instructions.txt");
    while(in.eof()==0)
    {
        getline(in,line);
        std::cout<<line<<std::endl;
    }
    in.close();
    std::cin.get();
    std::cin.get();
}


