#include <stdio.h>
#include <stdlib.h>

//accept 20 characters max per line
#define MAX_CHARS 20

int main() {
    FILE* filePointer;
    char buf[MAX_CHARS];
    float sales[12];
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    filePointer = fopen("input.txt", "r");
    
    //write 12 numbers to sales
    for (int i=0; i<12; i++) {
        fgets(buf, MAX_CHARS, filePointer);
        sales[i] = atof(buf);
    }

    printf("Monthly sales report:\n");
    for (int i=0; i<12; i++) {
        if (strlen(months[i]) < 7) {
            printf("%s:\t\t%.2f\n", months[i], sales[i]);
        }
        else {
            printf("%s:\t%.2f\n", months[i], sales[i]);
        }
    }

    fclose(filePointer);

    return 0;
}