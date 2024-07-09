long long maxSubArray(vector<long long>& arr) {
        int n = arr.size();
        long long sum=0;
        long long ans = LONG_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            ans = max(ans,sum);
            if(sum<0) sum = 0;
        }
        return ans;
    }
