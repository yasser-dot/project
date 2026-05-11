#include "tic-tac-toe.hpp"
#include <iostream>
using namespace std;

const int SIZE = 4;

void print_board_row_separator() {
  cout << "  ----+";
  for (int i = 0; i < SIZE - 2; i++) {
    cout << "---+";
  }
  cout << "----\n";
}

void print_board(int board[SIZE][SIZE]) {
  cout << "    ";
  for (int i = 0; i < SIZE; i++) {
    cout << i + 1 << "   ";
  }
  cout << '\n';

  print_board_row_separator();
  for (int i = 0; i < SIZE; i++) {
    cout << i + 1 << " |";
    for (int j = 0; j < SIZE; j++) {
      char c = ' ';
      if (board[i][j] == 1) {
        c = 'X';
      } else if (board[i][j] == 2) {
        c = 'O';
      }

      cout << ' ' << c << " |";
    }
    cout << '\n';
    print_board_row_separator();
  }
}

bool check_win(int board[SIZE][SIZE], int player) {
  bool main_diagonal_found = true;
  bool secondary_diagonal_found = true;

  for (int i = 0; i < SIZE; i++) {
    if (board[i][i] != player) {
      main_diagonal_found = false;
    }

    if (board[i][SIZE - i - 1] != player) {
      secondary_diagonal_found = false;
    }

    bool horizontal_found = true;
    bool vertical_found = true;
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] != player) {
        horizontal_found = false;
      }

      if (board[j][i] != player) {
        vertical_found = false;
      }
    }

    if (horizontal_found || vertical_found) {
      return true;
    }
  }

  if (main_diagonal_found || secondary_diagonal_found) {
    return true;
  }

  return false;
}

void play_tic_tac_toe() {
  cout << "Tic-tac-toe!\nPlayer 1 places X and player 2 places O.\n";

  // 0 = none, 1 = X, 2 = O
  int board[SIZE][SIZE] = {};

  bool x_turn = true;
  int t = SIZE * SIZE;
  while (t != 0) {
    int player = x_turn ? 1 : 2;
    char c = x_turn ? 'X' : 'O';

    print_board(board);

    cout << "It's player " << player << "'s turn!\n";
    cout << "Player " << player << " picks a location on the board to place "
         << c << " (row col): ";

    int row;
    cin >> row;
    row--;

    int col;
    cin >> col;
    col--;

    if (row < 0 || row > SIZE - 1 || col < 0 ||
        col > SIZE - 1) {
      cout << "Invalid move! You may only enter a value from 1 to "
           << SIZE << ".\n";
    }

    if (board[row][col] != 0) {
      cout << "Invalid move! The location you picked is not empty.\n";
      continue;
    }

    board[row][col] = player;

    if (check_win(board, player)) {
      print_board(board);
      cout << "Player " << player << " won!\n";
      return;
    }

    x_turn = !x_turn;
    t--;
  }

  cout << "Draw!\n";
}
