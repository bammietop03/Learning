## LEARNING PYTHON
![image](https://github.com/bammietop03/Learning/assets/133250516/7c84d008-d255-45f4-aaa1-014fc346449c)

## TABLE OF CONTENT
* [Strings](#string-variable)
* [Integers](#integer-variable)
* [Floats](#float-variable)
* [Slicing in python](#slicing-in-python)
* [Input](#input-in-python)
* [If and Else statement](#if-and-else-statement)
* [logical operators](#logical-operator)
* [While Loop](#while-loop)
* [For Loop](#for-loop)
* [Nested Loop](#nested-loop)
* [Loop Controls](#loop-controls)
* [List](#list-in-python)
* [2D List](#2d-list)
* [Tuples](#tuples-in-python)
* [Set](#set-in-python)
* [Dictionaries](#dictionaries-in-python)
* [Index Opereator](#index-operator-in-python)
* [Functions](#functions)
* [Return Statement](#return-function)
* [Keyword Argument](#keyword-argument)
* [Nested Function](#nested-functions-calls)
* [Scope..Global Variable](#scope)
* [*args](#args)
* [**kwargs](#kwargs)



## STRING VARIABLE
    name = "Bamiwo"

    len(name) - lenght of name

    name.capitalize() - capitalize the first word
    name.upper() - changes the string to uppercase
    name.lower() - change the string to lowercase
    name.isdigit() - checks if the string is digit
    name.isalpha() - checks if the string is alphabet

## INTEGER VARIABLE
age = 24

## FLOAT VARIABLE
weight = 97.5

## MATH FUNCTION
    import math

    math.ceil(weight) - round up
    math.floor(weight) - round down
    math.pow(age, 2) - age raise to the power of 2
    math.sqrt(age) - sqaure root
    math.abs(age) - absolute of age
    math.factorial(age) - factorial of age

    max(x, y, z) - maximum of x, y, z
    min(x, y, z) - minimum of x, y, z


## SLICING IN PYTHON

we can use slice(start,stop,step) or name[start:stop:step]

    name = "bamiwo"

    slice_name = name[1:3] - starts at index 1 and stop at index 3
    slice_name = name[::2] - [0:end:2]output is bmw
    slice_name = name[::-1] - [0:end:-1] will reverse the string

    website = "http://google.com"

    To get the word google using slice function

    slice_web = slice(7,-4)
    print(website[slice_web]) - output = google

## INPUT IN PYTHON
To accept input from the terminal

    input(what is your name: )

    by default input are stored in a string

    name = input(what is your name: )

    To store other types we use

    name = int(input(what is your name: ))
    name = float(input(what is your name: ))

## IF AND ELSE STATEMENT

    age = int(input("what is your age: "))

    if age > 20 and age < 50:
        print("You are above 20")

    elif age < 20:
        print("You are bellow 20")

    else:
        print("You are 20")

## LOGICAL OPERATOR

and, or and not

not(age > 20 and age < 50)

## WHILE LOOP

    name = None

    while not name:
        name = input("what is your name")

    or

    while name == "":  or len(name) == 0:
        name = input("what is your name")

## FOR LOOP
it iterate for a limited amount of time

    for i in range(10):
        print(i) - will print i ten times 

    for i in range(10, 50, 2):
        print(i) - will print i from 10 to 50 with two step

Happy New Year countdown

    import time

    for seconds in range(10,0,-1):
        print(seconds)
        time.sleep(1)
    print("Happy New Year!")

## NESTED LOOP

    row = int(input("How many rows: "))
    columns = int(input("How many columns: "))
    symbol = input("What symbol whould you like to use: ")

    for i in range(row):
        for j in range(columns):
            print(symbol, end="")
        print()

## LOOP CONTROLS
break, continue and pass

Break - is used to terminate the loop entirely

Continue - is used to skip to the next iteration of the loop

Pass - does nothing, acks as a placeholder

Example of Break

    while True:
        name = input("What is your name: ")

            if name != "":
                break

Example of continue

    phone_number = "081-6787-4968"

    for i in phone_number:
        if i == "-":
            continue
    print(i, end="")

Example of Pass

    for i in range(21):
        if i == 13:
            pass
        else:
            print(i, end="")

## LIST IN PYTHON
list is used to store multiple items in a single variable

    country = ["japan", "nigeria", "france", "spain", "china"]

    country. to append, remove and more

    for x in country:
        print(x)

## 2D LIST
    country = ["japan", "nigeria", "france", "spain", "china"]
    food = ["garri", "yam", "mango"]
    drinks = ["viju", "coke", "water"]

    all = [country, food, drinks]
    print(all[1][1]) # prints yam

## TUPLES IN PYTHON
tuples are collection which is ordered and uchangeable and are used to group together related data

    student = ("Bammie", 21, "male")

    print(student.count("Bammie"))
    print(student.index("male"))

    for x in student:
        print(x)

    if "Bammie" in student:
        print("Bammie is here")

## SET IN PYTHON
Set are collection which is unorderd, unindexed. No duplicate values

    untensils = {"fork","spoon","knife"}
    dishes = {"bowl", "plate","cup","knife"}

    untensils.add("napkin")
    untensils.remove("spoon")
    untensils.clear()
    dishes.update(untensils) #adds untensils to dishes
    dinner_table = untensils.union(dishes) #join the two set together and store it in dinner_table

    print(untensils.difference(dishes))
    print(untensils.intersection(dishes))

    for x in untensils:
        print(x)

## DICTIONARIES IN PYTHON
dictionaries is a changable, unorderd collection of unique key:value pairs
fast because they use hashing, allow us to access a value quickly

    capitals = {'USA':'washington DC',
                'India':'New Dehli',
                'China':'Beijing',
                'Russia':'Moscow'}

    capitals.update({'Germany':'Berlin'}) # adds new item to the dictonary
    capitals.update({'USA':'Berlin'}) #changes the value of USA to berlin
    capitals.pop('China') # removes china from the dictionaries
    capitals.clear() #clear all the items in the dictionary

    print(capitals.get('Germany')) # will return None
    print(capitals.keys()) # will return all the keys
    print(capitals.values()) # will return all the values
    print(capitals.items()) #will return all the keys and values

    or

    for key,value in capitals.items():
        print(key, value)


## INDEX OPERATOR IN PYTHON

    name = "bamiwo adebayo"

    if (name[0].islower()):
        name = name.capitalize() # capitalizes name
        print(name) # output - Bamiwo

    or

    first_name = name[:7].upper() # bamiwo will be changed to uppercase
    last_name = name[8:].lower() # adebayo will be changed to lowercase

    print(first_name) # output - BAMIWO
    print(last_name) # output - adebayo

## FUNCTIONS
A function is a bolck of code which is executed only when it is called

    def hello(name):
        print("Hello "+name)
        print("Have a nice day")

    hello("Bamiwo")

Passing two parameters

    def hello(first_name,last_name,age):
        print("Hello "+first_name+" "+last_name)
        print("YOur age is "+str(age)+" years old")
        print("Have a nice day")

    hello("Bamiwo","Adebayo",26)

## RETURN FUNCTION
Function send python values/objects back to the caller.

These values/objects are known as the function's return value

    def multiply(num1,num2):
        result = num1 * num2
        return result

    x = multiply(5,4)
    print(x)

## KEYWORD ARGUMENT
Argument preceded by an identifier when we pass them to a function\n

The order of the argument doesn't matter, unlike positional arguments

python knows the names of the arguments that our function receives

    def hello(first,middle,last):
        print("Hello "+first+" "+middle+" "+last)

    hello(last="Ade",first="Bammie",middle="moses")

## NESTED FUNCTIONS CALLS
Function calls inside other function calls

    print(round(abs(float(input("Enter a whole positive number: ")))))

## SCOPE
The region that a variable is recognized

A variable is only available from inside the region it is created

A global and locally scoped version can be created

    name = "Bammie"  # Global Variable

    def display_name():
        name = "Moses"  # Local Variable
        print(name)

    display_name()
    print(name)

## *args
Parameter that will pack all arguments into a tuple

Useful so that a function can accept a varying amount of argument

    def add(*args):         # any word can be used with * not nessesary args  e.g *number 
        sum = 0
        for i in args:
            sum += i
        return sum

    print(add(1,2,3,4,4,6,5))

Since it is a tuple we can't change it value but we can by passing the tuple to a list

    def add(*args):        
        sum = 0
        numbers = list(args)
        numbers[0] = 9
        for i in args:
            sum += i
        return sum

    print(add(1,2,3,4,4,6,5))

## **kwargs
Parameter that will pack all arguments into a dictionary.

Usefull so that a function can accept a varying amount of kryword arguments

    def hello(**kwargs):
        print("Hello", end=" ")
        for key,value in kwargs.item():
            print(value, end=" ")

    hello(title="Mr.",first="Bamiwo",last="Adebayo")