// Given a string, determine if it is a palindrome, considering 
// only alphanumeric characters and ignoring cases.
// Note: For the purpose of this problem, we define empty string 
// as valid palindrome.
// Example 1:
// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:
// Input: "race a car"
// Output: false
bool isPalindrome(string s) {
    if (s.empty()) return true;
    std::transform(s.begin(), s.end(),s.begin(), ::tolower);
    int i = 0, j = s.size() - 1;
    while(i < j) {
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))) {
            i++;
            continue;
        }
        if (!((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'a' && s[j] <= 'z'))) {
            j--;
            continue;
        }
        if (s[i] != s[j])
            return false;
        else {
            i++;
            j--;
        }
        
    }
    return true;
}