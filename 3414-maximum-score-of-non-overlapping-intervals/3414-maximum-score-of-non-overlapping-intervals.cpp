class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> indices;
    };

    vector<vector<int>> intervals;
    vector<int> nextIndex;
    vector<vector<State>> dp;
    vector<vector<bool>> vis;

    // Returns the better of two states
    State better(State a, State b) {
        if (a.score != b.score)
            return (a.score > b.score ? a : b);

        // Same score -> lexicographically smaller indices
        if (lexicographical_compare(
                a.indices.begin(), a.indices.end(),
                b.indices.begin(), b.indices.end()))
            return a;

        return b;
    }

    State solve(int i, int remaining) {
        // We can take at most 4 intervals
        if (i == intervals.size() || remaining == 0)
            return {0, {}};

        if (vis[i][remaining])
            return dp[i][remaining];

        vis[i][remaining] = true;

        // Option 1: Skip current interval
        State skip = solve(i + 1, remaining);

        // Option 2: Take current interval
        State takeNext = solve(nextIndex[i], remaining - 1);

        State take;
        take.score = intervals[i][2] + takeNext.score;

        take.indices = takeNext.indices;
        take.indices.push_back(intervals[i][3]); // original index

        // Keep indices sorted because lexicographical comparison
        // is done on the final original indices.
        sort(take.indices.begin(), take.indices.end());

        dp[i][remaining] = better(skip, take);

        return dp[i][remaining];
    }

    vector<int> maximumWeight(vector<vector<int>>& arr) {
        int n = arr.size();

        // Add original index
        // [left, right, weight, originalIndex]
        intervals.clear();

        for (int i = 0; i < n; i++) {
            intervals.push_back({
                arr[i][0],
                arr[i][1],
                arr[i][2],
                i
            });
        }

        // Sort by left endpoint
        sort(intervals.begin(), intervals.end());

        vector<int> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = intervals[i][0];

        // Find next interval with left > current right
        nextIndex.resize(n);

        for (int i = 0; i < n; i++) {
            int right = intervals[i][1];

            nextIndex[i] =
                upper_bound(starts.begin(), starts.end(), right)
                - starts.begin();
        }

        dp.assign(n, vector<State>(5));
        vis.assign(n, vector<bool>(5, false));

        return solve(0, 4).indices;
    }
};