// 1024. Palindromic Number (25)

// A number that will be the same when it is written forwards or backwards is known as a Palindromic Number.  For example, 1234321 is a palindromic number.  All single digit numbers are palindromic numbers.

// Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number.  For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

// Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

// Input Specification:

// Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 10<sup>10</sup>) is the initial numer and K (<= 100) is the maximum number of steps.  The numbers are separated by a space.

// Output Specification:

// For each test case, output two numbers, one in each line.  The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number.  If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

// Sample Input 1:
// 67 3

// Sample Output 1:
// 484
// 2

// Sample Input 2:
// 69 3

// Sample Output 2:
// 1353
// 3


#include <iostream>
#include <algorithm>
using namespace std;

string str_add(string s, string t) {
    int carry = 0;
    for(int i = 0; i < s.length(); i++) {
        s[i] = s[i] + (t[i]-'0') + carry;
        carry = 0;
        if(s[i] > '9') {
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if(carry) s += '1';
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string num;
    int max_step;
    cin >> num >> max_step;
    
    int step = 0;
    for(; step < max_step; step++) {
        string num_rev = num;
        reverse(num_rev.begin(), num_rev.end());
        if(num == num_rev) break;
        num = str_add(num, num_rev);
    }
    cout << num << endl << step;
    return 0;
}