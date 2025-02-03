#include<iostream>
using namespace std;

class employee {
    int id;
    string name, address;
    employee *LC, *RC; 
public:
    void create();
    void insert(employee *, employee *);
    void display(employee *);
} *root; 

void employee::create() {
    int ch;
    employee *next;
    root = new employee;
    cout << "Enter the employee details: " << endl;
    cin >> root->id >> root->name;
    root->LC = root->RC = NULL;
    
    do {
        cout << "Do you want to enter more employee information? {YES(1) / NO(0)} " << endl;
        cin >> ch;
        if(ch == 1) {
            next = new employee;
            cout << "Enter the employee details: " << endl;
            cin >> next->id >> next->name; 
            next->LC = next->RC = NULL;
            insert(root, next);
        }
    } while(ch == 1);
}

void employee::insert(employee *root, employee *next) {
    char c;
    cout << "Insert at LEFT('L' OR 'l') OR Insert at RIGHT('R' OR 'r')"<< endl;
    cin >> c;
    if(c == 'L' || c == 'l') { 
        if(root->LC == NULL) {
            root->LC = next;
        } else {
            insert(root->LC, next);
        }
    } else if(c == 'R' || c == 'r') { 
        if(root->RC == NULL) {
            root->RC = next;
        } else {
            insert(root->RC, next);
        }
    }
}

void employee::display(employee *root) {
    if(root != NULL) {
        display(root->LC); 
        cout << "ID: " << root->id << ", Name: " << root->name << endl; 
        display(root->RC); 
    }
}

int main() {
    employee emp;
    emp.create();
    cout << "Employee details in the tree: " << endl;
    emp.display(root); 
    return 0;
}
