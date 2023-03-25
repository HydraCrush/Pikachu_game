#include "back_ground.h"

void draw_back_ground(int x, int y) {
	ifstream read("pika.txt");
	string str;
	while (!read.eof())
	{
		gotoXY(x, y);
		getline(read, str);
		cout << str << endl;
		++y;
	}
	read.close();
}