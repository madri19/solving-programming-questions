/*
Given a positive integer number n, your task is to calculate the difference between the product of its digits and the sum of its digits.

Note: The order matters; the answer should be of the form product - sum (and not sum - product).
passed 21/22 tests
*/

int digitsManipulations(int n) {
    
    int finalAnswer;
    
    //Get the number of digits
    int temp1 = n;
    int count = 0;
    while (temp1 != 0) {
        temp1 /= 10;
        ++count;
    }// variable count now contains the number of digits of n input which helps for the rest of the calculations.
    // if n = 1234, then count = 4, if n = 1234567890, then count = 10
    
    // Next calculate the product and addition of all the digits
    int temp2 = n;
    int product = 1;
    int powered = 1;
    int added = 0;
    for(int i = 1; i <= count; i++){
        //get the power of 10
        for(int j = 0; j < i; j++){
            powered = powered * 10;
        }
        
        //first remove the front numbers of i
        int digit = temp2 % powered;
        printf("step 1 = %d\n", digit);
        
        //then remove the back numbers of i
        if (digit > 9)
            digit = digit / (powered/10);
        printf("step 2 = %d\n", digit);
        
        //then multiply
        product = product * digit;
        added = added + digit;
        digit = 0;
        powered = 1;
    }
    
    //Finally do product - added = finalAnswer
    finalAnswer = product - added;
    
    return finalAnswer;
}
