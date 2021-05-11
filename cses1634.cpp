//tt89 ;)
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define clock cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
void testcase(int t) { cout<<"Case #"<<t<<": "; }
void online() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}
const int mod= 1e9+7;

int n,x;
vector<int> arr,dp;

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>x;
        arr.resize(n);
        dp.resize(x+1,INT_MAX);
        for(int &i: arr) cin>>i;

        dp[0]=0;
        for(int i=0;i<=x;i++) {
            for(int j: arr) {
                if(i+j<=x) dp[i+j]=min(dp[i]+1,dp[i+j]);
            }
        }
        if(dp[x]==INT_MAX) dp[x]=-1;
        cout<<dp[x];
    }
    return 0;
}