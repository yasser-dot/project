#include <iostream>
#include "x_o.h"
#include "connect.h"

//#define SIZE1 7
using namespace std;
int main() {
  int ni;
  cout << "If you want to play X/O press 1"<< endl;
  cout << "If you want to play Connect_4 press 2"<< endl;
  cin >> ni;
  if (ni==2){
    // 0 = none, 1 = X, 2 = O
    int board[SIZE1][SIZE1] = {};

    int t = SIZE1 * SIZE1;

    // true = player x's turn, false = player o's turn
    bool x_turn = true;

    cout << "Connect-4!\nPlayer 1 places X and player 2 places O.\n";

    while (t--) {
      int player = x_turn ? 1 : 2;
      char c = x_turn ? 'X' : 'O';

      print_board(board);
      cout << "It's player " << player << "'s turn!\n";
      cout << "Player " << player << " picks a column to place " << c << ": ";

      int col;
      cin >> col;
      col--;

      if (col < 0 || col > SIZE1 - 1) {
        cout << "Invalid move! You are only allowed to input between 1 and "
             << SIZE1 << ".\n";
        continue;
      }

      bool column_full = true;
      for (int i = 0; i < SIZE1; i++) {
        if (board[i][col] == 0) {
          column_full = false;
          break;
        }
      }

      if (column_full) {
        cout << "Invalid move! Column is full!\n";
        continue;
      }
      play_turn(board, col, x_turn);
      if (check_win(board, player)) {
        print_board(board);
        cout << "Player " << player << " won!\n";
        return 0;
      }

      x_turn = !x_turn;
    }

    cout << "Draw!\n";
    return 0;
  }
  else if (ni==1) {
    bool mainFlag = true;
    do {
      system("cls");
      char arr[4][4] = { {' ',' ',' ',' '}, {' ',' ',' ',' '}, {' ',' ',' ',' '}, {' ',' ',' ',' '} };
      int count = 0;
      int cursorX = 0, cursorY = 0;
      WinPath wp;

      while (!(wp = checkWin(arr)).found && count < 16) {
        bool turnFinished = false;
        while (!turnFinished) {
          printBoard(arr, cursorY, cursorX, wp);
          if (count % 2 == 0) { setColor(12); cout << "X Player Turn\n"; setColor(7); }
          else { setColor(9); cout << "O Player Turn\n"; setColor(7); }

          int key = _getch();
          if (key == 224) {
            key = _getch();
            if (key == UP && cursorY > 0) cursorY--;
            else if (key == DOWN && cursorY < 3) cursorY++;
            else if (key == LEFT && cursorX > 0) cursorX--;
            else if (key == RIGHT && cursorX < 3) cursorX++;
          } else if (key == ENTER) {
            if (arr[cursorY][cursorX] == ' ') {
              arr[cursorY][cursorX] = (count % 2 == 0 ? 'X' : 'O');
              count++;
              turnFinished = true;
            }
          }
        }
      }

      wp = checkWin(arr);
      printBoard(arr, -1, -1, wp);

      if (wp.found) {
        char winner = arr[wp.y[0]][wp.x[0]];
        if (winner == 'X') { setColor(12); cout << "RESULT: X WINS!\n"; }
        else { setColor(9); cout << "RESULT: O WINS!\n"; }
      } else cout << "RESULT: DRAW!\n";

      setColor(7);
      cout << "\nPress any key to play again, or ESC to exit...";
      int choice = _getch();
      if (choice == 27) mainFlag = false;

    } while (mainFlag);
    return 0;
  }
  else cout << "Invalid Input"<< endl;
}