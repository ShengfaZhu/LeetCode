// 201. Bitwise AND of Numbers Range
int rangeBitwiseAnd(int m, int n) {
    int i = 0;
    while (m != n) {
        m = m >> 1;
        n = n >> 1;
        i++;
    }
    return m << i;
}