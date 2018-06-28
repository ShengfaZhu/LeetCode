// 332. Reconstruct Itinerary
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <set>
#include <string>
using namespace std;

// greedy search algorithm
void backtrack(unordered_map<string, multiset<string>>& adj, vector<string>& route, string department) {
    while (adj.find(department) != adj.end() && adj[department].size() > 0) {
        cout << department << endl;
        string next = *adj[department].begin();
        adj[department].erase(adj[department].begin());
        backtrack(adj, route, next);
    }
    // cout << department << endl;
    route.push_back(department);
}

// using multiset to store destination is a really smart choice. 
// when put airport into multiset, the airports will keep lexical order automatically.
// Because there are same tickets, using multiset instead of set is essential.
vector<string> findItinerary(vector<pair<string, string>> tickets) {
    // generate adajacent list
    unordered_map<string, multiset<string>> adj;
    for (auto it = tickets.begin(); it != tickets.end(); it++)
            adj[it->first].emplace(it->second);
    vector<string> route;
    backtrack(adj, route, "JFK");
    return vector<string>(route.rbegin(), route.rend());
}
 
int main() {
    vector<pair<string, string>> tickets = {{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},
    {"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
    vector<string> itinerary = findItinerary(tickets);
    for (string str : itinerary) cout << str << "\t";
    system("pause");
    return 0;
}