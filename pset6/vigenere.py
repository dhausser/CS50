import cs50
import sys

def main():
    #Check if single argument
    if not len(sys.argv) == 2:
        print('Error: missing command line argument')
        return 1
    
    #Check if argument contains non-alphabetical character
    if not sys.argv[1].isalpha():
         print('Error: argument contains non-alphabetical character')
    
    #Prompt user for plaintext input   
    print('plaintext: ', end='')
    plaintext = cs50.get_string()
    
    #Print result of Vigenere cipher
    print('ciphertext: {}'.format(vigenere(sys.argv[1], plaintext)))
    return 0
    
def index(c):
    if c.isupper():
        return ord(c) - ord('A')
    elif c.islower():
        return ord(c) - ord('a')
    else:
        return 1
    
def vigenere(keyword, text):
    if text:
        
        plaintext = list(text) 
        j = 0
        
        for i in range(len(plaintext)):
            if plaintext[i].isalpha():
                
                #Cipher char conserving case
                if plaintext[i].isupper():
                    plaintext[i] = chr(ord('A') + (index(plaintext[i]) + index(keyword[j])) % 26)
                elif plaintext[i].islower():
                    plaintext[i] = chr(ord('a') + (index(plaintext[i]) + index(keyword[j])) % 26)
                else:
                    print('Error {} is neither uppercase nor lowercase'.format(plaintext[i]))
                
                #Increment cipher key from keyword
                if j < len(keyword)-1:
                    j += 1
                else:
                    j = 0
        return ''.join(plaintext)

    else:
        return 1
    
if __name__ == ("__main__"):
    main()