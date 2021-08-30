#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

void original(){
    vector<int> origin;
    origin.resize(n);

    vector<int> s;
    for(int i=1; i<=n; i++){
        s.push_back(i);
    }

    for(int i=n-1; i>=0; i--){
        auto it = s.end();
        it--;   it-=v[i];
        origin[i] = *it;
        s.erase(it);
    }

    for(int i=0; i<n; i++){
        cout << origin[i] << " ";    
    }
    cout << endl;
}

int main(){    
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> n;
        v.resize(n);

        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        original();
    }
}