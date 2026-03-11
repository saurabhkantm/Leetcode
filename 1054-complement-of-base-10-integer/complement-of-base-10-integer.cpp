class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        string binary = "";

        while(n > 0) {
            int digit = n % 2;
            binary = (digit == 0 ? "0" : "1") + binary;
            n = n / 2;
        }

        for(int i = 0; i < binary.size(); i++) {
            if(binary[i] == '0') binary[i] = '1';  
            else binary[i] = '0';
        }

        int ans = 0;
        for(char c : binary) ans = ans * 2 + (c - '0');
        return ans;
    }
};