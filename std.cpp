#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct Student {
    int id;
    char name[50];
    int age;
};
struct Student students[MAX];
int count = 0;
void addStudent();
void deleteStudent();
void updateStudent();
void displayStudents();

int main() {
    int choice;
    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: displayStudents(); break;
            case 5: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
void addStudent() {
    if (count >= MAX) {
        printf("Cannot add more students.\n");
        return;
    }
    printf("Enter Student ID: ");
    scanf("%d", &students[count].id);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter Age: ");
    scanf("%d", &students[count].age);
    count++;
    printf("Student added successfully.\n");
}
void deleteStudent() {
    int id, i, found = 0;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void updateStudent() {
    int id, i, found = 0;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Student updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
    }
}
