#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops") 
#define ll long long
#define memset(a,x) memset(a,x,sizeof(a))
#define PI 3.1415926535897932384626433832795l 
#define ys cout<<"Yes"<<'\n'
#define no cout<<"No"<<'\n'
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-9;
ll binary_search(ll e, vector<ll>&v, ll n, ll k) {
    ll s = 0;
    ll mid;
    ll ans = 0;
    while(s<e) {
       mid = (s+e+1)/2; 
       ll sum = 0;
       for(int i = 0; i<n; i++) {
        sum += max(v[i] - mid, 0*1LL);
        if(sum>=k)break;
       }
       if(sum>=k) {
        s = mid;
        ans = max(ans, mid);
       }
       else e = mid - 1;
    }
    return ans;
}
void No_Brain() {
    ll n, k; cin>>n>>k;
    vector<ll>v(n);
    ll maxx = -1;
    for(int i = 0; i<n; i++) {
        cin>>v[i];
        maxx = max(maxx, v[i]);
    }
    sort(v.begin(), v.end());
    ll ans = binary_search(maxx, v, n, k);
    cout<<ans<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        No_Brain();
    }
    return 0;
}