#include "menu.h"


void exit_menu(int x, int y, int w, int h, bool& GAME_ACTIVE) {
	ShowCur(0);

	textcolor(0);
	for (int ix = x; ix <= x + w; ix++)
	{
		for (int iy = y; iy <= y + h; iy++)
		{
			gotoXY(ix, iy);
			cout << " ";

		}
	}

	//--------ve khung---------
	SetColor(15);
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y + h); cout << char(217);



	gotoXY(x + 5, y + 2);
	cout << "DO YOU WANT TO EXIT ?";
	gotoXY(x + 24, y + 6);
	cout << "NO";

	SetColor(4);
	gotoXY(x + 5, y + 6);
	cout << "YES <<<";

	while (GAME_ACTIVE) {
		if (_kbhit()) {
			char get_key = _getch();

			if (tolower(get_key) == 'a') {
				SetColor(15);
				gotoXY(x + 20, y + 6);
				cout << "    NO";

				SetColor(4);
				gotoXY(x + 5, y + 6);
				cout << "YES <<<";
			}

			else if (tolower(get_key) == 'd') {
				SetColor(15);
				gotoXY(x + 5, y + 6);
				cout << "YES    ";

				SetColor(4);
				gotoXY(x + 20, y + 6);
				cout << ">>> NO";
			}

			else if (get_key == 13 && whereX() < 75)
				GAME_ACTIVE = false;
		}
	}

}