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
	vector<int> ans;
	ans.push_back(arr[0]);
	for(int i = 1;i<n;i++){
		auto it =lower_bound(ans.begin(),ans.end(),arr[i]);
		if(it==ans.end())ans.push_back(arr[i]);
		else *it = arr[i];
	}
	cout<<ans.size();
}
int main() {
	IOS
	int t;
	t=1;
	while(t--){
		solve();
	}
}