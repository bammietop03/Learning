import random
import string

chars = " " + string.punctuation + string.digits + string.ascii_letters
chars = list(chars)
keys = chars.copy()
random.shuffle(keys)

plain_text = input("Enter a message to be encrypted: ")
encrypted = ""

for letter in plain_text:
    index = chars.index(letter)
    encrypted += keys[index]

print(f"Original Message: {plain_text}")
print(f"Encrypted Message: {encrypted}")


encrypted = input("Enter the encrypted value: ")
plain_text = ""

for letter in encrypted:
    index = keys.index(letter)
    plain_text += chars[index]

print(f"Encrypted Message: {encrypted}")
print(f"Original Message: {plain_text}")