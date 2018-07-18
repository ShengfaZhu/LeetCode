// Minimum Number of Arrows to Burst Balloons
int findMinArrowShots(vector<pair<int, int>>& points) {
    auto cmp = [](pair<int, int> x, pair<int, int> y) {return x.second < y.second;};
    sort(points.begin(), points.end(), cmp);
    int i = 0, count = 0;
    while (i < points.size()) {
        int shoot = points[i].second;
        count++;
        int j = i + 1;
        while (j < points.size() && shoot >= points[j].first && shoot <= points[j].second)
            j++;
        i = j;
    }
    return count;
}