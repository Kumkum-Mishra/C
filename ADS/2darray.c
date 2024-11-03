#include <stdio.h>

int main() {
    int stud_rollno, stud_marks;

    printf("Enter the number of students: ");
    scanf("%d", &stud_rollno);
    printf("Enter the number of subjects per student: ");
    scanf("%d", &stud_marks);

    int arr[stud_rollno][stud_marks];

    for (int i = 0; i < stud_rollno; i++) {
        printf("Enter roll number for student %d: ", i + 1);
        scanf("%d", &arr[i][0]);
        for (int j = 1; j <= stud_marks; j++) {
            printf("Enter marks of subject %d for student with roll number %d: ", j, arr[i][0]);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nEntered data:\n");
    for (int i = 0; i < stud_rollno; i++) {
        printf("Roll No: %d, Marks: ", arr[i][0]);
        for (int j = 1; j < stud_marks; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
