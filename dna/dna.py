import csv
import sys


def main():

    # TODO: Check for command-line usage
    valid_input()

    # TODO: Read database file into a variable
    DNA_dict, column_SRTs = read_database()

    # TODO: Read DNA sequence file into a variable
    sequence = read_sequence()

    # TODO: Find longest match of each STR in DNA sequence
    # TODO: Check database for matching profiles
    match = check_database(DNA_dict, column_SRTs, sequence)

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
        # get first CSV's columns
        column_SRTs = reader.fieldnames
        for row in reader:
            DNA_dict.append(row)
        return DNA_dict, column_SRTs


def read_sequence():
    with open(sys.argv[2]) as file:
        sequence = file.read()
        return sequence


def check_database(DNA_dict, column_SRTs, sequence):
    # assign to suspect the dictionaries in the list DNA_dict
    for suspect in DNA_dict:
        # assigns the SRT we are looking for to subsequence
        for subsequence in column_SRTs[1:]:
            # subsequence is used as the key to check whether the suspect's SRT value eqauls the longest_match
            if int(suspect[subsequence]) != longest_match(sequence, subsequence):
                guilty = False
                break
            else:
                guilty = True
        if guilty:
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
