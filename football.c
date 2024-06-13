#include <stdio.h>
#include <stdlib.h>

int main() {
    int score;
    int points[] = {8, 7, 6, 3, 2};
    char *name[] = {"TD + 2pt", "TD + 1pt", "TD", "FG", "Safety"};
    int count[5];

    printf("Enter 0 or 1 to stop\nEnter NFL score: ");
    scanf("%d", &score);
    
    int tempScore = score;
    for (int j=0; j<5; j++) {
        count[j] = 0;
        while ((tempScore - points[j] > 1) || (tempScore == points[j])) { //no point value of 1 exists
            tempScore -= points[j];
            count[j]++;
        }
        printf("%d %s, ", count[j], name[j]);
    }
    printf("\n");
}