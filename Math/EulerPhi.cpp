int phi (int n) {
    if ( n == 1 )
        return 0;
    int output = n;
 
    if ( n % 2 == 0 ) {
        output -= (output / 2);
        while ( n % 2 == 0 )
            n /= 2;
    }
 
    for ( int i = 3; i * i <= n; i += 2 ) { // i <= sqrtN may be ??
        if ( n % i == 0 ) {
            output -= (output / i);
            while ( n % i == 0 )
                n /= i;
        }
    }
 
    if ( n > 1 )
        output -= (output / n);
 
    return output;
}

// using prime sieve
// generate prime numbers upto certain limit using sieve/segmented sieve
// sieve(sqrt(n));
int phi (int n) {
    int phi = n;
    int sqrtN = sqrt(n);
    for(int i = 0; i < (int)primes.size() and primes[i] <= sqrtN; i++) {
        if(n % primes[i] == 0) {
            phi *= (1 - 1 / (double) primes[i]);
            while(n % primes[i] == 0) {
                n /= primes[i];
            }
        }
    }

    if(n > 1) {
        phi *= (1 - 1 / (double) n);
    }
    
    return phi;
}