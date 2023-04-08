//Cashier Login Details found in cashier's file
//Manager Login Details; Name:Godwin Password:pass
#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream> //To read and write to file
#include <sstream>
#include <iomanip>

using namespace std;
string toLowerCase(string);
//Item class to represent an item in the inventory
class Item {
    private:
    string itemName;
    float itemPrice;
    int itemQuantity;
public:

    //Item constructor to set values
    Item(string name, float price, int quantity) {
        this->itemName = name;
        this->itemPrice = price;
        this->itemQuantity = quantity;
    }

    //Get Item Name
    string getName() {
     return itemName;
     }

     //Method to Get Item Price
    float getPrice() {
        return itemPrice;
        }

    //Method to Get Item Quantity
    int getQuantity() {
         return itemQuantity;
     }

      //Method to Set Item Name
     void setName(string name) {
         this->itemName = name;
         }

     //Method to Set Item Price
     void setPrice(float price) {
         this->itemPrice = price;
         }
    //Method to Set Item Quantity
    void setQuantity(int quantity) {
         this->itemQuantity = quantity;
         }

    //Method to Update Price
    void updatePrice(float newPrice){
         this->itemPrice = newPrice;
    }
     //Method to Update quantity
    void updateQuantity(int newQuantity){
         this->itemQuantity = newQuantity;
    }

};

// Cashier class to manage cashier details
class Cashier {
private:
    string name;
    string password;
    float cash;
public:

    //Cashier constructor to set values
    Cashier(string n, string p, float c){
      this -> name = n;
      this -> password = p;
      this -> cash = c;
    }

    //Method to Get Cashier Name
    string getName(){
        return name;
    }

    //Method to Get Cashier Password
    string getPassword()
    {
        return password;
    }

    //Method to Get Cashier Cash
    float getCash(){
    return cash;
    }

    // Method for updating cashier cash
    void updateCash(float c){
        this -> cash = c;
    }
    // Method for updating cashier cash
    void updatePassword(string newPassword){
        this -> password = newPassword;
    }
};

class Manager {
private:
    string name;
    string password;
public:

    //Manager constructor to set values
    Manager(string n, string p){
      this -> name = n;
      this -> password = p;
    }

    //Method to Get Manager Name
    string getName(){
        return name;
    }

    //Method to Get Manager Password
    string getPassword()
    {
        return password;
    }
};


// Shop class to manage inventory and cashiers

class Shop {
private:
    vector<Item> inventory; //Dynamic array to store Item objects reference
    vector<Cashier> cashiers; //Dynamic array to store cashier objects reference
    vector<Manager> manager; //Dynamic array to store cashier objects reference
public:

    //Method to read from inventory file
    void readInventoryFile(){
        inventory.clear();
        // Open a file input stream and specify the file name
        ifstream infile("inventory.txt");

        // Read each line from the file and create a new Item object
        string line;
        while (getline(infile, line)) {
            string name;
            float price;
            int quantity;
            istringstream iss(line);
            iss >> name >> price >> quantity;
            Item item(name, price, quantity); // Create a new Item object
            inventory.push_back(item); // Add the new Item object to the inventory vector
        }

        // Close the file input stream
        infile.close();
    }

     //Method to read from cashier file
    void readCashierFile(){
        cashiers.clear();
        // Open a file input stream and specify the file name
        ifstream infile("cashier.txt");

        // Read each line from the file and create a new Item object
        string line;
        while (getline(infile, line)) {
            string name;
            string password;
            float cash;
            istringstream iss(line);
            iss >> name >> password >> cash;
            Cashier cashier(name, password, cash); // Create a new Item object
            cashiers.push_back(cashier); // Add the new Item object to the inventory vector
        }

        // Close the file input stream
        infile.close();
    }

    void writeToInventoryFile(){
        // Open a file output stream and specify the file name
                ofstream outfile("inventory.txt");

                // Write each Item object to the file using the << operator
                for (auto& item : inventory) {
                    outfile << item.getName() << " " << item.getPrice() << " " << item.getQuantity() << endl;
                }

                // Close the file output stream
                outfile.close();
                 // Clear the inventory vector
                 inventory.clear();
            }

    //Method to write to Cashier File
     void writeToCashierFile(){
        // Open a file output stream and specify the file name
                ofstream outfile("cashier.txt");

                // Write each Item object to the file using the << operator
                for (auto& cashier : cashiers) {
                    outfile << cashier.getName() << " " << cashier.getPassword() << " " << cashier.getCash() << endl;
                }

                // Close the file output stream
                outfile.close();
                 // Clear the inventory vector
                 cashiers.clear();
            }
    // Method for adding an item from the inventory
    void addItem(string name, float price, int quantity) {
        readInventoryFile(); //Read from inventory file and save items in Inventory vector
        for (int i = 0; i < inventory.size(); i++) {
            if (toLowerCase(inventory[i].getName()) == toLowerCase(name)) {
                cout << "Sorry, Item already Exist!" <<endl;
                cout << endl;
                return;
            }

        }
        Item newItem(name, price, quantity); // Create a new Item object

        // Open a file output stream and specify the file name
        ofstream outfile("inventory.txt", ios::app); // Use ios::app flag to append to file
        // Write the new Item object to the file using the << operator
        outfile << newItem.getName() << " " << newItem.getPrice() << " " << newItem.getQuantity() << endl;
        // Close the file output stream
        outfile.close();

        // Clear the inventory vector
        inventory.clear();
        cout << "\nItem(s) successfully added!" << endl;
}


