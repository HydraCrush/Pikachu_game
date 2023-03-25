#pragma once
#include "coor_lib.h"

struct Draw {
	int key;
};

//-----------khung tro choi----------
void border();

//-----------ve o chu----------
void draw_matrix_delay(Draw** arr, int x, int y, int row, int col, int b_color, int t_color);
void draw_matrix(Draw** arr, int x, int y, int row, int col, int b_color, int t_color);

//-----------to mau o bat dau------------
void draw_starting(Draw** arr, int x, int y, int x_arr, int y_arr, int b_color, int t_color);

//-----------ve hinh----------
void draw(int n, int x, int y, int b_color, int t_color);


void instruction();


void clock_();


void score();