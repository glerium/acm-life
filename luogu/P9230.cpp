#include<bits/stdc++.h>
using namespace std;

char pid;
int main() {
    cin >> pid;
    if(pid == 'A')
        puts("4430091");
    else
        puts("4165637");
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
int dig(int x) {
    int ct=0;
    while(x) {
        x/=10;
        ct++;
    }
    return ct;
}
bool test(int x, int k) {
    k/=2;
    int s1=0, s2=0;
    while(k--) {
        s1+=x%10;
        x/=10;
    }
    while(x) {
        s2+=x%10;
        x/=10;
    }
    // if(s1==s2) cout<<xx<<endl;
    return s1==s2;
}
int a[30];
int main() {
    int ans1=0;
    for(int i=1;i<=100000000;i++) ans1+=dig(i)%2==0&&test(i,dig(i));
    cout<<ans1<<endl;
    int ans2=0;
    ans2 = 1ll<<22;
    for(int i=0;i<(1<<22);i++) {
        for(int j=0;j<22;j++) a[j]=i&(1<<j);
        bool in=false;
        int ima=0;
        for(int j=0;j<22;j++) {
            if(a[j]) {
                if(in) {
                    ima++;
                    if(ima>=10) {
                        ans2--;
                        break;
                    }
                }else{
                    in=true;
                    ima=1;
                }
            }else{
                if(in) {
                    in=false;
                    ima=0;
                }
            }
        }
    }
    cout<<ans2<<endl;
    return 0;
}
*/