#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int n;
int a[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int ans=a[1]*a[n];
	int f=1;
	for(int i=2;i<=(n+1)/2;i++)
	{
		if(a[i]*a[n-i+1]!=ans)
		{
			f=0;
			break;
		}
	}
	if(!f)
	{
		cout<<-1<<'\n';
		return;
	}
	int cnt=0;
	for(int i=2;i*i<=ans;i++)
	{
		if(ans%i==0)
		{
			if(i*i==ans)cnt++;
			else cnt+=2;
		}
	}
	if(cnt!=n)cout<<-1<<'\n';
	else
	cout<<ans<<'\n';
}
signed main()
{
	int T=1;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	solve();
	return 0;
}