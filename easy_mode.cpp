#include "easy_mode.h"


void game_play_easy(bool& GAME_ACTIVE) {
	//---------tat con tro-------
	ShowCur(0);
	srand(time(0));

	//---------hang cot----------
	int row = 10, col = 14;
	//---------nhan phim bam---------
	char get_key;
	//---------tao mang ghi mau----------
	int** arr_color = new int* [row];
	//---------tao mang ki tu----------
	Draw** arr = new Draw * [row];
	//---------so luong chu cai----------
	int nums_of_char = 6;
	create_matrix_game_play(arr, arr_color, row, col, nums_of_char);



	//--------toa do bat dau ve khung tro choi----------
	int x = 7, y = 13;
	//--------bien x,y di chuyen----------
	int xp = x, yp = y;
	//--------bien x,y luu toa do cu----------
	int xcu = x, ycu = y;
	//--------bien x,y tuong ung voi vi tri trong mang arr----------
	int x_arr = 2, y_arr = 2;
	//--------mau chu---------
	int t_color = 15;
	//--------mau nen---------
	int b_color = 16 * 0;
	//--------mang nho vi tri can xoa------
	delete_coor coor_delete[2];
	//--------dem so o da duoc chon------
	int count_choose = 0;

	//border();
	//instruction();
	//draw_back_ground(70, 13);
	draw_matrix_delay(arr, x, y, row, col, b_color, t_color);
	draw_starting(arr, x, y, 2, 2, 19 * 4, t_color);


	b_color = 16 * 4;
	//--------di chuyen-------
	while (GAME_ACTIVE) {
		//----------kiem tra xem nguoi dung co nhap tu ban phimm khong--------
		if (_kbhit()) {
			get_key = _getch();		//----------luu phim nguoi dung vua bam vao get_key-----------

			moving(get_key, arr, arr_color, x_arr, y_arr, xp, yp, xcu, ycu, b_color, t_color, col, row, GAME_ACTIVE, coor_delete, count_choose);
		}
		Sleep(1);
	}
	gotoXY(0, 0);
	cout << "end game";

	//--------xoa mang dong--------
	for (int i = 0; i < row; ++i)
		delete[]arr[i];
	delete[] arr;

	for (int i = 0; i < row; ++i)
		delete[]arr_color[i];
	delete[] arr_color;

	//get_key = _getch();
}

