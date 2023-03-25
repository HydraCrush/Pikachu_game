#include "border.h"


//-------ve khung vien xung quanh--------
void border() {
	char border = '\xCD';
	gotoXY(0, 0);
	cout << "\xC9";

	gotoXY(155, 40);
	cout << "\xBC";
	for (int i = 1; i <= 154; ++i)
	{
		Sleep(10);
		gotoXY(i, 0);
		cout << border;
		gotoXY(155 - i, 40);
		cout << border;
	}

	gotoXY(155, 0);
	cout << '\xBB';
	gotoXY(0, 40);
	cout << '\xC8';

	for (int i = 1; i < 40; ++i) {
		Sleep(15);
		gotoXY(155, i);
		cout << '\xBA';
		gotoXY(0, 40 - i);
		cout << '\xBA';
	}

	for (int i = 11; i < 40; ++i) {
		Sleep(30);
		gotoXY(95, i);
		cout << "\xBA";
	}

	for (int i = 1; i <= 154; ++i) {
		Sleep(10);
		gotoXY(i, 10);
		cout << border;
	}

	int xp = 96;
	for (int i = 11; i < 40; ++i) {
		Sleep(20);
		gotoXY(125, i);
		cout << '\xBA';

	}

	for (int i = 154; i >= xp; --i) {
		Sleep(20);
		gotoXY(xp, 23);
		cout << border;
		++xp;
		gotoXY(i, 23);
		cout << border;
	}
}

//-----------ve hinh----------
void draw(int n, int x, int y, int b_color, int t_color) {
	if (n == 0) {
		textcolor(b_color);
		for (int ix = x + 1; ix < x + 8; ++ix)
		{
			for (int iy = y + 1; iy < y + 4; ++iy)
			{
				gotoXY(ix, iy);
				cout << " ";
			}
		}
		return;
	}

	//---------khung----------
	string str[] = {
					" ------- ",
					"|       |",
					"|       |",
					"|       |",
					" ------- " };


	SetColor(t_color);  //-------ve khung------
	for (int i = 0; i < 5; ++i)
	{
		gotoXY(x, y);
		cout << str[i] << endl;
		++y;
	}

	y -= 5;		//-------------reset toa do y---------
	//--------ve mau back ground--------
	textcolor(b_color);
	for (int ix = x + 1; ix < x + 8; ++ix)
	{
		for (int iy = y + 1; iy < y + 4; ++iy)
		{
			gotoXY(ix, iy);
			cout << " ";
		}
	}

	//----------viet chu o giua----------
	SetColor(t_color);
	gotoXY(x + 4, y + 2);
	cout << (char)n;

	//-------reset back ground ve den-------
	textcolor(0);
	//-------reset mau chu ve trang-------
	SetColor(15);
}


void instruction() {
	string text[] = {
					"  HOW TO PLAY:",
					"USE A TO MOVE LEFT" ,
					"USE W TO MOVE UPWARD" ,
					"USE S TO MOVE DOWNWARD" ,
					"USE D TO MOVE RIGHT" ,
					"USE ENTER TO CHOOSE",
					"",
					"",
					"EVERY MATCHED PAIR: +5",
					"EVERY WRONG PAIR: -3",
					"",
					"",
					"PRESS ESC TO EXIT" };
	int x = 128, y = 25;

	//-----set mau chu------
	SetColor(14);

	//-----in phan huong dan-------
	for (int i = 0; i < sizeof(text) / sizeof(text[0]); ++i) {
		gotoXY(x, y);
		Sleep(20);
		cout << text[i];
		++y;
	}

	gotoXY(108, 13);
	cout << "SCORE";

	SetColor(15);
}


void draw_matrix_delay(Draw** arr, int x, int y, int row, int col, int b_color, int t_color) {
	gotoXY(x, y);
	int xp = x, yp = y;		//-------bien toa do chay-------

	for (int i = 2; i < row - 2; ++i) {
		xp = x;
		for (int j = 2; j < col - 2; ++j) {
			gotoXY(xp, yp);
			Sleep(30);
			draw(arr[i][j].key, xp, yp, b_color, t_color);
			xp += 8;
		}
		yp += 4;
	}
}


void draw_matrix(Draw** arr, int x, int y, int row, int col, int b_color, int t_color) {
	gotoXY(x, y);
	int xp = x, yp = y;		//-------bien toa do chay-------

	for (int i = 2; i < row - 2; ++i) {
		xp = x;
		for (int j = 2; j < col - 2; ++j) {
			gotoXY(xp, yp);
			//if (arr[i][j].key != 0)
				draw(arr[i][j].key, xp, yp, b_color, t_color);
			xp += 8;
		}
		yp += 4;
	}
}


void draw_starting(Draw **arr, int x, int y, int x_arr, int y_arr, int b_color, int t_color){
	//-------to mau o bat dau-------
	gotoXY(x, y);
	draw(arr[x_arr][y_arr].key, x, y, b_color, t_color);
}


void clock_() {
	cout << "a";
}


void score() {
	cout << "a";
}