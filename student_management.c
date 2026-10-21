
#include <stdio.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks[3];
    float average;
};

int main(void) {
    struct Student students[MAX];
    int n, i, j, topper = 0;

    printf("Enter number of students (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of students.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter roll number: ");
        scanf("%d", &students[i].roll);

        printf("Enter name (one word): ");
        scanf("%49s", students[i].name);

        students[i].average = 0;

        for (j = 0; j < 3; j++) {
            printf("Enter marks for subject %d: ", j + 1);

            if (scanf("%f", &students[i].marks[j]) != 1 ||
                students[i].marks[j] < 0 ||
                students[i].marks[j] > 100) {
                printf("Invalid marks.\n");
                return 1;
            }

            students[i].average += students[i].marks[j];
        }

        students[i].average /= 3;

        if (students[i].average >
            students[topper].average) {
            topper = i;
        }
    }

    printf("\n--- Student Records ---\n");

    for (i = 0; i < n; i++) {
        printf("Roll: %d | Name: %s | Average: %.2f\n",
               students[i].roll,
               students[i].name,
               students[i].average);
    }

    printf("\nTopper: %s (%.2f%%)\n",
           students[topper].name,
           students[topper].average);

    return 0;
}
