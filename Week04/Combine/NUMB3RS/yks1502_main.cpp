#include <bits/stdc++.h>
using namespace std;

int C, n, d, p, t, q;
int A[50][50], nbh[50];
double prob[50][101];

double calcProb(int town, int day) {
  double& c = prob[town][day];
  if (c != -1.0) return c;
  if (day == 0 && town == p) return c = 1.0;
  c = 0.0;
  if (day == 0) return c;

  for (int i = 0; i < n; i++) {
    if (A[town][i]) {
      c += ((double) 1 / nbh[i]) * calcProb(i, day - 1);
    }
  }

  return c;
}

int main() {
  cin >> C;

  for (int i = 0; i < C; i++) {
    fill_n(&prob[0][0], 50 * 101, -1.0);
    memset(nbh, 0, sizeof(nbh));

    cin >> n >> d >> p;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        cin >> A[r][c];
        if (A[r][c]) nbh[r]++;
      }
    }
    cin >> t;
    for (int j = 0; j < t; j++) {
      cin >> q;
      printf("%.8f\n", calcProb(q, d));
    }
  }
}