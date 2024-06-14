#include <stdio.h>
#include <stdlib.h>

int score;
int points[] = {8, 7, 6, 3, 2};
char *name[] = {"TD + 2pt", "TD + 1pt", "TD", "FG", "Safety"};
int count[] = {0, 0, 0, 0, 0};

void generateCounts(int tempScore1, int index) {
    if (index > 4) {
        return;
    }
    int maxCountI = tempScore1 / points[index];
    if (tempScore1 % points[index] == 1) {
        maxCountI--;
        if (index == 4) {
            count[3]++;
        }
    }
    int tempScore2;
    for (int j = 0; j <= maxCountI; j++) {
        tempScore2 = tempScore1;
        tempScore2 -= j * points[index];
        count[index] = j;
        generateCounts(tempScore2, (index + 1));
    }
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += count[i] * points[i];
    }
    if (total == score && index == 4 && tempScore2 == 0) {
        for (int i = 0; i < 4; i++) {
            printf("%d %s, ", count[i], name[i]);
        }
        printf("%d %s\n", count[4], name[4]);
    }
}

int main() {
    printf("Enter 0 or 1 to stop\nEnter NFL score: ");
    scanf("%d", &score);
    
    generateCounts(score, 0);
}