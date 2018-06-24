// 313. Super Ugly Number
// based on 264. Ugly Number II
int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> k(n);
    k[0] = 1;
    vector<int> t(primes.size());
    for (int i = 1; i < n; i++) {
        k[i] = INT_MAX;
        for (int j = 0; j < primes.size(); j++) {
            k[i] = min(k[i], k[t[j]] * primes[j]);
        }
        for (int j = 0; j < primes.size(); j++) {
            if (k[i] == k[t[j]] * primes[j])
                t[j]++;
        }
    }
    return k.back();
}