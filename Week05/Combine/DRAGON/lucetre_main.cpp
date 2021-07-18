/*
+FX+YF => +FX+YF+FX-YF
     0 =>      0     1
+FX-YF => +FX+YF-FX-YF
     1 =>      0     3
-FX+YF => -FX+YF+FX-YF
     2 =>      2     1
-FX-YF => -FX+YF-FX-YF
     3 =>      2     3

0        : +FX+YF
01       : +FX+YF+FX-YF
0103     : +FX+YF+FX-YF+FX+YF-FX-YF
01030123 : +FX+YF+FX-YF+FX+YF-FX-YF+FX+YF+FX-YF-FX+YF-FX-YF

0103012301032123
0103012321032123
        *
01030123010321230103012321032123
01030123010321232103012321032123
                *

0103012301032123010301232103212301030123010321232103012321032123
0103012301032123010301232103212321030123010321232103012321032123
                                *
*/

/*
string dragon1(int k) {
    if (k == 1) return "0";
    string s = "";
    string p = dragon1(k-1);
    for (auto c: p) {
        switch (c) {
            case '0': s += "01"; break;
            case '1': s += "03"; break;
            case '2': s += "21"; break;
            case '3': s += "23"; break;
        }
    }
    return s;
}

string dragon(int k) {
    if (k <= 3) return "0103";
    string s1 = dragon(k-1);
    string s2 = s1;
    s2[1<<(k-3)] = '2';
    return s1 + s2;
}
*/

#include <bits/stdc++.h>
#define INF 1000000000
#define L 50
using namespace std;
int n, p, l;
int length[L+1];

const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

char expand(const string& dragonCurve, int generations, int skip) {
	if (generations == 0)
		return dragonCurve[skip];

	for (int i = 0; i < dragonCurve.size(); ++i)
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y')
			if (skip >= length[generations])
				skip -= length[generations];
			else if (dragonCurve[i] == 'X')
				return expand(EXPAND_X, generations - 1, skip);
			else
				return expand(EXPAND_Y, generations - 1, skip);
		else if (skip > 0)
			skip--;
		else
    		return dragonCurve[i];
}

int main() {
	length[0] = 1;
	for (int i = 1; i <= L; i++)
		length[i] = min(INF, 2 * length[i - 1] + 2);

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> p >> l;
        string s = "FX";
        for (int skip = p-1; skip < p+l-1; skip++) {
            char temp = expand(s, n, skip);
            cout << temp;
        }
        cout << endl;
    }
    return 0;
}