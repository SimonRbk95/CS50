from cs50 import get_float


def main():
    cents = get_cents()

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents = cents-quarters*25

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents = cents-dimes*10

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents = cents-nickels*5

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents = cents-pennies*1

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(coins)


def get_cents():
    while True:
        dollars = get_float("Change owed: ")
        if dollars >= 0:
            # turn dollars into cents
            cents = dollars*100
            return cents


def calculate_quarters(dollars):
    quarters = 0
    while dollars >= 25:
        dollars -= 25
        quarters += 1
    return quarters


def calculate_dimes(dollars):
    dimes = 0
    while dollars >= 10:
        dollars -= 10
        dimes += 1
    return dimes


def calculate_nickels(dollars):
    nickels = 0
    while dollars >= 10:
        dollars -= 10
        nickels += 1
    return nickels


def calculate_pennies(dollars):
    pennies = 0
    while dollars >= 1:
        dollars -= 1
        pennies += 1
    return pennies


if __name__ == "__main__":
    main()

