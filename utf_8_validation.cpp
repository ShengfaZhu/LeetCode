#include <iostream>
#include <vector>
using namespace std;

int count_one(int num) {
    int i = 128, num_one = 0;
    while ((num & i) != 0) {
        num_one++;
        i = i >> 1;
    }
    return num_one;
}

bool validUtf8(vector<int>& data) {
    if (data.empty()) return true;
    int i = 0;
    while (i < data.size()) {
        int num_one = count_one(data[i]);
        if (num_one > 0) {
            int j = i + 1;
            for (; j < i + num_one; j++) {
                if (count_one(data[j]) != 1) return false;
            }
            i = j;
        }
        else i++;
    }
    return true;
}

int main() {
    vector<int> data = {197, 130, 1};
    // for (int i : data) cout << count_one(i) << endl;
    cout << validUtf8(data) << endl;
    system("pause");
    return 0;
}