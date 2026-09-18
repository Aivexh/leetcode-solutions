class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        // first[c] = first position of character c
        // last[c]  = last position of character c
        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < n; i++) {

            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try every character as the starting character
        for (int c = 0; c < 26; c++) {

            // Character doesn't exist
            if (last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            // Check all characters inside [l, r]
            for (int i = l; i <= r; i++) {

                int x = s[i] - 'a';

                // x occurs before l,
                // so this substring cannot be valid
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // We must include all x's
                r = max(r, last[x]);
            }

            // Store valid interval
            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // Earlier ending interval first
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;

        int previousEnd = -1;

        // Greedily choose non-overlapping intervals
        for (auto [l, r] : intervals) {

            if (l > previousEnd) {

                ans.push_back(
                    s.substr(l, r - l + 1)
                );

                previousEnd = r;
            }
        }

        return ans;
    }
};