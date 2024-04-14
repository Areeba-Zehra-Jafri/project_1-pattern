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
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open())
        {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        Account temp;
        while (file.read(reinterpret_cast<char *>(&temp), sizeof(Account)))
        {
            accounts.push_back(temp);
        }

        file.close();
    }

    void save_accounts(const std::string &filename)
    {
        std::ofstream file(filename, std::ios::binary);
        if (!file.is_open())
        {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        for (const auto &acc : accounts)
        {
            file.write(reinterpret_cast<const char *>(&acc), sizeof(Account));
        }

        file.close();
    }

    void create_account(const std::string &usernamme, const std::string &password)
    {
        for (const auto &acc : accounts)
        {
            if (acc.username == usernamme)
            {
                std::cout << "This username already exists. Please choose a different username" << std::endl;
                return;
            }
        }
        Account new_account;
        new_account.username = usernamme;
        new_account.password = password;
        accounts.push_back(new_account);
        std::cout << "Account created successfully!" << std::endl;
    }

    void delete_account(const std::string &username, const std::string &password)
    {
        for (auto it = accounts.begin(); it != accounts.end(); ++it)
        {
            if (it->username == username)
            {
                if (it->password == password)
                {
                    accounts.erase(it);
                    std::cout << "Account deleted successfully!" << std::endl;
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
        for (const auto &acc : accounts)
        {
            if (acc.username == username && acc.password == password)
            {
                std::cout << "Login successful!" << std::endl;
                // main_screen();
                return;
            }
        }
        std::cout << "Invalid username or password. Try again." << std::endl;
    }
};

int main()
{
    password_screen();
    std::cin.get();
    return 0;
}
void password_screen(void)
{
    Management m1;
    m1.load_accounts("accounts.dat");
    std::string username, password;
    int choice;
    while (1)
    {
        std::cout << "1. Create Account\n2. Delete Account\n3. Login\n4. Exit\nEnter choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter your username: ";
            std::cin >> username;
            std::cout << "Enter your password: ";
            std::cin >> password;
            m1.create_account(username, password);
            break;
        case 2:
            std::cout << "Enter your username: ";
            std::cin >> username;
            std::cout << "Enter your password: ";
            std::cin >> password;
            m1.delete_account(username, password);
            break;
        case 3:
            std::cout << "Enter your username: ";
            std::cin >> username;
            std::cout << "Enter your password: ";
            std::cin >> password;
            m1.login(username, password);
            break;
        case 4:
            m1.save_accounts("accounts.dat");
            exit(0);
        default:
            std::cout << "Invalid input. Try again." << std::endl;
            break;
        }
    }
    // main_screen();
}