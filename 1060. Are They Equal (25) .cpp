// 1060. Are They Equal (25)

// If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123*10<sup>5</sup> with simple chopping.  Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.

// Input Specification:

// Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A and B are the two float numbers to be compared.  Each float number is non-negative, no greater than 10<sup>100</sup>, and that its total digit number is less than 100.

// Output Specification:

// For each test case, print in a line "YES" if the two numbers are treated equal, and then the number in the standard form "0.d1...dN*10^k" (d1&gt;0 unless the number is 0); or "NO" if they are not treated equal, and then the two numbers in their standard form.  All the terms must be separated by a space, with no extra space at the end of a line.

// Note: Simple chopping is assumed without rounding.

// Sample Input 1:
// 3 12300 12358.9

// Sample Output 1:
// YES 0.123*10^5

// Sample Input 2:
// 3 120 128

// Sample Output 2:
// NO 0.120*10^3 0.128*10^3


// #include <iostream>
// #include <string.h>
// using namespace std;
// int main() {
//     int N;
//     char A[10000], B[10000];
//     scanf("%d%s%s", &N, A, B);

//     for (int i=0; i<; i++) {
//         if (A[i]=='.')
//     }

#include<string>
#include<iostream>
using namespace std;

int helper(string& str, string& str_sig, int N){
    int point_idx = str.size(), nozero_idx=-1;
    for(int i=0; i<str.size(); i++) {
        if(str[i]=='.')
            point_idx = i;
        else if(nozero_idx==-1 && str[i]!='0'){
            nozero_idx=i;
            str_sig+=str[i];
        }
        else if(nozero_idx!=-1 && str_sig.size()<N)
            str_sig += str[i];
    }

    while(str_sig.size() < N)
        str_sig+="0";
    if(nozero_idx == -1)
        return 0;
    point_idx -= nozero_idx;
    return point_idx<0 ? point_idx+1 : point_idx;
}

int main(){
    int N;
    string A, B, A_sig="", B_sig="";
    cin >> N >> A >> B;
    int A_exp = helper(A, A_sig, N), B_exp = helper(B, B_sig, N);
    if(A_exp==B_exp && A_sig==B_sig)
        cout << "YES 0." << A_sig << "*10^" << A_exp;
    else
        cout << "NO 0." << A_sig << "*10^" << A_exp << " 0."<<B_sig << "*10^"<<B_exp;
    return 0;
}
