// Compare two version numbers version1 and version2.
// If version1 > version2 return 1; if version1 < version2 
// return -1;otherwise return 0.
// You may assume that the version strings are non-empty and 
// contain only digits and the . character.
// The . character does not represent a decimal point and is 
// used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to 
// version three", it is the fifth second-level revision of 
// the second first-level revision.

int string2num(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        num = num * 10 + s[i] - '0';
    }
    return num;
}

int compareVersion(string version1, string version2) {
    int i = 0, j = 0;
    while (i < version1.size() || j < version2.size()) {
        int k1 = i, k2 = j;
        while (k1 < version1.size() && version1[k1] != '.') k1++;
        while (k2 < version2.size() && version2[k2] != '.') k2++;
        int num1 = 0, num2 = 0;
        if (i < version1.size())
            num1 = string2num(version1.substr(i, k1 - i));
        if (j < version2.size())
            num2 = string2num(version2.substr(j, k2 - j));
        if (num1 < num2) return -1;
        else if (num1 > num2) return 1;
        else {
            i = k1 + 1;
            j = k2 + 1;
        }
    }
    return 0;
}