#include <stdio.h>

void HanoiTower(int num, char from, char by, char to)
{
    if(num==1)
    {
        printf("����1�� %c���� %c�� �̵� \n",from,to);
    }
    else
    {
        HanoiTower(num-1,from,to,by);
        printf("����%d�� %c���� %c�� �̵� \n",num,from,to);
        HanoiTower(num-1,by,from,to);
    }
}

int main(void)
{
    HanoiTower(3,'A','B','C');
    return 0;
}