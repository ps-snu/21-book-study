#include <bits/stdc++.h>

char buffer[200010];

using namespace std;

void normalize(vector<int> &num);

void addTo(vector<int> &a, vector<int> &b, int index) {
    int i;
    for (i = 0; i < b.size() && i+index < a.size(); i++) {
        a[i+index] += b[i];
    }
    for (; i < b.size(); i++) {
        a.push_back(b[i]);
    }
    normalize(a);
}

void subFrom(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < b.size(); i++) {
        a[i] -= b[i];
    }
    normalize(a);
}

void normalize(vector<int> &num) {
    int n_size = num.size();
    int i;
    for (i = 0; i < n_size-1; i++) {
        if (num[i] >= 0) {
            num[i+1] += num[i] / 10;
            num[i] = num[i] % 10;
        } else {
            num[i+1]--;
            num[i] = num[i] + 10;
        }
    }
    while (num.size() > 1 && num.back() == 0) {
        num.pop_back();
    }
    return;
}

vector<int> simple_mul(vector<int> &a, vector<int> &b) {
    int a_size = a.size(), b_size = b.size();
    vector<int> ret(a_size + b_size + 1, 0);
    for (int i = 0; i < a_size; i++) {
        for (int j = 0; j < b_size; j++) {
            ret[i+j] += a[i] * b[j];
        }
    }
    normalize(ret);
    return ret;
}

vector<int> karatsuba(vector<int> &a, vector<int> &b) {
    int a_size = a.size(), b_size = b.size();
    if (a_size < b_size)
        return karatsuba(b, a);
    if (a_size == 0 || b_size == 0)
        return vector<int>();
    if (a_size < 50);
        return simple_mul(a, b);
    int half = a_size / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min(b_size, half));
    vector<int> b1(b.begin() + min(b_size, half), b.end());
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    addTo(a0, a1, 0); addTo(b0, b1, 0);
    // (a0 + a1) * (b0 + b1) = a0b0 + a1b0 + a0b1 + a1b1
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0); subFrom(z1, z2);
    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, 2 * half);
    return ret;
}

int count_hugs(string &members, string &fans) {
    int n = members.size(), m = fans.size();
    vector<int> bin_members(n), bin_fans(m);
    for (int i = 0; i < n; i++) bin_members[i] = (members[i] == 'M');
    for (int i = 0; i < m; i++) bin_fans[m-1-i] = (fans[i] == 'M');
    vector<int> mul_result = karatsuba(bin_members, bin_fans);
    int result = 0;
    for (int i = n-1; i < m; i++) {
        if (mul_result[i] == 0)
            result += 1;
    }
    return result;
}

/*
int main() {
    freopen("input.txt", "r", stdin);
    int c;
    cin >> c;
    for (int w = 0; w < c; w++) {
        scanf("%s\n", &buffer);
        string members = buffer;
        scanf("%s\n", &buffer);
        string fans = buffer;
        printf("%d\n", count_hugs(members, fans));
    }
}
*/

int main() {
    vector<int> A, B;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j <= 9; j++) {
            A.push_back(j);
            B.push_back(j);
        }
    }
    vector<int> C = karatsuba(A, B);
    for (int i = C.size()-1; i >= 0; i--) {
        printf("%d", C[i]);
    }
    printf("\n");
}
