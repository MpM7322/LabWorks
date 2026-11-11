#include <stdio.h>

struct dot
{
    int x;
    int y;
};

int chetvert(struct dot *user_dot)
{
    if (user_dot->x > 0 && user_dot->y > 0)
        return 1;
    else if (user_dot->x < 0 && user_dot->y > 0)
        return 2;
    else if (user_dot->x < 0 && user_dot->y < 0)
        return 3;
    else if (user_dot->x > 0 && user_dot->y < 0)
        return 4;
    else
        return 0;
}

int main()
{
    struct dot user_dot;
    scanf("%d %d", &user_dot.x, &user_dot.y);
    printf("%d четверть!", chetvert(&user_dot));

    return 0;
}