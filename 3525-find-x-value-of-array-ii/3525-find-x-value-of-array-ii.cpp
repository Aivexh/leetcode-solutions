class Solution {
    struct Node {
        int prod = 1;
        int cnt[5] = {0, 0, 0, 0, 0};
    };

    int k;
    vector<Node> tree;

    Node mergeNode(const Node& a, const Node& b) {
        Node res;

        // Product of the complete segment
        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside a
        for (int r = 0; r < k; r++) {
            res.cnt[r] = a.cnt[r];
        }

        // Prefixes containing all of a + prefix of b
        for (int r = 0; r < k; r++) {
            int nr = (a.prod * r) % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    Node makeNode(int x) {
        Node res;
        int r = x % k;

        res.prod = r;
        res.cnt[r] = 1;

        return res;
    }

public:
    vector<int> resultArray(
        vector<int>& nums,
        int k_,
        vector<vector<int>>& queries
    ) {
        k = k_;

        int n = nums.size();

        // Iterative segment tree
        int size = 1;
        while (size < n)
            size <<= 1;

        tree.resize(2 * size);

        // Build leaves
        for (int i = 0; i < n; i++) {
            tree[size + i] = makeNode(nums[i]);
        }

        // Build tree
        for (int i = size - 1; i >= 1; i--) {
            tree[i] = mergeNode(tree[i << 1], tree[i << 1 | 1]);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent point update
            nums[index] = value;

            int pos = size + index;
            tree[pos] = makeNode(value);

            for (pos >>= 1; pos; pos >>= 1) {
                tree[pos] = mergeNode(
                    tree[pos << 1],
                    tree[pos << 1 | 1]
                );
            }

            // Query [start, n)
            Node leftRes;   // identity
            Node rightRes;  // identity

            int l = size + start;
            int r = size + n;

            while (l < r) {
                if (l & 1) {
                    leftRes = mergeNode(leftRes, tree[l]);
                    l++;
                }

                if (r & 1) {
                    --r;
                    rightRes = mergeNode(tree[r], rightRes);
                }

                l >>= 1;
                r >>= 1;
            }

            Node res = mergeNode(leftRes, rightRes);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};