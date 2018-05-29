// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *>& is_cloned) {
    if (node == NULL) return NULL;
    if (is_cloned.find(node->label) != is_cloned.end()) return is_cloned[node->label]; 
    UndirectedGraphNode *source = new UndirectedGraphNode(node->label);
    is_cloned[source->label] = source;
    for (auto it : node->neighbors) {
        UndirectedGraphNode *tmp = cloneGraph(it, is_cloned);
        source->neighbors.push_back(tmp);
    }
    return source;
} 

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL) return node;
    unordered_map<int, UndirectedGraphNode *> is_cloned;
    return cloneGraph(node, is_cloned);
}