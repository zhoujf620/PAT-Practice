// 1059. Prime Factors (25)

// Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *¡­*pm^km.

// Input Specification:

// Each input file contains one test case which gives a positive integer N in the range of long int.

// Output Specification:

// Factor N in the format N = p1^k1 * p2^k2 *¡­*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

// Sample Input:
// 97532468

// Sample Output:
// 97532468=2^2*11*17*101*1291


#include <iostream>
#include <vector>
using namespace std;

vector<int> prime(50000, 1);
int main() {
    for(int i = 2; i * i < 50000; i++)
        for(int j = 2; j * i < 50000; j++)
            prime[j * i] = 0;

    long int N;
    scanf("%ld", &N);
    printf("%ld=", N);
    if(N == 1) printf("1");

    bool state = false;
    for(int i = 2; i < 50000 && N >= 2; i++) {
        int cnt = 0, flag = 0;
        while(prime[i] == 1 && N % i == 0) {
            cnt++;
            N = N / i;
            flag = 1;
        }
        if(flag) {
            if(state) printf("*");
            printf("%d", i);
            state = true;
        }
        if(cnt >= 2) printf("^%d", cnt);
    }
    if (N > 1) printf("%s%ld", state ? "*" : "", N);
    return 0;
}
