#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randomNumber(int die)
{
    srand(time(NULL));
    return rand() % die +1;
}
int main(void)
{
    printf("Enter dice to roll by saying \"d{Dice to roll}\": ");
    int die;
    scanf("d%d",&die);
    int result = randomNumber(die);
    printf("%d\n",result);
    return 0;
}