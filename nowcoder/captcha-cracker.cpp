#include <bits/stdc++.h>
using namespace std;
int n,ct;
char s[100017],t[100017];
map<string,string> mp;
int main() {
    cin>>n;
    while(n--) {
        cin>>(s+1);
        ct=0;
        int m=strlen(s+1);
        for(int i=1;i<=m;i++) {
            if(s[i]=='0'||s[i]=='2'||s[i]=='4'||s[i]=='6'||s[i]=='9') 
                t[++ct]=s[i];
            else if(s[i]=='z'&&s[i+1]=='e'&&s[i+2]=='r'&&s[i+3]=='o')
                t[++ct]='0';
            else if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')
                t[++ct]='2';
            else if(s[i]=='f'&&s[i+1]=='o'&&s[i+2]=='u'&&s[i+3]=='r')
                t[++ct]='4';
            else if(s[i]=='s'&&s[i+1]=='i'&&s[i+2]=='x')
                t[++ct]='6';
            else if(s[i]=='n'&&s[i+1]=='i'&&s[i+2]=='n'&&s[i+3]=='e')
                t[++ct]='9';
        }
        cout<<(t+1)<<endl;
    }
    return 0;
}