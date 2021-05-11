//tt89 ;)
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void testcase(int t) { cout<<"Case #"<<t<<": "; }
void online() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}
const int mod= 1e9+7;

int n;
vector<int> arr;
vector<vector<int>> tree;

int getDfs(int i) {
    for(int j: tree[i]) arr[i]+= getDfs(j);
    return arr[i]+1;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        arr.resize(n+1,0);
        tree.resize(n+1);
        for(int i=2;i<=n;i++) {
            int a; cin>>a;
            tree[a].push_back(i);
        }
        getDfs(1);
        for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    }
    return 0;
}