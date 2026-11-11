#include <stdio.h>

struct Date
{
    char date[100];
};

struct Time
{
    char time[100];
};

struct Visitor
{
    char snp[200];
};

struct Journal
{
};

void add_data(struct Date *user_date, struct Time *user_time, struct Visitor *user_fio, char journal[][50])
{
    int number = 0;
}

int main()
{
    struct Date user_data;
    struct Time user_time;
    struct Visitor user_fio;

    char journal[50][50];
    int ch;

    scanf("%s", &user_data.date);
    while ((ch = getchar()) != '\n' && ch != EOF);
    
    scanf("%s", &user_time.time);
    while ((ch = getchar()) != '\n' && ch != EOF);

    scanf("%s", &user_fio.snp);
    while ((ch = getchar()) != '\n' && ch != EOF);


    return 0;
}