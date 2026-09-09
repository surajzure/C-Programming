/*
Name:suraj zure

Date:

Description:
Implement an student record which will contain roll no., Name of student, subject marks, average and grade.
Read number of students and declare array of structure with no.of students, then read number of subjects and n subject names.
Read the particulars for each student.
Roll.no
Name.
Score of each subject
Calculate the average. Based on that decide the grade.

Sample execution:
Enter no.of students : 2
Enter no.of subjects : 2
Enter the name of subject 1 : Maths
Enter the name of subject 2 : Science
----------Enter the student datails-------------
Enter the student Roll no. : 1
Enter the student 1 name : Nandhu
Enter Maths mark : 99
Enter Science mark : 91
----------Enter the student datails-------------
Enter the student Roll no. : 2
Enter the student 2 name : Bindhu
Enter Maths mark : 88
Enter Science mark : 78
----Display Menu----
1. All student details
2. Particular student details
Enter your choice : 2

----Menu for Particular student----
1. Name.
2. Roll no.
Enter you choice : 1
Enter the name of the student : Nandhu
Roll No.   Name           Maths         Science       Average       Grade
1              Nandhu        99               91                95                  A
Do you want to continue to display(Y/y) : n*/
#include <stdio.h>
#include <string.h>

// Structure to store student details
struct Student
{
    int roll;            // Roll number
    char name[50];       // Student name
    float marks[10];     // Marks for subjects
    float avg;           // Average marks
    char grade;          // Grade
};

int main()
{
    int n, sub;

    // Input number of students
    printf("Enter no.of students : ");
    scanf("%d", &n);

    // Input number of subjects
    printf("Enter no.of subjects : ");
    scanf("%d", &sub);

    struct Student s[n];        // Array of structures
    char subjects[10][20];      // Subject names

    // Input subject names
    for(int i = 0; i < sub; i++)
    {
        printf("Enter the name of subject %d : ", i + 1);
        scanf("%s", subjects[i]);
    }

    // Input student details
    for(int i = 0; i < n; i++)
    {
        printf("----------Enter the student datails-------------\n");

        printf("Enter the student Roll no. : ");
        scanf("%d", &s[i].roll);

        printf("Enter the student %d name : ", i + 1);
        scanf("%s", s[i].name);

        float sum = 0;   // Initialize sum for each student

        // Input marks
        for(int j = 0; j < sub; j++)
        {
            printf("Enter %s mark : ", subjects[j]);
            scanf("%f", &s[i].marks[j]);

            sum += s[i].marks[j];   // Add marks
        }

        // Calculate average
        s[i].avg = sum / sub;

        // Assign grade
        if(s[i].avg >= 90)
            s[i].grade = 'A';
        else if(s[i].avg >= 75)
            s[i].grade = 'B';
        else if(s[i].avg >= 50)
            s[i].grade = 'C';
        else
            s[i].grade = 'D';
    }

    char ch;   // For continue option

    // Menu loop
    do
    {
        int choice;

        printf("\n----Display Menu----\n");
        printf("1. All student details\n");
        printf("2. Particular student details\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            // Display all students
            printf("Roll No.\tName\t");

            // Print subject names
            for(int j = 0; j < sub; j++)
                printf("%s\t", subjects[j]);

            printf("Average\tGrade\n");

            for(int i = 0; i < n; i++)
            {
                printf("%d\t\t%s\t", s[i].roll, s[i].name);

                // Print marks
                for(int j = 0; j < sub; j++)
                    printf("%.0f\t", s[i].marks[j]);

                printf("%.0f\t%c\n", s[i].avg, s[i].grade);
            }
        }
        else if(choice == 2)
        {
            int sub_choice;

            printf("\n----Menu for Particular student----\n");
            printf("1. Name\n");
            printf("2. Roll no\n");
            printf("Enter your choice : ");
            scanf("%d", &sub_choice);

            if(sub_choice == 1)
            {
                char search[50];

                printf("Enter the name of the student : ");
                scanf("%s", search);

                int found = 0;

                for(int i = 0; i < n; i++)
                {
                    if(strcmp(s[i].name, search) == 0)
                    {
                        found = 1;

                        printf("Roll No.\tName\t");

                        for(int j = 0; j < sub; j++)
                            printf("%s\t", subjects[j]);

                        printf("Average\tGrade\n");

                        printf("%d\t\t%s\t", s[i].roll, s[i].name);

                        for(int j = 0; j < sub; j++)
                            printf("%.0f\t", s[i].marks[j]);

                        printf("%.0f\t%c\n", s[i].avg, s[i].grade);
                    }
                }

                if(!found)
                    printf("Student not found\n");
            }
            else if(sub_choice == 2)
            {
                int roll_search;

                printf("Enter the roll no of the student : ");
                scanf("%d", &roll_search);

                int found = 0;

                for(int i = 0; i < n; i++)
                {
                    if(s[i].roll == roll_search)
                    {
                        found = 1;

                        printf("Roll No.\tName\t");

                        for(int j = 0; j < sub; j++)
                            printf("%s\t", subjects[j]);

                        printf("Average\tGrade\n");

                        printf("%d\t\t%s\t", s[i].roll, s[i].name);

                        for(int j = 0; j < sub; j++)
                            printf("%.0f\t", s[i].marks[j]);

                        printf("%.0f\t%c\n", s[i].avg, s[i].grade);
                    }
                }

                if(!found)
                    printf("Student not found\n");
            }
            else
            {
                printf("Invalid choice\n");
            }
        }
        else
        {
            printf("Invalid choice\n");
        }

        // Continue option
        printf("Do you want to continue to display(Y/y) : ");
        scanf(" %c", &ch);

    } while(ch == 'Y' || ch == 'y');

    return 0;
}