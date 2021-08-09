#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, root;

vector<int> slice(vector<int> v, int start, int end){
    return vector<int>(v.begin()+start, v.begin()+end);
}

void postorder(vector<int> pre, vector<int> in){
    int size = pre.size();
    if(size == 0){
        return;
    }
    int index;
    for(int i=0; i<size; i++){
        if(in[i] == pre[0]){
            index = i;
        }
    }

    postorder(slice(pre, 1, 1+index), slice(in, 0, index));
    postorder(slice(pre, index+1, size), slice(in, index+1, size));

    cout << pre[0] << " ";
}

int main(){
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> n;

        vector<int> preorder, inorder;
        for(int i=0; i<n; i++){
            int k;  cin >> k; preorder.push_back(k);
        }
        for(int i=0; i<n; i++){
            int k;  cin >> k; inorder.push_back(k);
        }

        postorder(preorder, inorder);
        cout << endl;
    }
}