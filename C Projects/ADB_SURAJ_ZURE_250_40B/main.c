/*Address Book – 
NAME : SURAJ SUNIL ZURE
DATE : 28/01/2026
BATCH : 250_40B
BATCH ID :25026_285
Project Description:
The Address Book is a console-based application developed in C programming that helps users store
and manage contact information efficiently.
This application allows users to maintain a list of contacts containing Name, Phone Number,
and Email ID.
The system provides options to add new contacts, edit existing contact details, delete unwanted 
contacts, and search contacts based on name, phone number, or email ID. 
Editing can be performed using any of these fields, making the application flexible and 
user-friendly.
The application also supports displaying all saved contacts in a structured format for easy viewing. 
All contact details are saved to a file, ensuring that data is not lost when the program is closed.
When the program is executed again, the previously saved contact list is loaded automatically.
This project demonstrates the use of structures, file handling, string manipulation, functions,
and menu-driven programming in C. 
The Address Book application is suitable for beginners to understand real-world data management
concepts using the C language.
*/
#include <stdio.h>
#include "contact.h"
#ifndef COLORS_H
#define COLORS_H
/* Text colors */
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"
#endif

int main()
{
    int option;
    AddressBook addressbook;

    addressbook.contact_count = 0;
    load_contact(&addressbook);

    while (1)
    {
        printf(BLUE"\n╔══════════════════════════════════════╗\n");
        printf("║          ADDRESS BOOK MENU           ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║  1. Add Contact                      ║\n");
        printf("║  2. Search Contact                   ║\n");
        printf("║  3. Edit Contact                     ║\n");
        printf("║  4. Delete Contact                   ║\n");
        printf("║  5. List / Display Contacts          ║\n");
        printf("║  6. Save Contacts                    ║\n");
        printf("║  7. Save and Exit                    ║\n");
        printf("╚══════════════════════════════════════╝\n"RESET);
        printf("Enter your choice : ");

        scanf("%d", &option);
        getchar();   // clear input buffer

        switch (option)
        {
            case 1:
                create_contact(&addressbook);
                break;

            case 2:
                search_contacts(&addressbook);
                break;

            case 3:
                edit_contact(&addressbook);
                break;

            case 4:
                delete_contact(&addressbook);
                break;

            case 5:
                list_contacts(&addressbook);
                break;

            case 6:
                save_contacts(&addressbook);
                break;

            case 7:
                printf("\n👋 Saving data and exiting...\n");
                save_contacts(&addressbook);
                return 0;

            default:
                printf("\n❌ Invalid option! Please try again.\n");
        }
    }

    return 0;
}
