#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n;
map<vector<int>, int> vdistance;
vector<int> list;

void precal(int n){
    vector<int> v(n);
    for(int i=0; i<n; i++){
        v[i] = i;
    }

    queue<vector<int>> q;
    q.push(v);
    vdistance[v] = 0;

    while(!q.empty()){
        vector<int> here = q.front();
        q.pop();
        int d = vdistance[here];

        for(int i=0; i<n-1; i++){
            for(int j=2; j<n+1; j++){
                reverse(here.begin()+i, here.begin()+j);
                if(vdistance.count(here)==0){
                    q.push(here);
                    vdistance[here] = d+1;
                }
                reverse(here.begin()+i, here.begin()+j);
            }
        }
    }
}

void makelist(){   
    int k=0;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        int findmin = 987654321;
        int index = 0;
        for(int j=0; j<n; j++){
            if(findmin>list[j] && !visited[j]){
                index = j;
                findmin = list[j];
            }
        }
        list[index] = k++;
        visited[index] = true;
    }
}

int main(){
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> n;
        for(int i=0; i<n; i++){
            int k;  cin >> k;
            list.push_back(k);
        }
        makelist();
        precal(n);
        cout << vdistance[list] << endl;
        list.clear();
    }
}