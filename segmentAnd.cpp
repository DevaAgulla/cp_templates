class SGTree{
   vector<int> sg;
   public:
    SGTree(int n){
     sg.resize(4*n+1);
   }
   
   void build(int ind ,int low ,int high,vector<int>& arr){
      if(low==high){
          sg[ind] = arr[low];
          return ;
      }
      
      int mid = (low+high) >> 1;
      build(2*ind+1,low,mid,arr);
      build(2*ind+2,mid+1,high,arr);
      sg[ind] = sg[2*ind+1]&sg[2*ind+2];
   }
   int query(int ind ,int low,int high,int l,int r){
      if(r < low or l > high) return INT_MAX;
      if(low >= l and high <=r) return sg[ind];
      int mid = (high+low) >> 1;
      int left = query(2*ind+1,low,mid,l,r);
      int right = query(2*ind+2,mid+1,high,l,r);
      return left&right;
   }
};
