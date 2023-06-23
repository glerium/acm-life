#include <bits/stdc++.h>
using namespace std;
int p1,p2,p3,n;
char s[201];
void make(char c) {
    for(int i=1;i<=p2;i++) {
        if(p1==3) putchar('*');
        else {
            if(p1==1) putchar(tolower(c));
            else putchar(toupper(c));
        }
    }
}
int main() {
    scanf("%d%d%d",&p1,&p2,&p3);
    scanf("%s",s+1);
    n=strlen(s+1);
    int lastx=-1,lasty=-1;
    for(int i=1;i<=n;i++) {
        if(s[i]!='-') putchar(s[i]);
        else {
            if((isalpha(s[i-1])&&isalpha(s[i+1])||isdigit(s[i-1])&&isdigit(s[i+1])) &&
               (i-1!=lasty)&&(s[i-1]<s[i+1])) {
                if(p3==1) {
                    for(int j=s[i-1]+1;j<s[i+1];j++) make(j);
                }else {
                    for(int j=s[i+1]-1;j>s[i-1];j--) make(j);
                }
                lasty=i+1;
            } else {
                putchar(s[i]);
            }
        }
    }
    return 0;
}