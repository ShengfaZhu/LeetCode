#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <list>
#include <climits>
#include <stack>
#include <vector>
using namespace std;

// dijstra algorithm
double min_distance(const vector<list<pair<int, double>>>& adj, int s, int e) {
    int num_node = adj.size();
    vector<double> distance(num_node, INT_MAX);
    vector<int> status(num_node, 0);// 0-discovered, 1-discovered
    distance[s] = 1.0;
    status[s] = 1;
    stack<int> discovered_nodes;
    discovered_nodes.push(s);
    while (!discovered_nodes.empty()) {
        int sz = discovered_nodes.size();
        while (sz--) {
            int curr = discovered_nodes.top();
            discovered_nodes.pop();
            for (auto it = adj[curr].begin(); it != adj[curr].end(); it++) {
                if (status[it->first] == 0) {
                    discovered_nodes.push(it->first);
                    status[it->first] = 1;
                    distance[it->first] = min(distance[it->first], distance[curr] * it->second);
                }    
            }
        }
    }
    if (e < distance.size() && distance[e] < INT_MAX)
        return distance[e];
    else return -1.0;
}

vector<double> calcEquation(vector<pair<string, string>> equations, 
    vector<double>& values, vector<pair<string, string>> queries) {
    unordered_map<string, int> my_map;
    // build directed graph with weight
    int count = 0;
    vector<list<pair<int, double>>> adj;// adjacent list, outdegree
    for (int i = 0; i < equations.size(); i++) {
        if (my_map.find(equations[i].first) == my_map.end()) {
            my_map[equations[i].first] = count++;
            adj.push_back(list<pair<int, double>>());
        }
        if (my_map.find(equations[i].second) == my_map.end()) {
            my_map[equations[i].second] = count++;
            adj.push_back(list<pair<int, double>>());            
        }
        adj[my_map[equations[i].first]].push_back(make_pair(my_map[equations[i].second], values[i]));
        adj[my_map[equations[i].second]].push_back(make_pair(my_map[equations[i].first], 1.0 / values[i]));
    }
    for (int i = 0; i < adj.size(); i++) {
        for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
            cout << "(" << i << ", " << it->first << ": " << it->second << ")" << "\t";
        }
        cout << endl;
    }
    // query distance
    vector<double> res;
    for (auto it = queries.begin(); it != queries.end(); it++) {
        if (my_map.find(it->first) == my_map.end() || my_map.find(it->second) == my_map.end())
            res.push_back(-1.0);
        else if (it->first == it ->second) res.push_back(1.0);
        else res.push_back(min_distance(adj, my_map[it->first], my_map[it->second]));
    }
    return res;
}

int main() {
    vector<pair<string, string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<pair<string, string>> queries = { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };
    vector<double> res = calcEquation(equations, values, queries);
    for (double d : res) cout << d << "\t";
    system("pause");
    return 0;
}