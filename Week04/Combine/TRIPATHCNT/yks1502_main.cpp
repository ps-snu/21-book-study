#include <bits/stdc++.h>
using namespace std;

int n;
int tri[100][100];
int cache[100][100][2];

int maxTri(int r, int c) {
  int& ca = cache[r][c][0];
  if (ca != -1) return ca;
  if (r == n - 1) {
    cache[r][c][1] = 1;
    return ca = tri[r][c];
  }

  for (int i = 0; i < 2; i++) {
    if (ca < tri[r][c] + maxTri(r + 1, c + i)) {
      ca = tri[r][c] + maxTri(r + 1, c + i);
      cache[r][c][1] = cache[r + 1][c + i][1];
    } else if (ca == tri[r][c] + maxTri(r + 1, c + i)) {
      cache[r][c][1] += cache[r + 1][c + i][1];
    }
  }

  return ca;
}

int main() {
  int C;
  cin >> C;

  for (int i = 0; i < C; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < j + 1; k++) {
        cin >> tri[j][k];
      }
    }

    memset(cache, -1, sizeof(cache));
    maxTri(0, 0);
    cout << cache[0][0][1] << endl;
  }
}