#include "connect-4.hpp"
#include <iostream>
using namespace std;

#define CONNECT_4_SIZE 7

inline void print_board_row_separator() {
  cout << "----+";
  for (int i = 0; i < CONNECT_4_SIZE - 2; i++) {
    cout << "---+";
  }
  cout << "----\n";
}

void print_board(int board[CONNECT_4_SIZE][CONNECT_4_SIZE]) {
  // numbers of columns
  cout << "| ";
  for (int i = 1; i <= CONNECT_4_SIZE; i++) {
    cout << i;
    cout << (i == CONNECT_4_SIZE ? " |\n" : " | ");
  }
  print_board_row_separator();

  for (int i = 0; i < CONNECT_4_SIZE; i++) {
    cout << '|';

    // print cells
    for (int j = 0; j < CONNECT_4_SIZE; j++) {
      char c = ' ';

      if (board[i][j] == 1)
        c = 'X';
      else if (board[i][j] == 2)
        c = 'O';

      cout << ' ' << c << " |";
    }

    cout << '\n';
    print_board_row_separator();
  }
}

int play_turn(int board[CONNECT_4_SIZE][CONNECT_4_SIZE], int col, bool x_turn) {
  int i = CONNECT_4_SIZE - 1;
  for (; board[i][col] != 0; i--)
    ;

  board[i][col] = x_turn ? 1 : 2;

  return i;
}

bool check_win(int board[CONNECT_4_SIZE][CONNECT_4_SIZE], int player) {
  for (int i = 0; i < CONNECT_4_SIZE; i++) {
    for (int j = 0; j < CONNECT_4_SIZE - 3; j++) {
      if (board[i][j] == player && board[i][j + 1] == player &&
          board[i][j + 2] == player && board[i][j + 3] == player)
        return true;
    }
  }

  for (int i = 0; i < CONNECT_4_SIZE - 3; i++) {
    for (int j = 0; j < CONNECT_4_SIZE; j++) {
      if (board[i][j] == player && board[i + 1][j] == player &&
          board[i + 2][j] == player && board[i + 3][j] == player)
        return true;
    }
  }

  for (int i = 0; i < CONNECT_4_SIZE - 3; i++) {
    for (int j = 0; j < CONNECT_4_SIZE - 3; j++) {
      if (board[i][j] == player && board[i + 1][j + 1] == player &&
          board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
        return true;
    }
  }

  for (int i = 0; i < CONNECT_4_SIZE - 3; i++) {
    for (int j = 3; j < CONNECT_4_SIZE; j++) {
      if (board[i][j] == player && board[i + 1][j - 1] == player &&
          board[i + 2][j - 2] == player && board[i + 3][j - 3] == player)
        return true;
    }
  }

  return false;
}

void play_connect_4() {
  // 0 = none, 1 = X, 2 = O
  int board[CONNECT_4_SIZE][CONNECT_4_SIZE] = {};

  int t = CONNECT_4_SIZE * CONNECT_4_SIZE;

  // true = player x's turn, false = player o's turn
  bool x_turn = true;

  cout << "Connect-4!\nPlayer 1 places X and player 2 places O.\n";

  while (t != 0) {
    int player = x_turn ? 1 : 2;
    char c = x_turn ? 'X' : 'O';

    print_board(board);
    cout << "It's player " << player << "'s turn!\n";
    cout << "Player " << player << " picks a column to place " << c << ": ";

    int col;
    cin >> col;
    col--;

    if (col < 0 || col > CONNECT_4_SIZE - 1) {
      cout << "Invalid move! You are only allowed to input between 1 and "
           << CONNECT_4_SIZE << ".\n";
      continue;
    }

    bool column_full = true;
    for (int i = 0; i < CONNECT_4_SIZE; i++) {
      if (board[i][col] == 0) {
        column_full = false;
        break;
      }
    }

    if (column_full) {
      cout << "Invalid move! Column is full!\n";
      continue;
    }

    int row = play_turn(board, col, x_turn);

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
