// 1020. Tree Traversals (25)

// Suppose that all the keys in a binary tree are distinct positive integers.  Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

// Input Specification:

// Each input file contains one test case.  For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree.  The second line gives the postorder sequence and the third line gives the inorder sequence.  All the numbers in a line are separated by a space.

// Output Specification:

// For each test case, print in one line the level order traversal sequence of the corresponding binary tree.  All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

// Sample Input:
// 7
// 2 3 1 5 7 6 4
// 1 2 3 4 5 6 7

// Sample Output:
// 4 1 6 3 5 7 2


#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorder, inorder;
unordered_map<int, int> hash_map;

TreeNode* DFS(int l, int r) {
    if (l > r) return nullptr;

    TreeNode* root = new TreeNode(postorder.back());
    postorder.pop_back();
    int m = hash_map[root->val];
    
    root->right = DFS(m+1, r);
    root->left = DFS(l, m-1);
    return root;
}

int main() {
    int N;
    cin >> N;

    inorder.resize(N);
    postorder.resize(N);

    for (int i = 0; i < N; i++) scanf("%d", &postorder[i]);
    for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
    for (int i=0; i<inorder.size(); i++) {
        hash_map[inorder[i]] = i;
    }

    TreeNode* root = DFS(0, N-1);
    
    queue<TreeNode*> q;
    q.push(root);
    int flag = 0;

    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if (flag!=0) cout << " ";
        cout << cur->val;
        flag = 1;

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }

    return 0;
}