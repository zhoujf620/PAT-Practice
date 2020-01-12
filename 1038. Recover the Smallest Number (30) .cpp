// 1038. Recover the Smallest Number (30)

// Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given {32, 321, 3214, 0229, 87}, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.

// Input Specification:

// Each input file contains one test case.  Each case gives a positive integer N (<=10000) followed by N number segments.  Each segment contains a non-negative integer of no more than 8 digits.  All the numbers in a line are separated by a space.

// Output Specification:

// For each test case, print the smallest number in one line.  Do not output leading zeros.

// Sample Input:
// 5 32 321 3214 0229 87

// Sample Output:
// 22932132143287



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool my_sort(string a, string b) {
    return a + b < b + a;
}

string nums[10001];
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> nums[i];

    sort(nums, nums + N, my_sort);

    string num;
    for(int i = 0; i < N; i++)
        num += nums[i];

    while(num.length() != 0 && num[0] == '0')
        num.erase(num.begin());
    if(num.length() == 0) 
        cout << 0;
    cout << num;
    return 0;
}