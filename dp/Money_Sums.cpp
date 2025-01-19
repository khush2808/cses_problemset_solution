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
int n;
cin>>n;
vector<int> arr(n);
for(auto &i:arr)cin>>i;
int sum = accumulate(arr.begin(),arr.end(),0);
vector<bool> dp(sum+1,0);
dp[0]=1;
for(auto i:arr){
	for(int j = sum;j>=i;j--){
		if(dp[j-i])dp[j]=1;
	}
}
int cnt = 0;
for(auto i:dp)if(i)cnt++;
cout<<cnt-1<<'\n';
for(int i =1;i<=sum;i++){
	if(dp[i])cout<<i<<' ';
}
		
		
}
int main() {
	IOS
	int t;
	t=1;
	while(t--){
		solve();
	}
}