#include <bits/stdc++.h>
using namespace std;

int n, m;
double cache[1001][1001];

double canEscape(int d, int r) {
  double& c = cache[d][r];
  if (c != -1.0) return c;
  if (r == 0 && d == 0) return c = 1.0;
  if (r == 0) return c = 0.0;
  if (d == 0) return c = 1.0;
  if (d == 1) return c = 1.0;

  return c = 0.75 * canEscape(d - 2, r - 1) + 0.25 * canEscape(d - 1, r - 1);
}

int main() {
  int C;
  cin >> C;
  for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
      cache[i][j] = -1.0;
    }
  }

  for (int i = 0; i < C; i++) {
    cin >> n >> m;
    printf("%.10f\n", canEscape(n, m));
  }
}