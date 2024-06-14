#include <stdio.h>
#include <stdlib.h>

int score;
int points[] = {8, 7, 6, 3, 2};
char *name[] = {"TD + 2pt", "TD + 1pt", "TD", "FG", "Safety"};
int count[] = {0, 0, 0, 0, 0};

void generateCounts(int tempScore1, int index) {
    //do not accept indices not in arrays
    if (index > 4) {
        return;
    }
    //calculate the maximum count of the point value of the current index
    int maxCountI = tempScore1 / points[index];
    if (tempScore1 % points[index] == 1) { //no point value 1 exists so 3 must be used
        maxCountI--;
        if (index == 4) {
            count[3]++;
        }
    }
    int tempScore2;
    //find counts for combinations up to maximum
    for (int i = 0; i <= maxCountI; i++) {
        tempScore2 = tempScore1;
        tempScore2 -= i * points[index];
        count[index] = i;
        //find counts for next index with the remaining score
        generateCounts(tempScore2, (index + 1));
    }
    //find current total score from counts
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += count[i] * points[i];
    }
    //ensures only valid combinations are printed
    if (total == score && index == 4 && tempScore2 == 0) {
        for (int i = 0; i < 4; i++) {
            printf("%d %s, ", count[i], name[i]);
        }
        printf("%d %s\n", count[4], name[4]);
    }
}

int main() {
    while (1) {
        //get score input
        printf("Enter 0 or 1 to stop\nEnter NFL score: ");
        scanf("%d", &score);

        //break from loop if invalid score
        if (score < 2) {
            break;
        }
        
        //print combinations
        generateCounts(score, 0);
        printf("\n");
    }
}