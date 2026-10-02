class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int sum1 = (N * (N + 1)) / 2;
        int sum2 = 0;
        for(int num:nums){
            sum2+=num;
        }
        int total = sum1 - sum2;
        return total;
    }
};