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
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ll mod = 1e9+7;
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


void solve(){

		ll n;
		cin>>n;
		ll sum = n*(n+1)/2;
		if(sum&1)cout<<0<<'\n';
		else {
			vector<ll> dp(sum+1,0);

		dp[0]=1;
		for(ll i = 1;i<=n;i++)
			for(ll j = sum;j>=i;j--)
				dp[j]=(dp[j]+dp[j-i])%mod;
		
		cout<<(dp[sum/2]*modInverse(2,mod))%mod<<'\n';
		}
}
int main() {
	IOS
	ll t;
	t=1;
	while(t--){
		solve();
	}
}