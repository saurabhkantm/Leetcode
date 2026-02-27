class Solution {
public:
    string removeOuterParentheses(string s) {
         string result = "";

         int level = 0;

         for( char x : s){
            if( x == '('){
                if( level > 0 ){
                    result+= '(';

                }

                level++;

            }
            else if( x ==')' ){

                level--;
                if( level > 0){
                    result += ')';
                }
            }
         }
         return result;
    }
};