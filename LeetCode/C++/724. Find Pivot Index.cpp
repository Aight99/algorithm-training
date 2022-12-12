class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 1; i < nums.size(); ++i) {
            rightSum += nums[i];
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
            if (i < nums.size() - 1) {
                rightSum -= nums[i + 1];
            }
        }
        return -1;
    }
};