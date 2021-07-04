#include <bits/stdc++.h>
using namespace std;

int cache[101][101];
int q = 10000000;

int poly_first(int n, int first) {
  int& c = cache[n][first];
  if (c != -1) return c;
  if (n == 1 || n == first) return c = 1;

  c = 0;
  for (int i = 1; i <= n - first; i++) {
    c += (first + i - 1) * poly_first(n - first, i);
    c %= q;
  }

  return c;
}

int poly(int n) {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += poly_first(n, i);
    res %= q;
  }
  return res;
}

int main() {
  int C, n;
  cin >> C;
  memset(cache, -1, sizeof(cache));

  for (int i = 0; i < C; i++) {
    cin >> n;
    cout << poly(n) << endl;
  }
}