ll func(vector<ll>& arr){
  int n = arr.size();
  unordered_map<ll, pair<ll, ll>> mpp; mpp[0] = {1, 0};
  ll ans = 0;
  ll xorr = 0;
  for(int i = 0; i < n; i++) {
      xorr ^= arr[i];
      if(mpp.find(xorr) != mpp.end()) {
           ans += i * mpp[xorr].first - mpp[xorr].second;
           mpp[xorr].first += 1;
           mpp[xorr].second += i + 1;
      }
      else mpp[xorr] = {1, i + 1};
  }
}
