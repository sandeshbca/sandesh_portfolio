import random

def hangman():
    # Predefined word list
    words = ["python", "apple", "banana", "computer", "coding"]
    word = random.choice(words)  # Select a random word

    guessed_letters = []  # List to store guessed letters
    tries = 6  # Number of incorrect attempts allowed

    print("🎮 Welcome to Hangman Game!")
    print("You have 6 chances to guess the correct word.")
    print("_ " * len(word))  # Display blank spaces

    while tries > 0:
        guess = input("Enter a letter: ").lower()

        # Check if already guessed
        if guess in guessed_letters:
            print("You already guessed that letter. Try another one!")
            continue

        guessed_letters.append(guess)

        #  Correct guess
        if guess in word:
            print("✅ Correct guess!")
        else:
            tries -= 1
            print(f"❌ Wrong guess! You have {tries} tries left.")

        # Display current progress
        display = ""
        for letter in word:
            if letter in guessed_letters:
                display += letter + " "
            else:
                display += "_ "
        print(display)


        # Check if player won
        if "_" not in display:
            print("🎉 Congratulations! You guessed the word correctly:", word)
            break
    else:
        print("😢 Out of tries! The word was:", word)


hangman()
