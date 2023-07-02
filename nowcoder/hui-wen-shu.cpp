#include <bits/stdc++.h>
using namespace std;
int a[14];
int main() {
    for(int i=0;i<=9;i++) cin>>a[i];
    int pos=-1;
    int single=-1, singct=0;
    for(int i=0;i<=9;i++) if(a[i]%2==1) {
        singct++;
        single=i;
    }
    if(singct==1&&a[single]==1) {
        bool found=false;
        for(int i=0;i<=9;i++) {
            if(i!=single&&a[i])
                found=true;
        }
        if(!found) {
            cout<<single<<endl;
            return 0;
        }
    }
    if(singct>1) {
        puts("-1");
        return 0;
    }
    else if(singct==1&&single==0&&a[0]>1) {
        bool found=false;
        for(int i=1;i<=9;i++) {
            if(i!=single&&a[i]) {
                found=true;
                break;
            }
        }
        if(!found) {
            puts("-1");
            return 0;
        }
    }else if(singct==1&&single!=0) {
        if(a[0]) {
            bool found=false;
            for(int i=1;i<=9;i++) {
                if(i!=single&&a[i]) {
                    found=true;
                    break;
                }
            }
            if(!found) {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=9;i++) {
        if(a[i]!=0) {
            pos=i;
            break;
        }
    }
    putchar(pos+'0');
    for(int i=1;i<=a[0]/2;i++) putchar('0');
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=a[i]/2-(i==pos?1:0);j++)
            putchar(i+'0');
    }
    if(single!=-1) putchar(single+'0');
    for(int i=9;i>=1;i--) {
        for(int j=1;j<=a[i]/2-(i==pos?1:0);j++)
            putchar(i+'0');
    }
    for(int i=1;i<=a[0]/2;i++) putchar('0');
    putchar(pos+'0');
    return 0;
}