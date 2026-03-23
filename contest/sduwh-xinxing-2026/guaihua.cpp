#include<bits/stdc++.h>
using namespace std;
bool compare(const string& a,const string& b)
{
	return a.length()>b.length();
}
int main()
{
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;++i)
		cin>>s[i];
	string sen; cin>>sen;
	sort(s,s+n,compare);
	int len=sen.length();
	for(int i=0;i<len;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(sen.substr(i,s[j].length())==s[j])
			{
				sen.replace(i,s[j].length(),s[j].length(),'*');
				i+=s[j].length();
			}
		}
	}
	cout<<sen;
}