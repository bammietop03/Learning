import random

options = ("rock", "paper", "scissors")
player = None
running = True
print("Welcome to Rock Paper Scissor Game")

while running:
    player = None
    computer = random.choice(options)

    while player not in options:
        player = input("Enter either rock , paper, scissors: ")

    print(f"Player: {player}")
    print(f"Computer: {computer}")

    if player == computer:
        print("It's a tie.")
    elif player == "rock" and computer == "scissors":
        print("You win!")
    elif player == "paper" and computer == "rock":
        print("You win!")
    elif player == "scissors" and computer == "paper":
        print("You win!")
    else:
        print("You lose!")

    play_again = input("Do you which to play again (y/n): ").lower()
    if not play_again == "y":
        running = False