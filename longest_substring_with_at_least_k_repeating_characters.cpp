#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestSubstring(string s, int k) {
    int max_len = 0;
    for (int h = 1; h <= 26; h++) {
        int slow = 0, fast = 0, unique = 0, noLessThanK = 0;
        vector<int> count(26, 0);
        while (fast < s.size()) {
            if (unique <= h) {
                int idx = s[fast] - 'a';
                if (count[idx] == 0) unique++;
                count[idx]++;
                if (count[idx] == k) noLessThanK++;
                fast++;
            }
            else {
                int idx = s[slow] - 'a';
                if (count[idx] == k) noLessThanK--;
                count[idx]--;
                if (count[idx] == 0) unique--;
                slow++;
            }
            if (noLessThanK == h && unique == h)
                max_len = max(max_len, fast - slow);
        }
    }
    return max_len;
}

int main() {
    string s = "ababbc";
    int k = 2;
    cout << longestSubstring(s, k) << endl;
    system("pause");
    return 0;
}