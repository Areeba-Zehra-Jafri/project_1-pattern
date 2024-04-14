

#include <iostream>
#include "functions.h"
#include <string>
#include <vector>
#include <fstream>

class Management
{
private:
    struct Account
    {
        std::string username;
        std::string password;
    };

public:
    std::vector<Account> accounts;

    void load_accounts(const std::string &filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        Account temp;
        while (file >> temp.username >> temp.password)
        {
            accounts.push_back(temp);
        }

        file.close();
    }

    void save_accounts(const std::string &filename)
    {
        std::ofstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        for (const auto &acc : accounts)
        {
            file << acc.username << " " << acc.password << std::endl;
        }

        file.close();
    }

    void sign_up(const std::string &username, const std::string &password)
    {
        system("cls");
        for (const auto &acc : accounts)
        {
            if (acc.username == username)
            {
                std::cout << "This username already exists. Please choose a different username" << std::endl;
                return;
            }
        }
        Account new_account;
        new_account.username = username;
        new_account.password = password;
        accounts.push_back(new_account);
        std::cout << "Account created successfully!" << std::endl;
    }

    void change_password(const std::string &username, const std::string &password)
    {
        system("cls");
        std::string pass;
        for (auto it = accounts.begin(); it != accounts.end(); ++it)
        {
            if (it->username == username)
            {
                if (it->password == password)
                {
                    std::cout << "Enter your new password: ";
                    std::cin >> pass;
                    it->password = pass;
                    std::cout << "Password changed successfully!" << std::endl;
                    return;
                }
                else
                {
                    std::cout << "Invalid password";
                    return;
                }
            }
        }
        std::cout << "Account not found." << std::endl;
    }

    void login(const std::string &username, const std::string &password)
    {
        system("cls");
        for (const auto &acc : accounts)
        {
            if (acc.username == username && acc.password == password)
            {
                std::cout << "Login successful!" << std::endl;
                main_screen();
                return;
            }
        }
        std::cout << "Invalid username or password. Try again." << std::endl;
    }
};

void password_screen(void)
{
    system("cls");
    Management m1;
    m1.load_accounts("data.txt");
    std::string username, password;
    int choice;
    while (1)
    {
        std::cout << "1. Sign_up\n2. Change password\n3. Login\n4. Exit\nEnter choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter your username: ";
            std::cin >> username;
            std::cout << "Enter your password: ";
            std::cin >> password;
            m1.sign_up(username, password);
            break;
        case 2:
            std::cout << "Enter your username: ";
            std::cin >> username;
            std::cout << "Enter your password: ";
            std::cin >> password;
            m1.change_password(username, password);
            break;
        case 3:
            std::cout << "Enter your username: ";
            std::cin >> username;
            std::cout << "Enter your password: ";
            std::cin >> password;
            m1.login(username, password);
            break;
        case 4:
            m1.save_accounts("data.txt");
            exit(0);
        default:
            std::cout << "Invalid input. Try again." << std::endl;
            break;
        }
    }
}
