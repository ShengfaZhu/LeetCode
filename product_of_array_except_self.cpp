    vector<int> productExceptSelf(vector<int>& nums) {
        assert(nums.size() > 1);
        vector<int> num1(nums.begin(), nums.end());
        for (int i = num1.size()-2; i >= 0; i--) 
            num1[i] = num1[i+1] * num1[i];
        for (int i = 1; i < nums.size(); i++)
            nums[i] = nums[i-1] * nums[i];
        num1[0] = num1[1];    
        for (int i = 1; i < num1.size()-1; i++)
            num1[i] = nums[i-1] * num1[i+1];
        num1[num1.size()-1] = nums[nums.size()-2];
        return num1;
    }