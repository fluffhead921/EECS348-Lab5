#include <stdio.h>
#include <stdlib.h>

//accept 20 characters max per line
#define MAX_CHARS 20

int main() {
    FILE* filePointer;
    char buf[MAX_CHARS];
    char sales[12][MAX_CHARS];
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    filePointer = fopen("input.txt", "r");
    
    //write 12 numbers to sales
    for (int i=0; i<12; i++) {
        fgets(buf, MAX_CHARS, filePointer);
        for (int j=0; j<20; j++) {
            sales[i][j] = buf[j];
        }
    }

    printf("Monthly sales report:\n");
    for (int i=0; i<12; i++) {
        printf("%s:\t%s", months[i], sales[i]);
    }

    fclose(filePointer);

    return 0;
}