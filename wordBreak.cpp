bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n,0);
        set<string> st(wordDict.begin(),wordDict.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(st.find(s.substr(j,i-j+1))!=st.end() and (j==0 or dp[j-1]))
                   dp[i] = 1;
            }
        }
        return dp[n-1];
}
