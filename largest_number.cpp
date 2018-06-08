#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <sstream>
using namespace std;

bool cmp(string num1, string num2) {
    if (num1 == num2) return true;
    int i = 0, j = 0, n1, n2;
    while (i < num1.size() || j < num2.size()) {
        if (i >= num1.size()) i = 0;
        if (j >= num2.size()) j = 0;
        n1 = num1[i] - '0';
        n2 = num2[j] - '0';
        if (n1 > n2) return true;
        if (n1 < n2) return false;
        i++, j++;
    }
    return true;
}

void merge(vector<string>& nums, int low, int mid, int high) {
    vector<string> L, R;
    for (int i = low; i <= mid; i++) L.push_back(nums[i]);
    for (int i = mid + 1; i <= high; i++) R.push_back(nums[i]);
    int i = 0, j = 0, k = low;
    while (i < L.size() && j < R.size()) {
        if (cmp(L[i], R[j])) {
            nums[k] = L[i];
            i++;
        }
        else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < L.size()) {
        nums[k] = L[i];
        i++, k++;
    }
    while (j < R.size()) {
        nums[k] = R[j];
        j++; k++;
    }
}

// merge sort
void string_sort(vector<string>& nums, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    string_sort(nums, low, mid);
    string_sort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

string largestNumber(vector<int>& nums) {
    // convert to string
    vector<string> str;
    bool all_zeros = true;
    for (int num : nums) {
        if (num != 0) all_zeros = false;
        stringstream tmp;
        tmp << num;
        str.push_back(tmp.str());
    }
    if (all_zeros) return "0";
    // sort nums
    string_sort(str, 0, str.size()-1);
    // connect 
    string res;
    for (string s : str)
        res = res + s;
    return res;
}

int main() {
    vector<int> nums = {0, 0};
    cout << largestNumber(nums) << endl;
    system("pause");
    return 0;
}