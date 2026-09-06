class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;

        function<void()> solve = [&]() {

            // If all elements are used,
            // we have one complete permutation
            if (current.size() == nums.size()) {
                ans.push_back(current);
                return;
            }

            // Try every element
            for (int i = 0; i < nums.size(); i++) {

                // Check if nums[i] is already used
                if (find(current.begin(), current.end(), nums[i]) 
                    != current.end()) {
                    continue;
                }

                // Choose nums[i]
                current.push_back(nums[i]);

                // Recursively build the rest
                solve();

                // Remove nums[i] and try another choice
                current.pop_back();
            }
        };

        solve();

        return ans;
    }
};