#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
struct treenode{
    int x, y, r;
    vector<treenode*> children;
};
int n;
treenode* fortress;

int isChildren(treenode* t1, treenode* t2){
    int x1 = t1->x; int y1 = t1->y; int r1 = t1->r;
    int x2 = t2->x; int y2 = t2->y; int r2 = t2->r;

    if((r1-r2)*(r1-r2) > (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)){
        if(r1>r2){
            return 1;
        }
        else{
            return 2;
        }
    }
    else{
        return 3;
    }
}

treenode* maketreenode(treenode* fortress, treenode* input){
    if(fortress->children.size() == 0){
        fortress->children.push_back(input);
        return fortress;
    }
    else{
        for(int i=0; i<fortress->children.size(); i++){
            int state = isChildren(fortress->children[i], input);
            if(state == 1){
                fortress->children[i] = maketreenode(fortress->children[i], input);
                return fortress;
            }
            else if(state == 2){
                input->children.push_back(fortress->children[i]);
                fortress->children[i] = input;
                return fortress;
            }
        }
        fortress->children.push_back(input);
        return fortress;
    }    
    return fortress;
}

int height(treenode* child){
    if(child->children.size()==0){
        return 1;
    }
    else{
        int h = 1;
        for(int i=0; i<child->children.size(); i++){
            h = max(h, height(child->children[i])+1);
        }
        return h;
    }
}

int calresult(treenode* t){
    int size = t->children.size();
    if(size == 0){
        return 0;
    }
    else if(size == 1){
        return max(calresult(t->children[0]), height(t->children[0]));
    }
    else{
        vector<int> result;
        for(int i=0; i<size; i++){
            result.push_back(height(t->children[i]));
        }
        sort(result.begin(), result.end());
        int ret = result[size-1]+result[size-2];
        for(int i=0; i<size; i++){
            ret = max(ret, calresult(t->children[i]));
        }
        return ret;
    }
    return 0;
}

int main(){
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        fortress = new treenode;
        cin >> n;
        cin >> fortress->x >> fortress->y >> fortress->r;
        for(int i=0; i<n-1; i++){
            treenode* input = new treenode;
            cin >> input->x >> input->y >> input->r;
            fortress = maketreenode(fortress, input);
        }
        cout << calresult(fortress) << endl;
        
    }
}