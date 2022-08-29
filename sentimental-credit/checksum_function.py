def checksum_function(cc):
    cc_number_string = str(cc)
    checksum = 0
    digits = []
    digit_times_2 = 0
    for i in range(int(len(cc_number_string))):

        if (int(len(cc_number_string) - 2 - (2 * i))) < 0:
            break

        else:

            digit_times_2 = int(cc_number_string[len(cc_number_string) - 2 - (2 * i)]) * 2

            digits.append(digit_times_2)

    for i in range(len(digits)):
        # Adding double digits to checksum
        if digits[i] > 9:
            string_digits = str(digits[i])
            sum_digits = int(string_digits[0]) + int(string_digits[1])
            checksum += sum_digits
        else:
            # Adding single digits to checksum
            checksum += digits[i]

    for i in range(int(len(cc_number_string))):

        if (int(len(cc_number_string) - 1 - (2 * i))) < 0:
            break

        else:
            # Adding the remaining digits to the checksum
            checksum += int(cc_number_string[len(cc_number_string) - 1 - (2 * i)])