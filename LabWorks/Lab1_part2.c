#include <stdio.h>
#include <math.h> // pow
#include <stdlib.h> // для llabs

int main()
{
    char beginning[] =
  "\n******************************************************\n"
  "* Nizhny Novgorod State Technical University         *\n"
  "* Study work number 1. Task number 2.                *\n"
  "* Performed by a student of 26-IVT-4-2 Andryukov M.V.*\n"
  "******************************************************\n";

  printf("%s", beginning);

    double user_number1;

    printf("\nEnter your number: ");
    scanf("%lf", &user_number1);

    int digits_counter = 0;

    if (user_number1 - (long long)user_number1 != 0) printf("\nYour number isn't an integer\n");
    
    else {
        printf("\nYour number is an integer\n");
        long long user_number2 = user_number1;

        if (user_number2 == 0) digits_counter = 1;

        else {
            while (llabs(user_number2) > 0) {
                user_number2 /= 10;
                digits_counter++;
            }
        }

        printf("\nThe amount of digits in your number: %d\n", digits_counter);

        long long maxpow10 = pow(10, digits_counter - 1);
        user_number2 = user_number1;

        printf("\nYour number broken down by digits: \n");
        while (maxpow10 > 0) {
            int digit = llabs(user_number2) / maxpow10;
            printf("%d\n", digit);
            user_number2 %= maxpow10;
            maxpow10 /= 10;
        }
    }

    return 0;
}
