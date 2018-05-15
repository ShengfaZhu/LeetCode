#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> L, R;
    for(int z = low; z <= mid; z++) {
        L.push_back(nums[z]);
    }
    for (int z = mid + 1; z <= high; z++) {
        R.push_back(nums[z]);
    }
    L.push_back(INT_MAX), R.push_back(INT_MAX);
    int i = 0, j = 0;
    for (int k = low; k <= high; k++) {
        if (L[i] < R[j] ) {
            nums[k] = L[i];
            i++;
        }
        else {
            nums[k] = R[j];
            j++;
        }
    }
}

void merge_sort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

int main() {
    vector<int> nums = {5, 1, 2, 6, 4, 3};
    merge_sort(nums, 0, nums.size() - 1);
    for (int& num : nums) {
        cout << num << "\t";
    }
    system("pause");
    return 0;
}