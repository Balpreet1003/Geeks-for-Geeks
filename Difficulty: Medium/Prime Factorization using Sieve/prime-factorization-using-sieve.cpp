class Solution {
    static const int MAXN = 200000 + 5;  // given constraint
    vector<int> spf; // smallest prime factor

public:
    Solution() {
        spf.assign(MAXN, 0);
        sieve();
    }

    // Build SPF array
    void sieve() {
        for (int i = 2; i < MAXN; i++) {
            if (spf[i] == 0) {  // i is prime
                spf[i] = i;
                for (long long j = 1LL * i * i; j < MAXN; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }
    }

    // Factorize N using SPF
    vector<int> findPrimeFactors(int N) {
        vector<int> factors;
        while (N > 1) {
            int prime = spf[N];
            factors.push_back(prime);
            N /= prime;
        }
        return factors;
    }
};
