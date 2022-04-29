import csv
import sys


# global variables of sequences
for seq in range(1, len(column_names)):
    
sq1 = "AGATC"
sq2 = "AATG"
sq3 = "TATC"


def main():

    # TODO: Check for command-line usage
    valid_input()

    # TODO: Read database file into a variable
    DNA_dict, column_names = read_database()

    # TODO: Read DNA sequence file into a variable
    sequence = read_sequence()

    # TODO: Find longest match of each STR in DNA sequence
    for seq in range(1,len(column_names):
        long_sq1 = longest_match(sequence, seq)
    long_sq2 = longest_match(sequence, s)
    long_sq3 = longest_match(sequence, sq3)

    # TODO: Check database for matching profiles
    match = check_database(DNA_dict, long_sq1, long_sq2, long_sq3)

    if match != None:
        print(match)
    else:
        print("no match")


def valid_input():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")


def read_database():
    # list of dictionaries about the DNA profiles
    DNA_dict = []
    with open(sys.argv[1]) as database:
        reader = csv.DictReader(database)
        column_names = reader.fieldnames
        for row in reader:
            DNA_dict.append(row)
        return DNA_dict, column_names


def read_sequence():
    with open(sys.argv[2]) as file:
        sequence = file.read()
        return sequence


def check_database(DNA_dict, long_sq1, long_sq2, long_sq3):
     # assign suspect the dictionaries in the list DNA_dict
    for suspect in DNA_dict:
        print(int(suspect[sq1]))
        # check if all longest sequences matches with the current name's sequence values
        if int(suspect[sq1]) == long_sq1 and int(suspect[sq2]) == long_sq2 and int(suspect[sq3]) == long_sq3:
            return suspect["name"]


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


if __name__ == "__main__":
    main()