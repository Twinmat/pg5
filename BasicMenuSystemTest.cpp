#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <vector>
#include "Contacts.h"

using std::string;      using std::vector;
using std::istream;     using std::map;
using std::ostream;     using std::iterator;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

vector<Contact> contacts;
vector<Contact*> favorites;

//int main(int argc, char *argv[]) {
int main() {
	
	clearScreen();
    
    //startMainMenu:
    //string mainMenuInput;
    //mainMenuInput.clear();
    while(true) {
        startMainMenu:
        string mainMenuInput;
        mainMenuInput.clear();
        char singleCharInput = '\0';
        
        cout << "::Main Menu::PhoneList\n\n"
             << " 1) Edit Contacts List\n"
             << " 2) Edit Favorites List\n"
             << " 3) Display All Contacts\n"
             << " 4) Display Favorites\n"
             << " 5) Exit PhoneList\n\n"
             << "Selection: ";
        //cin >> singleCharInput;
        getline(cin, mainMenuInput);
        //singleCharInput = cin.get();
        
        // Check to make sure only one character was input by user
        //if (mainMenuInput.length() > 1 || mainMenuInput[0] > '5' || mainMenuInput[0] < '1') {
        if (mainMenuInput.length() > 1) {
            clearScreen();
            cout << "too long Invalid Input Entered\n\n";
            system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
            clearScreen();
            goto startMainMenu;
        } else {
            singleCharInput = mainMenuInput[0];
        }

        clearScreen();
        
        startSwitch:
        switch (singleCharInput) {
            case '1':
                // First display contacts, names and indexes only
                break;
                
            case '2':
                // First display favorites, names and indexes only
                clearScreen();
                
                char editFavsList;
                cout << "::Favorites List::\n\n"
                     << " [X] favorite name\n"
                     << " [X] favorite name\n"
                     << " [X] favorite name\n"
                     << "=============================================\n\n"
                     << "::Edit Favorites List::\n\n"
                     << " 1) Add Contact to Favorites\n"
                     << " 2) Delete Contact from Favorites\n"
                     << " 3) Rearrange Favorites\n"
                     << " 4) Return to Main Menu\n\n"
                     << "Selection: ";
                cin >> editFavsList;
                cout << endl;
                
                if (editFavsList > '4' || editFavsList < '1') {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '2';
                    clearScreen();
                    goto startSwitch;
                } else if (editFavsList == '1') {
                    // Add contact from full list to favorites
                    // Print full contacts, names and indexes only
                    char addContactToFavsChar;
                    int addContactToFavsInt;
                    
                    // PRINT ALL CONTACTS THAT HAVE isFav == false;
                    cout << "::Contacts Not in Favorites::\n\n"
                         << " [X] contact name\n"
                         << " [X] contact name\n"
                         << " [X] contact name\n"
                         << " [X] contact name\n"
                         << " [X] contact name\n"
                    << endl;
                    cout << "Which contact do you wish to add to your favorites list?:  ";
                    cin >> addContactToFavsChar;
                    addContactToFavsInt = addContactToFavsChar - '0';
                    printf ("Adding contact at [%d] to favs...\n", addContactToFavsInt);
                    // store index and pass to method below
                    // addContactToFavs();
                    cout << "Done.\n";
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    clearScreen();
                } else if (editFavsList == '2') {
                    // Delete contact from favorites
                    char deleteContactFromFavsChar;
                    int deleteContactFromFavsInt;
                    
                    cout << "Which contact do you wish to delete from your favorites list?:  ";
                    cin >> deleteContactFromFavsChar;
                    deleteContactFromFavsInt = deleteContactFromFavsChar - '0';
                    printf ("Deleting contact at [%d] from favs...\n", deleteContactFromFavsInt);
                    // store name OR index and pass to method below
                    // deleteContactFromFavs();
                    cout << "Done.\n";
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    clearScreen();
                } else if (editFavsList == '3') {
                    // Rearrange favorites
                    char origIndexChar, destIndexChar;
                    int origIndexInt, destIndexInt;
                    
                    cout << "What is the favorite's current index?: ";
                    cin >> origIndexChar;
                    origIndexInt = origIndexChar - '0';
                    
                    cout << "What is the favorite's desired index?: ";
                    cin >> destIndexChar;
                    destIndexInt = destIndexChar - '0';
                    
                    printf ("Moving favorite from [%d] to [%d]...\n", origIndexInt, destIndexInt);
                    // store both ints and pass to rearrangeFavorite()
                    // rearrangeFavorites(dest, orig);
                    // print possible success message: Done.
                    cout << "Done.\n";
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    clearScreen();
                } else if (editFavsList == '4') {
                    clearScreen();
                    goto startMainMenu;
                } else {
                    cout << "Edit favs menu: Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '2';
                    clearScreen();
                    goto startSwitch;
                }
                break;
                
            case '3':
                // Display all contacts with number pairs
                clearScreen();
                cout << "**All contacts + number pairs go here**\n"
                << "=============================================\n\n";
                // displayAll();
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                clearScreen();
                break;
                
            case '4':
                // Display all favorites with number pairs
                clearScreen();
                cout << "**All favorites + number pairs go here**\n"
                << "=============================================\n\n";
                // dispalyFavs();
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                clearScreen();
                break;
                
            case '5':
                clearScreen();
                cout << "Thanks for using PhoneList.\n\n";
                return 0;
                break;
            
            /*
            default:
                cout << "main 1<input<5: Invalid Input Entered\n\n";
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                clearScreen();
                break;
            */
        }
        
        // Old if-statement structure:
        /*
		if (mainMenuInput > '5' || mainMenuInput < '1') { // Validates user input
			//system("CLS"); // Clears screen
			//cout << "Invalid Input Entered\n\n";
			//system("PAUSE"); // Pauses until any key pressed
			//system("CLS");
			//clearScreen();
			cout << "Invalid Input Entered\n\n";
			system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
			clearScreen();
		} else if (mainMenuInput == '1') {
            // First display contacts, names and indexes only
		} else if (mainMenuInput == '2') {
            // First display favorites, names and indexes only
            clearScreen();
            
            char editFavsList;
            cout << "**All favorites + indexes (no number pairs)**\n\n"
                 << " 1) Add Contact to Favorites\n"
                 << " 2) Delete Contact from Favorites\n"
                 << " 3) Rearrange Favorites\n"
                 << " 4) Exit PhoneList\n\n"
                 << "Selection: ";
            cin >> editFavsList;
            cout << endl;
            
            if (editFavsList > '4' || editFavsList < '1') {
                cout << "Invalid Input Entered\n\n";
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
            } else if (editFavsList == '1') {
                // Add contact from full list to favorites
                // Print full contacts, names and indexes only
                cout << "**prompt for index or name: << **\n\n";
                // store name OR index and pass to method below
                // addContactToFav();
                // print possible success message: Done.
                //system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                break;
                mainMenuInput = '2';
                //clearScreen();
            } else if (editFavsList == '2') {
                // Delete contact from favorites
                cout << "**prompt for index or name: << **\n\n";
                // store name OR index and pass to method below
                // deleteContactFromFavs();
                // print possible success message: Done.
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                clearScreen();
            } else if (editFavsList == '3') {
                // Rearrange favorites
                cout << "**prompt for contact's current index: << **\n";
                // store current index --> pass to swapFavorites()
                cout << "**promt for desired index: << **\n\n";
                // store desired index --> pass to swapFavorites()
                // swapFavorites(dest, orig);
                // print possible success message: Done.
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                clearScreen();
            } else if (mainMenuInput == '4') {
                clearScreen();
                cout << "Thanks for using PhoneList.\n\n";
                mainMenuInput = '5';
            } else {
                cout << "Invalid Input Entered\n\n";
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                mainMenuInput = '5';
                clearScreen();
            }
            
            
		} else if (mainMenuInput == '3') {
			// Display all contacts with number pairs
            clearScreen();
            cout << "**All contacts + number pairs go here**\n\n";
            // displayAll();
            system( "read -n 1 -s -p \"Press any key to return to Main Menu...\"" );
            clearScreen();
		} else if (mainMenuInput == '4') {
            // Display all favorites with number pairs
            clearScreen();
            cout << "**All favorites + number pairs go here**\n\n";
            // dispalyFavs();
            system( "read -n 1 -s -p \"Press any key to return to Main Menu...\"" );
            clearScreen();
        } else if (mainMenuInput == '5') {
            clearScreen();
            cout << "Thanks for using PhoneList.\n\n";
            return 0;
		} else {
			cout << "Invalid Input Entered\n\n";
            system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
			clearScreen();
		}
        */
    }
}

void clearScreen() {
	for (int i = 0; i < 1000; i++)  {cout << endl;} // Mimics clear screen
}
