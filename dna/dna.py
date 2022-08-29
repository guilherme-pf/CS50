import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    database = []
    databases = sys.argv[1]
    with open(databases) as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)

    # TODO: Read DNA sequence file into a variable
    sequences = sys.argv[2]
    with open(sequences) as file:
        reader = csv.reader(file)
        for row in reader:
            sequence = row

    # Getting the STR patterns
    column_names = []
    STRS = []
    with open(databases) as file:
        reader = csv.reader(file)
        for row in reader:
            column_names = row
            break
    STRS = column_names[1:]

    # TODO: Find longest match of each STR in DNA sequence

    STRS_longest_sequences = []
    for i in range(len(STRS)):
        STRS_longest_sequences.append(longest_match(sequence[0], STRS[i]))

    # TODO: Check database for matching profiles

    # Create a new dictionary with the names: score, and create a loop to check if the there is any matching profiles, incrementing +1 the score every time there is a match, at the end if the score is equal to the number os STRs being tested, then there is a match.
    scores_dict = {}

    for i in range(len(database)):
        scores_dict[(database[i]["name"])] = 0

    for i in range(len(database)):
        for j in range(len(STRS)):
            if int(database[i][STRS[j]]) == int(STRS_longest_sequences[j]):
                scores_dict[(database[i]["name"])] += 1

    # Getting the KEY by VALUE
    def get_key(val):
        for key, value in scores_dict.items():
            if val == value:
                return key
        return "No Match"
    print(get_key(len(STRS)))

    return


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


main()
