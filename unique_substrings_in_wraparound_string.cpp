// 467. Unique Substrings in Wraparound String
int findSubstringInWraproundString(string p) {
    // len of end with curr letter
    vector<int> count(26, 0);
    int curr_len = 0;
    for (int i = 0; i < p.size(); i++) {
        if (i > 0 && (p[i] - p[i-1] == 1 || p[i-1] - p[i] == 25))
            curr_len++;
        else curr_len = 1;
        count[p[i] - 'a'] = max(count[p[i] - 'a'], curr_len);
    }
    int sum = 0;
    for (int n : count) sum += n;
    return sum;
}