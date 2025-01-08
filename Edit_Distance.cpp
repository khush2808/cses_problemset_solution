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
int f(string &a,string &b,int i,int j,vector<vector<int>>& dp){

	if(i==a.size() and j ==b.size())return 0;
	else if(i==a.size())return b.size()-j;
	else if(j==b.size())return a.size()-i;
	if(dp[i][j]!=-1)return dp[i][j];
	int ans = INT_MAX;
	if(a[i]==b[j]){
		
		ans = f(a,b,i+1,j+1,dp);
	}
	else{
		//replace
		ans = min(ans,f(a,b,i+1,j+1,dp));
		// insert in a
		 ans =min(ans,f(a,b,i+1,j,dp));
		//insert in b
		ans = min(ans,f(a,b,i,j+1,dp));
		ans++;
		//delete in a
	}
	return dp[i][j]=ans;
}
void solve(){
string a,b;
cin>>a>>b;
int m = a.size(),n=b.size();
vector<vector<int>> dp(m,vector<int>(n,-1));
cout<<f(a,b,0,0,dp);
		
		
}
int main() {
	IOS
	int t;
t=1;	while(t--){
		solve();
	}
}