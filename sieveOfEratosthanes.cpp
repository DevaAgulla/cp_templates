vector<ll> sieve(ll n){
    vector<ll> is_prime(n+1, 1);
    is_prime[0] = is_prime[1] = 0;
   for (ll i = 2; i*i <= n; i++) {
        if (is_prime[i]) {
          for (ll j = i * i; j <= n; j += i)
              is_prime[j] = 0;
         }
    }
    return is_prime;
}
