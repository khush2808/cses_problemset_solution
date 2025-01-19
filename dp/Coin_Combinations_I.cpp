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
const int mod = 1e9+7;
void solve(){
int n,x;
cin>>n>>x;
vector<int> c(n);
for(auto &i:c)cin>>i;
vector<int> dp(x+1,0);
dp[0]=1;
for(int i= 1;i<=x;i++){
	for(auto j:c){
		if(i-j>=0)
		dp[i]=(dp[i]+dp[i-j])%mod;
	}
}
		cout<<dp[x]<<'\n';
}
int main() {
	IOS
	int t;
	t=1;
	while(t--){
		solve();
	}
}