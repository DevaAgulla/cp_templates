 int maxProduct(vector<int>& arr) {
        float pre=1,suf= 1,ans = INT_MIN;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(pre==0)pre = 1;
            if(suf==0) suf = 1;
            pre *= arr[i];
            suf *= arr[n-1-i];
            //cout << pre << " " << suf << endl;
            ans = max({ans,pre,suf});
        }
        cout << FLT_MAX << endl;
        cout << LONG_MAX << endl;
        return ans;
    }
