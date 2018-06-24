// 310. Minimum Height Trees
#include <iostream>
#include <vector>
#include <list>
#include <utility>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    if (n == 1) return vector<int>(1, 0);
    // convert edges to adjacent list
    vector<list<int>> adj(n);
    for (auto e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }
/*     for (int i = 0; i < n; i++){
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
            cout << *it << "\t";
        cout << endl;
    }   */ 
    // shrink from leaves
    vector<int> leaves;
    for (int i = 0; i < n; i++){
        if (adj[i].size() == 1)
            leaves.push_back(i);
    }
    while (n > 2) {
        n = n - leaves.size();
        vector<int> new_leaves;
        // delet leaves
        for (int i : leaves) {
            int j = adj[i].front();
            for (auto it = adj[j].begin(); it != adj[j].end(); it++)
                if (*it == i) {
                    adj[j].erase(it);
                    break;
                }
            adj[i].clear();
            // generate new leaves
            if (adj[j].size() == 1)
                new_leaves.push_back(j);
        }      
        leaves = new_leaves;
    }
    return leaves;
}

int main() {
    vector<pair<int, int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    vector<int> roots = findMinHeightTrees(4, edges);
    for(int i : roots) cout << i << "\t";
    system("pause");
    return 0;
}