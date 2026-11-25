from collections import Counter
from typing import List


class Solution:

    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)

        # Double hashing parameters to prevent collisions
        MOD1, MOD2 = 10**9 + 7, 10**9 + 9
        BASE1, BASE2 = 131313, 131317

        # Precompute powers of BASE1 and BASE2
        pow1 = [1] * (n + 1)
        pow2 = [1] * (n + 1)
        for i in range(n):
            pow1[i + 1] = (pow1[i] * BASE1) % MOD1
            pow2[i + 1] = (pow2[i] * BASE2) % MOD2

        # Precompute prefix hashes
        pref1 = [0] * (n + 1)
        pref2 = [0] * (n + 1)
        for i in range(n):
            pref1[i + 1] = (pref1[i] * BASE1 + nums[i]) % MOD1
            pref2[i + 1] = (pref2[i] * BASE2 + nums[i]) % MOD2

        def has_unique_subarray(length: int) -> bool:
            counts = Counter()
            for i in range(n - length + 1):
                h1 = (pref1[i + length] - pref1[i] * pow1[length]) % MOD1
                h2 = (pref2[i + length] - pref2[i] * pow2[length]) % MOD2
                counts[(h1, h2)] += 1

            return any(freq == 1 for freq in counts.values())

        # Binary search on the answer
        low, high = 1, n
        ans = n
        while low <= high:
            mid = (low + high) // 2
            if has_unique_subarray(mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans
