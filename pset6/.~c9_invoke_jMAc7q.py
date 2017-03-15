import cs50
from math import log10

def main():
    print("CC Number: ",end=(''))
    cc_number = cs50.get_int()
    #cc_number = 378282246310005
    lenght = 1 + int(log10(cc_number))
    if not Luhn(cc_number, lenght):
        print(cc_company(cc_number, lenght))
    else:
        print ('INVALID')
    return 0
    
def cc_company(cc_number, lenght):
    digits = int(cc_number / 10**(lenght-2))
    if digits > 39 and digits < 50:
        return 'VISA'
    elif digits == 34 or digits == 37:
        return 'AMEX'
    elif digits > 50 and digits < 56:
        return 'MASTERCARD'
    else:
        return 1

def Luhn(cc_numsder, lenght):
    sumEven = 0
    sumOdd = 0
    digit = 0
    for i in range(lenght):
        
        digit = int(cc_number % 10)
        cc_number = int(cc_number / 10)
        
        if not (i+1) % 2:
            digit = digit * 2
            if (digit) > 9:
                sumEven += (digit - 9)
            else:
                sumEven += digit
        else:
            sumOdd += digit
    #print("sumEven: {} sumOdd:{}".format(sumEven, sumOdd))
    return (sumEven + sumOdd) % 10
        
if __name__ == ("__main__"):
    main()