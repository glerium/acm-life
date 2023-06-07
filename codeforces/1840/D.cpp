#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,n,a[maxn];
bool check(int x) {
	int last=a[1],cnt=1;
	for(int i=1;i<=n;i++) {
		if(a[i]-last>x) {
			last=a[i];
			cnt++;
		}
		if(cnt>3) return false;
		//cout<<"\t"<<i<<' '<<cnt<<endl;
	}
	return true;
}
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		int l=0,r=1e9,mid,ans;
		while(l<=r) {
			mid=l+r>>1;
			//printf(":%d %d\n",mid,check(mid));
			if(check(mid)) r=mid-1, ans=mid;
			else l=mid+1;
		}
		cout<<ans/2+ans%2<<endl;
	}
	return 0;
}