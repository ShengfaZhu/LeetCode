class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int> > arrangements = permutation(n);
        vector<vector<string>> res;
        // check each arrangement
        for (auto& arrangement : arrangements) {
            if (check(arrangement) == true) {
                res.push_back(convert(arrangement));
            }
        }
        return res;
    }
    
    bool check(const vector<int>& arrangement) {
        for (int i = 0; i + 1 < arrangement.size(); ++i) {
            for (int j = i + 1; j < arrangement.size(); ++j) {
                if (abs(i - j) == abs(arrangement[i] - arrangement[j])) {
                    return false;
                }
            }
        }
        return true;
    }
    
    vector<string> convert(const vector<int>& arrangement) {
        // initillization
        vector<string> ans(arrangement.size(), string(arrangement.size(), '.'));
        // put Q in place
        for (int i = 0; i < arrangement.size(); ++i) {
            ans[i][arrangement[i] - 1] = 'Q';
        }
        return ans;
    }
    
    vector<vector<int> > permutation(const int& n) {
        vector<int> nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }
        vector<vector<int> > arrangement;
        permutation(nums, arrangement, 0);
        return arrangement;
    }
    
    void permutation(vector<int> curr, vector<vector<int> >& ans, int i) {
        if (i + 1 == curr.size()) {
            ans.push_back(curr);
            return;
        }
        for (int j = i; j < curr.size(); ++j) {
            swap(curr[i], curr[j]);
            permutation(curr, ans, i + 1);
            swap(curr[i], curr[j]);
        }
    }
};