#include <bits/stdc++.h>
using namespace std;
__int128_t atoint128_t(const char *s)
{
    const char *p = s;
    __int128_t val = 0;

    if (*p == '-' || *p == '+') {
        p++;
    }
    while (*p >= '0' && *p <= '9') {
        val = (10 * val) + (*p - '0');
        p++;
    }
    if (*s == '-') val = val * -1;
    return val;
}
int main(){
    int t;
    cin>>t;
    int n;
    cin>>n;
    __int128 ans=0, ima;
    char anss[100];
    while(n--) {
        char s[100];
        cin>>s;
        ima = atoint128_t(s);
        if(ima > ans) {
            ans = ima;
            strcpy(anss,s);
        }
    }
    cout<<anss<<endl;
}
