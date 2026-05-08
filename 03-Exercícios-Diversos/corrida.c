#include <stdio.h>

int main() {

    int road;

    printf("Road: \n");
    scanf("%d", &road);

    if (road == 1) {
        printf("Road: \n");
        scanf("%d", &road);

        if (road == 4) {
            printf("Road: \n");
            scanf("%d", &road);

            if (road == 6) {
                printf("Road successful, the destination was reached \n");
            }
            else {
                printf("Road invalid \n");
            }
        }
        else {
            printf("Road Invalid \n");
        }
    }

    else if (Road == 2) {
        printf("Road successful, the destination was not reached \n");
    }

    else if (Road == 3) {
        printf("Road: \n");
        scanf("%d", &road);

        if (road == 5) {
            printf("Road: \n")
            scanf("%d", &road);

            if (road == 7) {
                printf("Road: \n");
                scanf("%d", &road);

                if(road == 8) {
                    printf("Road successful, the destination was reached \n");
                }
                else {
                    printf("Road invalid \n");
                }
            }
            else {
                printf("Road invalid \n");
            }
        }
        else {
            printf("Road invalid \n");
        }
    }
    else {
        printf("Road invalid \n");
    }

    return 0;
}