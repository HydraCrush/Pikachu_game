#include "algorithm.h"


bool checkLineX(int y1, int y2, int x, Draw ** matrix)
{
    int minVal = min(y1, y2);
    int maxVal = max(y1, y2);
    for (int y = minVal; y <= maxVal; y++)
    {
        if (matrix[x][y].key != 0)
            return false;
    }
    return true;
}

bool checkLineY(int x1, int x2, int y, Draw** matrix)
{
    int minVal = min(x1, x2);
    int maxVal = max(x1, x2);
    for (int x = minVal; x <= maxVal; x++)
    {
        if (matrix[x][y].key != 0)
            return false;
    }
    return true;
}

int checkRectX(int x1, int y1, int x2, int y2, Draw** matrix)
{
    int miny = y2, minx = x2;
    int maxy = y1, maxx = x1;

    if (y1 < y2) {
        miny = y1, minx = x1; 
        maxy = y2, maxx = x2;
    }

    for (int y = miny + 1; y < maxy; y++)
    {
        // check three line
        if (checkLineX(miny, y, minx, matrix)
            && checkLineY(minx, maxx, y, matrix)
            && checkLineX(y, maxy, maxx, matrix))
            return y;
    }
    // have a line in three line not true then return -1
    return -1;
}

int checkRectY(int x1, int y1, int x2, int y2, Draw ** matrix){
    // find point have y min
    int miny = y2, minx = x2;
    int maxy = y1, maxx = x1;

    if (y1 < y2) {
        miny = y1, minx = x1;
        maxy = y2, maxx = x2;
    }

    // find line and y begin
    for (int x = minx + 1; x < maxx; x++)
    {
        if (checkLineY(minx, x, miny, matrix)
            && checkLineX(miny, maxy, x, matrix)
            && checkLineY(x, maxx, maxy, matrix))
            return x;
    }
    return -1;
}

int checkMoreLineX(int x1, int y1, int x2, int y2, int type, Draw** matrix)
{
    // find point have y min
    int miny = y2, minx = x2;
    int maxy = y1, maxx = x1;

    if (y1 < y2) {
        miny = y1, minx = x1;
        maxy = y2, maxx = x2;
    }

    // find line and y begin
    int y = maxy;
    int row = minx;
    if (type == -1)
    {
        y = miny;
        row = maxx;
    }
    // check more
    if (checkLineX(miny, maxy, row, matrix))
    {
        while (matrix[minx][y].key == 0 && matrix[maxx][y].key == 0)
        {
            if (checkLineY(minx, maxx, y, matrix))
                return y;
            y += type;
        }
    }
    return -1;
}

int checkMoreLineY(int x1, int y1, int x2, int y2, int type, Draw** matrix)
{
    int miny = y2, minx = x2;
    int maxy = y1, maxx = x1;

    if (y1 < y2) {
        miny = y1, minx = x1;
        maxy = y2, maxx = x2;
    }
    
    int x =maxx;
    int col = miny;
    if (type == -1)
    {
        x = minx;
        col = maxy;
    }

    if (checkLineY(minx, maxx, col, matrix))
    {
        while (matrix[x][miny].key == 0 && matrix[x][maxx].key == 0)
        {
            if (checkLineX(miny, maxy, x, matrix))
                return x;
            x += type;
        }
    }
    return -1;
}

bool checkTwoPoint(int x1, int y1, int x2, int y2, Draw** matrix)
{
    // check line with x
    if (x1 == x2)
    {
        if (checkLineX(y1, y2, x1, matrix))
            return true;
    }

    // check line with y
    if (y1 == y2)
    {
        if (checkLineY(x1, x2, y1, matrix))
            return true;
    }

    int t = -1; // t is column find

    // check in rectangle with x
    if ((t = checkRectX(x1, y1, x2, y2, matrix)) != -1)
        return true;

    // check in rectangle with y
    if ((t = checkRectY(x1, y1, x2, y2, matrix)) != -1)
        return true;

    // check more right
    if ((t = checkMoreLineX(x1, y1, x2, y2, 1, matrix)) != -1)
        return true;

    // check more left
    if ((t = checkMoreLineX(x1, y1, x2, y2, -1, matrix)) != -1)
        return true;

    // check more down
    if ((t = checkMoreLineY(x1, y1, x2, y2, 1, matrix)) != -1)
        return true;

    // check more up
    if ((t = checkMoreLineY(x1, y1, x2, y2, -1, matrix)) != -1)
        return true;
    else
        return false;
}




