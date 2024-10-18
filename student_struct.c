#include <stdio.h>
#include <string.h>

struct class
{
    char name[50];
    int age;
    int marks;
};

int main()
{
    int p, sum = 0, temp = 0, counter = 0;
    int avg,str;
    int sep[5];
    FILE *ptr;
    ptr = fopen("student_data.txt", "a");

    printf("Enter 1 to search//Enter 2 to input data\n");
    scanf("%d", &str);
    getchar();

    struct class student[10];
    if (str == 2)
    {

        if (ptr == NULL)
        {
            printf("ERROR OCURRED");
        }

        for (int i = 0; i < 10; i++)
        {

            printf("Enter name of %dst student: ", i + 1);
            fgets(student[i].name, sizeof(student[i].name), stdin);
            student[i].name[strcspn(student[i].name, "\n")] = 0;
            printf("Enter age of student %d: ", i + 1);
            scanf("%d", &student[i].age);
            printf("Enter marks of student %d: ", i + 1);
            scanf("%d", &student[i].marks);
            printf("\n");

            getchar();
            fprintf(ptr, "%s %d %d\n", student[i].name, student[i].age, student[i].marks);
        }
        fclose(ptr);
    }

    ptr = fopen("student_data.txt", "r");
    for (int i = 0; i < 10; i++)
    {

        fscanf(ptr, "%s %d %d\n", student[i].name, &student[i].age, &student[i].marks);
    }

    for (int i = 0; i < 10; i++)
    {
        sum = sum + student[i].marks;
    }

    avg = sum / 10;

    for (int i = 0; i < 10; i++)
    {
        sep[i] = student[i].marks;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sep[i] < sep[i + 1])
            {

                temp = sep[i + 1];
                sep[i + 1] = sep[i];
                sep[i] = temp;
            }
        }
    }

    printf("Highest marks: %d\n", sep[0]);
    printf("The Average Marks is: %d\n", avg);
    while (1)
    {

        printf("Enter student number: ");
        scanf("%d", &p);

        getchar();
        printf("Name: %s\n", student[p - 1].name);
        printf("AGe: %d\n", student[p - 1].age);
        printf("Marks: %d\n", student[p - 1].marks);
        if (student[p].marks >= avg)
        {
            printf("Pass\n");
        }
        else
        {
            printf("FAIL\n");
        }

        printf("Enter 1 to search // Enter 000 to exit\n");
        scanf("%d", &counter);
        if (counter == 0)
        {
            return 0;
        }
    }
    fclose(ptr);

    return 0;
}