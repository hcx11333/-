long long qpow(long long a, long long b,int mod){
	long long ans = 1;
	while (b){
		if (b & 1)ans *= a%mod;
		a *= a%mod;
		b >>= 1;
	}
	return ans;
}