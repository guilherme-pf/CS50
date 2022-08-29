#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit_card_number;
    do
    {
        credit_card_number = get_long("Credit Card Number: ");
    }
    // Restrictions to input
    while (credit_card_number > 9999999999999999 || credit_card_number < 0);


    // getting the sum of the digits of (2nd to last number * 2)
    long last_2_numbers = credit_card_number % 100;
    long second_to_last_digit = last_2_numbers / 10;
    long second_to_last_digit1 = 1;
    long second_to_last_digit2 = (second_to_last_digit * 2) % 10;
    long sum_second_to_last = 0;


    if (second_to_last_digit > 4)
    {
        sum_second_to_last = (second_to_last_digit1 + second_to_last_digit2);
    }
    else
    {
        sum_second_to_last = second_to_last_digit * 2 ;
    }


    // getting the sum of the digits of (4th to last number * 2)
    long last_4_numbers = credit_card_number % 10000;
    long fourth_to_last_digit = last_4_numbers / 1000;
    long fourth_to_last_digit1 = 1;
    long fourth_to_last_digit2 = (fourth_to_last_digit * 2) % 10;
    long sum_fourth_to_last = 0;


    if (fourth_to_last_digit > 4)
    {
        sum_fourth_to_last = (fourth_to_last_digit1 + fourth_to_last_digit2);
    }
    else
    {
        sum_fourth_to_last = fourth_to_last_digit * 2;
    }


    // getting the sum of the digits of (6th to last number * 2)
    long last_6_numbers = credit_card_number % 1000000;
    long sixth_to_last_digit = last_6_numbers / 100000;
    long sixth_to_last_digit1 = 1;
    long sixth_to_last_digit2 = (sixth_to_last_digit * 2) % 10;
    long sum_sixth_to_last = 0;


    if (sixth_to_last_digit > 4)
    {
        sum_sixth_to_last = (sixth_to_last_digit1 + sixth_to_last_digit2);
    }
    else
    {
        sum_sixth_to_last = sixth_to_last_digit * 2;
    }


    // getting the sum of the digits of (8th to last number * 2)
    long last_8_numbers = credit_card_number % 100000000;
    long eigth_to_last_digit = last_8_numbers / 10000000;
    long eigth_to_last_digit1 = 1;
    long eigth_to_last_digit2 = (eigth_to_last_digit * 2) % 10;
    long sum_eigth_to_last = 0;


    if (eigth_to_last_digit > 4)
    {
        sum_eigth_to_last = (eigth_to_last_digit1 + eigth_to_last_digit2);
    }
    else
    {
        sum_eigth_to_last = eigth_to_last_digit * 2;
    }


    // getting the sum of the digits of (10th to last number * 2)
    long last_10_numbers = credit_card_number % 10000000000;
    long tenth_to_last_digit = last_10_numbers / 1000000000;
    long tenth_to_last_digit1 = 1;
    long tenth_to_last_digit2 = (tenth_to_last_digit * 2) % 10;
    long sum_tenth_to_last = 0;


    if (tenth_to_last_digit > 4)
    {
        sum_tenth_to_last = (tenth_to_last_digit1 + tenth_to_last_digit2);
    }
    else
    {
        sum_tenth_to_last = tenth_to_last_digit * 2;
    }



    // getting the sum of the digits of (12th to last number * 2)
    long last_12_numbers = credit_card_number % 1000000000000;
    long twelfth_to_last_digit = last_12_numbers / 100000000000;
    long twelfth_to_last_digit1 = 1;
    long twelfth_to_last_digit2 = (twelfth_to_last_digit * 2) % 10;
    long sum_twelfth_to_last = 0;


    if (twelfth_to_last_digit > 4)
    {
        sum_twelfth_to_last = (twelfth_to_last_digit1 + twelfth_to_last_digit2);
    }
    else
    {
        sum_twelfth_to_last = twelfth_to_last_digit * 2;
    }


    // getting the sum of the digits of (14th to last number * 2)
    long last_14_numbers = credit_card_number % 100000000000000;
    long fourteenth_to_last_digit = last_14_numbers / 10000000000000;
    long fourteenth_to_last_digit1 = 1;
    long fourteenth_to_last_digit2 = (fourteenth_to_last_digit * 2) % 10;
    long sum_fourteenth_to_last = 0;


    if (fourteenth_to_last_digit > 4)
    {
        sum_fourteenth_to_last = (fourteenth_to_last_digit1 + fourteenth_to_last_digit2);
    }
    else
    {
        sum_fourteenth_to_last = fourteenth_to_last_digit * 2;
    }


    // getting the sum of the digits of (16th to last number * 2)
    long last_16_numbers = credit_card_number % 10000000000000000;
    long sixteenth_to_last_digit = last_16_numbers / 1000000000000000;
    long sixteenth_to_last_digit1 = 1;
    long sixteenth_to_last_digit2 = (sixteenth_to_last_digit * 2) % 10;
    long sum_sixteenth_to_last = 0;


    if (sixteenth_to_last_digit > 4)
    {
        sum_sixteenth_to_last = (sixteenth_to_last_digit1 + sixteenth_to_last_digit2);
    }
    else
    {
        sum_sixteenth_to_last = sixteenth_to_last_digit * 2;
    }


    // getting last digit
    long last_digit = credit_card_number % 10;

    // getting the 3th to last digit
    long last_3_numbers = credit_card_number % 1000;
    long third_to_last_digit = last_3_numbers / 100;

    // getting the 5th to last digit
    long last_5_numbers = credit_card_number % 100000;
    long fifth_to_last_digit = last_5_numbers / 10000;

    // getting the 7th to last digit
    long last_7_numbers = credit_card_number % 10000000;
    long seventh_to_last_digit = last_7_numbers / 1000000;

    // getting the 9th to last digit
    long last_9_numbers = credit_card_number % 1000000000;
    long nineth_to_last_digit = last_9_numbers / 100000000;

    // getting the 11th to last digit
    long last_11_numbers = credit_card_number % 100000000000;
    long eleventh_to_last_digit = last_11_numbers / 10000000000;

    // getting the 13th to last digit
    long last_13_numbers = credit_card_number % 10000000000000;
    long thirteenth_to_last_digit = last_13_numbers / 1000000000000;

    // getting the 15th to last digit
    long last_15_numbers = credit_card_number % 1000000000000000;
    long fifteenth_to_last_digit = last_15_numbers / 100000000000000;



    // Checksum formula
    long checksum = ((sum_second_to_last) + (sum_fourth_to_last) + (sum_sixth_to_last) + (sum_eigth_to_last) + (sum_tenth_to_last) +
                     (sum_twelfth_to_last) + (sum_fourteenth_to_last) + (sum_sixteenth_to_last)) + (last_digit + third_to_last_digit +
                             fifth_to_last_digit + seventh_to_last_digit + nineth_to_last_digit + eleventh_to_last_digit + thirteenth_to_last_digit +
                             fifteenth_to_last_digit);

    // check for card lenght by dividing th card number by 10, if this number is not 0, add +1 to lenght and divide again, until the car number is 0
    long length = 0;
    long credit_card_number_length = credit_card_number;

    do
    {
        credit_card_number_length = credit_card_number_length / 10;
        length += 1;
    }

    while (credit_card_number_length != 0);


    // Checking the first 2 digits of the card


    // Checking if the cardnumber is valid one and from what company
    long is_valid = 0;
    if (checksum % 10 == 0 && (length == 13 || length == 15 || length == 16) && ((credit_card_number >= 340000000000000
            && credit_card_number < 350000000000000) || (credit_card_number >= 370000000000000 && credit_card_number < 380000000000000)))
    {
        printf("AMEX\n");
    }

    else if (checksum % 10 == 0 && (length == 13 || length == 15 || length == 16) && ((credit_card_number >= 4000000000000
             && credit_card_number < 5000000000000) || (credit_card_number >= 4000000000000000 && credit_card_number < 5000000000000000)))
    {
        printf("VISA\n");
    }

    else if (checksum % 10 == 0 && (length == 13 || length == 15 || length == 16) && ((credit_card_number >= 5100000000000000
             && credit_card_number < 5600000000000000) || (credit_card_number >= 4000000000000000 && credit_card_number < 5000000000000000)))
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("INVALID\n");
    }


}

