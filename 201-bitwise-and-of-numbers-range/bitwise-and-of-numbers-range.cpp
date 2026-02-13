class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        
        return left << shift;
    }
};
    //     # We are given a range [left,right]. We need to compute the bitwise AND of all numbers in
    //     # the range. 
    //     # Bitwise AND
    //     # 0 & 0 = 0
    //     # 0 & 1 = 0
    //     # 1 & 0 = 0
    //     # 1 & 1 = 1
    //     # Bitwise AND results in a 1 only if all corresponding bits are 1 in every number
    //     # Example : 
    //     # left = 5 (101)
    //     # right = 7 (111)
    //     # Numbers in range : 5 --> (101) , 6 --> (110), 7 --> (111)
    //     # Bitwise AND : 101 & 110 = 100, 100 & 111 = 100 ---> 4. Therefore, result = 4

    //     # A brute force approach will be to loop from left to right and use & operation.
    //     # This will work for small ranges, but for large inputs it isnt ok. 

    //     # An optimal approach would be to BITWISE AND to keep common prefix in binary.
    //     # We can keep shifting both left and right until they are equal.
    //     # As we shift each bit, we will lose a bit in the final result --> it will be filled with 0
    //     #
    //     # left = 5 --> 101
    //     # right = 7 --> 111
    //     #
    //     # Shift right
    //     # 5 >> 1 = 10
    //     # 7 >> 1 = 11
    //     # Shift again
    //     # 10 >> 1 = 1
    //     # 11 > 1 = 1
    //     # Now left == right = 1
    //     # Therefore, shifted bits = 2
    //     # Final AND = 1 << 2 = 100 (4)
        
    //     # Make a variable to count how many bits we need to shift
    //     shift = 0

    //     # Find the common prefix
    //     while left < right:
    //         # Shift both left and right to the right by 1
    //         left >>= 1
    //         right >>= 1
    //         shift = shift + 1 # Keep track of the shifted bits

    //     # Shift the common prefix back to the left
    //     return left << shift
    
    // # Time Complexity : Each shift will divide the number by 2 --> I dont know
    // # Space Complexity : O(1) --> only a few variables are used.


        

        