#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
union MyUnion {
        struct {
            char active_bool[6];
        } innerStruct1;
        struct {
            int active_int;
        } innerStruct2;
};

struct User
{
    char username[50];
    char password[50];
    union MyUnion data;

};


// Define an array to store user data
struct User users[1000];
int userCount = 0;

// Function to register a new user
void registerUser()
{
    if (userCount >= 100)
    {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }

    struct User newUser;
    

    printf("Enter username: ");
    scanf("%s", newUser.username);

    // Check if the username is already taken
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(newUser.username, users[i].username) == 0)
        {
            printf("Username already exists. Please choose another username.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", newUser.password);

    printf("Enter Active-Status: ");
    scanf( "%s" ,  &newUser.data.innerStruct1.active_bool);
    if (sscanf(newUser.data.innerStruct1.active_bool, "%d", &newUser.data.innerStruct2.active_int) == 1) {
        printf("You entered an integer: %d\n", newUser.data.innerStruct2.active_int);
    } else {
        printf("You entered a string: %s\n", newUser.data.innerStruct1.active_bool);
    }
    printf("nnnnn");

    users[userCount] = newUser;
    userCount++;

    printf("Registration successful. You can now log in.\n");
}

// Function to perform user login
int loginUser()
{
    char username[50];
    char password[50];
    
    struct User user;
    

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0 )
        if(users[i].data.innerStruct2.active_int==1||users[i].data.innerStruct1.active_bool=="true"){
            {
            printf("Login successful. Welcome, %s!\n", username);
            return 1; // Return 1 to indicate a successful login
            }
        }
        
    }

    printf("Login failed. Invalid username or password.\n");
    return 0; // Return 0 to indicate a failed login
}

int main(void)
{
    int choice;

    do
    {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser())
            {
                // If login is successful, you can perform additional actions for the logged-in user here.
            }
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
