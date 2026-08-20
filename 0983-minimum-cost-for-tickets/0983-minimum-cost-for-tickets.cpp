class Solution {
public:

    int solve(int index, vector<int>& days, vector<int>& costs,
              vector<int>& dp) {

        // Base case
        if (index >= days.size()) {
            return 0;
        }

        // Already calculated
        if (dp[index] != -1) {
            return dp[index];
        }

        // 1-day pass
        int oneDay = costs[0] + solve(index + 1, days, costs, dp);

        // 7-day pass
        int i = index;

        while (i < days.size() && days[i] < days[index] + 7) {
            i++;
        }

        int sevenDay = costs[1] + solve(i, days, costs, dp);

        // 30-day pass
        i = index;

        while (i < days.size() && days[i] < days[index] + 30) {
            i++;
        }

        int thirtyDay = costs[2] + solve(i, days, costs, dp);

        // Store answer
        dp[index] = min(oneDay, min(sevenDay, thirtyDay));

        return dp[index];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        vector<int> dp(days.size(), -1);

        return solve(0, days, costs, dp);
    }
};