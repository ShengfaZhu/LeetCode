class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> indice;
        if (s.empty() || words.empty()) {
            return indice;
        }
        int length = words.at(0).size();
        // establish hash table to record frequence of words
        unordered_map<string, int> count;
        for (auto word : words) {
            if (count.find(word) == count.end()) {
                count[word] = 1;
            }
            else {
                count[word]++;
            }
        }
        // scan string to find matching indice
        int end_ind = s.size() - length * words.size();
        for (int i = 0; i <= end_ind; ++i) {
            if (isMatch(s, i, length, words.size(), count) == true) {
                indice.push_back(i);
            }
        }
        return indice;
    }

private:
    bool isMatch(const string& s, const size_t& start_indice, const size_t& length,
        const int& n_words, unordered_map<string, int> count) {
        if (start_indice >= s.size() || start_indice < 0) {
            return false;
        }
        // scan string from start_indice
        int n_match = 0;
        for (size_t i = start_indice; i < s.size(); i = i + length) {
            string curr = s.substr(i, length);
            if (count.find(curr) == count.end() || count[curr] <= 0) {
                return false;
            }
            else {
                n_match++;
                count[curr]--;
            }
            if (n_match == n_words) {
                return true;
            }
        }
        return true;
    }
};