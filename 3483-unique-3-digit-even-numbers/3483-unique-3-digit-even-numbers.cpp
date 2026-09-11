class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};

        // Count frequency of each digit available
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;

        // Check every 3-digit even number
        for (int num = 100; num <= 999; num += 2) {
            int temp = num;

            int ones = temp % 10;
            temp /= 10;

            int tens = temp % 10;
            temp /= 10;

            int hundreds = temp % 10;

            // Count digits required by this number
            int needed[10] = {0};
            needed[ones]++;
            needed[tens]++;
            needed[hundreds]++;

            bool possible = true;

            for (int d = 0; d <= 9; d++) {
                if (needed[d] > freq[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                count++;
            }
        }

        return count;
    }
};