#include <bits/stdc++.h>
#define MAX_SIZE 32

using namespace std;

int cur = -1;

// void decompress(char* c, int size, int y, int x) {
//     cur += 1;

//     if (c[cur] == 'b' || c[cur] == 'w') {
//         for(int i = 0; i < size; i++) {
//             for(int j = 0; j < size; j++) {
//                 decomped[y+i][x+j] = c[cur];
//             }
//         }
//     }
//     else {
//         decompress(c, size/2, y, x);
//         decompress(c, size/2, y, x + size/2);
//         decompress(c, size/2, y + size/2, x);
//         decompress(c, size/2, y + size/2, x + size/2);
//     }
// }

// void compress(int size, int y, int x) {
//     char f = decomped[y][x];
//     bool comp_ok = true;

//     for(int i = 0; i < size; i++) {
//         for(int j = 0; j < size; j++) {
//             if(f != decomped[y+i][x+j]) {
//                 comp_ok = false; break;
//             }
//         }
//     }

//     if(comp_ok) {
//         comped.push_back(f);
//     }
//     else {
//         comped.push_back('x');
//         compress(size/2, y, x);
//         compress(size/2, y, x+size/2);
//         compress(size/2, y+size/2, x);
//         compress(size/2, y+size/2, x+size/2);
//     }
// }

// void p_decomp() {
//     for(int i = 0; i < MAX_SIZE; i++) {
//         for(int j = 0; j < MAX_SIZE; j++) {
//             printf("%c", decomped[i][j]);
//         }
//         printf("\n");
//     }
// }

// void p_comp() {
//     for(int i = 0; i < comped.size(); i++) {
//         printf("%c", comped[i]);
//     }
//     printf("\n");
// }

string reverse(char* c) {
    cur += 1;
    
    if(c[cur] == 'w' || c[cur] == 'b') {
        return string(1, c[cur]);
    }
    string ul = reverse(c);
    string ur = reverse(c);
    string dl = reverse(c);
    string dr = reverse(c);

    return string("x") + dl + dr + ul + ur;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cur = -1;
        char c[1000]; cin >> c;
        string res = reverse(c);
        printf("%s\n",res.c_str());
    }
    return 0;
}