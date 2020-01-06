// 1008. Elevator (20)

// The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

// For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

// Input Specification:

// Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

// Output Specification:

// For each test case, print the total time on a single line. 

// Sample Input:
// 3 2 3 1

// Sample Output:
// 41


#include <iostream>
using namespace std;

int main() {
    int next, cur = 0, sum = 0;
    cin >> next;

    while(cin >> next) {
        if(next > cur)
            sum += 6 * (next - cur);
        else
            sum += 4 * (cur - next);
        cur = next;
        sum += 5;
    }

    cout << sum;
    return 0;
}