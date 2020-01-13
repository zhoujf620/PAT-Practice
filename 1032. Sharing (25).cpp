// 1032. Sharing (25)

// To store English words, one method is to use linked lists and store a word letter by letter.  To save some space, we may let the words share the same sublist if they share the same suffix.  For example, "loading" and "being" are stored as showed in Figure 1.

// <center><img src="http://nos.patest.cn/1w_m16pjsommxz.jpg"/><br/>Figure 1</center>

// You are supposed to find the starting position of the common suffix (e.g. the position of "i" in Figure 1).

// Input Specification:

// Each input file contains one test case.  For each case, the first line contains two addresses of nodes and a positive N (<= 10<sup>5</sup>), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes.  The address of a node is a 5-digit positive integer, and NULL is represented by -1.

// Then N lines follow, each describes a node in the format:

// <i>Address Data Next</i>

// where <i>Address</i> is the position of the node, <i>Data</i> is the letter contained by this node which is an English letter chosen from {a-z, A-Z}, and <i>Next</i> is the position of the next node.

// Output Specification:

// For each case, simply output the 5-digit starting position of the common suffix.  If the two words have no common suffix, output "-1" instead.

// Sample Input 1:
// 11111 22222 9
// 67890 i 00002
// 00010 a 12345
// 00003 g -1
// 12345 D 67890
// 00002 n 00003
// 22222 B 23456
// 11111 L 00001
// 23456 e 67890
// 00001 o 00010


// Sample Output 1:
// 67890


// Sample Input 2:
// 00001 00002 4
// 00001 a 10001
// 10001 s -1
// 00002 a 10002
// 10002 t -1


// Sample Output 2:
// -1


#include <iostream>
using namespace std;

struct NODE {
    char key;
    int next;
    bool visited;
}node[100001];

int main() {
    int start1, start2, N;
    cin >> start1 >> start2 >> N;

    int addr, next_addr;
    char data;
    for(int i = 0; i < N; i++) {
        scanf("%d %c %d", &addr, &data, &next_addr);
        node[addr] = {data, next_addr, false};
    }

    for(int i = start1; i != -1; i = node[i].next)
        node[i].visited = true;
    for(int i = start2; i != -1; i = node[i].next) {
        if(node[i].visited == true) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}