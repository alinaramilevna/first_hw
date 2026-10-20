//
//  main.cpp
//  hw1_c
//
//  Created by user on 14.10.2026.
//

#include <iostream>
#include <cstring>

using namespace std;

const int ROWS = 5;
const int COLS = 10;

void Clear(char board[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i][j] = ' ';
    }
  }
}

bool Put(char board[ROWS][COLS], int x, int y, char c) {
  if (x < 0 || x >= COLS || y < 0 || y >= ROWS) {
    return false;
  }

  board[y][x] = c;
  return true;
}

bool Text(char board[ROWS][COLS], int x, int y, char word[]) {
  int len = strlen(word);

  if (y < 0 || y >= ROWS || x < 0 || x + len > COLS) {
    return false;
  }

  for (int i = 0; i < len; i++) {
    board[y][x + i] = word[i];
  }

  return true;
}

void Print(char board[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << board[i][j];
    }
    cout << '\n';
  }
}

int main() {
  char board[ROWS][COLS];
  char command[20];
  char word[1000];
  int x, y;
  char c;

  Clear(board);

  while (cin >> command) {
    if (strcmp(command, "clear") == 0) {
      Clear(board);
    } else if (strcmp(command, "put") == 0) {
      cin >> x >> y >> c;

      if (!Put(board, x, y, c)) {
        cout << "error\n";
      }
    } else if (strcmp(command, "text") == 0) {
      cin >> x >> y >> word;

      if (!Text(board, x, y, word)) {
        cout << "error\n";
      }
    } else if (strcmp(command, "print") == 0) {
      Print(board);
    } else if (strcmp(command, "quit") == 0) {
      break;
    }
  }

  return 0;
}
