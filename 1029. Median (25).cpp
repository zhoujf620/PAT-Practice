// 1029. Median (25)

//   Given an increasing sequence S of N integers, the <i>median</i> is the number at the middle position.  For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15.  The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences.  For example, the median of S1 and S2 is 13.

// Given two increasing sequences of integers, you are asked to find their median.

// Input

// Each input file contains one test case.  Each case occupies 2 lines, each gives the information of a sequence.  For each sequence, the first positive integer N (<=1000000) is the size of that sequence.  Then N integers follow, separated by a space.  It is guaranteed that all the integers are in the range of long int
// .

// Output

// For each test case you should output the median of the two given sequences in a line.

// Sample Input
// 4 11 12 13 14
// 5 9 10 15 16 17

// Sample Output
// 13


#include<iostream>
using namespace std;

int MAX = 0x7fffffff;

int main(){
    int N;
    cin >> N;
    int nums1[N+1];
    for (int i=0; i<N; i++) {
        scanf("%d", &nums1[i]);
    }
    nums1[N] = MAX;

    int M;
    cin >> M;
    int i=0, j=1, num2, median;
    scanf("%d", &num2);

    for(int k=0; k<(N+M+1)/2; k++) {
        if(nums1[i] < num2){
            median = nums1[i];
            i++;
        }
        else{
            median = num2;
            if(j < M) scanf("%d", &num2);
            else num2 = MAX;
            j++;
        }
    }
    cout << median;
    return 0;
}
