#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 25
#define MAX_FILE_NAME_LENGTH 10
#define MAX_DOB_LENGTH 10

int tries = 0;

void add_null(char *str)
{
    size_t length = strlen(str);
    if (str[length - 1] == '\n')
    {
        str[length - 1] = '\0';
    }
}

void to_lowercase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

int check_password(const char *password_file_name, const char *input_password)
{
    char stored_password[MAX_PASSWORD_LENGTH];
    FILE *password_file = fopen(password_file_name, "r");

    if (password_file == NULL)
    {
        printf("Error opening password file: %s\n", password_file_name);
        return 0;
    }

    fgets(stored_password, sizeof(stored_password), password_file);
    add_null(stored_password);
    fclose(password_file);

    return strcmp(stored_password, input_password) == 0;
}
//the code from here on out is going to be very complex so get ready
int contains_dob_digits(const char *password, const char *dob)
{
    char dob_digits[9] = "";
    int j = 0;
    int passlen = strlen(password);

    for (int i = 0; dob[i] != '\0'; i++)
    {
        if (isdigit(dob[i]))
        {
            dob_digits[j++] = dob[i];
        }
    } 
    dob_digits[j] = '\0';

    for (int i = 0; i < passlen; i++)
    {
        int count = 0;
        for (int j = 0; j < 8; j++)
        {
            if (((i + count) < passlen) && (password[i + count] == dob_digits[j]))
            {
                count++;
            }
            else
            {
                if (count > 3)
                    return count;
                count = 0;
            }
        }
    }

    return 0;
}

void print_error()
{
    if (tries == 1)
    {
        printf("First attempt failed.\n");
    }
    else if (tries == 2)
    {
        printf("Second attempt failed.\n");
    }
    else if (tries == 3)
    {
        printf("Third attempt failed.\n");
    }
    else if (tries == 4)
    {
        printf("Fourth attempt failed.\n");
    }
}

void timer(int sec)
{
    for (int i = sec; i > 0; i--)
    {
        printf("Wait for %d seconds\n", i);
        sleep(1);
    }
}

int count_conc_char(const char *newPassword, const char *oldPassword)
{
    int newLen = strlen(newPassword);
    int oldLen = strlen(oldPassword);

    for (int i = 0; i < newLen; i++)
    {
        int count = 0;
        for (int j = 0; j < oldLen; j++)
        {
            if (((i + count) < newLen) && (newPassword[i + count] == oldPassword[j]))
            {
                count++;
            }
            else
            {
                if (count > 4)
                    return count;
                count = 0;
            }
        }
    }

    return 0;
}

int contains_pass_digits(const char *password, const char *passfile)
{
    FILE *password_file = fopen(passfile, "r");

    if (password_file == NULL)
    {
        printf("Error opening password file for writing: %s\n", passfile);
        return 1;
    }

    char oldpass[MAX_PASSWORD_LENGTH];
    char lower_pass[MAX_PASSWORD_LENGTH];
    strcpy(lower_pass, password);
    to_lowercase(lower_pass);

    while (fgets(oldpass, sizeof(oldpass), password_file))
    {
        to_lowercase(oldpass);
        int concChar = count_conc_char(lower_pass, oldpass);
        if (concChar)
            return concChar;
    }

    return 0;
}

int verify_password(const char *password, const char *password_file_name, const char *name, const char *surname, const char *dob)
{
    int r2 = 0, r3 = 0, r4 = 0, r5 = 0, r5_1 = 0;
    const char *allowed_special = ".,@!#$%^&*-_";
    char password_lower[MAX_PASSWORD_LENGTH];
    strcpy(password_lower, password);
    to_lowercase(password_lower);

    char name_lower[MAX_USERNAME_LENGTH], surname_lower[MAX_USERNAME_LENGTH];
    strcpy(name_lower, name);
    strcpy(surname_lower, surname);
    to_lowercase(name_lower);
    to_lowercase(surname_lower);
    int failed = 0;

    if (strlen(password) < 12)
    {
        print_error();
        failed = 1;
        printf("Password does not contain a minimum of 12 characters.\n");
    }

    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
            r2 = 1;
        else if (islower(password[i]))
            r3 = 1;
        else if (isdigit(password[i]))
            r4 = 1;
        else if (strchr(allowed_special, password[i]))
            r5 = 1;
        else
        {
            r5_1 = 1;
            return 0;
        }
    }

    if (failed == 0 && (r2 == 0 || r3 == 0 || r4 == 0 || r5 == 0 || r5_1 == 1))
    {
        print_error();
        failed = 1;
    }

    if (r2 == 0)
        printf("Password does not contain at least one uppercase letter.\n");
    if (r3 == 0)
        printf("Password does not contain at least one lowercase letter.\n");
    if (r4 == 0)
        printf("Password does not contain at least one digit.\n");
    if (r5 == 0)
        printf("Password does not contain at least one of the allowed special characters.\n");
    if (r5_1 == 1)
        printf("Password contains invalid character.\n");

    int samePassword = contains_pass_digits(password, password_file_name);

    if (samePassword > 0)
    {
        if (failed == 0)
        {
            failed = 1;
            print_error();
        }
        printf("Password contains %d characters consecutively similar to one of the past 10 passwords.\n", samePassword);
    }

    if (strstr(password_lower, name_lower) && strstr(password_lower, surname_lower))
    {
        if (failed == 0)
        {
            failed = 1;
            print_error();
        }
        printf("Password contains name and surname portions of username.\n");
    }
    else if (strstr(password_lower, surname_lower))
    {
        if (failed == 0)
        {
            failed = 1;
            print_error();
        }
        printf("Password contains surname portion of username.\n");
    }
    else if (strstr(password_lower, name_lower))
    {
        if (failed == 0)
        {
            failed = 1;
            print_error();
        }
        printf("Password contains name portion of username.\n");
    }

    int sameDOB = contains_dob_digits(password, dob);

    if (sameDOB > 0)
    {
        if (failed == 0)
        {
            failed = 1;
            print_error();
        }
        printf("Password contains %d digits consecutively similar to the date of birth.\n", sameDOB);
    }

    if (failed == 0)
    {
        return 1;
    }

    return 0;
}

