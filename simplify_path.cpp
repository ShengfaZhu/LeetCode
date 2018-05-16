// Given an absolute path for a file (Unix-style), simplify it.
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, 
// such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string simplifyPath(string path) {
    vector<string> res;
    int i = 0;
    string tmp;
    while (i < path.size()) {
        // avoid redundant slashes
        if (path[i] == '/' && i > 0 && path[i - 1] == '/') {
            i++;
            continue;
        }    
        if (!tmp.empty() && path[i] == '/') {
            if (tmp == "/." || (res.empty() && tmp == "/..")) {
            }   
            else if (tmp == "/.." && !res.empty())
                res.pop_back();
            else 
                res.push_back(tmp);
            tmp = "";
        }
        tmp.push_back(path[i]);
        i++;
    }
    if (tmp != "/.." && tmp != "/." && tmp != "/") {
        res.push_back(tmp);
    }
    else if (tmp == "/.." && !res.empty()) {
        res.pop_back();
    }
    if (res.empty())
        return "/";
    string simplifed_path;
    for (string &s : res)
        simplifed_path += s;
    return simplifed_path;
}

int main() {
    string path = "/home/";
    cout << "Simplified path : " << simplifyPath(path) << endl;
    system("pause");
    return 0;
}