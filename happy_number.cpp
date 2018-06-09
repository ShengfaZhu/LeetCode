// 202. Happy number
int digit_square_sum(int n) {
    int square_sum = 0;
    while (n) {
        square_sum += (n % 10) * (n % 10);
        n = n / 10;
    }
    return square_sum;
}

bool isHappy(int n) {
    int slow = n, fast = n;
    // do-while loop skip condition check for the first iteration 
    // slow fast method to detect if loop exist
    do {
        slow = digit_square_sum(slow);
        if (slow == 1) return true;
        fast = digit_square_sum(fast);
        fast = digit_square_sum(fast);
    } while (slow != fast);
    return false;
}