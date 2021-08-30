#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> nerd;

int newnerd(int p, int q){
    auto it = nerd.lower_bound(p);

    if(it!=nerd.end() && q<it->second){
        return nerd.size();
    }

    if(it!=nerd.begin()){
        it--;
    }
    else{
        nerd[p] = q;
        return nerd.size();
    }
    
    while(q>it->second){
        if(it == nerd.begin()){
            nerd.erase(it);
            break;
        }
        else{
            nerd.erase(it--);
        }
    }
    nerd[p] = q;
    return nerd.size();
}

int main(){    
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> n;

        int sum = 0;
        for(int i=0; i<n; i++){
            int p, q;   cin >> p >> q;
            sum+=newnerd(p, q);
        }
        cout << sum << endl;
        nerd.clear();
    }
}