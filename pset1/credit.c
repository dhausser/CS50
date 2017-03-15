#include <stdio.h>
#include <math.h>
#include <cs50.h>

_Bool Luhn(long long cc_number, int lenght)
{
    int sumEven = 0, sumOdd = 0;
    
    // Verify validity of the number on the card using Luhn's algorithm
    for(int i = 1, digit = cc_number % 10; i <= lenght; i++, cc_number /= 10, digit = cc_number % 10)
    {
        if (!(i%2))
        {
            if((digit *= 2) > 9)
                sumEven += (digit - 9);
            else
                sumEven += digit;
        }
        else
            sumOdd += digit;
    }
    return ((sumEven + sumOdd) % 10);
}

int main(void)
{
    printf("CC Number: ");
    long long cc_number = GetLongLong();
    int lenght = 1 + log10(cc_number);
    
    // Starts by checking validity of the card using Luhn's algorithm
    if(!Luhn(cc_number, lenght))
    {
        // Gather the first two digits 
        cc_number /= pow(10, (lenght-2) );
        
        // If the credit card is valid check which credit card company build it
        switch(lenght)
        {
            // Verify whether the card is a VISA
            case 13: 
                if(cc_number > 39 && cc_number < 50)
                    printf("VISA\n");
                break;
            
            // Verify whether the card is an AMEX
            case 15: 
                if(cc_number == 34 || cc_number == 37)
                    printf("AMEX\n");
                break;
            
            // Verify whether the card is a VISA or a MASTERCARD
            case 16: 
                if(cc_number > 39 && cc_number < 50)
                    printf("VISA\n");
                else if(cc_number > 50 && cc_number < 56) 
                    printf("MASTERCARD\n");
                break;
            
            default:  
                break;
        }
    }
    
    // If Luhn's algorithm does not return true the card is invalid
    else
        printf("INVALID\n");
    
    return 0;
}