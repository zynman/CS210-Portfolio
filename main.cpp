/* Victor Curran 2/26/24
Project 7-3 */



#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> frequency_item; 
    ifstream input_file("CS210_Project_Three_Input_File.txt"); 
    ofstream output_file("frequency.dat"); 

    string item;
    while (input_file >> item) {
        ++frequency_item[item];
    }

    for (auto i : frequency_item) {
        output_file << i.first << ' ' << i.second << endl;
    }

    int option;
    do {
        cout << "----------------- Menu - Option -----------------:" << endl;
        cout << "1. Frequency of an item" << endl;
        cout << "2. Print Frequency of items" << endl;
        cout << "3. Print histogram of items" << endl;
        cout << "4. Exit Program" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        switch (option) {
        case 1: {
            string find_item;
            cout << "Enter the item you wish to find frequency: ";
            cin >> find_item;
            cout << find_item << " appears " << frequency_item[find_item] << " times." << endl;
            break;
        }
        case 2: {
            cout << "Item Frequency" << endl;
            for (auto i : frequency_item) {
                cout << i.first << ' ' << i.second << endl;
            }
            break;
        }
        case 3: {
            cout << "Item Histogram" << endl;
            for (auto i : frequency_item) {
                cout << i.first << " ";
                for (int j = 0; j < i.second; ++j) {
                    cout << "*";
                }
                cout << endl;
            }
            break;
        }
        case 4: {
            break;
        }
        default: {
            cout << "Invalid. Enter again." << endl;
            break;
        }
        }
    } while (option != 4);

    return 0;
}