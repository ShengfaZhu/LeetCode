// Given n, how many structurally unique BST's 
// (binary search trees) that store values 1 ... n?
// Example:
// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// int gen_trees(int start, int end) {
//     int sum = 0;
//     if (start >= end) return 1;
//     for (int i = start; i <= end; i++) {
//         int num_left = gen_trees(start, i - 1);
//         int num_right = gen_trees(i + 1, end);
//         sum = sum + (num_left * num_right);
//     }
//     return sum;
// }

int numTrees(int n) {
    if (n == 1 || n == 0) return 1;
    vector<int> G(n + 1, 0);
    G[0] = 1, G[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= i-1; j++)
            G[i] += G[j] * G[i - j - 1];
    }
    return G[n];
}

int main() {
    cout << numTrees(3) << endl;
    system("pause");
    return 0;
}