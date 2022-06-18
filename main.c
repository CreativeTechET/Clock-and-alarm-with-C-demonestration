#include "main.h"
#include <term.h>


int main()
{
    int min, hour, sec, index,cl;
    char tmp;
    hour = 0;
    sec = 0;
    min = 0;

    fclear();
    printf("===============DO YOU WANT TO START A CLOCK TIMER==============\n\n--> y / Y (yes)\n--> n / N (No)\n");
    choice:
    switch (index){
        case 0:
            printf("\n\n");
            scanf("%c", &tmp);
            if (tmp == 'y' || tmp == 'Y') {
                index = 1;
            }
            else if (tmp == 'n' || tmp == 'N') {
                return 0;
            }
            else {
                printf("Please select a valid choice (y or n) yes to start and no to quit\n");
                goto choice;
            }
        getcl:
        case 1:
            fclear();
            printf(" 1. Start clock from initial 00/00/00\n");
            printf(" 2. Enter prefered time to start\n");
            scanf("%d", &cl);
            if (cl == 1) {
                goto clocker;
            }
            else if (cl == 2) {
                ti:
                printf(" Enter Hour, Time & Secound like ( 2 10 0 )\n");
                scanf("%02d %02d %02d", &hour, &min, &sec);
                if (hour > 24 || min > 60 || sec > 60)
                {
                    fclear();
                    printf("please enter a valid time\n\n");
                    sleep(2);
                    goto ti;
                }
                goto clocker;
            }
            else {
                printf("\nplease enter a valid number (1 or 2)\n\n");
                sleep(3);
                goto getcl;
            }
        
        default:
            index = 0;
            break;
    }
            clocker:
            /* One-time initialization near the beginning of your program */
            setupterm(NULL, STDOUT_FILENO, NULL);

            /* Enter bold mode */
            putp(enter_bold_mode);

            printf("I am bold\n");

            /* Turn it off! */
            putp(exit_attribute_mode);
            while (1)
            {
                
                if (hour < 24)
                {
                    if (min < 60)
                    {
                        if (sec < 60)
                        {
                            sec++;
                            sleep(1);
                            system("clear");
                            printf("%02d:%02d:%02d\n", hour, min, sec);
                        }
                        else
                        {
                            sec = 0;
                            min++;
                        }
                        if (min == 60)
                        {
                            min = 0;
                            hour++;
                        }
                    }
                }
                else
                {
                    hour = 01;
                }
    }
}
void fclear(void) {
    system("clear");
    fheader();
}
void fheader(void) {
    printf(" *********************** CLOCK TIMER IN C ***********************\n\n");
}

