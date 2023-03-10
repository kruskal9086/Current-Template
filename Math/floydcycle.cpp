pair<int, int> floyd_cycle_finding(int (*f)(int), int x0) {
    // the main phase of the algorithm, finding a repetation x(i) = x(2i). hare's speed is 2 * tortoise's
    int tortoise = f(x0), hare = f(f(x0));
    while( tortoise != hare ) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
 
    // find the position of mu, the hare and tortoise move at the same speed
    int mu = 0;
    hare = tortoise;
    tortoise = x0;
    while( tortoise != hare ) {
        tortoise = f(tortoise);
        hare = f(hare);
        ++mu;
    }
 
    // find the length of the shortest cycle starting from x(mu), hare moves, tortoise stays
    int lambda = 1;
    hare = f(tortoise);
 
    while( tortoise != hare ) {
        hare = f(hare);
        ++lambda;
    }
 
    return make_pair(mu, lambda);
}