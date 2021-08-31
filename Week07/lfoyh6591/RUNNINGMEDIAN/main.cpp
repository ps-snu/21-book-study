#include <bits/stdc++.h>
using namespace std;
#define MOD 20090711
int n, a, b;

int process(){
    priority_queue<int> front;
    priority_queue<int, vector<int>, greater<int>> back;

    long long num = 1983;
    int fsize=1;    int bsize=0;
    long long sum=1983;

    front.push(1983);

    for(int i=0; i<n-1; i++){
        int nextnum = (int)((num*a+b)%MOD);
        if(fsize==bsize){
            if(nextnum>front.top()){
                back.push(nextnum);
                front.push(back.top());
                back.pop();
            }
            else{
                front.push(nextnum);
            }
            fsize++;
        }
        else{
            if(nextnum>front.top()){
                back.push(nextnum);
            }
            else{
                front.push(nextnum);
                back.push(front.top());
                front.pop();
            }
            bsize++;
        }

        num = nextnum;
        sum+=front.top();
        sum%=MOD;
    }
    return sum;

}

int main(){    
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> n >> a >> b;
        cout << process() << endl;
    }
}