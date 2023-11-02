#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> fa;
    dsu(int size) {
        fa.resize(size);
        for(int i=1;i<=size;i++) {
            fa[i]=i;
        }
    }

    int find(int x) {
        if(fa[x]==x) return x;
        else return fa[x]=find(x);
    }
};
int main() {

}