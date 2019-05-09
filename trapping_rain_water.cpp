#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int trap(vector<int>& height) {
    // input check
    if (height.empty() || height.size() < 3) {
        return 0;
    }
    int trap_water = 0;
    int i = 0;
    while (i + 1 < height.size()) {
        for (; i + 1 < height.size(); ++i) {
            if (height.at(i + 1) < height.at(i)) {
                break;
            }
        }
        int index_left = i;
        // find index of increase
        for (; i + 1 < height.size(); ++i) {
            if (height.at(i + 1) > height.at(i)) {
                break;
            }
        }
        for (;i + 1 < height.size(); ++i) {
            if (height.at(i + 1) < height.at(i)) {
                break;
            }
        }
        if (i >= height.size()) {
            break;
        }
        int index_right = i;      
        // calculate sum of water
        int water_level = min(height.at(index_left), height.at(index_right));
        for (int j = index_left; j <= index_right; ++j) {
            if (height.at(j) < water_level) {
                trap_water += water_level - height.at(j);
                height.at(j) = water_level;
            }   
        }
    }
    if (trap_water == 0) {
        return 0;
    }
    else {
        return trap_water + trap(height);
    }
}

int main()
{
    vector<int> height = {5, 2, 1, 2, 1, 5};
    cout << trap(height) << endl;
    system("pause");
    return 0;
}