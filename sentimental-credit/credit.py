# Restrictions against invalid input
while True:
    try:
        cc_number = int(input("Credit Card Number: "))
        if cc_number < 9999999999999999 and cc_number > 0:
            break
    except:
        print("", end="")

cc_number_string = str(cc_number)
checksum = 0
digits = []
digit_times_2 = 0

# Checksum validation
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

# Checking if the cc number is valid
if checksum % 10 == 0 and (len(cc_number_string) == 13 or len(cc_number_string) == 15 or len(cc_number_string) == 16) and ((cc_number >= 340000000000000 and cc_number < 350000000000000) or (cc_number >= 370000000000000 and cc_number < 380000000000000)):

    print("AMEX")

elif checksum % 10 == 0 and (len(cc_number_string) == 13 or len(cc_number_string) == 15 or len(cc_number_string) == 16) and ((cc_number >= 4000000000000 and cc_number < 5000000000000) or (cc_number >= 4000000000000000 and cc_number < 5000000000000000)):

    print("VISA")

elif checksum % 10 == 0 and (len(cc_number_string) == 13 or len(cc_number_string) == 15 or len(cc_number_string) == 16) and ((cc_number >= 5100000000000000 and cc_number < 5600000000000000) or (cc_number >= 4000000000000000 and cc_number < 5000000000000000)):

    print("MASTERCARD")

# If it is not any of the brands above, then INVALID
else:

    print("INVALID")
