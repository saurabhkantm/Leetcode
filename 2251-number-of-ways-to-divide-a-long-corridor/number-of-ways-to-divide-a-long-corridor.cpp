class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        long long totalSeats = 0, i = 0;
        long long sCnt = 0, pCnt = 0, ans = 1;
        const int MOD = 1e9 + 7;

        while (i < n) {
            // if seat cout < 2
            if (sCnt < 2) {
                if (corridor[i] == 'S') {
                    sCnt++;
                    totalSeats++;
                }
                i++;
            } 

            // when we have 2 seats 
            else {
                // count plants
                while (i < n && corridor[i] == 'P') {
                    pCnt++;
                    i++;
                }

                // plants to extreme right doesn't counts for dividing
                if (i == n) 
                    break;

                // if pcnt is not zero then only we will consider divider    
                if (pCnt != 0) {
                    ans = (ans*(pCnt+1)) % MOD;
                }

                // reset counts of plant and seats
                pCnt = 0;
                sCnt = 0;
            }
        }

        // if totalseats are even times and also not zero times
        if (totalSeats % 2 == 0 && totalSeats != 0) {
            if (ans == 0)
                return 1;
            else
                return ans;
        } 

        // when totalseats are odd times then we can't put divider
        else 
            return 0;
        
    }
};