// 1023. Have Fun with Numbers (20)

// Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication.  Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation.  Check to see the result if we double it again!

// Now you are suppose to check if there are more numbers with this property.  That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

// Input Specification:

// Each input file contains one test case.  Each case contains one positive integer with no more than 20 digits.

// Output Specification:

// For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not.  Then in the next line, print the doubled number.

// Sample Input:
// 1234567899

// Sample Output:
// Yes
// 2469135798


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string num1, num2;
    cin >> num1;
    reverse(num1.begin(), num1.end());

    int carry=0;
    for(int i=0; i<num1.size(); ++i){
        int n = 2 * (num1[i]-'0') + carry;
        num2 += n%10 + '0';
        carry = n/10;
    }
    if(carry!=0)
        num2+=carry+'0';

    int hash_table[10] = {0};
    for(int i=0; i<num1.size(); ++i){
        hash_table[num1[i]-'0']++;
        hash_table[num2[i]-'0']--;
    }

    string flag = (count(hash_table, hash_table+10, 0)==10) ? "Yes": "No";
    cout << flag << endl;
    reverse(num2.begin(), num2.end());
    cout << num2;
    return 0;
}