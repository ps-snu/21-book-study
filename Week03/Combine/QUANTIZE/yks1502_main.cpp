#include <bits/stdc++.h>
using namespace std;

int N, S;
int num[100];
int cache[100][11];
int sum[100];
int sum_sq[100];

int err_sq(int a, int b) {
  int s = sum[b] - (a == 0 ? 0 : sum[a - 1]);
  int s_sq = sum_sq[b] - (a == 0 ? 0 : sum_sq[a - 1]);
  int m = int(0.5 + (double) s / (b - a + 1));
  return (b - a + 1) * m * m - 2 * s * m + s_sq;
}

int quantize(int idx, int left) {
  int& c = cache[idx][left];
  if (c != -1) return c;
  if (idx + left >= N) return c = 0;
  if (left == 0) return c = 100000000;

  c = 100000000;

  for (int i = idx; i < N; i++) {
    c = min(c, err_sq(idx, i) + quantize(i + 1, left - 1));
  }

  return c;
}

int main() {
  freopen("input.txt", "r", stdin);
  int C;
  cin >> C;

  for (int i = 0; i < C; i++) {
    cin >> N >> S;
    for (int j = 0; j < N; j++) {
      cin >> num[j];
    }
    sort(num, num + N);
    memset(cache, -1, sizeof(cache));
    sum[0] = num[0];
    sum_sq[0] = num[0] * num[0];
    for (int j = 1; j < N; j++) {
      sum[j] = sum[j - 1] + num[j];
      sum_sq[j] = sum_sq[j - 1] + num[j] * num[j];
    }

    int res = 100000000;
    for (int j = 1; j <= S; j++) {
      res = min(res, quantize(0, j));
    }

    cout << res << endl;
  }
}