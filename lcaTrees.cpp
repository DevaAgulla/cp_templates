#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> up;


void binary_lifting(ll node,ll par,vector<vector<ll>> &adj){
    up[node][0] = par;
    for(ll i=1;i<=19;i++){
        if(up[node][i-1]==-1){
            up[node][i] = -1;
        }
        else{
            up[node][i] = up[up[node][i-1]][i-1];
        }
    }
    for(auto it:adj[node]){
        if(it==par)continue;
        binary_lifting(it,node,adj);
    }
}

ll lift_node(ll node,ll item){
    if(node==-1 or item==0)return node;
  for(ll i=19;i>=0;i--){
    if((item&(1<<i))){
        return lift_node(up[node][i],(item^(1<<i)));
    }
  }
  return -1;
}
int main(){
  ll n,q;
  cin >> n >>q;
  vector<ll>arr(n);
  for(int i=1;i<n;i++)cin >> arr[i];
  vector<vector<ll>> adj(n);
  for(int i=1;i<n;i++){
    ll u = i;
    ll v = --arr[i];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<ll> level(n,0);
  queue<ll> qu;
  qu.push(0);
  vector<ll>vis(n,0);
  vis[0]= 1;
  while(!qu.empty()){
    ll node = qu.front();qu.pop();
    for(auto it:adj[node]){
     if(vis[it])continue;
      level[it] = level[node]+1;
      qu.push(it);
      vis[it] = 1;
    }
  }
  up.assign(n,vector<ll>(20,-1));
  binary_lifting(0,-1,adj);

  for(ll i=0;i<q;i++){
    ll u,v;
    cin >> u >>v;
    --u;--v;
    if(level[u]<level[v]){
      swap(u,v);
    }
    u = lift_node(u,abs(level[u]-level[v]));
   // cout << u << " " << v << endl;
   // cout << level[u] << " " << level[v] << endl;
   // order of logn^2
    // ll low = 0;
    // ll high = level[u];
    // ll ans = -1;
    // while(low<=high){
    //   ll mid = (low+high)>>1;
    //   ll x1 = lift_node(u,mid);
    //   ll x2 = lift_node(v,mid);
    //   if(x1==x2){
    //     ans = x1;
    //     high = mid-1;
    //   }
    //   else{
    //     low = mid+1;
    //   }
    // }
    // cout << ans+1 << endl;
    if(u==v){
      cout << u+1 << endl;continue;
    }
    for(int i=19;i>=0;i--){
      if(up[u][i]!=up[v][i]){
        u = up[u][i];
        v = up[v][i];
       // cout <<u << " " << v <<endl;
      }
    }
    cout << up[u][0]+1 << endl;
  }
}
