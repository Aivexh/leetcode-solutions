from typing import List


class Solution:

    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)
        free_cnt = [0] * n
        for i in range(n):
            fi = items[i][0]
            cnt = 0
            for j in range(n):
                if i != j and items[j][0] % fi == 0:
                    cnt += 1
            free_cnt[i] = cnt

        min_price = min(price for _, price in items)
        neg_inf = -(10**9)
        dp = [neg_inf] * (budget + 1)
        dp[0] = 0

        for i in range(n):
            cost = items[i][1]
            gain = 1 + free_cnt[i]
            for c in range(budget, cost - 1, -1):
                if dp[c - cost] != neg_inf and dp[c - cost] + gain > dp[c]:
                    dp[c] = dp[c - cost] + gain

        ans = 0
        for c in range(budget + 1):
            if dp[c] != neg_inf:
                total = dp[c] + (budget - c) // min_price
                if total > ans:
                    ans = total

        return ans

