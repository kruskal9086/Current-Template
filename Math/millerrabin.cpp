bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 or n % 3 == 0) {
        return false;
    }
    int sqrtN = sqrt(n);
    for(int i = 5; i <= sqrtN; i += 6) {
        if(n % i == 0 or n % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

#define i64 unsigned long long

// c <= a x b
i64 mulmod(i64 a, i64 b, i64 mod) {
    i64 x = 0, y = a % mod;
    while(b) {
        if(b & 1) {
            x = (x + y) % mod;
        }
        y = (y << 1) % mod;
        b >>= 1;
    }
    return x;
}

// modular exponentiation for numbers where base * base can exceed LLONG_MAX
i64 power(i64 base, i64 exp, i64 mod) {
    i64 x = 1, y = base % mod;
    while(exp) {
        if(exp & 1) {
            x = mulmod(x, y, mod);
        }
        y = mulmod(y, y, mod);
        exp >>= 1;
    }
    return x;
}

// returns false if n is composite and returns true if n is probably prime.
// d is an odd number such that d*2^r = n - 1 for some r >= 1
bool millerTest(i64 n, i64 d) {

    // pick a random number between [1 ... n - 1]
    i64 a = rand() % (n - 1) + 1;

    // compute a^d % n
    i64 x = power(a, d, n);


    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n - 1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n - 1
    while(d != n - 1 and x != 1 and x != n - 1) {
        x = mulmod(x, x, n);
        d <<= 1;
    }

    if(x != n - 1 and !(d & 1)) {
        // composite number
        return false;
    }

    return true;
}

// returns false if n is composite and returns true if n is probably prime.
// iter is an input parameter that determines accuracy level. Higher value of iter indicates more accuracy.
// accurate till 10^18 e.g. isPrime(LLONG_MAX) works even only in 1 iterations
bool isPrime(i64 n, int iter = 1) {

    // corner cases
    if(n < 2) {
        return false;
    }
    if(n == 2) {
        return true;
    }
    if(!(n & 1)) { // even
        return false;
    }

    // Find d such that n = d * 2^r + 1 for some r >= 1
    i64 d = n - 1;
    while(!(d & 1)) {
        d >>= 1;
    }

    // check iter times
    for(int i = 0; i < iter; i++) {
        if(!millerTest(n, d)) {
            return false;
        }
    }
    return true;
}