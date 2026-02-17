class Solution {
public:
    int cntBit(int n){
        int cnt = 0;
        while(n){
            n = n & (n-1);
            cnt++;    
        }

        return cnt;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int hrs=0;hrs<12;hrs++){
            for(int min = 0;min<60;min++){
                int totalBits = cntBit(hrs) + cntBit(min);

                if(totalBits == turnedOn){
                    string hour = to_string(hrs);
                    string minute = to_string(min);

                    if(minute.size() < 2)
                        minute = '0' + minute;

                    ans.push_back(hour + ":" + minute);    
                }
            }
        }

        return ans;
    }
};