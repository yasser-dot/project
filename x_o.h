//#include "connect.h"


#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>

//using namespace std;

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

struct WinPath {
    int y[4], x[4];
    bool found = false;
};

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

WinPath checkWin(char arr[4][4]) {
    WinPath wp;
    for (int i = 0; i < 4; i++) {
        if (arr[i][0] != ' ' && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3]) {
            for (int j = 0; j < 4; j++) { wp.y[j] = i; wp.x[j] = j; }
            wp.found = true; return wp;
        }
        if (arr[0][i] != ' ' && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] == arr[3][i]) {
            for (int j = 0; j < 4; j++) { wp.y[j] = j; wp.x[j] = i; }
            wp.found = true; return wp;
        }
    }
    if (arr[0][0] != ' ' && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == arr[3][3]) {
        for (int j = 0; j < 4; j++) { wp.y[j] = j; wp.x[j] = j; }
        wp.found = true; return wp;
    }
    if (arr[0][3] != ' ' && arr[0][3] == arr[1][2] && arr[1][2] == arr[2][1] && arr[2][1] == arr[3][0]) {
        for (int j = 0; j < 4; j++) { wp.y[j] = j; wp.x[j] = 3 - j; }
        wp.found = true; return wp;
    }
    return wp;
}

void printBoard(char arr[4][4], int currY, int currX, WinPath wp) {
    clearScreen();
   std:: cout << "Use Arrows to Move | Enter to Select\n";
  std::  cout << "------------------\n";
    for (int y = 0; y < 4; y++) {
      std::  cout << "|";
        for (int x = 0; x < 4; x++) {
            bool isWinPath = false;
            if (wp.found) {
                for (int i = 0; i < 4; i++) if (wp.y[i] == y && wp.x[i] == x) isWinPath = true;
            }

            if (isWinPath) {
                setColor(224); // خلفية صفراء توضح خط الفوز
              std::  cout << " " << arr[y][x] << " ";
                setColor(7);
            } else if (y == currY && x == currX) {
                if (arr[y][x] != ' ') { setColor(160); std::cout << " " << arr[y][x] << " "; }
                else { setColor(240); std::cout << " . "; }
                setColor(7);
            } else {
                if (arr[y][x] == 'X') { setColor(12); std::cout << " X "; setColor(7); }
                else if (arr[y][x] == 'O') { setColor(9); std::cout << " O "; setColor(7); }
                else std::cout << "   ";
            }
            std::cout << "|";
        }
       std:: cout << "\n------------------\n";
    }
}

