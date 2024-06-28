#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> z_function(string s) {
    int n = s.size();
    vector<ll> z(n);
    ll l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve(){
    string str;
    cin >> str;
    ll n = str.size();
    vector<ll> pre = z_function(str);
    reverse(str.begin(),str.end());
    vector<ll> suf = z_function(str);
    if(n&1){
        cout << 0 << endl;
        return;
    }
   ll ans = 0;
   for(int i=0;i<=n/2;i++){
       int l = i;
       int r = n-(i+n/2-1)-1;
       if(pre[i]>=i and suf[r]>=r){
           ans++;
       }
   }
   cout << ans << endl;
}
int main() {
	int t;
	cin >> t;
	while(t--)solve();

}
