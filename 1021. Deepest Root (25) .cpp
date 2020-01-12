// 1021. Deepest Root (25)

// A graph which is connected and acyclic can be considered a tree.  The height of the tree depends on the selected root.  Now you are supposed to find the root that results in a highest tree.  Such a root is called <i>the deepest root</i>.

// Input Specification:

// Each input file contains one test case.  For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N.  Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

// Output Specification:

// For each test case, print each of the deepest roots in a line.  If such a root is not unique, print them in increasing order of their numbers.  In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.

// Sample Input 1:
// 5
// 1 2
// 1 3
// 1 4
// 2 5

// Sample Output 1:
// 3
// 4
// 5

// Sample Input 2:
// 5
// 1 3
// 1 4
// 2 5
// 3 4

// Sample Output 2:
// Error: 2 components


#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<int>> adj(10010);
bool visit[10010];
vector<int> temp_root;
set<int> root_set;
int max_height;

void DFS(int node,int height){
    if(height > max_height) {
        temp_root.clear();
        temp_root.push_back(node);
        max_height = height;
    }
    else if(height == max_height){
        temp_root.push_back(node);
    }

    visit[node] = true;
    for(int i: adj[node])
        if(!visit[i]){
            DFS(i, height+1);
        }
}

int main(){
    int N;
    cin >> N;

    int node1, node2;
    for(int i = 1; i < N; i++) {
        scanf("%d%d", &node1, &node2);
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    int num_conponet = 0;
    for(int i = 1; i<=N; i++) {
        if(!visit[i]) {
            DFS(i, 1);
            num_conponet++;
            if (i==1) {
                for (int j=0; j<temp_root.size(); j++) 
                    root_set.insert(temp_root[j]);
            }
        }
    }

    if(num_conponet>1)
        printf("Error: %d components", num_conponet);
    else{
        int root = temp_root[0];
        temp_root.clear();
        max_height = 0;
        fill(visit, visit+10010, false);
        DFS(root, 1);

        for (int i=0; i<temp_root.size(); i++) 
            root_set.insert(temp_root[i]);

        for(auto it=root_set.begin(); it!=root_set.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}

