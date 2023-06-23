#include <bits/stdc++.h>
using namespace std;
int m,n,q[100005],tail=1,head=1;
int main() {
    cin>>m>>n;
    for(int i=1;i<=n;i++) {
        int x; cin>>x;
        bool found=false;
        for(int j=tail;j<head;j++) {
            if(q[j]==x) {
                found=true;
                break;
            }
        }
        if(!found) {
            if(head-tail>=m) tail++;
            q[head++]=x;
        }
    }
    cout<<head-1<<endl;
    return 0;
}