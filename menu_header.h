#ifndef FUNCTIONS_H_INCLUDED_
#define FUNCTIONS_H_INCLUDED_

#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>

#include "matrix_header.h"

using namespace std;

//Menu options
void ShowMenu();
void gotoxy(int x, int y);
int menu_move(int counter);
void add_update();
void sub_update();
void mul_update();
void pow_update();
void trans_update();
void det_update();
void inverse_update();
void about_update();

//Operations
Matrix InputMatrix();
void addition();
void subtraction();
void multiplication();
void power();
void trans();
void determ();
void inverse();
#endif#
