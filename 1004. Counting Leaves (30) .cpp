
// 1004. Counting Leaves (30)

// A family hierarchy is usually presented by a pedigree tree.  Your job is to count those family members who have no child.

// Input

// Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes.  Then M lines follow, each in the format:
// ID K ID[1 ID[2 ... ID[K

// where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children.  For the sake of simplicity, let us fix the root ID to be 01.

// Output

// For each test case, you are supposed to count those family members who have no child for every seniority level
//  starting from the root.  The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
// The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child.  Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node.  Then we should output "0 1" in a line.

// Sample Input
// 2 1
// 01 1 02

// Sample Output
// 0 1


#include <iostream>
#include <vector>
using namespace std;

vector<int> nodes[100];
int res[100], max_depth = -1;

void DFS(int index, int depth) {
    if(nodes[index].size() == 0) {
        res[depth]++;
        max_depth = max(max_depth, depth);
        return ;
    }
    for(int i = 0; i < nodes[index].size(); i++)
        DFS(nodes[index][i], depth + 1);
}

int main() {
    int N, M, K, node, child;

    cin >> N >> M;
    for(int i = 0; i <M; i++) {
        cin >> node >> K;
        for(int j = 0; j < K; j++) {
            cin >> child;
            nodes[node].push_back(child);
        }
    }

    DFS(1, 0);
    cout << res[0];
    for(int i = 1; i <= max_depth; i++)
        cout << " " << res[i];
    return 0;
}