from cs50 import get_float


def main():
    cents = get_cents()



def get_cents():
    dollars = get_float("Change owed: ")
    # turn dollars into cents
    dollars *=100
    return cents


def calculate_quarters(dollars):
    quarters = 0
    while dollars>=25:
        dollars -= 25
        quarters += 1
    return quarters


def calculate_dimes(dollars):
    dimes = 0
    while dollars>=10:
        dollars -= 10
        dimes += 1
    return dimes

def calculate_nickels(dollars):
    nickels = 0
    while dollars>=10:
        dollars -= 10
        nickels += 1
    return nickels

def calculate_pennies(dollars):
    pennies = 0
    while dollars>=1:
        dollars -= 1
        pennies += 1
    return pennies





