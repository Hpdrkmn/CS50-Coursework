# TODO
from cs50 import get_float

# get float because decimal numbers
while True:
    dollars = get_float("Enter Change due: ")
    if dollars >= 0:
        break

cents = round(dollars * 100)
coins = 0
denominations = [25, 10, 5, 1]

# denominations is like array for my coins

for denom in denominations:
    while cents >= denom:
        cents -= denom
        coins += 1

print(coins)
