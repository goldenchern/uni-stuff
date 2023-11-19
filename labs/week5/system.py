from week3.number_quiz import start_quiz_1 as guessingNumber, start_quiz_2 as calculateSum
from week4.registration import get_name, get_password, password_checker
from week4.users import create_database, update_database

USERS = create_database()


def main():
    choice = getUserChoice()
    if choice == 1:
        userRegistration(getNewUserName(),getStrongPassword())
    elif choice == 2:
        userLogin()
    elif choice == 3:
        guestQuiz()


def getNewUserName():
    while True:
        name = get_name()
        if not name in USERS:
            break
        print("The user exists. Please choose another username.")


def getStrongPassword():
    while True:
        password = get_password()
        if password_checker(password):
            break


def userRegistration(name, password):
    update_database(USERS, name, password)
    print("New user registered. You can start the game.")


def userLogin():
    while True:
        name = input("Input username: ")
        password = input("Input password: ")

        if name in USERS and password == USERS[name]:
            print(f"Welcome back, {name}, You can start the game.")
            break

        print("Invalid username/password. Please try again.")


def getUserChoice():
    return int(input('''Please select one of the followingoptions:
1. User registration
2. User Login
3. Play the game as a guest\n'''))


def guestQuiz():
    quizChoice = chooseQuiz()
    isPass = takeQuiz(quizChoice)

    if isPass:
        print("Congratulations. You can start the game.")


def chooseQuiz():
    return int(input('''Dear Guest, you have to pass one quiz to
play the game.
Please select one of the following quizzes:
1. Number guessing
2. Calculate sum\n'''))


def takeQuiz(choice):
    if choice == 1:
        isPass = guessingNumber()
    elif choice == 2:
        isPass = calculateSum()
    return isPass



if __name__ == "__main__":
    main()