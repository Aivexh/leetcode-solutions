class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        // first[i] = first occurrence of character i
        // last[i]  = last occurrence of character i
        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence of every character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try to create a valid substring for every character
        for (int c = 0; c < 26; c++) {

            // Character does not exist
            if (last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            // Expand the interval if necessary
            for (int i = l; i <= r; i++) {

                int x = s[i] - 'a';

                // This character appeared before l.
                // Therefore we cannot make a valid substring
                // starting at l.
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // We must include all occurrences of x
                r = max(r, last[x]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // Earliest ending interval first
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;

        int end = -1;

        // Greedy interval selection
        for (auto [l, r] : intervals) {

            // Non-overlapping
            if (l > end) {
                ans.push_back(s.substr(l, r - l + 1));
                end = r;
            }
        }

        return ans;
    }
};