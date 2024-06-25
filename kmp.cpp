vector<int> kmp(string str){
    int n = str.size();
    vector<int>lps(n,0);
    for(int i=1;i<n;i++){
        int pre = lps[i-1];
        while(pre>0 and str[i]!=str[pre]){
            pre = lps[pre-1];
        }
        lps[i] = pre+(str[i]==str[pre]);
    }
    return lps;
}
