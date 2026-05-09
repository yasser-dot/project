#include <iostream>
//using namespace std;
#define SIZE1 7
inline void print_board_row_separator() {
    std::cout << "----+";
    for (int i = 0; i < SIZE1 - 2; i++) {
      std::  cout << "---+";
    }
   std:: cout << "----\n";
}

void print_board(int board[SIZE1][SIZE1]) {
    // numbers of columns
  std::  cout << "| ";
    for (int i = 1; i <= SIZE1; i++) {
       std:: cout << i;
       std:: cout << (i == SIZE1 ? " |\n" : " | ");
    }
    print_board_row_separator();

    for (int i = 0; i < SIZE1; i++) {
       std:: cout << '|';

        // print cells
        for (int j = 0; j < SIZE1; j++) {
            char c = ' ';

            if (board[i][j] == 1)
                c = 'X';
            else if (board[i][j] == 2)
                c = 'O';

           std:: cout << " " << c << " |";
        }

      std::  cout << '\n';
        print_board_row_separator();
    }
}

int play_turn(int board[SIZE1][SIZE1], int col, bool x_turn) {
  int i = SIZE1 - 1;
  for (; board[i][col] != 0; i--)
    ;

  board[i][col] = x_turn ? 1 : 2;

  return i;
}

bool check_win(int board[SIZE1][SIZE1], int player) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == player && board[i][j + 1] == player &&
                board[i][j + 2] == player && board[i][j + 3] == player)
                return true;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == player && board[i + 1][j] == player &&
                board[i + 2][j] == player && board[i + 3][j] == player)
                return true;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == player && board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
                return true;
        }
    }

    for (int i = 0; i <= 3; i++) {
        for (int j = 3; j < 7; j++) {
            if (board[i][j] == player && board[i + 1][j - 1] == player &&
                board[i + 2][j - 2] == player && board[i + 3][j - 3] == player)
                return true;
        }
    }

    return false;
}