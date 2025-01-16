#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define c1 cout<<"-1\n"
#define all(x) x.begin(),x.end()
#define re(x) x.rbegin(),x.rend()
#define F first
#define S second
#define ii pair<ll,ll>
#define vin ll n;cin>>n;vector<ll> arr(n);for(auto&i:arr)cin>>i;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ll mod = 1e9+7;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(long long t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long  double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll gcdExtended(ll a, ll b, ll* x, ll* y)
{

		if (a == 0) {
				*x = 0, *y = 1;
				return b;
		}

		ll x1, y1;
		ll gcd = gcdExtended(b % a, a, &x1, &y1);
		*x = y1 - (b / a) * x1;
		*y = x1;

		return gcd;
}
ll modInverse(ll A, ll M) {
		ll x, y;
		ll g = gcdExtended(A, M, &x, &y);
				ll res = (x % M + M) % M;
			 return res;
		
}
ll bpow(ll a,ll b){
ll ans =1;
while(b){
if(b&1)ans*=a;
a*=a;
b>>=1;
}
return ans;
}
ll powmod(ll a,ll b){
		ll ans =1;
while(b){
if(b&1)ans= (ans*a)%mod;
a=(a*a)%mod;
b>>=1;
}
return ans;
}
void solve(){
	ll n;cin>>n;
	vector<ll> arr(n),neg,pos;

for(auto &i:arr){
	cin>>i;
	if(i<0)neg.push_back(i);
	else pos.push_back(i);
}
ll ans = 0;

auto f = [&] (ll lim){ll  curr_sum = 0;
ll i = 0;
ll j = 0;
ll m = pos.size();
ll n = neg.size();
while(i<m and j<n){
	if(pos[i]>lim)return false;
	if(curr_sum+pos[i]<=lim)curr_sum+=pos[i++];
	else{
		curr_sum+=neg[j++];
	}
	if(curr_sum<0)curr_sum= 0;
}
while(i<m)curr_sum +=pos[i++];
return curr_sum<=lim;

};
ll start = 0;
ll end = 1e9;
while(start<=end){
	ll mid = (start+end)/2;
	if(f(mid)){
		ans =mid;
		end = mid-1;
	}
	else{
		start =mid+1;
	}
}
cout<<ans<<'\n';




}
int main() {
IOS
ll t;
cin>>t;
while(t--){
solve();
}
}