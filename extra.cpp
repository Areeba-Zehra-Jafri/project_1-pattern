
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include "functions.h"

// // int main()
// // {
// //     customizable_screen();
// // }

// // void customizable_screen(void)
// // {
// //     char c;int count=0,choice,rows;
// //     std::cout<<"Enter D to move forward and A to move backward S to select and W to go back "<<std::endl;
// //     std::cin>>c;
// //     while(1)
// //     {
// //         if(c=='A'&&count>0){count=(count-1)%4;}
// //         if(c=='D'){count=(count+1)%4;}
// //         if(c=='S'){break;}
// //         if(c=='W'){exit(0);}//{start_screen();}
// //         switch (count)
// //         {
// //             case 0:
// //             std::cout<<"pyramid"<<count<<std::endl;
// //             pyramid(5);
// //             break;
// //         case 1:
// //             std::cout<<"rectangle"<<count<<std::endl;
// //             rectangle(5);
// //             break;
// //         case 2:
// //             std::cout<<"diamond"<<count<<std::endl;
// //             diamond(5);
// //             break;
// //         case 3:
// //             std::cout<<"hourglass"<<count<<std::endl;
// //             hourglass(5);
// //             break;
// //         default:
// //             std::cout<<"Invalid input"<<std::endl;
// //             break;
// //         }
// //         std::cin>>c;
// //     }
// //     std::cout<<"Enter the number of pattern you wanted:"<<std::endl;
// //     std::cin>>choice;
// //     std::cout<<"Enter the number of rows you want in the output:"<<std::endl;
// //     std::cin>>rows; 
// //     switch(choice)
// //     {
// //        case 0:
// //             std::cout<<"pyramid"<<count<<std::endl;
// //             pyramid(rows);
// //             break;
// //         case 1:
// //             std::cout<<"rectangle"<<count<<std::endl;
// //             rectangle(rows);
// //             break;
// //         case 2:
// //             std::cout<<"diamond"<<count<<std::endl;
// //             diamond(rows);
// //             break;
// //         case 3:
// //             std::cout<<"hourglass"<<count<<std::endl;
// //             hourglass(rows);
// //             break;
// //         default:
// //             std::cout<<"Invalid input"<<std::endl;
// //             break; 
// //     }
// //     customizable_screen();
// // }
// // void pyramid(int r)
// // {
// //     for(int i=0;i<r;i++)
// //     {
// //         for(int j=0;j<r-1-i;j++)
// //         {
// //             std::cout<<"  ";
// //         }
// //         for(int j=0;j<(2*i)+1;j++)
// //         {
// //             std::cout<<"*"<<" ";
// //         }
// //         std::cout<<std::endl;
// //     }
// // }
// // void rectangle(int r)
// // {
// //     for(int i=0;i<r;i++)
// //     {
// //         for(int j=0;j<r;j++)
// //         {
// //             std::cout<<"*"<<" ";
// //         }
// //         std::cout<<std::endl;
// //     }
// // }
// // void diamond(int r)
// // {
// //     for(int i=0;i<r;i++)
// //     {
// //         for(int j=0;j<r-i-1;j++)
// //         {
// //             std::cout<<"  ";
// //         }
// //         for(int j=0;j<(2*i)+1;j++)
// //         {
// //             std::cout<<"*"<<" ";
// //         }
// //         std::cout<<std::endl;
// //     }
// //     r=r-1;
// //     for(int i=1;i<=r;i++)
// //     {
// //         for(int j=0;j<i;j++)
// //         {
// //             std::cout<<"  ";
// //         }
// //         for(int j=0;j<(2*r)-(2*i)+1;j++)
// //         {
// //             std::cout<<"*"<<" ";
// //         }
// //         std::cout<<std::endl;
// //     }
// // }
// // void hourglass(int r)
// // {
// //     for(int i=1;i<=r;i++)
// //     {
// //         for(int j=0;j<i;j++)
// //         {
// //             std::cout<<"  ";
// //         }
// //         for(int j=0;j<(2*r)-(2*i)+1;j++)
// //         {
// //             std::cout<<"*"<<" ";
// //         }
// //         std::cout<<std::endl;
// //     }
// //     for(int i=0;i<r;i++)
// //     {
// //         for(int j=0;j<r-i;j++)
// //         {
// //             std::cout<<"  ";
// //         }
// //         for(int j=0;j<(2*i)+1;j++)
// //         {
// //             std::cout<<"*"<<" ";
// //         }
// //         std::cout<<std::endl;
// //     }
// // }

// struct Account {
//     std::string username;
//     std::string password;
//     // Add other fields as needed
// };

// std::vector<Account> accounts;


// void createAccount(const std::string& username, const std::string& password) {
//     // Check if username already exists
//     for (const auto& acc : accounts) {
//         if (acc.username == username) {
//             std::cout << "Username already exists. Please choose a different username.\n";
//             return;
//         }
//     }
//     // Create new account
//     Account newAccount;
//     newAccount.username = username;
//     newAccount.password = password;
//     accounts.push_back(newAccount);
//     std::cout << "Account created successfully!\n";
// }

// void deleteAccount(const std::string& username) {
//     for (auto it = accounts.begin(); it != accounts.end(); ++it) {
//         if (it->username == username) {
//             accounts.erase(it);
//             std::cout << "Account deleted successfully!\n";
//             return;
//         }
//     }
//     std::cout << "Account not found.\n";
// }

// bool login(const std::string& username, const std::string& password) {
//     for (const auto& acc : accounts) {
//         if (acc.username == username && acc.password == password) {
//             std::cout << "Login successful!\n";
//             return true;
//         }
//     }
//     std::cout << "Invalid username or password.\n";
//     return false;
// }

// int main() {
//     std::string username, password;
//     int choice;

//     while (true) {
//         std::cout << "1. Create Account\n2. Delete Account\n3. Login\n4. Exit\nEnter choice: ";
//         std::cin >> choice;

//         switch (choice) {
//             case 1:
//                 std::cout << "Enter username: ";
//                 std::cin >> username;
//                 std::cout << "Enter password: ";
//                 std::cin >> password;
//                 createAccount(username, password);
//                 break;
//             case 2:
//                 std::cout << "Enter username to delete: ";
//                 std::cin >> username;
//                 deleteAccount(username);
//                 break;
//             case 3:
//                 std::cout << "Enter username: ";
//                 std::cin >> username;
//                 std::cout << "Enter password: ";
//                 std::cin >> password;
//                 login(username, password);
//                 break;
//             case 4:
//                 return 0;
//             default:
//                 std::cout << "Invalid choice. Try again.\n";
//         }
//     }

//     return 0;
// }
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream binaryFile("accounts.bin", std::ios::binary);
    return 0;
}