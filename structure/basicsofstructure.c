#include<stdio.h>
int main()
{
    struct pokemon{
     int hp;
     int speed;
     int attack;
     char tier;
    };
    struct pokemon pikachu;
    pikachu.hp=60;
    pikachu.speed=80;
    pikachu.attack=100;
    pikachu.tier='A';

    struct pokemon charizard;
    charizard.hp=50;
    charizard.speed=80;
    charizard.attack=130;
    charizard.tier='S';

    struct pokemon mewtwo;
    mewtwo.hp=150;
    mewtwo.speed=170;
    mewtwo.attack=180;
    mewtwo.tier='G';
    
    printf("%d\n",pikachu.speed);
    printf("%c\n",mewtwo.tier);
    printf("%d",charizard.attack);

    return 0; 
}