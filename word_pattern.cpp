// 290. Word Pattern
bool wordPattern(string pattern, string str) {
    // split str by blankspace
    vector<string> s;
    int i = 0, j = 0;
    while (j < str.size()) {
        if (str.at(j) == ' ') {
            s.push_back(str.substr(i, j - i));
            i = j + 1;
        }
        j++;
    }
    s.push_back(str.substr(i, j - i));
    if (s.size() != pattern.size()) return false;

    // build map and check
    unordered_map<string, int> map1;
    unordered_map<char, int> map2;
    for (int k = 0; k < pattern.size(); k++) {
        if (map1.find(s[k]) == map1.end() && map2.find(pattern[k]) == map2.end()) {
            map1[s[k]] = k;
            map2[pattern[k]] = k;
        }
        else if (map1.find(s[k]) != map1.end() && map2.find(pattern[k]) != map2.end()) {
            if (map1[s[k]] != map2[pattern[k]]) return false;
        }
        else return false;
    }
    return true;
}