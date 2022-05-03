# TODO
import cs50

# prompt user for int 1-8
while True:
    Height = cs50.get_int("Enter Height here: ")
    if Height >= 1 and Height <= 8:
        break

# row height outer
for row in range(Height):
    for space in range(Height):
        if (row + space >= Height - 1):
            print("#", end="")
        else:
            print(" ", end="")
    print()

