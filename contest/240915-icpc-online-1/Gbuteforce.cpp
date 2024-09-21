#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
int a[2005];
int b[2005][2005];
int c[2005][2005];

int zwsa(int l,int r) {
    int n;
    vector<int> d;
    for(int i=l;i<=r;i++)
        d.push_back(a[i]);
    sort(d.begin(),d.end());
    n=d.size();
    if(n%2==0)
        return d[n/2-1];
    else 
        return d[(n-1)/2];
}

int zwsb(int l,int r) {
    int n;
    vector<int> d;
    for(int i=l;i<=r;i++) {
        for(int j=i;j<=r;j++) {
              d.push_back(b[i][j]);      
        }
    }
    sort(d.begin(),d.end());
    n=d.size();
    if(n%2==0)
        return d[n/2-1];
    else 
        return d[(n-1)/2];
}

int zwsc(int l,int r) {
    int n;
    vector<int> d;
    for(int i=l;i<=r;i++) {
        for(int j=i;j<=r;j++) {
              d.push_back(c[i][j]);      
        }
    }
    sort(d.begin(),d.end());
    n=d.size();
    if(n%2==0)
        return d[n/2-1];
    else 
        return d[(n-1)/2];
}
int main() {
    while(1);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    // sort(a,a+n);
    // if(n%2==0)
    //     cout<<a[(n-1)/2];
    // else
    //     cout<<a[n/2];
    for(int l=0;l<n;l++)
        for(int r=l;r<n;r++) {
            b[l][r]=zwsa(l,r);
        }
    for(int l=0;l<n;l++) {
        for(int r=l;r<n;r++) {
            c[l][r]=zwsb(l,r);
        }
    }
    cout<<"b:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout<<b[i][j]<<" \n"[j==n-1];
    cout<<"c:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout<<c[i][j]<<" \n"[j==n-1];
    int ct[100]={};
    int ct2[100]={};
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ct[b[i][j]]++;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ct2[c[i][j]]++;
    cout<<"zwsc:\n";  
    cout<<zwsc(0,n-1)<<endl;       
    for(int i=1;i<=10;i++)
        cout << ct[i] << ' '; 
    cout<<endl;
    for(int i=1;i<=10;i++)
        cout << ct2[i] << ' '; 
    return 0;
}
