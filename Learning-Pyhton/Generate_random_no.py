import random

low = 1
high = 100
guesses = 0
numbers = random.randint(low, high)
# option = ("rock", "paper", "scissors")
# options = random.choice(option)  # generate random choice in option variable
# random.random() returns a float number
# random.shuffle(cards) shuffles a list

while True:
    guess = int(input(f"Enter a number between ({low} - {high}): "))
    guesses += 1

    if guess < numbers:
        print(f"{guess} is too low")
    elif guess > numbers:
        print(f"{guess} is too high")
    else:
        print(f"{guess} is correct")
        break

print(f"This round took you {guesses} guesses")