
Valid = True

while Valid:
    username = input("Enter Your username: ")

    n = username.find(" ")
    print(n)

    if len(username) > 12:
        print("Username can't be more than 12 character")

    elif not username.find(" ") == -1:  # Returns -1 if username does not contain any spaces
        print("Username contain spaces")

    elif not username.isalpha():
        print("Username contains numbers")

    else:
        print(f"Welcome {username}")
        Valid = False