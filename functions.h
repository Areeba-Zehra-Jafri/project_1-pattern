#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void welcome_screen(void);
void password_screen();
void main_screen(void);
void start_screen(void);
void instructions(void);
void customizable_screen(void);
void pyramid(int r,char c,char ch);
void rectangle(int r,char c,char ch);
void diamond(int r,char c,char ch);
void hourglass(int r,char c,char ch);
bool isValidInput(char c, char ch);
void printChar(int count, char ch);
void constants_screen(void);
void pascal_triangle(int r);
void floyd_triangle(int r);
void palindrome_pyramid(int r);
void number_pyramid(int r);
void alphabets_pattern(int r);
void number_square(int r);
void surprise_screen(void);
void butterfly(int r);
void christmas_tree(int r);
void heart(int r);
void mountain_range(int r);
#endif

