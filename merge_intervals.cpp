// Given a collection of intervals, merge all overlapping intervals.
// Example 1:
// Input: {{1,3},{2,6},{8,10},{15,18}}
// Output: {{1,6},{8,10},{15,18}}
// Explanation: Since intervals {1,3} and {2,6} overlaps, 
// merge them into {1,6}.

#include <iostream>
#include <vector> 
#include <limits.h>
#include <cmath>
using namespace std;


// Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

void Merge(vector<Interval>& nums, int low, int mid, int high) {
    vector<Interval> L, R;
    for(int z = low; z <= mid; z++) {
        L.push_back(nums[z]);
    }
    for (int z = mid + 1; z <= high; z++) {
        R.push_back(nums[z]);
    }
    Interval tmp = Interval(INT_MAX, 0);
    L.push_back(tmp), R.push_back(tmp);
    int i = 0, j = 0;
    for (int k = low; k <= high; k++) {
        if (L[i].start < R[j].start ) {
            nums[k] = L[i];
            i++;
        }
        else {
            nums[k] = R[j];
            j++;
        }
    }
}

void merge_sort(vector<Interval>& nums, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid + 1, high);
        Merge(nums, low, mid, high);
    }
}

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
    if (intervals.empty())
        return res;
    // sort by starts of intervals
    merge_sort(intervals, 0, intervals.size() - 1);
    // merge
    res.push_back(intervals[0]); 
    int j = 0;
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start > res[j].end) {
            res.push_back(intervals[i]);
            j++;
        }
        else {
            res[j].end = max(intervals[i].end, res[j].end);
        }
    }
    return res;
}


int main() {
    vector<vector<int>> nums = {{2,6},{8,10},{1,3},{15,18}};
    vector<Interval> intervals;
    for (int i = 0; i < nums.size(); i++) {
        Interval tmp = Interval(nums[i][0], nums[i][1]);
        intervals.push_back(tmp);
    }
    vector<Interval> res = merge(intervals);
    for (int i = 0; i < res.size(); i++) {
        cout << "[" <<res[i].start << ", " << res[i].end << "]" << "\t";
    }
    system("pause");
    return 0;
}