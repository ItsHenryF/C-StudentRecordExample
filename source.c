#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declare Global Variables
int addStudentPos = 0;
int i = 0;



// Struct that Holds Student Record Data 
struct studentRecord {
    int StudentID;
    float GPA;
    char phoneNumber[20];
    char name[20];
};

void printStudentRecordMenu(){
    printf("------------------------------------------------------\n");
    printf("Enter 1 to Print all Student Records\n");
    printf("Enter 2 to Add a Student Record\n");
    printf("Enter 3 to Modify a student Record\n");
    printf("Enter 4 to Exit Program\n");
    printf("------------------------------------------------------\n");
}


int main(){

    // Declare Local Variables
    int userChoice;
    int studentIDLookUp;

    struct studentRecord studentList[10]; // variable called studentList that holds 10 student record objects
    struct studentRecord student; // Variable called student that gets re-used for each student record and then added to studentList

    // Prints Menu to User to Select an Option
    printStudentRecordMenu();
    // User Input
    scanf("%d", &userChoice);

    // Switch Statement to Handle User Input
    while(1){ 
        switch (userChoice)
        {
        // Print Student Records
        case 1:
            // Iterivly goes through list to print all studentRecord items in list
            i = 0;
            for (size_t i = 0; i< addStudentPos; i++)
            {
                printf("Student Number: %d", i+1);
                printf("\nStudent ID: %d\n", studentList[i].StudentID);
                printf("Name: %s\n", studentList[i].name);
                printf("GPA: %f\n", studentList[i].GPA);
                printf("Phone Number: %s\n", studentList[i].phoneNumber);
                printf("\n");
            }
            
            // get user Input again 
            printStudentRecordMenu();
            scanf("%d", &userChoice);
            break;
        // Add Student Record
        case 2:
            // Ask user for Student Information
            printf("Enter Student ID: ");
            scanf("%d", &student.StudentID);
            printf("Enter Student GPA: ");
            scanf("%f", &student.GPA);
            printf("Enter Student Phone Number: ");
            scanf("%s", &student.phoneNumber);
            printf("Enter Student Name: ");
            scanf("%s", &student.name);

            // Add Student Record to List
            studentList[addStudentPos] = student;
            addStudentPos++;
            // get user Input again 
            printStudentRecordMenu();
            scanf("%d", &userChoice);
            break;
        // Modify Student Record
        case 3:
            // Ask user for Student ID to Modify
            printf("Enter Student ID To Look Up: ");
            scanf("%d", &studentIDLookUp);
            // Search for Matching Student ID
            for (size_t i = 0; i< addStudentPos; i++)
            {
                // If a match is found ask user to update student information
                if (studentIDLookUp == studentList[i].StudentID)
                {
                    printf("Enter Student ID: ");
                    scanf("%d", &student.StudentID);
                    printf("Enter Student GPA: ");
                    scanf("%f", &student.GPA);
                    printf("Enter Student Phone Number: ");
                    scanf("%s", &student.phoneNumber);
                    printf("Enter Student Name: ");
                    scanf("%s", &student.name);
                    studentList[i] = student;
                }
            }
            // get user Input again 
            printStudentRecordMenu();
            scanf("%d", &userChoice);
            break;
        // Exit Program
        case 4: 
            printf("Exiting Program");
            return 0;
            break;
        
        default:
            printf("Invalid Input\n");
            scanf("%d", &userChoice);
            
            break;
        }
    }


    return 0;
}