class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        // Sort so duplicate come together
        sort(candidates.begin(), candidates.end());
        
        // Backtracking function
        function<void(int, int)>solve = [&](int start, int target){

            // Target becomes 0 --> valid combination found
             if(target == 0){
                ans.push_back(current);
                return;
             }

             for(int i = start; i< candidates.size(); i++){

                // Skip duplicate numbers at the same level
                if(i > start && candidates[i] == candidates[i - 1])
                    continue;
                
                //Since array is sorted , no need to continue
                if(candidates[i] > target)
                    break;

                // Choose this number
                current.push_back(candidates[i]);

                // i + 1 --> use each element only once
                solve(i + 1, target - candidates[i]);


                //Backtrack
                current.pop_back();

             }
        };

        solve(0 , target);

        return ans; 
        }
};