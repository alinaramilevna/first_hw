//
//  main.cpp
//  hw1_c
//
//  Created by user on 05.10.2026.
//

#include <iomanip>
#include <iostream>

double Average(const int *temperatures, int n) {
  double s = 0;

  for (int i = 0; i < n; i++) {
    s += temperatures[i];
  }

  return s / n;
}

int ColdestCount(const int *temperatures, int n) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (temperatures[i] < 0)
      cnt++;
  }
  return cnt;
}

void SetMinMaxTemperature(const int *temperatures, int n, int &min_t,
                          int &max_t) {
  for (int i = 0; i < n; i++) {
    if (temperatures[i] < min_t)
      min_t = temperatures[i];
    if (temperatures[i] > max_t)
      max_t = temperatures[i];
  }
}

int main1(int argc, const char *argv[]) {
  std::cout << std::fixed << std::setprecision(1);

  int n;
  std::cin >> n;

  int *temperatures = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> temperatures[i];
  }

  int min_t = temperatures[0];
  int max_t = temperatures[0];

  std::cout << Average(temperatures, n) << '\n';
  SetMinMaxTemperature(temperatures, n, min_t, max_t);
  std::cout << min_t << ' ' << max_t << '\n';
  std::cout << ColdestCount(temperatures, n) << '\n';

  delete[] temperatures;
  return 0;
}