bool check_match(delete_coor coor[2], Draw** arr) {
    if (arr[coor[0].x][coor[0].y].key == arr[coor[1].x][coor[1].y].key)
        return true;

    return false;
}

void delet_match(delete_coor coor[2], Draw** arr) {
    arr[coor[0].x, coor[0].y] = 0;
    arr[coor[1].x, coor[1].y] = 0;

    draw(0, -1 + 8 * coor[0].y, 9 + 4 * coor[0].x, 0, 14);
    draw(0, -1 + 8 * coor[1].y, 9 + 4 * coor[1].x, 0, 14);
}

void moving(char get_key, Draw** arr, int** arr_color, int& x_arr, int& y_arr, int& xp, int& yp, int& xcu, int& ycu, int b_color, int t_color, int col, int row, bool& GAME_ACTIVE, delete_coor coor_delete[2], int& count_choose) {
    //-------di len-------
    if (tolower(get_key) == 'w') {
        if (x_arr != 2) {
            if (arr_color[x_arr][y_arr] == 0)
                //------xoa mau o cu----
                draw(arr[x_arr][y_arr].key, xcu, ycu, 0, t_color);
            else
                draw(arr[x_arr][y_arr].key, xp, yp, 16 * 9, t_color);
            //------cap nhat vi tri x trong mang-------
            --x_arr;
            //------cap nhat toa do y moi-----
            yp -= 4;
            //------ve o moi--------
            draw(arr[x_arr][y_arr].key, xp, yp, b_color, t_color);
            //------cap nhat toa do ycu-----
            ycu = yp;
        }
    }

    //-------qua trai-------
    else if (tolower(get_key) == 'a') {
        if (y_arr != 2) {
            if (arr_color[x_arr][y_arr] == 0)
                //------xoa mau o cu----
                draw(arr[x_arr][y_arr].key, xcu, ycu, 0, t_color);
            else
                draw(arr[x_arr][y_arr].key, xp, yp, 16 * 9, t_color);
            //------cap nhat vi tri y trong mang-----
            --y_arr;
            //------cap nhat toa do x moi-----
            xp -= 8;
            //------ve o moi--------
            draw(arr[x_arr][y_arr].key, xp, yp, b_color, t_color);
            //------cap nhat toa do ycu-----
            xcu = xp;
        }
    }

    //-------qua phai-------
    else if (tolower(get_key) == 'd') {
        if (y_arr != col - 3) {
            if (arr_color[x_arr][y_arr] == 0)
                //------xoa mau o cu----
                draw(arr[x_arr][y_arr].key, xcu, ycu, 0, t_color);
            else
                draw(arr[x_arr][y_arr].key, xp, yp, 16 * 9, t_color);
            //------cap nhat vi tri y trong mang-----
            ++y_arr;
            //------cap nhat toa do x moi-----
            xp += 8;
            //------ve o moi--------
            draw(arr[x_arr][y_arr].key, xp, yp, b_color, t_color);
            //------cap nhat toa do ycu-----
            xcu = xp;
        }
    }

    //-------di xuong-------
    else if (tolower(get_key) == 's') {
        if (x_arr != row - 3) {
            if (arr_color[x_arr][y_arr] == 0)
                //------xoa mau o cu----
                draw(arr[x_arr][y_arr].key, xcu, ycu, 0, t_color);
            else
                draw(arr[x_arr][y_arr].key, xp, yp, 16 * 9, t_color);
            //------cap nhat vi tri x trong mang-------
            ++x_arr;
            //------cap nhat toa do y moi-----
            yp += 4;
            //------ve o moi--------
            draw(arr[x_arr][y_arr].key, xp, yp, b_color, t_color);
            //------cap nhat toa do ycu-----
            ycu = yp;
        }
    }

    else if (get_key == 13 && arr[x_arr][y_arr].key != 0) {
        //-------to mau o dang dung-------
        draw(arr[x_arr][y_arr].key, xp, yp, 16 * 9, t_color);
        //-------danh dau o to mau--------
        arr_color[x_arr][y_arr] = 1;

        ++count_choose;
        //-------luu vi tri o to mau thu nhat--------
        if (count_choose == 1) {
            coor_delete[0].x = x_arr;
            coor_delete[0].y = y_arr;
        }
        else if (count_choose == 2) {
            if (coor_delete[0].x != x_arr || coor_delete[0].y != y_arr) {
                coor_delete[1].x = x_arr;
                coor_delete[1].y = y_arr;
            }
            else
                --count_choose;
        }

        if (count_choose == 2) {
            //----------reset bien dem--------
                count_choose = 0;

                if (check_match(coor_delete, arr) && checkTwoPoint(coor_delete[0].x, coor_delete[0].y, coor_delete[1].x, coor_delete[1].y, arr)) {
                    arr_color[coor_delete[0].x][coor_delete[0].y] = 0;
                    arr_color[coor_delete[1].x][coor_delete[1].y] = 0;
                    arr[coor_delete[0].x][coor_delete[0].y].key = 0;
                    arr[coor_delete[1].x][coor_delete[1].y].key = 0;
                    //draw_back_ground(7, 13);
                    draw_matrix(arr, 7, 13, row, col, 0, 15);
                    draw_starting(arr, xp, yp, x_arr, y_arr, 19 * 4, 15);
                }

                else{
                    arr_color[coor_delete[0].x][coor_delete[0].y] = 0;
                    arr_color[coor_delete[1].x][coor_delete[1].y] = 0;
                    draw_matrix(arr, 7, 13, row, col, 0, 15);
                    draw_starting(arr, xp, yp, x_arr, y_arr, 19 * 4, 15);
                }
        }
    }

    else if (get_key == 27)
        exit_menu(60, 15, 30, 8, GAME_ACTIVE);
}

