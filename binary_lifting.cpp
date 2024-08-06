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
        return ans(up[node][i],(item^(1<<i)));
    }
  }
  return -1;
}
