#include <bits/stdc++.h>
using namespace std;
int t,a[200007];
typedef long long ll;
ll n,k,q;
int main() {
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++) cin>>a[i];
		int last=-1;
		ll ans=0;
		for(int i=1;i<=n;i++) {
			//cout<<"i="<<i<<endl;
			if(a[i]>q) continue;
			last=i;
			i++;
			while(a[i]<=q&&i<=n) i++;
			i=min(i*1ll,n+1);
			int ct=i-last;
			//cout<<";"<<ct<<endl;
			if(ct>=k) {
				int tmp=ct-k+1;
				ans+=1ll*tmp*(tmp+1)/2;
			}
		}
		cout<<ans<<endl;
	}
}