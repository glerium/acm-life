#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
const int maxn=1e6+10;
int _,n,a[maxn];
int gcd(int x,int y) {
    return !y?x:gcd(y,x%y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>_;
    while(_--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        int f=0;
        int ct=1,s=1,gg;
        rep(i,1,n) {
            if(a[i]==1) {
                ct++;
                s++;
            }
            else if(a[i]==-1) {
                if(ct<=1) {
                    if(f>0) {
                        f--;
                        ct+=2;
                        s++;
                    }
                    else {
                        cout<<-1<<endl;
                        goto end;
                    }
                }
                ct--;
            }
            else {
                if(ct>1) {
                    f++;
                    ct--;
                }else{
                    ct++;
                    s++;
                }
            }
        }
        gg=gcd(ct,s);
        ct/=gg, s/=gg;
        cout<<s<<" "<<ct<<endl;
    end:;
    }
    return 0;
}