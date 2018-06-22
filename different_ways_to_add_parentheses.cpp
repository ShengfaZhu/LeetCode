// Different Ways to Add Parentheses
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
using namespace std;


vector<int> diffWaysToCompute(string input) {
    vector<int> ans;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
            vector<int> part1 = diffWaysToCompute(input.substr(0, i));
            vector<int> part2 = diffWaysToCompute(input.substr(i+1, input.size()-i-1));
            for (int n1 : part1)
                for (int n2 : part2) {
                    int tmp = 0;
                    switch (input[i]){
                        case '+':
                            tmp = n1 + n2;
                            break;
                        case '-':
                            tmp = n1 - n2;
                            break;
                        case '*':
                            tmp = n1 * n2;
                            break;
                    }
                    ans.push_back(tmp);
                }
        }
    }
    if (ans.empty()) {
        stringstream ss;
        ss << input;
        int num;
        ss >> num;
        ans.push_back(num);
    }
    return ans;
}

int main() {
    string input = "2*3-4*5";
    vector<int> nums = diffWaysToCompute(input);
    for (int n : nums) cout << n << "\t";
    system("pause");
    return 0;
}