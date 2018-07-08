// 372. Super Pow
int multi_product(int a, int order) {
    int res = 1;
    while (order--) {
        res = (res * a) % 1337;
    }
    return res;
}

int superPow(int a, vector<int>& b) {
    int res = 1, tmp = a % 1337;
    for (auto it = b.rbegin(); it != b.rend(); it++) {
        res = (res * multi_product(tmp, *it)) % 1337;
        tmp = multi_product(tmp, 10);
    }
    return res;
}