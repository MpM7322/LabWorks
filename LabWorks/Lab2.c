#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number_task;
    printf("\nВведите номер задачи, которая будет решена(1 или 2): ");
    scanf("%d", &number_task);

    switch (number_task) {
        case 1: {
            srand(time(NULL)); // получает текущее время и задаёт его в кач-ве нач значения генератора rand()

            int way;
            printf("\nВведите способ решения: 1) Динамичесим массивом 2) Статическим массивом: ");
            if (scanf("%d", &way) != 1) return 1;

            switch (way) {
                case 1: {
                    // Для того, чтобы поменять i-ую строку и j-ый столбец местами, массив должен быть квадратным
                    int rows;
                    printf("\nВведите кол-во строк и столбцов квадратного массива: ");
                    if (scanf("%d", &rows) != 1 || rows <= 0) return 1;

                    int **arr = malloc(rows * sizeof(int *));
                    for (int i = 0; i < rows; i++) *(arr + i) = malloc(rows * sizeof(int));

                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < rows; j++) {
                            *(*(arr + i) + j) = 1 + rand() % 10; // двумерный массив заполняется случайными числами от 1 до 10
                        }
                    }

                    printf("\n Ваш изначальный массив: \n");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < rows; j++) {
                            printf("%3d ", *(*(arr + i) + j));
                        }
                        printf("\n");
                    }

                    int row_number, col_number;
                    printf("\nВведите номер i-ой строки (от 1 до %d) и j-ого столбца (от 1 до %d), чтобы поменять их местами: ", rows, rows);
                    if (scanf("%d %d", &row_number, &col_number) != 2) return 1;

                    // Проверка корректности ввода:
                    if (row_number >= 1 && row_number <= rows && col_number >= 1 && col_number <= rows) {
                        int r_index = row_number - 1, c_index = col_number - 1;

                        // p идёт по строке, q идёт по столбцу
                        for (int p = 0, q = 0; p < rows && q < rows; p++, q++) {
                            // пропуск точек пересечения
                            if (p == c_index) p++;
                            if (q == r_index) q++;
                            if (p >= rows || q >= rows) break; // проверка на выход за границы

                            int tmp = *(*(arr + r_index) + p); // берём arr[r_index][p] - элемент из строки
                            *(*(arr + r_index) + p) = *(*(arr + q) + c_index); // записываем на его место arr[q][c_index] - элемент из столбца
                            *(*(arr + q) + c_index) = tmp; // в элемент из столбца записываем элемент из
                        }

                        printf("\n Ваш массив после того, как в нём поменяли i-ую строку и j-ый столбец: \n");
                        for (int i = 0; i < rows; i++) {
                            for (int j = 0; j < rows; j++) {
                                printf("%3d ", *(*(arr + i) + j));
                            }
                            printf("\n");
                        }
                    } else {
                        printf("\nНекорректный номер строки или столбца!\n");
                    }

                    for (int i = 0; i < rows; i++) free(*(arr + i));
                    free(arr);
                    break;
                }

                case 2: {
                    int arr[100][100], rows;
                    printf("\nВведите кол-во строк и столбцов квадратного массива: ");
                    if (scanf("%d", &rows) != 1 || rows <= 0) return 1;

                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < rows; j++) {
                            *(*(arr + i) + j) = 1 + rand() % 10; // двумерный массив заполняется случайными числами от 1 до 10
                        }
                    }

                    printf("\nВаш изначальный массив: \n");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < rows; j++) {
                            printf("%3d ", *(*(arr + i) + j));
                        }
                        printf("\n");
                    }

                    int row_number, col_number;
                    printf("\nВведите номер i-ой строки (от 1 до %d) и j-ого столбца (от 1 до %d), чтобы поменять их местами: ", rows, rows);
                    if (scanf("%d %d", &row_number, &col_number) != 2) return 1;

                    // Проверка корректности ввода:
                    if (row_number >= 1 && row_number <= rows && col_number >= 1 && col_number <= rows) {
                        int r_index = row_number - 1, c_index = col_number - 1;

                        // p идёт по строке, q идёт по столбцу
                        for (int p = 0, q = 0; p < rows && q < rows; p++, q++) {
                            // пропуск точек пересечения
                            if (p == c_index) p++;
                            if (q == r_index) q++;
                            if (p >= rows || q >= rows) break; // проверка на выход за границы

                            int tmp = *(*(arr + r_index) + p); // берём arr[r_index][p] - элемент из строки
                            *(*(arr + r_index) + p) = *(*(arr + q) + c_index); // записываем на его место arr[q][c_index] - элемент из столбца
                            *(*(arr + q) + c_index) = tmp; // в элемент из столбца записываем элемент из
                        }

                        printf("\nВаш массив после того, как в нём поменяли i-ую строку и j-ый столбец: \n");
                        for (int i = 0; i < rows; i++) {
                            for (int j = 0; j < rows; j++) {
                                printf("%3d ", *(*(arr + i) + j));
                            }
                            printf("\n");
                        }
                    } else {
                        printf("\nНекорректный номер строки или столбца!\n");
                    }

                    break;
                }

                default:
                    printf("\nТакого способа решения нет");
                    break;
            }
            break;
        }

        case 2: {
            char str[1000];
            while (getchar() != '\n');  // очистка буфера

            printf("\nВведите текст: ");
            gets_s(str, 1000);

            if (str[0] == '\0') {
                printf("\nСтрока не может быть пустой!");
                return 1;
            }

            else {
                int digits = 0, letters = 0, others = 0;
                for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
                    if (str[i] >= '0' && str[i] <= '9') digits++;
                    else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) letters++;
                    else others++;
                }

                if (digits > letters && digits > others) printf("\nЦифр в введённом тексте больше");
                else if (letters > digits && letters > others) printf("\nЛатинских букв в введённом тексте больше");
                else if (others > digits && others > letters) printf("\nДругих символов в введённом тексте больше");
                else printf("\nКоличество нескольких категорий символов в введённом тексте равно");
            }

            break;
        }
        
        default:
            printf("\nЗадачи с таким номером нет");
            break;
    }
    return 0;
}
