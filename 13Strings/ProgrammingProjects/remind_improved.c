#include <stdio.h>
#include <string.h>

#define MAX_REMIND  50 /* maximum number of reminders */
#define MSG_LEN     60 /* max length of reminder message */
#define MAX_MONTH_LEN   9
int read_line(char str[], int n);

int main(void) {
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[6], msg_str[MSG_LEN + 1], time_str[7];
    int day, month, i, j, num_remind = 0;
    int minute, hour;

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("-- No space left -- \n");
            break;
        }

        printf("Enter month/day, 24 hour-time and your reminder: ");



        scanf("%2d/ %2d", &month, &day);
        
        if (month == 0 || day == 0)
            break;

        if (month < 0 || month > 12 || day < 0 || day > 31)
        {
            printf("Please enter a correct date!\n");

            // Clear the input buffer
            while (getchar() != '\n')
                ;
            continue;
        }

        scanf("%2d: %2d", &hour, &minute);

        sprintf(day_str, "%2.2d/%2.2d", month, day);
        sprintf(time_str, "%2.2d:%2.2d", hour, minute);

        read_line(msg_str, MSG_LEN);

        // Sort by day and time
        for (i = 0; i < num_remind; i++)
        {
            if (strncmp(day_str, reminders[i], 5) < 0 ||
                (strncmp(day_str, reminders[i], 5) == 0 &&
                 strncmp(time_str, reminders[i] + 6, 5) < 0))
            {
                break;
            }
        }

        // Shift reminders to make space for the new one
        for (j = num_remind; j > i; j--) 
        {
            strcpy(reminders[j], reminders[j - 1]);
        }

        // Insert the new reminder
        sprintf(reminders[i], "%s %s %s", day_str, time_str, msg_str);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf("%s\n", reminders[i]);

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {
        if (i < n)
            str[i++] = ch;
    }

    str[i] = '\0'; /* null terminate the string */
    return i;
}
