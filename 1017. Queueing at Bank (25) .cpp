
// 1017. Queueing at Bank (25)

// Suppose a bank has K windows open for service.  There is a yellow line in front of the windows which devides the waiting area into two parts.  All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available.  It is assumed that no window can be occupied by a single customer for more than 1 hour.

// Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.

// Input Specification:

// Each input file contains one test case.  For each case, the first line contains 2 numbers: N (<=10000) - the total number of customers, and K (<=100) - the number of windows.  Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer.  Here HH is in the range [00, 23, MM and SS are both in [00, 59.  It is assumed that no two customers arrives at the same time.

// Notice that the bank opens from 08:00 to 17:00.  Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

// Output Specification:

// For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.

// Sample Input:
// 7 3
// 07:55:00 16
// 17:00:01 2
// 07:59:59 15
// 08:01:00 60
// 08:00:00 30
// 08:00:02 2
// 08:03:00 10


// Sample Output:
// 8.2



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Customer {
    int arrive_time, process_time;
};

bool cmp(Customer a, Customer b) {
    return a.arrive_time < b.arrive_time;
}

int close_time = 17*60*60;
int main() {
    int N, K;
    cin >> N >> K;

    vector<Customer> customers;
    for(int i = 0; i < N; i++) {
        int hh, mm, ss, process_time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &process_time);

        int arrive_time = hh * 3600 + mm * 60 + ss;
        if(arrive_time > close_time) continue;
        customers.push_back({arrive_time, process_time*60});
    }
    sort(customers.begin(), customers.end(), cmp);

    vector<int> windows(K, 28800);
    float wait_time = 0.0;
    for(int i = 0; i < customers.size(); i++) {
        int win_idx = 0, win_finish = windows[0];
        for(int j = 1; j < K; j++) {
            if(win_finish > windows[j]) {
                win_finish = windows[j];
                win_idx = j;
            }
        }
        if(windows[win_idx] <= customers[i].arrive_time) {
            windows[win_idx] = customers[i].arrive_time + customers[i].process_time;
        } 
        else {
            wait_time += (windows[win_idx] - customers[i].arrive_time);
            windows[win_idx] += customers[i].process_time;
        }
    }
    if(customers.size() == 0)
        printf("0.0");
    else
        printf("%.1f", wait_time / 60.0 / customers.size());
    return 0;
}