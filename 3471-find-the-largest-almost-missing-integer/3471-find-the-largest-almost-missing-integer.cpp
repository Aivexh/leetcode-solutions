class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        vector<int> count(51, 0);

        int n = nums.size();

        // Generate every subarray of size k
        for (int i = 0; i <= n - k; i++) {

            set<int> st;

            // Put elements of current subarray into set
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Each number counts only once for this subarray
            for (int x : st) {
                count[x]++;
            }
        }

        int ans = -1;

        // Find largest number appearing in exactly one subarray
        for (int x = 0; x <= 50; x++) {
            if (count[x] == 1) {
                ans = x;
            }
        }

        return ans;
    }
};