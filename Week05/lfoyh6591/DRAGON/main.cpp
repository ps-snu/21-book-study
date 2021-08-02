#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, p, l;
long long memolength[50];
long long skiplength(int);
char expand(const string&, int, int);
int main(){
    int C;
    cin >> C;
    memset(memolength, -1, sizeof(memolength));
    for(int c=0; c<C; c++){
        cin >> n;
        cin >> p;
        cin >> l;
        for(int i=p-1; i<p+l-1; i++){
            cout << expand("FX", n, i);
        }
        cout << endl;
    }
}

long long skiplength(int generation){
    if(generation == 0){
        memolength[0] = 1;
    }
    if(memolength[generation]!=-1){
        return memolength[generation];
    }
    long long& ret = memolength[generation];
    ret = 2*skiplength(generation-1) + 2;
    return ret;
}

char expand(const string& dragon, int generation, int skip){
    if(generation == 0){
        return dragon[skip];
    }

    for(int i=0; i<dragon.size(); i++){
        if(dragon[i] == 'X' || dragon[i] == 'Y'){
            if(skip >= skiplength(generation)){
                skip-=skiplength(generation);
            }
            else{
                if(dragon[i] == 'X'){
                    return expand("X+YF", generation-1, skip);
                }
                else{
                    return expand("FX-Y", generation-1, skip);
                }
            }
        }
        else{
            if(skip == 0){
                return dragon[i];
            }
            skip--;
        }
    }
    return '0';
}