import random

ans = random.randint(1, 100)
print(ans)


while True:
    guess = random.randint(1, 100)
    print(guess)
    answer = input()
    if answer == "correct":
        break
    elif answer == "higher":
        guess = random.randint(guess, 100)
    elif answer == "lower":
        guess = random.randint(1, guess)