    // Method for removing an item from the inventory
    void removeItem(string itemName) {
        readInventoryFile(); //Read from inventory file and save items in Inventory vector
        for (int i = 0; i < inventory.size(); i++) {
            if (toLowerCase(inventory[i].getName()) == toLowerCase(itemName)) {
                inventory.erase(inventory.begin() + i);
                cout << endl;
                cout << "Item Successfully Removed!" << endl;
                writeToInventoryFile();
                return;
            }
        }
            cout << endl;
            cout << "Item not found!" << endl;
    }


    // Method for updating an item from the inventory
    void updateItem(string itemName, int newQuantity) {
        readInventoryFile(); //Read from inventory file and save items in Inventory vector
        for (int i = 0; i < inventory.size(); i++) {
            if (toLowerCase(inventory[i].getName()) == toLowerCase(itemName)) {
                inventory[i].updateQuantity(newQuantity);
                cout << "Item Successfully Updated!" <<endl;
                cout << endl;
                writeToInventoryFile();
                return;
                 }

            }
            cout << endl;
            cout << "Item not found!" << endl;
        }

        void updateItem(string itemName, float price, int newQuantity) {
        readInventoryFile(); //Read from inventory file and save items in Inventory vector
        for (int i = 0; i < inventory.size(); i++) {
            if (toLowerCase(inventory[i].getName()) == toLowerCase(itemName)) {
                inventory[i].updatePrice(price);
                inventory[i].updateQuantity(newQuantity);
                cout << "Item Successfully Updated!" <<endl;
                cout << endl;
                writeToInventoryFile();
                return;
                 }

            }
            cout << endl;
            cout << "Item not found!" << endl;
        }
   //Method to Search item
    void searchItem(string itemName){
        readInventoryFile();
         cout << "========================" << endl;
         cout << "   Search Item Result   " << endl;
         cout << "========================" << endl;
        for (int i = 0; i < inventory.size(); i++) {
            if (toLowerCase(inventory[i].getName()) == toLowerCase(itemName)) {
                    cout << left << setw(10) << "Sn" << left << setw(20)<< "Name" << "\t" << left << setw(20)<< "Price" << setw(20)<<"Quantity" << "\n";
                    cout << "-----------------------------------------------------------------------" << endl;
                    cout << left << setw(10) << i+1 << "| " << left << setw(20)<< inventory[i].getName() << "| GHS" << left << setw(15) << inventory[i].getPrice()<< inventory[i].getQuantity() << endl;
                    cout << endl;
                    inventory.clear();
                    return;
            }
      }
      cout << endl;
      cout << "Item not found!" << endl;
            return;
    }

     //Method to display inventory
    void displayInventory() {
        readInventoryFile();
        cout << "==================" << endl;
        cout << "    Inventory     " << endl;
        cout << "==================" << endl;
        cout << left << setw(10) << "Sn" << left << setw(20)<< "Name" << "\t" << left << setw(20)<< "Price" << setw(20)<<"Quantity" << "\n";
        cout << "-----------------------------------------------------------------------" << endl;
        for (int i = 0; i < inventory.size(); i++) {
        cout << left << setw(10) << i+1 << "| " << left << setw(20)<< inventory[i].getName() << "| GHS" << left << setw(15) << inventory[i].getPrice()<< inventory[i].getQuantity() << endl;
        }
        cout << endl;
        inventory.clear();
    }


    //// Method for registering a cashier
    void addCashier(string name, string password, float cash) {
       readCashierFile();
       for (int i = 0; i < cashiers.size(); i++) {
            if (cashiers[i].getName() == name && cashiers[i].getPassword() == password) {
                cout << "Sorry, Cashier already Exist!" <<endl;
                cout << endl;
                return;
            }
        }

        Cashier newCashier(name, password, cash);
        cashiers.push_back(newCashier);

        // Open a file output stream and specify the file name
        ofstream outfile("cashier.txt", ios::app); // Use ios::app flag to append to file
        // Write the new Item object to the file using the << operator
        outfile << newCashier.getName() << " " << newCashier.getPassword() << " " << newCashier.getCash() << endl;
        // Close the file output stream
        outfile.close();

        // Clear the inventory vector
        cashiers.clear();
        cout << "Cashier successfully added!" << endl;
    }


