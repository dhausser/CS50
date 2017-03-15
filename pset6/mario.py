import cs50

def main():
    pyramid()

def pyramid():
    while True:
        print("Please enter heigh between 1 and 23: ")
        height = cs50.get_int()
        if height > 0 and height < 24:
            break
    for i in range(height):
        for j in range(height + i + 2):
            if j < height - i - 1:
                print(" ", end="")
            elif j == height:
                print("  ", end="")
            else:
                print("#", end="")
        print("")
        
if __name__ == ("__main__"):
    main()