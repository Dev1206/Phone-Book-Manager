#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_BIRTHDAY_LENGTH 20
#define MAX_GROUP_NAME_LENGTH 50
#define FILE_NAME "phonebook.txt"

// Structure to represent a contact
struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char birthday[MAX_BIRTHDAY_LENGTH];
    char group[MAX_GROUP_NAME_LENGTH];
};

// Function prototypes
void addContact(struct Contact contacts[], int* numContacts);
void displayContacts(struct Contact contacts[], int numContacts);
void searchContactByName(struct Contact contacts[], int numContacts);
void searchContactByPhone(struct Contact contacts[], int numContacts);
void searchContactByEmail(struct Contact contacts[], int numContacts);
void sortContactsByName(struct Contact contacts[], int numContacts);
void sortContactsByGroup(struct Contact contacts[], int numContacts);
void addContactToGroup(struct Contact contacts[], int numContacts);
void displayContactDetails(struct Contact contacts[], int numContacts);
void deleteContact(struct Contact contacts[], int* numContacts);
void saveContacts(struct Contact contacts[], int numContacts);
void loadContacts(struct Contact contacts[], int* numContacts);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    loadContacts(contacts, &numContacts);

    while (1) {
        printf("\nPhone Book Manager\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Search Contact by Phone\n");
        printf("5. Search Contact by Email\n");
        printf("6. Sort Contacts by Name\n");
        printf("7. Sort Contacts by Group\n");
        printf("8. Add Contact to Group\n");
        printf("9. Display Contact Details\n");
        printf("10. Delete Contact\n");
        printf("11. Save Contacts\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                searchContactByName(contacts, numContacts);
                break;
            case 4:
                searchContactByPhone(contacts, numContacts);
                break;
            case 5:
                searchContactByEmail(contacts, numContacts);
                break;
            case 6:
                sortContactsByName(contacts, numContacts);
                break;
            case 7:
                sortContactsByGroup(contacts, numContacts);
                break;
            case 8:
                addContactToGroup(contacts, numContacts);
                break;
            case 9:
                displayContactDetails(contacts, numContacts);
                break;
            case 10:
                deleteContact(contacts, &numContacts);
                break;
            case 11:
                saveContacts(contacts, numContacts);
                break;
            case 12:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a new contact
void addContact(struct Contact contacts[], int* numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }

    struct Contact newContact;

    printf("Enter name: ");
    scanf("%s", newContact.name);

    printf("Enter phone number (limit 10 digits): ");
    scanf("%s", newContact.phone);

    // Validate phone number length
    if (strlen(newContact.phone) != 10) {
        printf("Phone number must be 10 digits long.\n");
        return;
    }

    printf("Enter email: ");
    scanf("%s", newContact.email);

    printf("Enter address: ");
    scanf("%s", newContact.address);

    printf("Enter birthday: ");
    scanf("%s", newContact.birthday);

    printf("Enter group: ");
    scanf("%s", newContact.group);

    contacts[*numContacts] = newContact;
    (*numContacts)++;

    printf("Contact added successfully.\n");
}

// Function to display all contacts
void displayContacts(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. Name: %s, Phone: %s, Email: %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// Function to search for a contact by name
void searchContactByName(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact found:\nName: %s, Phone: %s, Email: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to search for a contact by phone number
void searchContactByPhone(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char searchPhone[MAX_PHONE_LENGTH];
    printf("Enter phone number to search: ");
    scanf("%s", searchPhone);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].phone, searchPhone) == 0) {
            printf("Contact found:\nName: %s, Phone: %s, Email: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to search for a contact by email
void searchContactByEmail(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char searchEmail[MAX_EMAIL_LENGTH];
    printf("Enter email to search: ");
    scanf("%s", searchEmail);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].email, searchEmail) == 0) {
            printf("Contact found:\nName: %s, Phone: %s, Email: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to sort contacts by name
void sortContactsByName(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    // Bubble sort algorithm for simplicity
    for (int i = 0; i < numContacts - 1; i++) {
        for (int j = 0; j < numContacts - i - 1; j++) {
            if (strcmp(contacts[j].name, contacts[j + 1].name) > 0) {
                // Swap contacts
                struct Contact temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }

    printf("Contacts sorted by name.\n");
}

// Function to sort contacts by group
void sortContactsByGroup(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    // Bubble sort algorithm for simplicity
    for (int i = 0; i < numContacts - 1; i++) {
        for (int j = 0; j < numContacts - i - 1; j++) {
            if (strcmp(contacts[j].group, contacts[j + 1].group) > 0) {
                // Swap contacts
                struct Contact temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }

    printf("Contacts sorted by group.\n");
}

// Function to add contact to a group
void addContactToGroup(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter name of the contact to add to group: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Enter group name: ");
            scanf("%s", contacts[i].group);
            printf("Contact added to group successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to display contact details
void displayContactDetails(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter name of the contact to display details: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact details:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("Address: %s\n", contacts[i].address);
            printf("Birthday: %s\n", contacts[i].birthday);
            printf("Group: %s\n", contacts[i].group);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact by name
void deleteContact(struct Contact contacts[], int* numContacts) {
    if (*numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char deleteName[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", deleteName);

    int found = 0;
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].name, deleteName) == 0) {
            for (int j = i; j < *numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*numContacts)--;
            found = 1;
            printf("Contact deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to save contacts to a file
void saveContacts(struct Contact contacts[], int numContacts) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numContacts; i++) {
        fprintf(fp, "%s %s %s %s %s %s\n", contacts[i].name, contacts[i].phone, contacts[i].email, contacts[i].address, contacts[i].birthday, contacts[i].group);
    }

    fclose(fp);
    printf("Contacts saved successfully.\n");
}

// Function to load contacts from a file
void loadContacts(struct Contact contacts[], int* numContacts) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("No saved contacts found.\n");
        return;
    }

    *numContacts = 0;
    while (fscanf(fp, "%s %s %s %s %s %s", contacts[*numContacts].name, contacts[*numContacts].phone, contacts[*numContacts].email, contacts[*numContacts].address, contacts[*numContacts].birthday, contacts[*numContacts].group) != EOF) {
        (*numContacts)++;
    }

    fclose(fp);
    printf("Contacts loaded successfully.\n");
}
