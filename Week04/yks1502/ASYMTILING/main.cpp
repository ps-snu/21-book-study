#include <bits/stdc++.h>
using namespace std;

long long cache[101], cache1[101], cache2[101];
long long q = 1000000007;

long long tile(int n) {
  long long & c1 = cache1[n];
  if (c1 != -1) return c1;
  long long & c = cache[n];
  long long & c2 = cache2[n];

  if (n == 0) {
    c = 0;
    c2 = 1;
    return c1 = 1;
  }

  if (n == 1) {
    c = 0;
    c2 = 1;
    return c1 = 1;
  }

  c1 = (tile(n - 1) + tile(n - 2)) % q;
  if (n % 2) {
    c2 = tile(n / 2) % q;
  } else {
    c2 = (tile(n / 2) + tile(n / 2 - 1)) % q;
  }
  c = c1 - c2;
  if (c < 0) c += q;
  return c1;
}

int main() {
  int C;
  cin >> C;
  memset(cache, -1, sizeof(cache));
  memset(cache1, -1, sizeof(cache1));
  memset(cache2, -1, sizeof(cache2));
  tile(100);

  for (int i = 0; i < C; i++) {
    int n;
    cin >> n;
    cout << cache[n] << endl;
  }
}