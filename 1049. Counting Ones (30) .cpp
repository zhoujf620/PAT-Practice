// 1049. Counting Ones (30)

// The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N.  For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

// Input Specification:

// Each input file contains one test case which gives the positive N (<=2<sup>30</sup>).

// Output Specification:

// For each test case, print the number of 1's in one line.

// Sample Input:
// 12

// Sample Output:
// 5


#include <iostream>
using namespace std;

int main() {
    int N, ans = 0;
    cin >> N;
    for(long m=1; m<=N; m*=10){
        int a = N / m, b = N % m;
        ans += (a+8)/10*m + (a%10==1)*(b+1);
    }
    printf("%d", ans);
    return 0;
}