void create_matrix_game_play(Draw** arr, int** arr_color, int row, int col, int nums_of_char) {
    //---------tao mang ghi mau----------
    for (int i = 0; i < row; ++i)
    {
        arr_color[i] = new int[col];
        for (int j = 0; j < col; ++j)
            arr_color[i][j] = 0;		//--------0: chua to mau, 1: da to mau---------
    }


    //---------tao mang----------
    for (int i = 0; i < row; ++i)
    {
        arr[i] = new Draw[col];
        for (int j = 0; j < col; ++j)
            arr[i][j].key = 0;		//--------mac dinh cac gia tri bang 0---------
    }

    //----------vien ngoai cung = -1-------------
    for (int i = 0; i < row; ++i) {
        arr[i][0].key = -1;
        arr[i][col - 1].key = -1;
    }
    for (int i = 0; i < col; ++i) {
        arr[0][i].key = -1;
        arr[row - 1][i].key = -1;
    }

    //---------tao mang random----------
    for (int i = 2; i < row - 2; ++i) {
        for (int j = 2; j < col - 2; ++j) {
            if (arr[i][j].key == 0) {
                arr[i][j].key = rand() % nums_of_char + 65;
                int i_ = i, j_ = j;
                while ((i_ == i && j_ == j) || arr[i_][j_].key != 0) {
                    i_ = rand() % (row - 4) + 2;
                    j_ = rand() % (col - 4) + 2;
                }
                arr[i_][j_].key = arr[i][j].key;	//--------tao ra 1 cap 2 gia tri giong nhau--------
            }
        }
    }
}
