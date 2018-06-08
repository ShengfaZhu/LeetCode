// 191. Number of 1 Bits
int hammingWeight(uint32_t n) {
    uint32_t check = 1;
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if (n & check)
            count++;
        check = check << 1;
    }
    return count;
}