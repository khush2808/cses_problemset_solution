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
void solve()
{

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (auto &i : arr)
		cin >> i;
	vector<int> dp(k + 1, INT_MAX);
	dp[0] = 0;
	for (auto j : arr)
	{
		for (int i = 0; i <= k; i++)
		{
			if (i - j >= 0 and dp[i - j] != INT_MAX)
				dp[i] = min(dp[i - j] + 1, dp[i]);
		}
	}

	cout << (dp[k] == INT_MAX ? -1 : dp[k]);
}
int main()
{
	IOS int t;
	t = 1;
	while (t--)
	{
		solve();
	}
}