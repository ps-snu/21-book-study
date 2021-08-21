#include <bits/stdc++.h>
using namespace std;
int n, k;

int main(){    
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> n >> k;
        vector<int> v;
        for(int i=0; i<n-1; i++){
            v.push_back(i+2);
        }
        n--;
        auto it = v.begin();
        while(n>2){
            int r = (k-1)%n;
            for(int i=0; i<r; i++){
                it++;
                if(it==v.end())     it = v.begin();
            }
            v.erase(it);
            if(it==v.end()){
                it=v.begin();
            }
            n--;
        }
        for(auto it=v.begin(); it!=v.end(); it++){
            cout << *it << endl;
        }
    }
}