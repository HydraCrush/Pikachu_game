/*
source:				https://www.youtube.com/watch?v=UjQIwlr_DqI
					https://www.youtube.com/watch?v=TgEbEQ78qAQ
					https://www.youtube.com/watch?v=TE2IyWVPrO0&t=523s
*/

#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h> 
#include <conio.h>
#include <windows.h>
#include "border.h"
#include <iomanip>
#include <fstream>

using namespace std;

//======= lấy tọa độ x của con trỏ hiện tại =============
int whereX();

//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY();

//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y);

//============= đặt màu cho chữ =========
void SetColor(WORD color);

//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility);

//============= đặt màu background=========
void textcolor(int x);