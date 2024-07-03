 void dfs(int node,int par,vector<vector<int>>& g,pair<int,int>& res,int dis){

        if(dis > res.first){
            res = {dis,node};
        }
        for(auto it:g[node]){
            if(it!=par){
                dfs(it,node,g,res,dis+1);
            }
        }
    }
