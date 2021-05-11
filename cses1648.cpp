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

int n,q;
vector<int> arr,up,low;

void getBuildUp(int i,int val) {
    while (i) {
        arr[i]+=val;
        i/=2;
    }
}

void getBorder(int i) {
    if(i>=n) { low[i]=up[i]=i; return; }
    getBorder(2*i); getBorder(2*i+1);
    low[i]= low[i*2]; up[i]= up[i*2+1];
}

int getSumRange(int a,int b,int i) {
    if(low[i]>b || up[i]<a) return 0;
    else if(low[i]>=a && up[i]<=b) return arr[i];
    return getSumRange(a,b,i*2)+getSumRange(a,b,i*2+1);
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q;
        int N=n;
        n= pow(2,ceil(log2(n)));
        arr.resize(2*n,0);
        up.resize(2*n); low.resize(2*n);
        for(int i=n;i<n+N;i++) {
            int a; cin>>a;
            getBuildUp(i,a);
        }
        getBorder(1);
//        for(int i=1;i<2*n;i++) cout<<low[i]<<"@"<<up[i]<<" "; cout<<"\n";
        while (q--) {
            int a,b,c; cin>>a>>b>>c;
            if(a==1) getBuildUp(n+b-1,c-arr[n+b-1]);
            else cout<<getSumRange(n+b-1,n+c-1,1)<<"\n";
        }
    }
    return 0;
}