#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j;i<=k;i++)
using namespace std;
struct arr{
	int v,p;
}a[200005];
int a1[200005],a2[200005],T,s1,s2,t1,t2,n;
bool cmp(arr a,arr b){
	return a.v>b.v;
}
int main(){
	cin>>T;
	while (T--){
		scanf("%d%d%d",&n,&s1,&s2);
		t1=t2=1;
		rep(i,1,n){
			scanf("%d",&a[i].v);
			a[i].p=i;
		}
		sort(a+1,a+n+1,cmp);
		rep(i,1,n){
			if (s1*t1<s2*t2)
				a1[t1++]=a[i].p;
			else a2[t2++]=a[i].p;
		}
		cout<<t1-1;
		rep(i,1,t1-1) printf(" %d",a1[i]);
		cout<<endl<<t2-1;
		rep(i,1,t2-1) printf(" %d",a2[i]);
		cout<<endl;
	}
	return 0;
}