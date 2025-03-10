#include <stdio.h>
#include <string.h>

char adminemail[20] = "admin14@gmail.com";
int adminpassword = 2303014;

char loginemail[20];
int loginpassword;

int usernumber = 0;
int maxuser = 3;

int medicineno = 0;
int maxmedicine = 10;

char searchmed[20];
int found = 0;

struct user {
    char userName[10];
    char email[20];
    int password;
};

struct user u[3];

struct medicine {
    char Mmedicine[15];
    char genericname[15];
    char alt1[15];
    char alt2[15];
    char alt3[15];
    char alt4[15];
};

struct medicine m[10];

 //m[1]
void addmed() {
    if (medicineno >= maxmedicine) {
        printf("Medicine storage is full!\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", m[medicineno].Mmedicine);

    printf("Enter generic name: ");
    scanf("%s", m[medicineno].genericname);

    printf("Enter alternative 1: ");
    scanf("%s", m[medicineno].alt1);

    printf("Enter alternative 2: ");
    scanf("%s", m[medicineno].alt2);

    printf("Enter alternative 3: ");
    scanf("%s", m[medicineno].alt3);

    printf("Enter alternative 4: ");
    scanf("%s", m[medicineno].alt4);

    medicineno++;
    printf("Medicine added successfully!\n");
}

void removemed() {
    char medname[15];
    printf("Enter the medicine name to remove: ");
    scanf("%s", medname);

    int index = -1;
    for (int i = 0; i < medicineno; i++) {
        if (strcmp(medname, m[i].Mmedicine) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found!\n");
        return;
    }

    for (int i = index; i < medicineno - 1; i++) {
        m[i] = m[i + 1];
    }

    medicineno--;
    printf("Medicine removed successfully!\n");
}

void USER() {
    int flag = 0;
    printf("Enter your medicine name: ");
    scanf("%s", searchmed);

    for (int i = 0; i < medicineno; i++) {
        if (strcmp(searchmed, m[i].Mmedicine) == 0) {
            found = i;
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("The generic name is: %s\n", m[found].genericname);
        printf("Alternatives:\n");
        printf("- %s\n", m[found].alt1);
        printf("- %s\n", m[found].alt2);
        printf("- %s\n", m[found].alt3);
        printf("- %s\n", m[found].alt4);
    } else {
        printf("Medicine not found!!!\n");
    }
}

void admin() {
    int n;
    printf("1. Add medicine\n2. Remove medicine\n");
    printf("Enter your choice: ");
    scanf("%d", &n);

    if (n == 1) {
        addmed();
    } else if (n == 2) {
        removemed();
    } else {
        printf("Invalid input\n");
    }
}

void login() {
    printf("Enter your email: ");
    scanf("%s", loginemail);

    if (strcmp(loginemail, adminemail) == 0) {
        printf("Enter password: ");
        scanf("%d", &loginpassword);

        if (loginpassword == adminpassword) {
            admin();
        } else {
            printf("Incorrect password!\n");
        }
        return;
    }

    for (int i = 0; i < usernumber; i++) {
        if (strcmp(loginemail, u[i].email) == 0) {
            printf("Enter password: ");
            scanf("%d", &loginpassword);

            if (loginpassword == u[i].password) {
                USER();
            } else {
                printf("Incorrect password!\n");
            }
            return;
        }
    }

    printf("User not found!\n");
}

void forgot() {
    char email[20];
    printf("Enter your registered email: ");
    scanf("%s", email);

    for (int i = 0; i < usernumber; i++) {
        if (strcmp(email, u[i].email) == 0) {
            printf("Your password is: %d\n", u[i].password);
            return;
        }
    }
    printf("Email not found!\n");
}

void signup() {
    if (usernumber >= maxuser) {
        printf("Memory full, cannot add more users!\n");
        return;
    }

    printf("Enter your user name: ");
    scanf("%s", u[usernumber].userName);

    printf("Enter email: ");
    scanf("%s", u[usernumber].email);

    printf("Enter password: ");
    scanf("%d", &u[usernumber].password);

    usernumber++;
    printf("Signed up successfully!\n");

    signin();
}

void signin() {
    int n;
    printf("1. Log in\n2. Forgotten password\n");
    printf("Enter your choice: ");
    scanf("%d", &n);

    if (n == 1) {
        login();
    } else if (n == 2) {
        forgot();
    } else {
        printf("Invalid choice\n");
    }
}

int main() {
    int n;
    printf("Welcome to Generic Medicine Search System!!\n");
    printf("Choose an option below -\n");
    printf("1. Sign up\n2. Sign in\n");
    printf("Enter your choice: ");
    scanf("%d", &n);

    if (n == 1) {
        signup();
    } else if (n == 2) {
        signin();
    } else {
        printf("Invalid option\n");
    }

    return 0;
}
