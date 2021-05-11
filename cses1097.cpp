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

const int N= 5e3+10,mx= 1e18;
int n;
int arr[N],dp[N][N][2];

void getDp(int i,int j) {
    if(i==j) { dp[i][j][0]=arr[i],dp[j][i][1]=0; return; }
    if(dp[i][j][0]!=-1e18) return;
    getDp(i+1,j); getDp(i,j-1);

    if(dp[i+1][j][1]+arr[i]>dp[i][j-1][1]+arr[j]) {
        dp[i][j][0]=dp[i+1][j][1]+arr[i];
        dp[i][j][1]=dp[i+1][j][0];
    }else{
        dp[i][j][0]=dp[i][j-1][1]+arr[j];
        dp[i][j][1]=dp[i][j-1][0];
    }
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j][0]=dp[1][j][1]=-1e18;
        getDp(0,n-1);
        cout<<dp[0][n-1][0];
    }
    return 0;
}