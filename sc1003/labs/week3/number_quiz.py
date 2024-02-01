import random


def main():
    quiz = get_quiz_selection()
    if quiz == "1":
        start_quiz_1()
    else:
        start_quiz_2()
    print("You can start the game now.")



def get_quiz_selection():
    print("Please select one of the following quizzes:")
    print("\t1. Number guessing")
    print("\t2. Calculate sum")

    # Validate selection
    selection = input()
    if selection == "1" or selection == "2":
        return selection
    else:
        quit("Wrong option. Bye.")


def start_quiz_1():
    n = random.randint(1, 99)

    # Run 3 trials
    for trial in range(1, 4):
        guess = int(input("Enter an integer from 1 to 99: "))
        
        # Compare guess to actual number
        if guess < n:
            print(f"guess is low")
        elif guess > n:
            print("guess is high")
        else:
            print(f"Congratulations. You guessed it by {trial} trials!")
            return
    quit("Sorry, you exceeded the trial limit. Failed.")
    

def start_quiz_2():

    # Calculate sum for randomly selected number
    start = random.randint(55, 66)
    sum = 0
    for n in range(start, start + 5):
        sum += n
    
    # Validate answer
    print(f"Please calculate the sum of 5 integers starting from {start}")
    try:
        answer = int(input("Please enter your answer: "))
    except ValueError:
        quit("Answer must be an integer.")

    # Check if answer is correct
    if answer != sum:
        quit("Sorry, wrong answer. Failed.")



if __name__ == "__main__":
    main()