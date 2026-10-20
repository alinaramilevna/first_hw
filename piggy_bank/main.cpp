//
//  main.cpp
//  hw1_c
//
//  Created by user on 14.10.2026.
//
#include <cstring>
#include <iostream>

using namespace std;

void deposit(int &sum, int k) {
  if (k <= 0) {
    cout << "error" << endl;
  } else {
    sum += k;
  }
}

void withdraw(int &sum, int k) {
  if (k <= 0 || k > sum) {
    cout << "error" << endl;
  } else {
    sum -= k;
  }
}

void balance(int &sum, int) { cout << sum << endl; }

void reset(int &sum, int) { sum = 0; }

void doubleSum(int &sum, int) { sum *= 2; }

int main() {
  const char *commands[] = {"deposit", "withdraw", "balance", "reset",
                            "double"};

  void (*functions[])(int &, int) = {deposit, withdraw, balance, reset,
                                     doubleSum};

  const int n = 5;
  int sum = 0;
  char cmd[100];

  while (cin >> cmd) {
    if (strcmp(cmd, "stop") == 0) {
      break;
    }

    int k = 0;

    if (strcmp(cmd, "deposit") == 0 || strcmp(cmd, "withdraw") == 0) {
      if (!(cin >> k)) {
        break;
      }
    }

    cin.ignore(10000, '\n');

    int i = 0;

    while (i < n && strcmp(cmd, commands[i]) != 0) {
      i++;
    }

    if (i == n) {
      cout << "error" << endl;
    } else {
      functions[i](sum, k);
    }
  }

  return 0;
}
