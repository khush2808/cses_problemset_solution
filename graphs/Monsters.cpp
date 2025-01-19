#include <bits/stdc++.h>
#include <functional>
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
	int m, n;
	cin >> m >> n;
	vector<string> v(m);
	for (auto &i : v)
		cin >> i;
	ll si, sj;
	queue<ii> q, q1;
	vector<vector<int>> dist(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == 'A')
			{
				si = i, sj = j;
			}
			if (v[i][j] == 'M')
			{
				dist[i][j]=-1;
				q.push({i, j});
			}
		}
	}
	vector<ii> x = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
	q1.push({si, sj});
	vector<vector<ii>> p(m,vector<ii>(n));
	auto f = [](ii a,ii b){
		auto [a1,a2]=a;
		auto [b1,b2]=b;
		if(a1==b1){
			if(a2==b2+1)return 'L';
			else return 'R';
		}
		else {
			if(a1==b1+1)return 'U';
			else return 'D';
		}
	};
	while (!q1.empty())
	{
		int size = sz(q);
		for (int i = 0; i < size; i++)
		{
			auto [xi, xj] = q.front();
			q.pop();
			for (auto it : x)
			{
				int ni = xi + it.F;
				int nj = xj + it.second;
				if (ni < 0 or nj < 0 or ni >= m or nj >= n or v[ni][nj] != '.' or dist[ni][nj])
					;
				else
				{
					q.push({ni, nj});
					dist[ni][nj] = 2;
				}
			}
		}
		size = sz(q1);
		for (int i = 0; i < size; i++)
		{
			auto [xi, xj] = q1.front();
			q1.pop();
			for (auto it : x)
			{
				int ni = xi + it.F;
				int nj = xj + it.S;
				if (ni < 0 or nj < 0 or ni >= m or nj >= n){
					cout<<"YES\n";
										vector<char> ans;
										// cout<<ni<<' '<<nj<<"\n";
						ni =xi;
						nj = xj;
						// cout<<ni<<' '<<nj<<'\n';
						
					do{
												debug(make_pair(ni,nj)); 
																														debug(p[ni][nj]); 

						ans.push_back(f({p[ni][nj]},{ni,nj}));
						ni =p[ni][nj].first;
						nj = p[ni][nj].second;

					}
					while(ni!=si or nj!=sj);
					reverse(ans.begin(),ans.end());
					cout<<ans.size()<<'\n';
					for(auto i:ans)cout<<i;
					// debug(si);debug(sj);
					exit(0);
				}
				else
				 if(dist[ni][nj] or v[ni][nj]=='#');
					
				else
				{
														p[ni][nj]={xi,xj};
					q1.push({ni, nj});
					// debug(make_pair(ni,nj));
					dist[ni][nj] = 1;
				}
			}
		}
	}
	cout<<"NO";
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