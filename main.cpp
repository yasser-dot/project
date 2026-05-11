#include "connect-4.hpp"
#include "tic-tac-toe.hpp"
#include <iostream>
using namespace std;

int main() {
  int ni;
  cout << "If you want to play X/O press 1" << endl;
  cout << "If you want to play Connect_4 press 2" << endl;
  cin >> ni;
  if (ni == 2) {
    play_connect_4();
  } else if (ni == 1) {
    play_tic_tac_toe();
  } else {
    cout << "Invalid Input" << endl;
  }
}
