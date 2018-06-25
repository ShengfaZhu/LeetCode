// 318. Maximum Product of Word Lengths
// convert words to an integer, excellent method 
// to determine if two words share common letter
int maxProduct(vector<string>& words) {
    int sz = words.size();
    if (sz == 0 || sz == 1) return 0;
    // cout letter
    vector<int> count(words.size(), 0);
    for (int i = 0; i < words.size(); i++) {
        for (char ch : words[i]) 
            count[i] |= 1 << (ch - 'a');
    }
    // find max product
    int max_product = 0;
    for (int i = 0; i < count.size(); i++) {
        for (int j = i+1; j < count.size(); j++) {
            if ((count[i] & count[j]) == 0 && (words[i].size() * words[j].size() > max_product))
                max_product = words[i].size() * words[j].size();
        }
    }
    return max_product;
}