#include "connect-4.hpp"
#include "common.hpp"
#include <iostream>
using namespace std;

const int SIZE = 7;

void c4_print_board_row_separator() {
  cout << "----+";
  for (int i = 0; i < SIZE - 2; i++) {
    cout << "---+";
  }
  cout << "----\n";
}

void print_board(int board[SIZE][SIZE]) {
  // numbers of columns
  cout << "| ";
  for (int i = 1; i <= SIZE; i++) {
    cout << i;
    cout << (i == SIZE ? " |\n" : " | ");
  }
  c4_print_board_row_separator();

  for (int i = 0; i < SIZE; i++) {
    cout << '|';

    // print cells
    for (int j = 0; j < SIZE; j++) {
      string s = " ";

      if (board[i][j] == 1)
        s = RED "X" RESET;
      else if (board[i][j] == 2)
        s = BLUE "O" RESET;

      cout << ' ' << s << " |";
    }

    cout << '\n';
    c4_print_board_row_separator();
  }
}

bool check_win(int board[SIZE][SIZE], int player) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE - 3; j++) {
      if (board[i][j] == player && board[i][j + 1] == player &&
          board[i][j + 2] == player && board[i][j + 3] == player)
        return true;
    }
  }

  for (int i = 0; i < SIZE - 3; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] == player && board[i + 1][j] == player &&
          board[i + 2][j] == player && board[i + 3][j] == player)
        return true;
    }
  }

  for (int i = 0; i < SIZE - 3; i++) {
    for (int j = 0; j < SIZE - 3; j++) {
      if (board[i][j] == player && board[i + 1][j + 1] == player &&
          board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
        return true;
    }
  }

  for (int i = 0; i < SIZE - 3; i++) {
    for (int j = 3; j < SIZE; j++) {
      if (board[i][j] == player && board[i + 1][j - 1] == player &&
          board[i + 2][j - 2] == player && board[i + 3][j - 3] == player)
        return true;
    }
  }

  return false;
}

void play_connect_4() {
  // 0 = none, 1 = X, 2 = O
  int board[SIZE][SIZE] = {};

  int t = SIZE * SIZE;

  // true = player x's turn, false = player o's turn
  bool x_turn = true;

  cout << "Connect-4!\nPlayer 1 places X and player 2 places O.\n";

  print_board(board);
  while (t != 0) {
    int player = x_turn ? 1 : 2;
    char c = x_turn ? 'X' : 'O';

    cout << "It's player " << player << "'s turn!\n";
    cout << "Player " << player << " picks a column to place " << c << ": ";

    int col;
    cin >> col;
    col--;

    if (col < 0 || col > SIZE - 1) {
      print_board(board);
      cout << RED "Invalid move! You are only allowed to input between 1 and "
           << SIZE << ".\n" RESET;
      continue;
    }

    if (board[0][col] != 0) {
      print_board(board);
      cout << RED "Invalid move! Column is full!\n" RESET;
      continue;
    }

    int i = SIZE - 1;
    while (board[i][col] != 0) i--;
    board[i][col] = x_turn ? 1 : 2;

    if (check_win(board, player)) {
      print_board(board);
      cout << GREEN "Player " << player << " won!\n" RESET;
      return;
    }

    print_board(board);
    x_turn = !x_turn;
    t--;
  }

  cout << "Draw!\n";
}
