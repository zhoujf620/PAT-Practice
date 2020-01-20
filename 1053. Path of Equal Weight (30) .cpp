// 1053. Path of Equal Weight (30)

// Given a non-empty tree with root R, and with weight Wi assigned to each tree node Ti.  The weight of a path from R to L is defined to be the sum of the weights of all the nodes along the path from R to any leaf node L.

// Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number.  For example, let's consider the tree showed in Figure 1: for each node, the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node.  Suppose that the given number is 24, then there exists 4 different paths which have the same given weight: {10 5 2 7}, {10 4 10}, {10 3 3 6 2} and {10 3 3 6 2}, which correspond to the red edges in Figure 1.

// <center><img src="http://nos.patest.cn/5b_mj58f84v11w.jpg"/><br/>Figure 1</center>

// Input Specification:

// Each input file contains one test case.  Each case starts with a line containing 0 < N <= 100, the number of nodes in a tree, M (< N), the number of non-leaf nodes, and 0 < S < 2<sup>30</sup>, the given weight number. The next line contains N positive numbers where Wi (<1000) corresponds to the tree node Ti.  Then M lines follow, each in the format:
// ID K ID[1 ID[2 ... ID[K

// where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 00.

// Output Specification:

// For each test case, print all the paths with weight S in non-increasing
//  order.  Each path occupies a line with printed weights from the root to the leaf in order.  All the numbers must be separated by a space with no extra space at the end of the line.

// Note: sequence {A1, A2, ..., An} is said to be greater than
//  sequence {B1, B2, ..., Bm} if there exists 1 <= k < min{n, m} such that Ai = Bi for i=1, ... k, and Ak+1 &gt; Bk+1.

// Sample Input:
// 20 9 24
// 10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
// 00 4 01 02 03 04
// 02 1 05
// 04 2 06 07
// 03 3 11 12 13
// 06 1 09
// 07 2 08 10
// 16 1 15
// 13 3 14 16 17
// 17 2 18 19

// Sample Output:
// 10 5 2 7
// 10 4 10
// 10 3 3 6 2
// 10 3 3 6 2



#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int N, M, S, weights[101];
vector<int> tree[101], path;

void DFS(int node,int pathWeight){
    pathWeight += weights[node];
    
    if(pathWeight>S || (pathWeight==S && !tree[node].empty()))
        return;

    path.push_back(node);
    if(pathWeight==S)
        for(int i=0; i<path.size(); i++)
            printf("%s%d%s",i>0?" ":"",weights[path[i]], i==path.size()-1?"\n":"");   
    for(int child: tree[node])
        DFS(child, pathWeight);
    path.pop_back();
}

int main(){
    cin >> N >> M >> S;
    for(int i=0; i<N; i++)
        scanf("%d", &weights[i]);

    while(M--){
        int id, K, child_id;
        scanf("%d%d", &id, &K);

        while(K--){
            scanf("%d",&child_id);
            tree[id].push_back(child_id);
        }

        sort(tree[id].begin(),tree[id].end(),[](int a,int b){
            return weights[a]>weights[b];
        });
    }

    DFS(0, 0);
    return 0;
}
