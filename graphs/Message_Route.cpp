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
#define vin           \
	int n;              \
	cin >> n;           \
	vector<int> arr(n); \
	for (auto &i : arr) \
		cin >> i;
#define sz(x) (int)(x).size()
#define vi(x) vector<x>
#define IOS                \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;
#ifndef ONLINE_JUDGE
#define debug(x)     \
	cerr << #x << " "; \
	_print(x);         \
	cerr << endl;
#else
#define debug(x)
#endif

void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
	cerr << "{";
	_print(p.first);
	cerr << ",";
	_print(p.second);
	cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(set<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
	cerr << "[ ";
	for (auto i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{

	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}

	ll x1, y1;
	ll gcd = gcdExtended(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}
ll modInverse(ll A, ll M)
{
	ll x, y;
	ll g = gcdExtended(A, M, &x, &y);
	ll res = (x % M + M) % M;
	return res;
}
ll bpow(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}
ll powmod(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].pb(u);
	}
	queue<ll> q;
	vector<int> p(n + 1, -1);
	vector<bool> vis(n+1,false);
	vis[1] = 1;
	p[1]=-1;
	q.push(1);
	while (q.size())
	{
		int size = sz(q);
		for (int i = 0; i < size; i++)
		{
			ll x = q.front();q.pop();
			for (auto i : adj[x])
			{
				if (!vis[i])
				{
					q.push(i);
					vis[i] = 1;
					p[i]=x;
				}
				if(i==n)break;
			}
		}
	}
	vector<int> ans;
	if(!vis[n]){
		cout<<"IMPOSSIBLE";
		return;
	}
	int use =n;
	while(use!=-1){
		ans.pb(use);
		use = p[use];

	}
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i<<' ';
}
int main()
{
	IOS int t;
t=1;	while (t--)
	{
		solve();
	}
}