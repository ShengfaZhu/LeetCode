// 331. Verify Preorder Serialization of a Binary Tree
bool isValidSerialization(string preorder) {
    // split
    vector<string> nodes;
    int start = 0, i = 0;
    while (i < preorder.size()) {
        if (preorder[i] == ',') {
            nodes.push_back(preorder.substr(start, i - start));
            start = i + 1;
        }
        i++;
    }
    nodes.push_back(preorder.substr(start, i - start));
    // calculate diff = outdegree - indegree
    int diff = 1;// diff = outdegree - indegree
    for (string str: nodes) {
        if (--diff < 0) return false;
        if (str != "#") diff = diff + 2;
    }
    return diff == 0;
}