#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;
#define c1 cout << "-1\n"
#define all(x) x.begin(), x.end()
#define re(x) x.rbegin(), x.rend()
#define F first
#define S second
#define ii pair<ll, ll>
#define IOS                \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
using namespace std;
const int mod = 1e9+7;
int dp[1000001];
void solve()
{
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 1e6; i++)
	{
		dp[i] = 0;
		for (int j = i; j >= max(i - 6, 0); j--)
		{
			dp[i] = (dp[i]+dp[j])%mod;
		}
	}
}
int main()
{
	IOS int t;
	t = 1;
	solve();
	while (t--)
	{
		int n;
		cin >> n;
		cout << dp[n];
	}
}