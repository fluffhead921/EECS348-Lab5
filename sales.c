#include <stdio.h>
#include <stdlib.h>

//accept 20 characters max per line
#define MAX_CHARS 20

int main() {
    FILE* filePointer;
    char buf[MAX_CHARS];
    float sales[12];
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float total = 0;
    float salesSorted[12];
    char *monthsSorted[12];

    filePointer = fopen("input.txt", "r");
    
    //write 12 numbers to sales, find total, initialize sorted arrays
    for (int i=0; i<12; i++) {
        fgets(buf, MAX_CHARS, filePointer);
        sales[i] = atof(buf);
        total += sales[i];
        salesSorted[i] = sales [i];
        monthsSorted[i] = months[i];
    }

    //chronological sales
    printf("Monthly sales report:\n");
    for (int i=0; i<12; i++) {
        if (strlen(months[i]) < 7) {
            printf("%s:\t\t$%.2f\n", months[i], sales[i]);
        }
        else {
            printf("%s:\t$%.2f\n", months[i], sales[i]);
        }
    }
    printf("\n");

    //sort
    for (int i=0; i<12; i++) {
        int iMax = i;
        for (int j=i+1; j<12; j++) {
            if (salesSorted[j] > salesSorted[iMax]) {
                iMax = j;
            }
        }
        if (iMax != i) {
            float tempSale = salesSorted[i];
            char *tempMonth = monthsSorted[i];
            salesSorted[i] = salesSorted[iMax];
            monthsSorted[i] = monthsSorted[iMax];
            salesSorted[iMax] = tempSale;
            monthsSorted[iMax] = tempMonth;
        }
    }

    //summary
    printf("Sales summary:\n");
    printf("Minimum sales:\t$%.2f\t(%s)\n", salesSorted[0], monthsSorted[0]);
    printf("Maximum sales:\t$%.2f\t(%s)\n", salesSorted[11], monthsSorted[11]);
    printf("Average sales:\t$%.2f\n\n", total / 12);

    //moving average

    //descending sales
    printf("Sales Report (Highest to Lowest):\n");
    for (int i=0; i<12; i++) {
        if (strlen(monthsSorted[i]) < 7) {
            printf("%s:\t\t$%.2f\n", monthsSorted[i], salesSorted[i]);
        }
        else {
            printf("%s:\t$%.2f\n", monthsSorted[i], salesSorted[i]);
        }
    }
    printf("\n");

    fclose(filePointer);

    return 0;
}