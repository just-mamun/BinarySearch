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

//to check if the distance is okay for fitting all the cows
bool is_fit(ll distance, vector<ll>&v, int n, ll num_cow) {
    ll curr_cow_position = v[0];
    ll cow_fit_cnt = 1;
    for(int i = 1; i<n; i++) {
        if(v[i] - curr_cow_position>=distance) {
            cow_fit_cnt++;
            curr_cow_position = v[i];
        }
        if(cow_fit_cnt==num_cow)break;
    }
    return (cow_fit_cnt==num_cow);
}


ll binary_search(vector<ll>&v, int n, ll s, ll e, ll num_cow) {
    ll mid;
    while(s<e) {
        mid = (s + e + 1)/2;
        if(is_fit(mid, v, n, num_cow)) {
            s = mid;
        }
        else e = mid - 1;
    }
    return s;
}
void No_Brain() {
    int n; ll c; cin>>n>>c;
    vector<ll>v(n);
    ll maxx = -INF, minn = INF;
    for(int i = 0; i<n; i++) {
        cin>>v[i];
        
    }
    sort(v.begin(), v.end());
    maxx = v[n-1]; minn = v[0];
    ll ans = binary_search(v, n, minn, maxx, c);
    cout<<ans<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        No_Brain();
    }
    return 0;
}