      // Method for removing a cashier from the inventory
    void removeCashier(string cashier) {
        readCashierFile(); //Read from cashier file and store cashiers into cashier vector
        for (int i = 0; i < cashiers.size(); i++) {
            if (toLowerCase(cashiers[i].getName()) == toLowerCase(cashier)) {
                cashiers.erase(cashiers.begin() + i);
                cout << "Cashier Successfully Removed!" <<endl;
                cout << endl;
                writeToCashierFile(); //Write to cashier file
                return;
                 }
        }
        cout << "Cashier not found!" << endl;
    }
    //Method for cashier verification
    bool verifyCashier(string name, string password) {
        readCashierFile();
        for (int i = 0; i < cashiers.size(); i++) {
            if (cashiers[i].getName() == name && cashiers[i].getPassword() == password) {
                return true;
            }
        }
        return false;
    }
    float getCashierCash(string cashier){
        readCashierFile();
        for (int i = 0; i < cashiers.size(); i++) {
            if (toLowerCase(cashiers[i].getName()) == toLowerCase(cashier)) {
                    return cashiers[i].getCash();
                 }
        }
    }

    // Method for updating a Cashier from the cashiers
    void updateCashierPassword(string cashier, string nPassword) {
        readCashierFile();
        for (int i = 0; i < cashiers.size(); i++) {
            if (toLowerCase(cashiers[i].getName()) == toLowerCase(cashier)) {
                cashiers[i].updatePassword(nPassword) ;
                cout << "Cashier Password Successfully Updated!" <<endl;
                cout << endl;
                writeToCashierFile();
                return;
            }

        }
         cout << "Cashier not found!" << endl;

    }
    void updateCashierCash(string cashier, float cash){
        readCashierFile();
        for (int i = 0; i < cashiers.size(); i++) {
            if (toLowerCase(cashiers[i].getName()) == toLowerCase(cashier)) {
                 cout << "Cashier Cash Successfully updated!" <<endl;
                 cout << endl;
                 cashiers[i].updateCash(cash);
                 writeToCashierFile();
                 return;
            }

        }
        cout << "Cashier not found!" <<endl;
    }

    //Method to Search Cashier
 void searchCashier(string cashier){
        readCashierFile();
         cout << "=============================" << endl;
         cout << "    Search Cashier Result    " << endl;
         cout << "=============================" << endl;
         cout << left << setw(10) << "Sn" << left << setw(20)<< "Name" << "\t" << left << setw(20)<< "Cash" <<endl;
         cout << "---------------------------------------------" << endl;
         int i;
        for (i = 0; i < cashiers.size(); i++) {
            if (toLowerCase(cashiers[i].getName()) == toLowerCase(cashier)) {
                     cout << left << setw(10) << i+1 << "| " << left << setw(20)<< cashiers[i].getName() << "| "<< left << setw(15) << cashiers[i].getCash()<< endl;
                    cout << endl;
            }

       }

        cashiers.clear();
        return;
    }

    //Method for Manager verification
    bool verifyManager(string name, string password) {
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i].getName() == name && manager[i].getPassword() == password) {
                return true;
            }
        }
        return false;
    }


    //Method to display cashiers
    void displayCashiers() {
        readCashierFile();
        cout << "=============================" << endl;
        cout << "           CASHIERS          " << endl;
        cout << "=============================" << endl;
        cout << left << setw(10) << "Sn" << left << setw(20)<< "Name" << "\t" << left << setw(20)<< "Cash" <<endl;
        cout << "------------------------------------------------" << endl;
        for (int i = 0; i < cashiers.size(); i++) {
             cout << left << setw(10) << i+1 << "| " << left << setw(20)<< cashiers[i].getName() << "| "<< left << setw(15) << cashiers[i].getCash()<< endl;
        }
        cout << endl;
        cashiers.clear();
        return;
    }

     //Method to sell items
    void sellItem(string itemName, int quantity, string cashier) {
        readInventoryFile();
        readCashierFile();
        for (int i = 0; i < inventory.size(); i++) {
            if (toLowerCase(inventory[i].getName()) == toLowerCase(itemName)) {
                if (inventory[i].getQuantity() >= quantity) {
                    double totalPrice = inventory[i].getPrice() * quantity;

                        cout << "===================================" << endl;
                        cout << "             RECEIPT               " << endl;
                        cout << "===================================" << endl;
                        cout << "Cashier: " << cashier << endl;
                        cout << "Item: " << inventory[i].getName() << endl;
                        cout << "Price: " << inventory[i].getPrice() << endl;
                        cout << "Quantity: " << quantity << endl;
                        cout << "Total: " << totalPrice << endl;
                        cout << endl;

                        inventory[i].updateQuantity(inventory[i].getQuantity() - quantity);
                        for(int i = 0; i < cashiers.size(); i++){
                            if(toLowerCase(cashiers[i].getName()) == toLowerCase(cashier)){
                            cashiers[i].updateCash(cashiers[i].getCash() + totalPrice);
                        }
                     }

                    writeToInventoryFile();
                    writeToCashierFile();
                    return;

                }else {
                    cout << "Insufficient stock!" << endl;
                    return;
                }

            }

        }
        cout << "Item not found!" << endl;


    }
    //// Method for registering a cashier
    void addManager(string name, string password) {
        Manager newManager(name, password);
        manager.push_back(newManager);
    }


};

string toLowerCase(string str){
    string text = "";
    for(int i = 0; str[i]!= '\0'; i++){
        text += tolower(str[i]);
    }
    return text;
}


#endif // SHOP_H
