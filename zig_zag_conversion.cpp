// The string "PAYPALISHIRING" is written in a zigzag pattern on a 
// given number of rows like this: (you may want to display this 
// pattern in a fixed font for better legibility)
// Example:
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1)
        return s;
    string zigzag;
    int a = s.size() / (numRows - 1) + 1, numCols = 0;
    if (a % 2 == 0) 
        numCols = (a / 2) * (numRows - 1);
    else
        numCols = ((a - 1)/ 2) * (numRows - 1) + 1;
    string str(numCols, ' ');
    vector<string> zigzag_matrix(numRows, str);
    int p = 0, q = 0;
    for (int i = 0; i < s.size(); i++) {
        zigzag_matrix[q][p] = s.at(i);
        int temp = i / (numRows - 1);
        if (temp % 2 == 0) {//down pattern
            q++;
        }
        if (temp % 2 == 1) {//diagonally upward
            p++;
            q--;
        }
        
    }
    for(auto it1 = zigzag_matrix.begin(); it1 != zigzag_matrix.end(); it1++) {
        // cout << *it1 << endl;
        for (auto it2 = it1->begin(); it2 != it1->end(); it2++) {
            if (*it2 != ' ')
                zigzag.push_back(*it2);
        }
    }
    return zigzag;
}

int main() {
    string s = "PAYPALISHIRING";
    int num_rows = 4;
    cout << convert(s, num_rows) << endl;
    system("pause");
    return 0;
}