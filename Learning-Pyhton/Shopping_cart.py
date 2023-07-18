
foods = []
prices = []
total = 0

while True:
    food = input("Enter a food to buy (q to quit): ")
    if food.lower() == "q":
        break

    else:
        foods.append(food)
        price = float(input("Enter the food amount: "))
        prices.append(price)
        total += price

print()
print("----- YOUR CART -----")
for x in foods:
    print(x, end=" ")

print()
print(f"Total Price = N{total}")