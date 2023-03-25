#pragma once
#include <algorithm>
#include "coor_lib.h"
#include "menu.h"
#include "border.h"
#include "back_ground.h"

#define barrier -1


struct Point
{
    int x, y;
    int value;
};


struct delete_coor {
    int x, y;
};


bool checkLineX(int y1, int y2, int x, Draw** matrix);
bool checkLineY(int x1, int x2, int y, Draw** matrix);
int checkRectX(int x1, int y1, int x2, int y2, Draw** matrix);
int checkRectY(int x1, int y1, int x2, int y2, Draw** matrix);
int checkMoreLineX(int x1, int y1, int x2, int y2, int type, Draw** matrix);
int checkMoreLineY(int x1, int y1, int x2, int y2, int type, Draw** matrix);
bool checkTwoPoint(int x1, int y1, int x2, int y2, Draw** matrix);
bool check_match(delete_coor coor[2], Draw** arr);
void delet_match(delete_coor coor[2], Draw** arr);
void moving(char get_key, Draw** arr, int** arr_color, int& x_arr, int& y_arr, int& xp, int& yp, int& xcu, int& ycu, int b_color, int t_color, int col, int row, bool& GAME_ACTIVE, delete_coor coor_delete[2], int& count_choose);
void create_matrix_game_play(Draw** arr, int** arr_color, int row, int col, int nums_of_char);