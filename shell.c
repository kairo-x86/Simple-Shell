#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char input[100];
    char arg[100];
    char cmd[20];
    char user[15];
    int space;
    int j = 0;
    int i = 0;

    system("clear");

    printf("Enter user: ");
    
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = '\0';

    while (1) {
        printf("%s@mysh: ", user);

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "quit") == 0) {
            break;
        } else {

            space = strcspn(input, " ");

            for (i = 0; i < space; i++) {
                cmd[i] = input[i];
            }

            cmd[i] = '\0';

            j = 0;

            for (i = space + 1; input[i] != '\0'; i++) {
                arg[j] = input[i];
                j++;
            }

            arg[j] = '\0';

            if (strcmp(cmd, "echo") == 0) {
                printf("%s\n", arg);

            } else if (strcmp(cmd, "clear") == 0) {
                system("clear");

            } else {
                printf("ERROR: Incorrect command.\n");
            }
        }
    }

    return 0;
}