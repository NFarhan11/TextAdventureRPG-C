#include <stdio.h>

// Horizontal line
void printSeparator()
{
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

int main()
{
    char name[20];

    printSeparator();
    printf("Welcome to the Garrison Frontier.\n");
    printf("A battle frontier for the adventurer to explore the dungeon.\n");
    printf("You are one of the adventurers that yearn to explore the infamous dungeon.\n");
    printSeparator();

    printf("Enter your Name: ");
    scanf("%s", name);

    printf("\nBe prepared %s for what's to come! The dungeon is said to be filled with treacherous traps, fearsome monsters, and untold treasures.\n", name);
    printf("Many have entered, but few have returned. Legends speak of a powerful artifact hidden deep within the dungeon.\n");
    printf("It is said that whoever possesses it will gain unimaginable power.\n");
    printSeparator();
    printf("The path ahead is perilous, but your courage and determination will guide you.\n");
    printf("Remember, %s, fortune favors the bold. Before you enter, make sure you are well-equipped with weapons, armor, and potions.\n", name);
    printf("The dungeon does not forgive the unprepared. The gates of the dungeon creak open, revealing a dark and ominous passage. Take a deep breath, %s, and step forward into the unknown.\n", name);
    printf("May the spirits of the brave adventurers who came before you watch over your journey.\n");
    printf("Good luck, %s, and may you emerge victorious!\n", name);

    printSeparator();
    printf("Bye!\n");

    return 0;
}