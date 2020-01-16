// 1044. Shopping in Mars (25)

// Shopping in Mars is quite a different experience.  The Mars people pay by chained diamonds.  Each diamond has a value (in Mars dollars M$).  When making the payment, the chain can be cut at any position for only once and some of the diamonds are taken off the chain one by one.  Once a diamond is off the chain, it cannot be taken back.  For example, if we have a chain of 8 diamonds with values M$3, 2, 1, 5, 4, 6, 8, 7, and we must pay M$15.  We may have 3 options:

// 1. Cut the chain between 4 and 6, and take off the diamonds from the position 1 to 5 (with values 3+2+1+5+4=15).<br/>
// 2. Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 (with values 5+4+6=15).<br/>
// 3. Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8+7=15).<br/>

// Now given the chain of diamond values and the amount that a customer has to pay, you are supposed to list all the paying options for the customer.

// If it is impossible to pay the exact amount, you must suggest solutions with minimum lost. 

// Input Specification:

// Each input file contains one test case.  For each case, the first line contains 2 numbers: N (<=10<sup>5</sup>), the total number of diamonds on the chain, and M (<=10<sup>8</sup>), the amount that the customer has to pay.  Then the next line contains N positive numbers D1 ... DN (Di<=10<sup>3</sup> for all i=1, ..., N) which are the values of the diamonds.  All the numbers in a line are separated by a space.

// Output Specification:

// For each test case, print "i-j" in a line for each pair of i <= j such that Di + ... + Dj = M.  Note that if there are more than one solution, all the solutions must be printed in increasing order of i.

// If there is no solution, output "i-j" for pairs of i <= j such that  Di + ... + Dj &gt; M with (Di + ... + Dj - M) minimized.  Again all the solutions must be printed in increasing order of i.

// It is guaranteed that the total value of diamonds is sufficient to pay the given amount. 

// Sample Input 1:
// 16 15
// 3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13

// Sample Output 1:
// 1-5
// 4-6
// 7-8
// 11-11

// Sample Input 2:
// 5 13
// 2 4 5 7 9

// Sample Output 2:
// 2-4
// 4-5


// #include <iostream>
// #include <vector>
// using namespace std;

// int N, M;
// vector<int> cumsums;


// int BiSearch(int i, int &j) {
//     int left = i, right = N;
//     while(left < right) {
//         int mid = (left + right) / 2;
//         if(cumsums[mid] - cumsums[i-1] >= M)
//             right = mid;
//         else
//             left = mid + 1;
//     }
//     j = right;
//     return cumsums[j] - cumsums[i-1];
// }

// int main() {
//     cin >> N >> M;

//     cumsums.resize(N+1);
//     for (int i=1; i<=N; i++) {
//         scanf("%d", &cumsums[i]);
//         cumsums[i] += cumsums[i-1];
//     }

//     vector<int> res;

//     int min_ans = cumsums[N];
//     for(int i = 1; i <= N; i++) {
//         int j;
//         int temp_sum = BiSearch(i, j);

//         if(temp_sum > min_ans) continue;
//         if(temp_sum >= M) {
//             if(temp_sum < min_ans) {
//                 res.clear();
//                 min_ans = temp_sum;
//             }
//             res.push_back(i);
//             res.push_back(j);
//         }
//     }

//     for(int i = 0; i < res.size(); i += 2)
//         printf("%d-%d\n", res[i], res[i+1]);
//     return 0;
// }


#include<iostream>
using namespace std;

int cumsums[100005];

int main(){
    int N, M;
    cin >> N >> M;

    int left = 0, min_diff = 100000001;
    bool isFind = false;

    for (int i=1; i<=N; i++) {
        scanf("%d", &cumsums[i]);
        cumsums[i] += cumsums[i-1];

        while(cumsums[i] - cumsums[left] > M) {
            min_diff = min(min_diff, cumsums[i]-cumsums[left]);
            left ++;
        }
        if(cumsums[i]-cumsums[left] == M) {
            printf("%d-%d\n",left+1,i);
            isFind = true;
        }
    }

    if (!isFind) {
        int j = 0;
        for (int i=0; i<=N; i++) {
            while (cumsums[i]-cumsums[j] > min_diff)
                j++;
            if (cumsums[i]-cumsums[j] == min_diff) 
                printf("%d-%d\n",j+1,i);
        }
    }
    return 0;
}
