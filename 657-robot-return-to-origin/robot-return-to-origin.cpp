class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int posX = 0, posY = 0;
        for(char &ch : moves){
            if(ch == 'R'){
                posX++;
            }else if(ch =='L'){
                posX--;
            }else if(ch == 'U'){
                posY++;
            }else{
                posY--;
            }
        }
        return (posX == 0 && posY == 0);
    }
};