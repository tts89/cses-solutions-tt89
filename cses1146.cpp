//tt89 ;)
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define clock cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
#define ff first
#define ss second
void testcase(int t) { cout<<"Case #"<<t<<": "; }
void online() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}
const int mod= 1e9+7;

int n;

int solve() {
    int ans=0,p=2;
    for(int i=0;i<61;i++) {
        ans+= (n/p)*p/2 ;
        if(n%p > p/2) ans+= n%p-p/2;
        p*=2;
    }
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n; n++;
        cout<<solve();
    }
    return 0;
}