// 210. Course Schedule II
// adjacent linklisk to represent directed graph, out-edge list
vector<vector<int>> generate_graph(int num_vertex, vector<pair<int, int>>& edges) {
    vector<vector<int>> adjacent_list(num_vertex);
    for (auto it = edges.begin(); it != edges.end(); it++) {
        adjacent_list[it->second].push_back(it->first);
    }
    return adjacent_list;
}

// Depth first search based on adjacent list
vector<int> dfs(vector<vector<int>> adjacent_list, int num_vertex) {
    vector<int> ans;
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
                        return vector<int>();//loop exist
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
                    ans.insert(ans.begin(), curr);
                }
            }
        }
    }
    
    // topo sort acording to visit time
    return ans;
    
}

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adjacent_list = generate_graph(numCourses,  prerequisites);
    return dfs(adjacent_list, numCourses);
}