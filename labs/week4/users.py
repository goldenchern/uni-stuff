import registration as reg


def main():
    users = create_database()
    print("User registration:")

    while True:
        name = reg.get_name()
        if not name in users:
            break
        print("The user exists. Please choose another username.")

    while True:
        password = reg.get_password()
        if reg.password_checker(password):
            break

    update_database(users, name, password)
    print(f"The users in system\n{users}")



def create_database():
    return {
        "Test": "Test12345",
        "Jack": "test12345",
        "Tom": "Password1",
    }


def update_database(users, name, password):
    users[name] = password



if __name__ == "__main__":
    main()