#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if(x<2) return false;
    if(x==2) return true;
    for(int i=2;i*i<=x;i++) {
        if(x%i==0)
            return false;
    }
    return true;
}
int main() {
    int n; cin>>n;
    vector<int> a(n+10);
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1) {
        cout<<1<<endl;
        return 0;
    }
    if(n==2) {
        cout<<"2 1"<<endl;
        return 0;
    }
    if(n%2==0) {
        if(isprime(1+n)) {
            for(int i=n;i>=1;i--) {
                cout<<i<<' ';
            }
            cout<<endl;
            return 0;
        }
        int target=-1;
        for(int i=2;i<=n;i+=2) {
            if(isprime(1+i)&&isprime(i+1+n)) {
                target=i;
                break;
            }
        }
        if(target==-1) {
            cout<<-1<<endl;
        }else{
            for(int i=target;i>=1;i--) cout<<i<<' ';
            for(int i=n;i>=target+1;i--) cout<<i<<' ';
            cout<<endl;
        }
    }else {
        cout<<"1 ";
        if(isprime(2+n)) {
            for(int i=n;i>=2;i--) cout<<i<<' ';
            cout<<endl;
        }else{
            int target=-1;
            for(int i=3;i<=n;i+=2) {
                if(isprime(2+i)&&isprime(i+1+n)) {
                    target=i;
                    break;
                }
            }
            if(target==-1) {
                cout<<-1<<endl;
            }else{
                for(int i=target;i>=2;i--) cout<<i<<' ';
                for(int i=n;i>=target+1;i--) cout<<i<<' ';
                cout<<endl;
            }
        }
    }
}