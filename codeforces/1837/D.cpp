#include <bits/stdc++.h>
using namespace std;
int t,n;
bool red[200007];
char s[200007];
int main(){
    cin>>t;
    while(t--){
        cin>>n>>s+1;
        if(n&1) {
            cout<<-1<<endl;
            continue;
        }
        int ct1=0,ct2=0;
        for(int i=1;i<=n;i++) {
            if(s[i]==')') ct1++;
            else ct2++;
        }
        if(ct1^ct2) {
            puts("-1");
            continue;
        }

        int left=0;
        bool fail=false;
        for(int i=1;i<=n;i++) {
            if(s[i]=='(') left++;
            else if(left>0) left--;
            else {
                fail=true;
                break;
            }
        }
        if(!fail) {
            puts("1");
            for(int i=1;i<=n;i++) printf("1 ");
            puts("");
            continue;
        }

        fail=false;
        left=0;
        for(int i=1;i<=n;i++) {
            if(s[i]==')') left++;
            else if(left>0) left--;
            else {
                fail=true;
                break;
            }
        }
        if(!fail) {
            puts("1");
            for(int i=1;i<=n;i++) printf("1 ");
            puts("");
            continue;
        }

        left=0;
        for(int i=1;i<=n;i++) {
            if(s[i]=='(') left++, red[i]=1;
            else if(left>0) {
                left--;
                red[i]=1;
            } else red[i]=0;
        }
        for(int i=n;i>=1;i--) {
            if(red[i]&&s[i]=='(') {
                red[i]=0;
                continue;
            }
            break;
        }
        
        left=0;
        for(int i=1;i<=n;i++) red[i]=0;
        for(int l=1,r=n;l<=r;) {
            if(s[l]=='(') left++;
            else left--;
            if(left<0) {
                red[l]=1;
                while(s[r]!='(') r--;
                red[r]=1;
                left++;
                r--;
            }
            l++;
        }
        puts("2 ");
        for(int i=1;i<=n;i++) {
            if(red[i]) printf("1 ");
            else printf("2 ");
        }
        putchar('\n');
    }
    return 0;
}