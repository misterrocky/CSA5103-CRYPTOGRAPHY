#include <stdio.h>
#include <math.h>
long int ext_euclidean(long int m, long int b) {
    long int a1 = 1, a2 = 0, a3 = m, b1 = 0, b2 = 1, b3 = b, q, t1, t2, t3;
    while (1) {
        if (b3 == 0) {
            return 0;
        }
        if (b3 == 1) {
            if (b2 < 0) b2 += m;
            return b2;
        }
        q = a3 / b3;
        t1 = a1 - (q * b1);
        t2 = a2 - (q * b2);
        t3 = a3 - (q * b3);
        a1 = b1;
        a2 = b2;
        a3 = b3;
        b1 = t1;
        b2 = t2;
        b3 = t3;
    }
}
long int power(long int a, long int j, long int c) {
    long int f = 1, i;
    for (i = 1; i <= j; i++) {
        f = (f * a) % c;
    }
    return f;
}
int main() {
    long int p, q, g, x, hm, k, y, r, s, s1, w, u1, u2, v3;
    printf("Enter p, q, g, x, hm, k:");
    scanf("%ld %ld %ld %ld %ld %ld", &p, &q, &g, &x, &hm, &k);
    y = power(g, x, p);
    r = power(g, k, p) % q;
    s = (ext_euclidean(q, k) * (hm + x * r)) % q;
    w = ext_euclidean(q, s);
    u1 = (hm * w) % q;
    u2 = (r * w) % q;
    v3 = (power(g, u1, p) * power(y, u2, p)) % q;
    printf("\nSignature (r, s): %ld %ld", r, s);
    printf("\nValue of v: %ld", v3);
    return 0;
}

