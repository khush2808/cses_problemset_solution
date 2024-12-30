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
vector<int> arr(n);
for(int i = 0;i<n;i++)cin>>arr[i];
vector<int> dp(x+1,0);
dp[0]=1;
for(auto i:arr){
	for(int j=1;j<=x;j++){
		if(j-i>=0)
		dp[j] = (dp[j]+dp[j-i])%mod;
	}
}
cout<<dp[x];
		
}
int main() {
	IOS
	int t;
	t=1;
	while(t--){
		solve();
	}
}