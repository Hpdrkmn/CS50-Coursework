#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // start up and asking for name
    printf("New user detected... \n");
    printf("Booting System Diagnostics \n");
    string answer = get_string("You are a new user, what's your name? \n");
    printf("Greetings, %s\n", answer);
    printf("You've been in cryosleep for 745 standard earth years \n");
    printf("Hello mom! \n");
}

