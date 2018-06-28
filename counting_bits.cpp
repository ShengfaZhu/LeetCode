// 338. Counting Bits
// f[i] = f[i / 2] + i % 2
vector<int> countBits(int num) {
    assert(num >= 0);
    vector<int> count(num+1, 0);
    for (int i = 1; i <= num; i++) {
        count[i] = count[i >> 1] + (i % 2);
    }
    return count;
}