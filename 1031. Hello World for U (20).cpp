// 1031. Hello World for U (20)

// Given any string of N (&gt;=5) characters, you are asked to form the characters into the shape of U.  For example, "helloworld" can be printed as:h  d
// e  l
// l  r
// lowo

// That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters.  And more, we would like U to be as squared as possible -- that is, it must be satisfied that n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.

// Input Specification:

// Each input file contains one test case.  Each case contains one string with no less than 5 and no more than 80 characters in a line.  The string contains no white space.

// Output Specification:

// For each test case, print the input string in the shape of U as specified in the description.

// Sample Input:
// helloworld!

// Sample Output:
// h   !
// e   d
// l   l
// lowor


#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char ch[81], u[30][30];
    memset(u, ' ', sizeof(u));
    scanf("%s", ch);

    int n = strlen(ch) + 2;
    int n1 = n / 3, n2 = n / 3 + n % 3, index = 0;

    for(int i = 0; i < n1; i++) 
        u[i][0] = ch[index++];
    for(int i = 1; i <= n2 - 2; i++) 
        u[n1-1][i] = ch[index++];
    for(int i = n1 - 1; i >= 0; i--) 
        u[i][n2-1] = ch[index++];
        
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) 
            printf("%c", u[i][j]);
        printf("\n");
    }
    return 0;
}