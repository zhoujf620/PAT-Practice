// 1001 A+B Format (20分)

// Calculate a + b and output the sum in standard format — that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

// Input
// Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

// Output
// For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

// Sample Input
// -1000000 9

// Sample Output
// -999,991

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    int s_size = s.size();
    for (int i = 0; i < s_size; i++) {
        cout << s[i];
        if (s[i] == '-') 
            continue;
        if ((i + 1) % 3 == s_size % 3 && i != s_size - 1) 
            cout << ",";
    }
    return 0;
}
