#include <bits/stdc++.h>
using namespace std;

int buf[200001];
vector<int> mv, fv;

int karatsuba() {
    /* Initial variables */
    int z0[100001], z2[100001], z1[100001];
    memset(z0, 0, 100001); memset(z2, 0, 100001);
    int mv_mid = mv.size() / 2;
    int fv_mid = fv.size() / 2;
    vector<int> mv_1(mv.begin(), mv.begin() + mv_mid);
    vector<int> mv_2(mv.begin() + mv_mid, mv.end());
    vector<int> fv_1(fv.begin(), fv.begin() + fv_mid);
    vector<int> fv_2(fv.begin() + fv_mid, fv.end());

    /* Find z0 */
    for(int i = 0; i < mv_1.size(); i++) {
        for(int j = 0; j < fv_1.size(); j++) {
            z0[i+j] += mv_1[i] & fv_1[j];
        }
    }
    // print z0
    printf("z0 : ");
    for(int i = 0; i < mv_1.size() + fv_1.size(); i++) {
        printf("%d", z0[i]);
    }
    printf("\n");

    /* Find z2 */
    for(int i = 0; i < mv_2.size(); i++) {
        for(int j = 0; j < fv_2.size(); j++) {
            z2[i+j] += mv_2[i] & fv_2[j];
        }
    }
    // print z2
    printf("z2 : ");
    for(int i = 0; i < mv_2.size() + fv_2.size(); i++) {
        printf("%d", z2[i]);
    }
    printf("\n");

    /* Find z1 */
    int z1_0[max(mv_1.size(), mv_2.size())];
    int z1_1[max(fv_1.size(), fv_2.size())];
    memset(z1_0, 0, max(mv_1.size(), mv_2.size())); 
    memset(z1_1, 0, max(fv_1.size(), fv_2.size()));

    for(int i = 0; i < mv_1.size(); i++) z1_0[i] += mv_1[i]; 
    for(int i = 0; i < mv_2.size(); i++) z1_0[i] += mv_2[i]; 
    for(int i = 0; i < fv_1.size(); i++) z1_1[i] += fv_1[i]; 
    for(int i = 0; i < fv_2.size(); i++) z1_1[i] += fv_2[i]; 
    for(int i = 0; i < max(mv_1.size(), mv_2.size()); i++) {
        for(int j = 0; j < max(fv_1.size(), fv_2.size()); j++) {
            z1[i+j] += z1_0[i] & z1_1[j];
        }
    }
    // print z1
    printf("z1 : ");
    for(int i = 0; i < max(mv_1.size(), mv_2.size()) + max(fv_1.size(), fv_2.size()); i++) {
        printf("%d", z1[i]);
    }
    printf("\n");


    return 0;
}

int solve() {
    int ret = 0;
    karatsuba();
    for(int i = mv.size()-1; i < fv.size(); i++) {
        ret += buf[i]; 
    }
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        printf("iter : %d\n", t);
        mv.clear(); fv.clear();
        string m, f;
        cin >> m; cin >> f;
        for(int i = 0; i < m.size(); i++) 
            mv.push_back(m[i] == 'M' ? 1 : 0);
        for(int i = 0; i < f.size(); i++) 
            fv.push_back(f[f.size()-1-i] == 'M' ? 1 : 0);

        printf("%d\n", solve());
        
    }
    return 0;
}