void move_to_file(const char *password_file_name, const char *new_password)
{
    char buffer[1000] = "";
    FILE *password_file = fopen(password_file_name, "r");
    char history[MAX_PASSWORD_LENGTH] = "";

    if (password_file == NULL)
    {
        printf("Error opening password file for writing: %s\n", password_file_name);
        return;
    }

    int count = 0;

    while (fgets(history, sizeof(history), password_file) && count < 9)
    {
        add_null(history);
        strcat(buffer, history);
        strcat(buffer, "\n");
        count++;
    }

    password_file = fopen(password_file_name, "w");

    if (password_file == NULL)
    {
        printf("Error opening password file for writing: %s\n", password_file_name);
        return;
    }

    fprintf(password_file, "%s\n%s", new_password, buffer);
    fclose(password_file);
}

int main()
{
    char input_username[MAX_USERNAME_LENGTH];
    char input_password[MAX_PASSWORD_LENGTH];
    char stored_username[MAX_USERNAME_LENGTH];
    char stored_dob[MAX_DOB_LENGTH];
    char password_file_name[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    int is_authenticated = 0;
    char name[MAX_USERNAME_LENGTH], surname[MAX_USERNAME_LENGTH];

    FILE *file = fopen("masterfile.txt", "r");

    printf("Enter username: ");
    while (1)
    {
        fgets(input_username, sizeof(input_username), stdin);
        add_null(input_username);
        int found = 0;

        while (fgets(line, sizeof(line), file))
        {
            sscanf(line, "%s %s %s", stored_username, stored_dob, password_file_name);

            if (strcmp(input_username, stored_username) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            printf("User does not exist! Enter username again: ");
        }
        else
        {
            break;
        }
    }

    fclose(file);

    printf("Enter password: ");
    while (tries < 3)
    {
        if (tries != 0)
            printf("Wrong password! Enter password again: ");
        fgets(input_password, sizeof(input_password), stdin);
        add_null(input_password);

        if (file == NULL)
        {
            printf("Error opening credentials file.\n");
            return 1;
        }

        if (check_password(password_file_name, input_password))
        {
            sscanf(input_username, "%[^.].%s", name, surname);
            is_authenticated = 1;
            break;
        }
        else
        {
            tries++;
        }
    }

    if (is_authenticated == 0)
    {
        printf("Wrong password entered 3 times. Application exiting....\n");
        return 0;
    }

    printf("Login successful!\n");
    tries = 0;

    while (tries++ < 4)
    {
        char new_password[MAX_PASSWORD_LENGTH];
        if (tries == 1)
            printf("Enter new password (1st attempt): ");
        else if (tries == 2)
            printf("Enter new password (2nd attempt): ");
        else if (tries == 3)
            printf("Enter new password (3rd attempt): ");
        else if (tries == 4)
            printf("Enter new password (4th attempt): ");

        fgets(new_password, sizeof(new_password), stdin);
        add_null(new_password);

        if (verify_password(new_password, password_file_name, name, surname, stored_dob))
        {
            move_to_file(password_file_name, new_password);
            printf("Password changed successfully.\n");
            break;
        }
        else
        {
            if (tries == 1)
                timer(8);
            if (tries == 2)
                timer(16);
            if (tries == 3)
                timer(32);
            continue;
        }
    }

    if (tries == 5)
    {
        printf("All 4 attempts failed. You need to try again later.\n");
    }

    return 0;
}
