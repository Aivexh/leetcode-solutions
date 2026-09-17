class Solution {
    public int minSumOfLengths(int[] arr, int target) {

        int n = arr.length;

        // best[i] = shortest target-sum subarray
        // completely inside arr[0...i]
        int[] best = new int[n];

        Arrays.fill(best, Integer.MAX_VALUE);

        // prefix sum -> latest index where this prefix sum occurred
        HashMap<Integer, Integer> map = new HashMap<>();

        // prefix sum 0 exists before the array starts
        map.put(0, -1);

        int sum = 0;
        int answer = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {

            sum += arr[i];

            // Copy the best answer from previous position
            if (i > 0) {
                best[i] = best[i - 1];
            }

            // We need previous prefix sum = sum - target
            if (map.containsKey(sum - target)) {

                int prev = map.get(sum - target);

                // Current subarray is (prev + 1 ... i)
                int currentLength = i - prev;

                // If another valid subarray exists before it
                if (prev >= 0 && best[prev] != Integer.MAX_VALUE) {
                    answer = Math.min(
                        answer,
                        currentLength + best[prev]
                    );
                }

                // Current subarray can become the best one
                best[i] = Math.min(best[i], currentLength);
            }

            // Store latest index of this prefix sum
            map.put(sum, i);
        }

        return answer == Integer.MAX_VALUE ? -1 : answer;
    }
}