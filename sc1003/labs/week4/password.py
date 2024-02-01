from re import search


def main():
    password = input("Please enter a password: ")
    if validate(password):
        print("Password is strong :)")
    else:
        print("Password is weak :(")



def validate(password):
    # Check if password length is more than 8
    if len(password) < 9:
        return False
    
    upper_case = lower_case = digit = False

    # Check if password has at least one:
    #   - upper case letter
    #   - lower case letter
    #   - digit
    for char in password:
        if char.isupper():
            upper_case = True
        elif char.islower():
            lower_case = True
        elif char.isdigit():
            digit = True

    return upper_case and lower_case and digit



if __name__ == "__main__":
    main()