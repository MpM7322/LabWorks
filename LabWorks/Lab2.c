#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100
#define MAX_STR 1000

void randomize_dynamic_matrix(int **, int);
void print_dynamic_matrix(int **, int);
int swap_row_and_col_dynamic(int **, int);

void randomize_static_matrix(int[][MAX], int);
void print_static_matrix(int[][MAX], int);
int swap_row_and_col_static(int[][MAX], int);

void analyze_string_characters(char *);

void clear_input_buffer();

int main()
{
    srand(time(NULL)); // получает текущее время и задаёт его в кач-ве нач значения генератора rand()

    while (1)
    {
        printf("\n\nЗадача 1: Обмен i-й строки и j-го столбца в числовом двумерном массиве.\n");
        printf("Задача 2: Сохранение текста и определение, каких символов в нем больше.\n");

        int number_task;
        printf("\nВведите номер задачи, которая будет решена (1 или 2): ");
        if (scanf("%d", &number_task) != 1)
        {
            printf("\nНеправильный ввод");

            clear_input_buffer();
            continue;
        }

        switch (number_task)
        {
        case 1:
        {
            int way;
            printf("\nВведите способ решения: 1) Динамичесим массивом 2) Статическим массивом: ");
            if (scanf("%d", &way) != 1)
            {
                printf("\nНеправильный ввод");
                clear_input_buffer();
                continue;
            }

            switch (way)
            {
            case 1:
            {
                // Для того, чтобы поменять i-ую строку и j-ый столбец местами, массив должен быть квадратным
                int rows;
                printf("\nВведите кол-во строк и столбцов квадратного массива: ");
                if (scanf("%d", &rows) != 1 || rows <= 0)
                {
                    printf("\nНеправильный ввод");
                    clear_input_buffer();
                    continue;
                }

                int **arr = (int **)malloc(rows * sizeof(int *));

                if (arr == NULL)
                {
                    printf("\nОшибка выделения памяти");
                    return 1;
                }

                for (int i = 0; i < rows; i++)
                {
                    *(arr + i) = (int *)malloc(rows * sizeof(int));

                    if (*(arr + i) == NULL)
                    {
                        for (int j = 0; j < i; j++)
                            free(*(arr + j));
                        free(arr);
                        printf("\nОшибка выделения памяти");
                        return 1;
                    }
                }

                randomize_dynamic_matrix(arr, rows);

                printf("\n Ваш изначальный массив: \n");
                print_dynamic_matrix(arr, rows);

                if (swap_row_and_col_dynamic(arr, rows))
                {
                    printf("\n Ваш массив после того, как в нём поменяли i-ую строку и j-ый столбец: \n");
                    print_dynamic_matrix(arr, rows);
                }

                for (int i = 0; i < rows; i++)
                    free(*(arr + i));
                free(arr);
                break;
            }

            case 2:
            {
                int arr[MAX][MAX], rows;
                printf("\nВведите кол-во строк и столбцов квадратного массива: ");
                if (scanf("%d", &rows) != 1 || rows <= 0 || rows > MAX)
                {
                    printf("\nНеправильный ввод");
                    clear_input_buffer();
                    continue;
                }

                randomize_static_matrix(arr, rows);

                printf("\n Ваш изначальный массив: \n");
                print_static_matrix(arr, rows);

                if (swap_row_and_col_static(arr, rows))
                {
                    printf("\n Ваш массив после того, как в нём поменяли i-ую строку и j-ый столбец: \n");
                    print_static_matrix(arr, rows);
                }

                break;
            }

            default:
                printf("\nТакого способа решения нет");
                break;
            }
            break;
        }

        case 2:
        {
            char str[MAX_STR];
            clear_input_buffer();

            printf("\nВведите текст: ");
            if (fgets(str, sizeof(str), stdin) != NULL)
            {
                str[strcspn(str, "\n")] = '\0';

                if (str[0] == '\0')
                {
                    printf("\nСтрока не может быть пустой!");
                    break;
                }

                else
                    analyze_string_characters(str);
            }
            break;
        }

        default:
            printf("\nЗадачи с таким номером нет");
            break;
        }

        int choice;
        while (1)
        {
            printf("\n\nХотите решить ещё одну задачу? 1 - Да ; 0 - Нет");
            printf("\nВаш выбор: ");

            if (scanf("%d", &choice) != 1)
            {
                printf("\nНеправильный ввод");
                clear_input_buffer();
                continue;
            }

            clear_input_buffer();

            if (choice == 1 || choice == 0)
                break;
            else
                printf("\nНеверный ввод");
        }

        if (choice == 0)
        {
            printf("\nПрограмма завершена.\n");
            break;
        }
    }

    return 0;
}

void randomize_dynamic_matrix(int **arr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            *(*(arr + i) + j) = 1 + rand() % 10;
        }
    }
}

void randomize_static_matrix(int arr[][MAX], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            *(*(arr + i) + j) = 1 + rand() % 10;
        }
    }
}

void print_dynamic_matrix(int **arr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%3d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void print_static_matrix(int arr[][MAX], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%3d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

int swap_row_and_col_dynamic(int **arr, int rows)
{
    int row_number, col_number;
    printf("\nВведите номер i-ой строки (от 1 до %d) и j-ого столбца (от 1 до %d), чтобы поменять их местами: ", rows, rows);
    if (scanf("%d %d", &row_number, &col_number) != 2)
    {
        printf("\nНекорректный ввод!\n");
        clear_input_buffer();
        return 0;
    }

    if (row_number >= 1 && row_number <= rows && col_number >= 1 && col_number <= rows)
    {
        int r_index = row_number - 1, c_index = col_number - 1;

        for (int i = 0; i < rows; i++)
        {
            if (i == r_index && i == c_index)
                continue;

            int temp = *(*(arr + r_index) + i);
            *(*(arr + r_index) + i) = *(*(arr + i) + c_index);
            *(*(arr + i) + c_index) = temp;
        }
        return 1;
    }

    else
    {
        printf("\nНекорректный номер строки или столбца!\n");
        return 0;
    }
}

int swap_row_and_col_static(int arr[][MAX], int rows)
{
    int row_number, col_number;
    printf("\nВведите номер i-ой строки (от 1 до %d) и j-ого столбца (от 1 до %d), чтобы поменять их местами: ", rows, rows);
    if (scanf("%d %d", &row_number, &col_number) != 2)
    {
        printf("\nНекорректный ввод!\n");
        clear_input_buffer();
        return 0;
    }

    if (row_number >= 1 && row_number <= rows && col_number >= 1 && col_number <= rows)
    {
        int r_index = row_number - 1, c_index = col_number - 1;

        for (int i = 0; i < rows; i++)
        {
            if (i == r_index && i == c_index)
                continue;

            int temp = *(*(arr + r_index) + i);
            *(*(arr + r_index) + i) = *(*(arr + i) + c_index);
            *(*(arr + i) + c_index) = temp;
        }
        return 1;
    }

    else
    {
        printf("\nНекорректный номер строки или столбца!\n");
        return 0;
    }
}

void analyze_string_characters(char *str)
{
    int digits = 0, letters = 0, others = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            digits++;
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            letters++;
        else
            others++;
    }

    if (digits > letters && digits > others)
        printf("\nЦифр в введённом тексте больше");
    else if (letters > digits && letters > others)
        printf("\nЛатинских букв в введённом тексте больше");
    else if (others > digits && others > letters)
        printf("\nДругих символов в введённом тексте больше");
    else
        printf("\nКоличество нескольких категорий символов в введённом тексте равно");
}

void clear_input_buffer()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}