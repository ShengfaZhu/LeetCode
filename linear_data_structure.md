# 线性数据结构相关问题

线性数据结构包括数组和链表，其中的查找问题、排序问题和动态规划均是考察的重点。

# 1 查找

# 1.1 N-sum问题
N-sum问题指的是，对于一个升序排列的数组，找到其中的N个数字之和等于给定目标值target的下标。显然如何进行N次循环一定可以找到，但是事实上只需要进行N-1次循环就可以。定义双指针，一个指向数组的前面，一个指向数组的后面，然后双指针向中部移动。根据两个字指针之和，利用有序数组的特性，就可以减少一次循环。
```c++
// the nums is in acsending order
// two pointer method
vector<vector<int>> twoSum(const vector<int>& nums, int target) {
    vector<vector<int>> indexs;
    vector<int> index_tmp(2, 0);
    int i = 0, j = nums.size() - 1;
    while(i < j){
        if (nums[i] + nums[j] == target) {
            index_tmp[0] = i;
            index_tmp[1] = j;
            indexs.push_back(index_tmp);
            i++, j--;
        }
        else if (nums[i] + nums[j] < target) i++;
        else j--;
    }
    return indexs;
}
```

