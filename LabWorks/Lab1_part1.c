#include <stdio.h>

void to_binary(int);
void bitwise_operation(int, int, char);

int main()
{
  char beginning[] =
  "\n******************************************************\n"
  "* Nizhny Novgorod State Technical University         *\n"
  "* Study work number 1. Task number 1.                *\n"
  "* Performed by a student of 26-IVT-4-2 Andryukov M.V.*\n"
  "******************************************************\n";

  printf("%s", beginning);
      
  // Объявление переменных простых типов
  int i;
  unsigned int ui;
  short s;
  long long l;
  float f;
  double d;
  char ch1, ch2;

  // Инициализация константы
  const float pi = 3.14;

  printf("\n===========================================\n");
  printf("\tWorking with variables in C\t\n");
  printf("===========================================\n");

  printf("\n\n1. Keybord data entry\n\n"); // Ввод данных с клавиатуры

  printf("\nEnter an integer(i): ");
  scanf("%d", &i);

  printf("\nEnter an unsigned integer(ui): ");
  scanf("%u", &ui);

  printf("\nEnter a number of type short(s): ");
  scanf("%hd", &s);
  
  printf("\nEnter a number of type long long(l): ");
  scanf("%lld", &l);

  printf("\nEnter a number of type float(f): ");
  scanf("%f", &f);

  printf("\nEnter a number of type double(d): ");
  scanf("%lf", &d);
 
  rewind(stdin); // Очищаем поток ввода, т. к там остаётся \n

  printf("\nThe first character will be read as a character");
  printf("\nEnter the first character(ch1): ");
  scanf("%c", &ch1);

  rewind(stdin); // Очищаем поток ввода, т. к там остаётся \n
 
  printf("\nThe second character will be read as a number");
  printf("\nEnter the second character(ch2): ");
  scanf("%hhd", &ch2);

  printf("\nYou entered: i = %d, ui = %u, s = %hd, l = %lld, f = %.3f, d = %lf, ch1 = %d = %c, ch2 = %d = %c", i, ui, s, l, f, d, ch1, ch1, ch2, ch2);
 
  printf("\n\n2. Expressions with variable\n\n"); // Выражение с переменными

  printf("2.1) Arithmetic operations\n\n");
  
  int a, b; // Объявление двух переменных для составления выражений
  printf("Enter two integers(1 - a; 2 - b): ");
  scanf("%d%d", &a, &b);
  
  printf("\na + b = %d\n", a + b);
  printf("\na - b = %d\n", a - b);
  printf("\na * b = %d\n", a * b);
  if (!b) printf("\nDivision by zero");
  else printf("\na / b = %.2f\n", (float)a / b);
  printf("\na %% b = %d\n\n\n", a % b);
  
  printf("2.2) Bitwise operations\n\n");

  bitwise_operation(a, b, '&');
  bitwise_operation(a, b, '|');
  bitwise_operation(a, b, '^');

  printf(" a = ");
  to_binary(a);
  printf(" (%d)\n", a);

  printf("~a = ");
  to_binary(~a);
  printf(" (%d)\n", ~a);

  int bits; // Объявление переменной для побитового сдвига
  printf("\nEnter the amount of bits to shift(0 - 31): ");
  scanf("%d", &bits);

  printf("\na >> %d = ", bits);
  to_binary(a);
  printf(" >> %d = ", bits);
  to_binary(a >> bits);
  printf(" (%d)", a >> bits);

  printf("\n\na << %d = ", bits);
  to_binary(a);
  printf(" << %d = ", bits);
  to_binary(a << bits);
  printf(" (%d)", a << bits);

  printf("\n\n\n2.3) Operations with constants\n");

  float radius; // Объявили переменную радиуса, чтобы дальше с помощью константы посчитатать S
  printf("\nEnter radius of the circle: ");
  scanf("%f", &radius);
  printf("Area of a circle with a radius of %.2f = %.2f", radius, radius * radius * pi);

  printf("\n\n3. Conversion between numeral systems\n\n"); // Перевод в СС
  int num; // Объявления переменной для перевода в разные СС
  printf("Enter your integer to convert to different numeral systems: ");
  scanf("%d", &num);

  printf("%d from 10 NS to 2 NS = ", num);
  to_binary(num);
  
  printf("\n\n%d from 10 NS to 8 NS = %o", num, num);
  printf("\n\n%d from 10 NS to 16 NS = %x", num, num);

  return 0;
}

void to_binary(int num) {
  int flag = 0;

  if (num == 0) printf("%d", num);

  else {
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
      int bit = (num >> i) & 1;
      if (bit) flag = 1;
      if (flag) printf("%d", bit);
    }
  }
}

void bitwise_operation(int a, int b, char operation) {
    int result;

    if (operation == '&') result = a & b;
    else if (operation == '|') result = a | b;
    else result = a ^ b;

    printf("a %c b:", operation);
    printf("\n");

    printf("  ");
    to_binary(a);
    printf(" (%d)", a);

    printf("\n%c ", operation);
    to_binary(b);
    printf(" (%d)", b);

    printf("\n----------------------------------\n  ");

    to_binary(result);
    printf(" (%d)\n\n\n", result);
}