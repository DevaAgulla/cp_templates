//zero index
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
ll lca(ll u,ll v){
     if(level[u]<level[v]){
      swap(u,v);
    }
    u = lift_node(u,abs(level[u]-level[v]));
    if(u==v) return u;
    for(int i=19;i>=0;i--){
      if(up[u][i]!=up[v][i]){
        u = up[u][i];
        v = up[v][i];
      }
    }
    return up[u][0];
}
