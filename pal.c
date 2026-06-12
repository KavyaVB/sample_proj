#include <stdio.h>

void pal() {
    int num, originalNum, remainder;
    int reversedNum = 0;

    // Request input from the user
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Save the original number since 'num' will be modified in the loop
    originalNum = num;

    // Mathematical logic to reverse the integer
    while (num != 0) {
        remainder = num % 10;                  // Extract the last digit
        reversedNum = reversedNum * 10 + remainder; // Append digit to reversed number
        num /= 10;                             // Remove the last digit from original
    }

    // Determine if the number is a palindrome
    if (originalNum == reversedNum) {
        printf("%d is a palindrome number.\n", originalNum);
    } else {
        printf("%d is not a palindrome number.\n", originalNum);
    }

    #return 0;
}
