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
int n ;
cin>>n;
		vector<string> p(n);
		for(auto &i:p)cin>>i;
		if(p[0][0]=='*'){
			cout<<0<<'\n';
			return ;
		}
		vector<vector<int>> dp(n,vector<int>(n,0));
		dp[0][0]=1;
		for(int i = 1;i<n;i++){
			if(p[0][i]!='*')
			dp[0][i] = (dp[0][i]+dp[0][i-1])%mod;
		}
		for(int i = 1;i<n;i++){
			if(p[i][0]!='*')
			dp[i][0] = (dp[i][0]+dp[i-1][0])%mod;
		}
		for(int i =1;i<n;i++){
			for(int j=1;j<n;j++){
				if(p[i][j]=='*')continue;
				int up =dp[i-1][j];
				int down =dp[i][j-1];
				dp[i][j] = (up+down)%mod;
			}
		}
		cout<<dp[n-1][n-1]<<'\n';
		
}
int main() {
	IOS
	int t;
	t=1;
	while(t--){
		solve();
	}
}