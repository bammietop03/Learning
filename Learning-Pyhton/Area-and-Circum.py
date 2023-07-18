import math

#Calculating the circumference of a circle 2 PI r

r = float(input("Enter the radius: "))

circum = 2 * math.pi * r

print(f"The Circumference is: {round(circum, 2)}")

#Calculating the area of a circle pi r^2

area = math.pi * r ** 2

print(f"The Area is: {round(area, 2)}")
