// 1005. Spell It Right (20)

// Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

// Input Specification:

// Each input file contains one test case. Each case occupies one line which contains an N (<= 10<sup>100</sup>).

// Output Specification:

// For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line. 

// Sample Input:
// 12345

// Sample Output:
// one five

#include <iostream>
using namespace std;
int main() {
    string N;
    cin >> N;

    int sum = 0;
    for (int i = 0; i < N.size(); i++)
        sum += (N[i] - '0');

    string s = to_string(sum);
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    cout << arr[s[0] - '0'];
    for (int i = 1; i < s.length(); i++)
        cout << " " << arr[s[i] - '0'];
    return 0;
}