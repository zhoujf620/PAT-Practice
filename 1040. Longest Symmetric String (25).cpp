// 1040. Longest Symmetric String (25)

// Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&amp;TAP symmetric?", the longest symmetric sub-string is "s PAT&amp;TAP s", hence you must output 11.

// Input Specification:

// Each input file contains one test case which gives a non-empty string of length no more than 1000.

// Output Specification:

// For each test case, simply print the maximum length in a line.

// Sample Input:
// Is PAT&amp;TAP symmetric?

// Sample Output:
// 11


#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    const int size_s = s.size();

    int max_len = 0;
    for (int i=0; i<size_s;) {
        int start = i, end = i;
        
        while (end+1<size_s and s[end]==s[end+1]) end ++;
        i = end + 1;

        while (start-1>=0 and end+1<size_s and s[start-1]==s[end+1]) {
            start--;
            end++;
        }
        
        if (end-start+1 > max_len) {
            max_len = end-start+1;
        }
    }
    cout << max_len;
    return 0;
}