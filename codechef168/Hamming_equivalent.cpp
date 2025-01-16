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
#define vin int n;cin>>n;vector<int> arr(n);for(auto&i:arr)cin>>i;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1e9+7;
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
int n;
cin>>n;
vector<int> arr(n);
for(auto &i:arr)cin>>i;
map<int,vector<pair<int,int>>> m;
int it=0;
for(auto i:arr){
    int cnt = __builtin_popcount(i);
    m[cnt].push_back({i,it});
    it++;
}
bool flag = true;
for(auto x:m){
    auto v = x.second;
    set<int> nj;
    for(auto jt:v){
        nj.insert(jt.second);
    }
    for(auto jt:v){
        nj.erase(jt.first-1);
    }
    if(!nj.empty()){
        flag= false;
    }
}
if(flag)cout<<"YES\n";
else cout<<"NO\n";
		
}
int main() {
	IOS
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}