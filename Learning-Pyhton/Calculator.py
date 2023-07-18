num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))
sign = input("Enter a sign (+ * / -): ")

if sign == "+":
    sum = num1 + num2
    print(f"sum = {sum}")

elif sign == "-":
    sum = num1 - num2
    print(f"sum = {sum}")

elif sign == "*":
    sum = num1 * num2
    print(f"sum = {sum}")

elif sign == "/":
    sum = num1 / num2
    print(f"sum = {sum}")

else:
    print("Invalid input")
