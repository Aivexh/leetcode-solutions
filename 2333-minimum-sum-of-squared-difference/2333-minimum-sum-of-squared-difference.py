class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        # Combine both k1 and k2 into a single pool of operations
        k = k1 + k2
        
        # Calculate absolute differences
        diffs = [abs(n1 - n2) for n1, n2 in zip(nums1, nums2)]
        max_diff = max(diffs)
        
        if max_diff == 0:
            return 0
            
        # Create a bucket array for frequencies of differences
        counts = [0] * (max_diff + 1)
        for d in diffs:
            counts[d] += 1
            
        # Greedily reduce the largest differences down
        for x in range(max_diff, 0, -1):
            if counts[x] == 0:
                continue
                
            # Determine how many elements we can reduce
            take = min(k, counts[x])
            counts[x] -= take
            counts[x - 1] += take
            k -= take
            
            # If no more operations are left, stop
            if k == 0:
                break
                
        # Calculate the final sum of squared differences
        return sum(counts[x] * (x ** 2) for x in range(len(counts)))
