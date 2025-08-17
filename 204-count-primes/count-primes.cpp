class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; // edge case

        vector<bool> isPrime(n, true); // size n, 0..n-1
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {  // i*i < n is enough
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) cnt++;
        }
        return cnt;
    }
};
