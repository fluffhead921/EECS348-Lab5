#include <stdio.h>
#include <stdlib.h>

//accept 20 characters max per line
#define MAX_CHARS 20

int main() {
    FILE* filePointer;
    char sales[MAX_CHARS];

    filePointer = fopen("input.txt", "r");
    
    //write 12 numbers to sales
    for (int i = 0; i < 12; i++) {
        fgets(sales, MAX_CHARS, filePointer);
        printf("%s", sales, "\n"); 
    }

    return 0;
}