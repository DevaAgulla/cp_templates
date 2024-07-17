int maxSubarraySumCircular(vector<int>& arr) {
       int n = arr.size();
       int sum1 = 0,sum2=0,maxi = INT_MIN,mini = INT_MAX,tot=0;
       for(int i=0;i<n;i++){
        tot+=arr[i];
        sum1+=arr[i];
        sum2+=arr[i];
        maxi = max(maxi,sum1);
        mini = min(mini,sum2);
        if(sum1 <0)sum1=0;
        if(sum2>0)sum2=0;
       } 
       if(tot==mini) return maxi;
       return max(tot-mini,maxi);      
    }
