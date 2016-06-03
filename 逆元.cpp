// when we used this method to calculate x / y % p, we also need x and p is coprime
// Method 2:	Quick Power
// Requires:	p is prime
// Modify:   	none
// Effects: 	return n's inverse element about p
// Return:  	n's inverse element about p

long long quick_inverse(long long n, long long p) {
	long long ret = 1;
	int exponent = p - 2;
	for (int i = exponent; i; i >>= 1, n = n * n % p) {
		if (i & 1) {
			ret = ret * n % p;
		}
	}
	return ret;
}


// when we used this method to calculate x / y % p, we also need x and p is coprime
// Method 3:	Recursive to get i's inverse element
// Requires:	p is prime and p != 2
// Modify:  	inv[]
// Effects: 	inv[i] is i's inverse element about p;

int inv[N];
void get_inverse(int n, int p) {
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] =  (long long)(p - p / i) * inv[p % i] % p;
	}
}
