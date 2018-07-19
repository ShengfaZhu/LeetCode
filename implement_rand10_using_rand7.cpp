// 470. Implement Rand10() Using Rand7()
int rand10() {
    int res = 40;
    while (res >= 40) res = 7 * (rand7() - 1) + (rand7() - 1);
    return res / 4 + 1;
}