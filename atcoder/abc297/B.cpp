#include <bits/stdc++.h>
using namespace std;
char s[100];
int main() {
    cin>>s+1;
    bool yes=true;
    for(int i=1;i<=8;i++) {
        for(int j=i+1;j<=8;j++) {
            if(s[i]=='B'&&s[j]=='B'){
                if(!((i&1)^(j&1))) {
                    yes=false;
                    goto end;
                }
            }
        }
    }
    for(int i=1;i<=8;i++) {
        for(int j=i+1;j<=8;j++){
            if(i==j) continue;
            for(int k=1;k<=8;k++) {
                if(i==k||k==j) continue;
                if(s[i]=='R'&&s[j]=='R'&&s[k]=='K'){
                    if(!(i<k&&k<j)) {
                        yes=false;
                        goto end;
                    }
                }
            }
        }
    }
end:
    cout<<(yes?"Yes":"No")<<endl;
    return 0;
}