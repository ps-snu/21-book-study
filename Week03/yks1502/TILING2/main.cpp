#include <bits/stdc++.h>
using namespace std;

long long cache[101];
long long q = 1000000007;

long long tile(int n) {
  long long& c = cache[n];
  if (c != -1) return c;

  if (n == 0) return c = 1;
  if (n == 1) return c = 1;

  return c = (tile(n - 1) + tile(n - 2)) % q;
}

int main() {
  freopen("input.txt", "r", stdin);
  int C, n;
  cin >> C;
  memset(cache, -1, sizeof(cache));

  for (int i = 0; i < C; i++) {
    cin >> n;
    long long res = tile(n);
    cout << res << endl;
  }
}