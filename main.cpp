//Cashier Login Details found in cashier's file
//Manager Login Details; Name:Godwin Password:pass

#include "shop.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <windows.h>
#include <unistd.h>
#include <ctime>
#include <iomanip> //needed for setw()
#include <limits> // needed for std::numeric_limits



// Main function to test the Shop class
int main() {
    Shop myShop; //myShop object from Shop


     //Add manager to shop
    myShop.addManager("Godwin", "pass");
    //system("cls");

   shop_management:
        cout << "===================================" << endl;
        cout << "Welcome to Shop Management System" << endl;
        cout << "===================================" << endl;
        cout << "1. Manager" <<endl;
        cout << "2. Cashier" <<endl;
        cout << "3. Exit" <<endl;

        int option1;
        while (true) {
        cout << "\nEnter your choice (1-3): ";
        cin >> option1;
        if (cin.fail()) {
            cin.clear(); // clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the remaining characters in the input buffer
            system("cls");
            cout << "Invalid input. Please enter a numeric value." << endl;
            goto shop_management;
        } else {
            break; // input was successful, break out of the loop
        }
    }
        cout << "\nRedirecting you....";
        sleep(1);
        system("cls");
        if(option1 == 1){
            manager:
            cout << "======================" << endl;
            cout << "    Manager Login" << endl;
            cout << "======================" << endl;
            cout << endl;
            string managerName, managerPassword;
            cout << "Enter name: ";
            cin >> managerName;
            cout << "Enter password: ";
            cin >> managerPassword;

             int option2;
            //Validate Manager
             if (myShop.verifyManager(managerName, managerPassword)) {
               do{

                    system("cls");
                    managerDashboard:
                    cout << "======================" << endl;
                    cout << "  Manager Dashboard" << endl;
                    cout << "======================" << endl;
                    cout << endl;
                    cout << "1. Add item" << endl;
                    cout << "2. Update item" << endl;
                    cout << "3. Remove item" << endl;
                    cout << "4. Search item" <<endl;
                    cout << "5. Display item" <<endl;
                    cout << "6. Add cashier" << endl;
                    cout << "7. Update cashier" << endl;
                    cout << "8. Remove cashier" << endl;
                    cout << "9. Search cashier" << endl;
                    cout << "10. Display cashier" <<endl;
                    cout << "11. Back" <<endl;
                    cout << "12. Exit" <<endl;
                    //Prevent user from entering non-numeric value
                     while (true) {
                        cout << "\nEnter your choice (1-12): ";
                        cin >> option2;
                        if (cin.fail()) {
                            cin.clear(); // clear the error flag on cin
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the remaining characters in the input buffer
                            system("cls");
                            cout << "Invalid input. Please enter a numeric value." << endl;
                            goto managerDashboard;
                        } else {
                            break; // input was successful, break out of the loop
                        }
                    }
                    cout << "\nRedirecting you....";
                    sleep(1);
                    system("cls");
                    //Condition
                    string itemName;
                    double itemPrice;
                    int itemQuantity;
                    string cashierName;
                    string cashierPassword;
                    int cash;

                if(option2 == 1){
                    //Add item
                    add1:
                    cout << "1. Add new Item(s)" << endl;
                    cout << "=====================\n" << endl;
                    int itemNumber;
                    cout << "How many items do you want to add: ";
                    cin >> itemNumber;
                    cout << endl;
                     if (cin.fail()) {
                            cin.clear(); // clear the error flag on cin
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the remaining characters in the input buffer
                            system("cls");
                            cout << "Invalid input. Please enter a numeric value." << endl;
                            goto add1;
                        }

                    for(int i = 0; i < itemNumber; i++){
                        cout << "    Item "<< i + 1 <<endl;
                        cout << "  ========="<<endl;
                        cout << "Enter item name: ";
                        getline(cin >> ws,itemName);
                        cout << "Enter item price: ";
                        cin >> itemPrice;
                        cout << "Enter item quantity: ";
                        cin >> itemQuantity;

                        //Add item to shop
                        myShop.addItem(itemName, itemPrice, itemQuantity);
                    }
                        system("pause");
                }else if(option2 == 2){
                    //Update Item
                        cout << "2. Update new Item" << endl;
                        cout << "======================\n" << endl;
                        cout << "Enter item to update: ";
                        getline(cin >> ws,itemName);
                        cout << "Enter item Price: ";
                        cin >> itemPrice;
                        cout << "Enter item quantity: ";
                        cin >> itemQuantity;

                        myShop.updateItem(itemName, itemPrice, itemQuantity);
                        system("pause");
                    }else if(option2 == 3){
                        //Remove Item
                        cout << "   3. Remove Item" << endl;
                        cout << "======================\n" << endl;
                        cout << "Enter item to remove: ";
                         getline(cin >> ws,itemName);

                         myShop.removeItem(itemName);
                         system("pause");

                    }else if(option2 == 4){
                        //Search Item
                        cout << "   4. Search Item" << endl;
                        cout << "======================\n" << endl;
                        cout << "Enter item to search: ";
                         getline(cin >> ws,itemName);
                         cout << "Searching for item...";
                         sleep(2);
                         system("cls");
                         myShop.searchItem(itemName);
                         system("pause");
                    }else if(option2 == 5){
                        //Display Item
                        cout << " 5. Display All Items" << endl;
                        cout << "======================\n" << endl;
                        myShop.displayInventory();
                        system("pause");
                    }else if(option2 == 6){
                        //Add cashier
                        cout << "  6. Add new Cashier" << endl;
                        cout << "======================\n" << endl;
                        cout << "Enter Cashier Name: ";
                        getline(cin >> ws, cashierName);
                        cout << "Enter Cashier Password: ";
                        cin >> cashierPassword;
                        cout << "Enter Cashier Initial Cash: ";
                        cin >> cash;

                        myShop.addCashier(cashierName,cashierPassword,cash);
                         cout << endl;
                        system("pause");

                    }else if(option2 == 7){
                        int option2a;
                        //Update cashier
                        update_cashier:
                            cout << " 7. Update Cashier" << endl;
                            cout << "=====================\n" << endl;
                            cout <<"1. Change Password  " << endl;
                            cout << "2. Update Cash" << endl;
                            cout << "3. Back" << endl;
                            //Prevent user from entering non-numeric value
                             while (true) {
                                cout << "\nEnter your choice (1-3): ";
                                cin >> option2a;
                                if (cin.fail()) {
                                    cin.clear(); // clear the error flag on cin
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the remaining characters in the input buffer
                                    cout << endl;
                                    system("cls");
                                    cout << "Invalid input. Please enter a numeric value." << endl;
                                    goto update_cashier;
                                } else {
                                    break; // input was successful, break out of the loop
                                }
                            }

                            cout << "\nRedirecting you....";
                            sleep(1);
                            system("cls");
                            if(option2a == 1){
                                cout << "   Change Password" << endl;
                                cout << "=====================\n" << endl;
                                string newPassword;
                                string cPassword;
                                cout << "Enter Cashier Name: ";
                                getline(cin >> ws, cashierName);
                                password:
                                cout << "Enter New Password: ";
                                cin >> newPassword;
                                cout << "Confirm Password: ";
                                cin >> cPassword;
                                if(newPassword == cPassword){
                                myShop.updateCashierPassword(cashierName,newPassword);
                                system("pause");
                               }else{
                                system("cls");
                                cout << "Password not marching" <<endl;
                                goto password;
                               }
                            }else if(option2a == 2){
                                 cout << "   Update Cash" << endl;
                                cout << "===================\n" << endl;
                                cout << "Enter Cashier Name: ";
                                getline(cin >> ws, cashierName);

                                cout << "Enter Cash: ";
                                cin >> cash;
                                myShop.updateCashierCash(cashierName,cash);
                                 cout << endl;
                                system("pause");
                            }else if(option2a == 3){
                                goto managerDashboard;
                            }else{
                                cout << "Invalid choice. Please enter a number from 1 to 3." << endl;
                                goto update_cashier;
                            }

                    }else if(option2 == 8){
                        //Remove cashier
                         cout << " 8. Remove Cashier" << endl;
                        cout << "=====================\n" << endl;
                        cout << "Enter Cashier Name: ";
                        cin >> cashierName;

                        myShop.removeCashier(cashierName);
                         cout << endl;
                        system("pause");

                    }else if(option2 == 9){
                        //Search Cashier
                         cout << " 9. Search Cashier" << endl;
                        cout << "=====================\n" << endl;
                        cout << "Enter Cashier Name: ";
                        cin >> cashierName;
                        cout << "Searching for Cashier...";
                         sleep(2);
                         system("cls");
                       myShop.searchCashier(cashierName);
                        cout << endl;
                       system("pause");
                    }else if(option2 == 10){
                        //Display cashier
                         cout << " Display Cashier" << endl;
                         cout << "=====================\n" << endl;
                         myShop.displayCashiers();
                         cout << endl;
                         system("pause");
                    }else if(option2 == 11){
                        //Back to Shop Management
                        goto shop_management;
                    }else if(option2 == 12){
                        system("cls");
                        cout << "   Exit " <<endl;
                        cout << " ======== " << endl;
                        cout << endl;
                        cout << "Thank you for using Shop Management System!" <<endl;
                    }else{
                        cout << "Invalid choice. Please enter a number from 1 to 12." << endl;
                        goto managerDashboard;
                    }
                }while(option2 != 12);
             }else {
                 //Back to Manager login
                 system("cls");
                    cout << "Invalid credentials!" << endl;
                    goto manager;
            }

        }else if(option1 == 2){
            cashier:
             cout << "=====================" << endl;
            cout << "  Cashier Login" << endl;
            cout << "======================" << endl;
            string cashierName, cashierPassword;
            cout << "Enter cashier name: ";
            cin >> cashierName;
            cout << "Enter password: ";
            cin >> cashierPassword;

             int option3;
             char key;
             //Validate Cashier
             if (myShop.verifyCashier(cashierName, cashierPassword)) {
                  //current date/time
                time_t now = time(0);
               //convert now to string form
               char* dt = ctime(&now);
                do{
                    cout << "\nRedirecting you....";
                    sleep(1);
                    system("cls");
                    cashierDashboard:
                    cout << "======================" << endl;
                    cout << "  Cashier Dashboard" << endl;
                    cout << "======================" << endl;
                    cout << "----------------------------------------------------------------------" <<endl;
                     cout <<"  Balance: " << myShop.getCashierCash(cashierName) <<"\t\t\t" << dt;
                     cout <<"----------------------------------------------------------------------" <<endl;
                     cout << endl;
                    cout << "1. Add item" << endl;
                    cout << "2. Sell item" << endl;
                    cout << "3. Update item" << endl;
                    cout << "4. Remove item" << endl;
                    cout << "5. Search item" << endl;
                    cout << "6. Display item" <<endl;
                    cout << "7. Back" <<endl;
                    cout << "8. Exit" <<endl;
                    while (true) {
                        cout << "\nEnter your choice (1-8): ";
                    cin >> option3;
                        if (cin.fail()) {
                            cin.clear(); // clear the error flag on cin
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the remaining characters in the input buffer
                            system("cls");
                            cout << "Invalid input. Please enter a numeric value." << endl;
                        } else {
                            break; // input was successful, break out of the loop
                        }
                    }
                    cout << "\nRedirecting you....";
                    sleep(1);
                    system("cls");
                     string itemName;
                    int itemQuantity;

                if(option3 == 1){
                    //Add item
                    add2:
                     cout << "1. Add new Item" << endl;
                        cout << "======================\n" << endl;
                    int itemNumber;
                    cout << "How many items do you want to add: ";
                    cin >> itemNumber;
                    if (cin.fail()) {
                            cin.clear(); // clear the error flag on cin
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the remaining characters in the input buffer
                            system("cls");
                            cout << "Invalid input. Please enter a numeric value." << endl;
                            goto add2;
                        }

                    float itemPrice;

                    for(int i = 0; i < itemNumber; i++){
                       cout << "    Item "<< i + 1 <<endl;
                        cout << "  ========="<<endl;
                        cout << "Enter item name: ";
                        getline(cin >> ws, itemName);
                        cout << "Enter item price: ";
                        cin >> itemPrice;
                        cout << "Enter item quantity: ";
                        cin >> itemQuantity;

                        //Add item to shop
                        myShop.addItem(itemName, itemPrice, itemQuantity);
                    }

                        system("pause");
                }else if(option3 == 2){
                    //Sell Item
                     cout << "2. Sell Item" << endl;
                        cout << "======================\n" << endl;
                     cout << "Enter item name: ";
                        cin >> itemName;
                        cout << "Enter item quantity: ";
                        cin >> itemQuantity;
                        myShop.sellItem(itemName, itemQuantity,cashierName);
                        system("pause");
                    }else if(option3 == 3){
                        //Update Item
                         cout << "3. Update new Item" << endl;
                        cout << "======================\n" << endl;
                         cout << "Enter item to update: ";
                        cin >> itemName;
                        cout << "Enter item quantity: ";
                        cin >> itemQuantity;

                        myShop.updateItem(itemName, itemQuantity);
                       system("pause");

                    }else if(option3 == 4){
                        //Remove Item
                         cout << "2. Remove Item" << endl;
                        cout << "======================\n" << endl;
                        cout << "Enter item to remove: ";
                        cin >> itemName;

                         myShop.removeItem(itemName);
                         system("pause");
                    }else if(option3 == 5){
                        //Search Item
                        cout << "   5. Search Item" << endl;
                        cout << "======================\n" << endl;
                        cout << "Enter item to search: ";
                         getline(cin >> ws,itemName);
                         cout << "Searching for item...";
                         sleep(2);
                         system("cls");
                         myShop.searchItem(itemName);
                         system("pause");
                    }else if(option3 == 6){
                        //Display Item
                        cout << "5. Display Item" << endl;
                        cout << "======================\n" << endl;
                        myShop.displayInventory();
                        system("pause");
                    }else if(option3 == 7){
                        //Back to Shop Management
                        goto shop_management;

                    }else if(option3 == 8){
                        system("cls");
                        cout << "   Exit " <<endl;
                        cout << " ======== " << endl;
                        cout << endl;
                        cout << "Thank you for using Shop Management System!" <<endl;
                    }else{
                       cout << "Invalid choice. Please enter a number from 1 to 8." << endl;
                       goto cashierDashboard;
                    }
                  }while(option3 != 8);
                }else {
                    system("cls");
                    cout << "Invalid credentials!" << endl;
                    goto cashier;
            }
        }else if(option1 == 3){
            system("cls");
            cout << "   Exit " <<endl;
            cout << " ======== " << endl;
            cout << endl;
            cout << "Thank you for using Shop Management System!" <<endl;
        }else {
                    cout << "Invalid choice. Please enter a number from 1 to 3." << endl;
                    goto shop_management;
            }

    return 0;
}


