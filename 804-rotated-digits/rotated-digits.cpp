class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=1;i<=n;i++){
            bool isChanged = false;
            bool isValid = true;
            int num = i;
            while(num!=0){
                int digit = num % 10;
                if(digit == 3 || digit == 4 || digit == 7){
                    isValid = false;
                    break;
                }
                else if(digit == 2 || digit == 5 || digit == 6 || digit == 9){
                    isChanged = true;
                }

                num = num/10;
            }

            if(isChanged && isValid){
                count++;
            }

        }

        return count;
    }
};