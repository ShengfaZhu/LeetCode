// Given a triangle, find the minimum path sum 
// from top to bottom. Each step you may move 
// to adjacent numbers on the row below.
// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 
// (i.e., 2 + 3 + 5 + 1 = 11).
int minimumTotal(vector<vector<int>>& triangle) {
    for (int i = 1; i < triangle.size(); i++) {
        triangle[i][0] = triangle[i][0] + triangle[i-1][0];
        triangle[i][triangle[i].size()-1] += triangle[i-1][triangle[i-1].size()-1];
        for(int j = 1; j < triangle[i].size()-1; j++)
            triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
    }
    int min_sum = INT_MAX;
    for (int j = 0; j < triangle[triangle.size()-1].size(); j++)
        if (triangle[triangle.size()-1][j] < min_sum) 
            min_sum = triangle[triangle.size()-1][j];
    return min_sum;
}