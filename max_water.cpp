// Given n non-negative integers a1, a2, ..., an, 
// where each represents a point at coordinate (i, ai). 
// n vertical lines are drawn such that the two endpoints 
// of line i is at (i, ai) and (i, 0). Find two lines, 
// which together with x-axis forms a container, 
// such that the container contains the most water.
// Note: You may not slant the container and n is at least 2.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int max_area = 0;
    vector<int> area(height.size(), 0);
    for (int i = 0; i < height.size(); i ++) {
        int j = 0;
        for (; j < i; j++) {
            if (height.at(j) >= height.at(i))
                break;
        }
        int left = height.at(i) * (i - j);
        j = height.size() - 1;
        for (; j > i; j--) {
            if (height.at(j) >= height.at(i))
                break;
        }
        int right = height.at(i) * (j - i);
        int temp_max = max(left, right);
        max_area = max(max_area, temp_max);
    }
    return max_area;
}

int main() {
    vector<int> height = {1, 1};
    cout << maxArea(height) << endl;
    system("pause");
    return 0;
}