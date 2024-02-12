//shoppingList
//1.Create a new list
//2. show all list
// -active
// -deactive
// -all
//3. pick one of in list
// -shoowing list
// -deleting list
//4. delete all list
//5. save
//6.make list active or diactive

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


struct List {
    string nameOfMaterial;
    double quantity = 0.0;
    bool active =true;
};

vector<List> lists; 

void CreateNewList() {
    cout << "CREATING NEW LIST" << endl;
    cout << endl;

    List newList; 
    cout << "What's The Name Of Material?" << endl;
    cin >> newList.nameOfMaterial;
    cout << "How Many/Much Do You Want To Take?" << endl;
    cin >> newList.quantity;
    newList.active = true;

    lists.push_back(newList); 
}

void ShowAllLists() {
    cout << "Which list would you like to see?" << endl;
    cout << "1. Active" << endl;
    cout << "2. Deactive" << endl;
    cout << "3. All" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        for (size_t i = 0; i < lists.size(); i++) {
            if (lists[i].active = true) {
                cout << i + 1 << ". Name Of Material: " << lists[i].nameOfMaterial << endl;
                cout << i + 1 << ". Quantity Of Material: " << lists[i].quantity << endl;
                cout << endl;
            }
        }
        break;
    case 2:
        for (size_t i = 0; i < lists.size(); i++) {
            if (lists[i].active = false) {
                cout << i + 1 << ". Name Of Material: " << lists[i].nameOfMaterial << endl;
                cout << i + 1 << ". Quantity Of Material: " << lists[i].quantity << endl;
                cout << endl;
            }
        }
        break;
    case 3:
        cout << "ALL LISTS" << endl;
        cout << endl;

        for (size_t i = 0; i < lists.size(); i++) {
            cout << i + 1 << ". Name Of Material: " << lists[i].nameOfMaterial << endl;
            cout << i + 1 << ". Quantity Of Material: " << lists[i].quantity << endl;
            cout << endl;
        }
    }

    
}
void ShowPickedList() {
    size_t selectedList;
    size_t newSelectedList;
    cout << "Selecet a list which is you want to see" << endl;

    cin >> selectedList;
    cout << "What would you do with this list?" << endl;
    cout << "1. Show it" << endl;
    cout << "2. Delete it" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        if (selectedList <= 0 && selectedList > lists.size()) {
            cout << "There is no list which is you picked, please select an available list.";
            cin >> newSelectedList;
            selectedList = newSelectedList;

            cout << "Selected List Is:" << endl;
            cout << "Name Of Material: " << lists[selectedList - 1].nameOfMaterial << endl;
            cout << "Quantity: " << lists[selectedList - 1].quantity << endl;
            cout << endl;
        }
        else {

            cout << "Selected List Is:" << endl;
            cout << "Name Of Material: " << lists[selectedList - 1].nameOfMaterial << endl;
            cout << "Quantity: " << lists[selectedList - 1].quantity << endl;
            cout << endl;
            break;

        }
    case 2:
        lists.erase(lists.begin() + selectedList - 1);
        cout << " The list has been delete." << endl;
    }
    
   
}
void deleteAllList() {
    for (size_t i = 0; i < lists.size(); i++) {
        lists.erase(lists.begin() + i);
        --i;
    }
}
void save() {
    ofstream outfile("lists.txt");  

    if (outfile.is_open()) {
        for (const List& list : lists) {
            outfile << list.nameOfMaterial << endl;
            outfile << list.quantity << endl;
        }
        outfile.close();
        cout << "Lists saved to lists.txt successfully!" << endl;
    }
    else {
        cerr << "Error opening file for saving lists." << endl;
    }
}
void ActiveorInactive() {
    cout << "Enter the list which is you want to change it condition " << endl;
    int choice;
    cin >> choice;
    cout << choice + 1 << ". "<< (lists[choice].active ? "Active" : "Inactive") << endl;
    cout << "What would you like to do , Active or Inactive?" << endl;
    cout << "1. Active" << endl;
    cout << "2. Inactive" << endl;
    bool userChoice;
    cin >> userChoice;
    lists[choice - 1].active = userChoice;
    cout << "Update is succesful" << endl;
}

int main() {
    
    int choice;
    do {
        cout << "MENU" << endl;
        cout << "1. Create a new list" << endl;
        cout << "2. Show all lists" << endl;
        cout << "3. pick one in the list" << endl;
        cout << "4. Delete All list" << endl;
        cout << "5. Save Lists" << endl;
        cout << "6. Make List Active or Inactive" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            CreateNewList();
            break;
        case 2:
            ShowAllLists();
            break;
        case 3:
            ShowPickedList();
            break;
        case 4:
            deleteAllList();
            break;
        case 5:
            save();
            break;
        case 6:
            ActiveorInactive();
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);

    return 0;
}

