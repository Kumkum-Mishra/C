#include<stdio.h>

// Define a structure with a tag name `student`
struct student {
    char* name;
    int id;
};

int main()
{
    // Declare variables of type `struct student`
    struct student std1, std2;
    
    // Initialize the student data
    std1.name = "Kumkum Mishra";
    std2.name = "Sahil Mishra";
    std1.id = 2023340804;
    std2.id = 2023340803;
    
    // Print the student data
    printf("%s\n", std1.name);
    printf("%s\n", std2.name);
    printf("%d\n", std1.id);
    printf("%d", std2.id);
    
    return 0;
}
