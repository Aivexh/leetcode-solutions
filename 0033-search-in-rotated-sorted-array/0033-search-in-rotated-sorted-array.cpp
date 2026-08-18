class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left +(right - left)/2;

            // Target Found
            if (nums[mid] == target)
                return mid;
            // Left Half is stored
            if (nums[left] <= nums[mid]){
                //Target lies in the stored left half
                if(nums[left] <= target && target < nums[mid]){
                    right = mid -1;

                }
                else{
                    left = mid + 1;
                }
            }

                //right half is sorted
            else{
                //Target lies in the sorted right half
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }

            }
            return -1;
        }
        
  
};