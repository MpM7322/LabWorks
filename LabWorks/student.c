#include <stdio.h>

struct student
{
    char name[20];
    int score[4];
    float average_score;
};

void get_average_of_group(struct student users[], int count)
{
    for (int i = 0; i < count; i++)
    {
        float average = 0;
        for (int j = 0; j < 4; j++)
        {
            average += users[i].score[j];
        }
        average /= 4;
        users[i].average_score = average;
    }

    float group_average = 0;
    for (int i = 0; i < count; i++)
    {
        group_average += users[i].average_score;
    }
    group_average /= count;

    printf("Средний балл группы: %.2f\n", group_average);
}

void get_dvoechniki_otlichniki(struct student users[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (users[i].average_score == 2)
            printf("Двоечник: %s\n", users[i].name);

        if (users[i].average_score == 5)
            printf("Отличник: %s\n", users[i].name);
    }
}

int main()
{
    struct student users[2];
    int ch;

    for (int j = 0; j < 2; j++)
    {
        printf("Введите имя студента %d: ", j + 1);
        scanf("%s", users[j].name);
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

        printf("Введите 4 оценки: ");
        for (int i = 0; i < 4; i++)
        {
            scanf("%d", &users[j].score[i]);
        }
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    get_average_of_group(users, 2);
    get_dvoechniki_otlichniki(users, 2);

    return 0;
}
