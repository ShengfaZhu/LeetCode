// 278. First Bad Version
int firstBadVersion(int n) {
    int low = 1, high = n;
    if (isBadVersion(low)) return low;
    while (low < high - 1) {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid))
            high = mid;
        else
            low = mid;
    }
    return high;
}