#include <bits/stdc++.h>
using namespace std;

int cache[101];

int poly(int n) {
  int& c = cache[n];
  if (c != -1) return c;
  if (n == 0) return c = 0;
  if (n == 1) return c = 1;

  
}

int main() {
  int C, n;
  cin >> C;
  memset(cache, -1, sizeof(cache));

  for (int i = 0; i < C; i++) {
    cin >> n;
  }
}