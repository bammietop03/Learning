# Dictionary Examples

food = { "Rice": 200.3,
        "Beans": 100.2,
        "Apple": 150.23,
        "Noodles": 310,
        "Milk": 201,
        "Coffee": 90.1
}

cart = []
total = 0

print("------- MENU -------")
for key,value in food.items():
    print(f"{key:10}{value:.2f}")

print("---------------------")

while True:
    stuff = input("Enter an item(q to quit): ")
    if stuff.lower() == "q":
        break
    elif food.get(stuff) is not None:
        cart.append(stuff)

print("------- YOUR ORDER -------")
for x in cart:
    total += food.get(x)
    print(x, end=" ")

print()
print(f"Total is : ${total:.2f}")