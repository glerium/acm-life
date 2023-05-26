#include <bits/stdc++.h>
using namespace std;
int t,ct;
string s;
struct Note{
    int i;
    char s;
}a[1000000];
int main(){
    cin>>t;
    while(t--) {
        cin>>s;
        string ans;
        ct=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='0'){
                a[++ct]=(Note){i,s[i]};
            }else if(s[i]=='1'){
                a[++ct]=(Note){i,s[i]};
            }
        }
        if(ct==0) {
            for(int i=0;i<s.length();i++) {
                putchar('0');
            }
            putchar('\n');
            continue;
        }
        if(a[1].i!=0) {
            for(int i=0;i<a[1].i;i++) putchar('0');
        }
        for(int i=1;i<ct;i++) {
            putchar(a[i].s);
            if(a[i].s==a[i+1].s) {
                for(int j=1;j<=a[i+1].i-a[i].i-1;j++) putchar(a[i].s);
            }else{
                for(int j=1;j<=a[i+1].i-a[i].i-1;j++) putchar('0');
            }
        }
        putchar(a[ct].s);
        if(a[ct].i!=s.length()-1) {
            for(int j=a[ct].i;j<s.length()-1;j++) putchar('1');
        }
        putchar('\n');
    }
    return 0;
}