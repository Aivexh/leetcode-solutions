
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int j = 0; j < n; j++) {
            if (n % (j + 1) == 0) {
                sum += nums[j] * nums[j];
            }
        }

        return sum;
    }
};