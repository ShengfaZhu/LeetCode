// 454. 4Sum II
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> map;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            if (map.find(A[i] + B[j]) == map.end()) map[A[i] + B[j]] = 1;
            else map[A[i] + B[j]]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < D.size(); j++) {
            if (map.find(-1 * (C[i] + D[j])) != map.end())
                ans += map[-1 * (C[i] + D[j])];
        }
    }
    return ans;
}