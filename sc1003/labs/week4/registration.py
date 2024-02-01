from password import validate


def main():
    print("User registration:")
    get_name()
    while True:
        password = get_password()
        if password_checker(password):
            break
    


def password_checker(password):
    valid = validate(password)
    if valid:
        print("Your password is strong enough. User registered.")
    else:
        print("Your password is weak. Please enter a new password.")
    return valid


def get_name():
    return input("Input your username: ")


def get_password():
    return input(
    """Input your password: 
    1. the password has at least one upper case letter
    2. the password has at least one lower case letter
    3. the password has at least one digit
    4. its length is more than 8\n""")



if __name__ == "__main__":
    main()