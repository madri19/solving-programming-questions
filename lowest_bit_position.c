// Given an int, return the bit position for the lowest set bit of the input.
#include <stdio.h>

int first_bit_position(int num);

int main()
{
    int x = 0b11110000;
    x = first_bit_position(x);
    printf("%d\n", x);
}

int first_bit_position(int num)
{
    int test = 0, i = 0;
    
    // Get out if the number is 0
    if( num == 0)
        return -1;
    
    // Continue looping until you hit the first bit and return the position. 
    while(1)
    {
        // Shift left a bit with the value of i and mask it with the number and shift the bit standing if there is one to the right i times.
        // This way either test == 1 or test == 0 which helps for the if statement.
        test = (num & (0x0001 << i)) >> i;
        
        if(test)
            return i;
        else
            i++;
    }
}
