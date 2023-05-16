#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int first, n;
struct Node {
    int adr;
    int val;
    int nxt;
}a[maxn], b[maxn];
map<int,int> mp;    //address -> index
int main() {
    scanf("%d%d",&first,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].adr, &a[i].val, &a[i].nxt);
        mp.insert(make_pair(a[i].adr, i));
    }
    int ima=first;
    for(int i=1;i<=n;i++){
        b[i] = a[mp[ima]];
        ima = b[i].nxt;
    }
    int ct=0;
    for(int i=n;ct<=n;i--) {
        int ii=n+1-i, iii=i-1;
        if(ct==n-1){
            printf("%05d %d -1\n", b[i].adr, b[i].val);
            break;
        }
        else printf("%05d %d %05d\n", b[i].adr, b[i].val, b[ii].adr);
        ct++;

        if(ct==n-1) {
            printf("%05d %d -1\n", b[ii].adr, b[ii].val);
            break;
        }
        else printf("%05d %d %05d\n", b[ii].adr, b[ii].val, b[iii].adr);
        ct++;
    }
    return 0;
}
