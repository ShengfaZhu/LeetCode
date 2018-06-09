// 207. Course Schedule
// There are a total of n courses you have to take, labeled from 0 to n-1.
// Some courses may have prerequisites, for example to take course 0 you 
// have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, 
// is it possible for you to finish all courses?

#include <iostream>
#include <vector>
#include <stack>
#include <utility>// header file for pair
using namespace std;

// adjacent linklisk to represent directed graph, out-edge list
vector<vector<int>> generate_graph(int num_vertex, vector<pair<int, int>>& edges) {
    vector<vector<int>> adjacent_list(num_vertex);
    for (auto it = edges.begin(); it != edges.end(); it++) {
        adjacent_list[it->second].push_back(it->first);
    }
    return adjacent_list;
}

// Depth first search based on adjacent list
bool dfs(vector<vector<int>> adjacent_list, int num_vertex) {
    // 0: undiscovered, 1: discovered, 2: visited
    vector<int> status(num_vertex, 0);
    vector<vector<int>> time(num_vertex, vector<int>(2, 0));
    stack<int> st;// assited stack for dfs
    int t = 1;
    for (int k = 0; k < num_vertex; k++) {
        if (status[k] == 0) {
            int source = k;
            st.push(source);
            time[source][0] = t++;
            status[source] = 1;
            while (!st.empty()) {
                int curr = st.top();
                for (int j = 0; j < adjacent_list[curr].size(); j++) {
                    int target = adjacent_list[curr][j];
                    if (status[target] == 1) {
                        return false;//loop exist
                    }
                }
                int i = 0;
                for (;i < adjacent_list[curr].size(); i++) {
                    int target = adjacent_list[curr][i];
                    if (status[target] == 0) {
                        st.push(target);
                        status[target] = 1;
                        time[target][0] = t++;
                        break;
                    }
                }
                if (i == adjacent_list[curr].size()) {
                    st.pop();
                    status[curr] = 2;
                    time[curr][1] = t++;
                }
            }
        }
    }
    return true; 
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    return true;
}

int main() {
    
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(pair<int, int>(1, 0));
    prerequisites.push_back(pair<int, int>(3, 0));
    prerequisites.push_back(pair<int, int>(1, 3));
    prerequisites.push_back(pair<int, int>(4, 1));
    prerequisites.push_back(pair<int, int>(4, 2));
    prerequisites.push_back(pair<int, int>(5, 2));
    prerequisites.push_back(pair<int, int>(3, 4));
    int num_vertex = 6;
    vector<vector<int>> list = generate_graph(num_vertex, prerequisites);
    dfs(list, num_vertex);
    system("pause");
    return 0;
}