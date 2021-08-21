#include <bits/stdc++.h>
using namespace std;
int n, k;

int process(){
    queue<int> input;    
    int sum =0;
    int ret = 0;
    long long before = 1983;
    for(int i=0; i<n; i++){
        int x;
        if(i==0){
            x = 1984;
        }
        else{
            before = (long long)(before*214013 + 2531011)%(long long )pow(2, 32);
            x = before%10000 + 1;
        }
        sum += x;
        input.push(x);
        if(sum>k){
            while(sum>k){
                sum-=input.front();
                input.pop();
            }
        }

        if(sum==k){
            ret++;
            sum-=input.front();
            input.pop();    
        }
    }
    return ret;
}

int main(){    
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> k >> n;
        cout << process() << endl;
    }
}