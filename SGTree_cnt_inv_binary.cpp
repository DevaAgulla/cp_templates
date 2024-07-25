#include<bits/stdc++.h>
using namespace std;
struct node{
   int  onecnt = 0;
   int zerocnt = 0;
   int invcnt= 0;
};

//for query return type is node 
class SGTree{

   vector<node> sg;
   public:
    SGTree(int n){
     sg.resize(4*n+1);
   }
   
   void build(int ind ,int low ,int high,vector<int>& arr){
      if(low==high){
          if(arr[low]==0)sg[ind].zerocnt++;
          else sg[ind].onecnt++;
          return ;
      }
      
      int mid = (low+high) >> 1;
      build(2*ind+1,low,mid,arr);
      build(2*ind+2,mid+1,high,arr);
      sg[ind].zerocnt = sg[2*ind+1].zerocnt+sg[2*ind+2].zerocnt;
      sg[ind].onecnt = sg[2*ind+1].onecnt + sg[2*ind+2].onecnt;
      sg[ind].invcnt = sg[2*ind+1].invcnt+sg[2*ind+2].invcnt+
                       sg[2*ind+2].zerocnt*sg[2*ind+1].onecnt;
   }
   node query(int ind ,int low,int high,int l,int r){
      if(r < low or l > high){
        node data;
        return data;
      };
      if(low >= l and high <=r) return sg[ind];
      int mid = (high+low) >> 1;
      auto left = query(2*ind+1,low,mid,l,r);
      auto right = query(2*ind+2,mid+1,high,l,r);
      node data;
      data.zerocnt = left.zerocnt+right.zerocnt;
      data.onecnt = left.onecnt + right.onecnt;
      data.invcnt = left.invcnt + right.invcnt + left.onecnt*right.zerocnt;
      return data;
   }
};
