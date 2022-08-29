import checksum_function
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

checksum_function.checksum_function(cc_number_string)

if checksum % 10 == 0 and (len(cc_number_string) == 13 or len(cc_number_string) == 15 or len(cc_number_string) == 16) and ((cc_number >= 340000000000000 and cc_number < 350000000000000) or (cc_number >= 370000000000000 and cc_number < 380000000000000)):

    print("AMEX")

elif checksum % 10 == 0 and (len(cc_number_string) == 13 or len(cc_number_string) == 15 or len(cc_number_string) == 16) and ((cc_number >= 4000000000000 and cc_number < 5000000000000) or (cc_number >= 4000000000000000 and cc_number < 5000000000000000)):

    print("VISA")

elif checksum % 10 == 0 and (len(cc_number_string) == 13 or len(cc_number_string) == 15 or len(cc_number_string) == 16) and ((cc_number >= 5100000000000000 and cc_number < 5600000000000000) or (cc_number >= 4000000000000000 and cc_number < 5000000000000000)):

    print("MASTERCARD")

# If it is not any of the brands above, then INVALID
else:

    print("INVALID")