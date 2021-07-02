#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool find(int r, int c, string& word, int idx);

string board[5];
const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int C, N;
    cin >> C;


    for (int i = 0; i < C; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[j];
        }

        cin >> N;
        for (int j = 0; j < N; j++) {
            string word;
            bool result = false;
            cin >> word;

            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    result = find(r, c, word, 0);
                    if (result) break;
                }
                if (result) break;
            }

            cout << word << " ";
            if (result)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}

bool find(int r, int c, string& word, int idx) {
    if (r < 0 || c < 0 || r == 5 || c == 5) return false;
    if (board[r][c] != word[idx]) return false;
    if (word.length() == idx + 1) return true;

    for (int i = 0; i < 8; i++) {
        int new_r = r + dr[i];
        int new_c = c + dc[i];
        bool found = find(new_r, new_c, word, idx + 1);
        if (found) return true;
    }
    return false;
}
