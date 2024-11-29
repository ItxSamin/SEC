#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Global variables
string name, address, medical_history, treatment_details, admission_date;
int patient_id,age;

// Function prototypes
void login();
void sign_up();
void main_menu();
void admit_patient();
void show_patient_data();
void search_patient();
void update_patient_data();
void delete_patient_data();
int input_validation();

int main() {
    while (true) {
        system("CLS");
        cout << "\n";
        cout << "\t\t\t*=============================================*\n";
        cout << "\t\t\t*               HOPE HOSPITAL                 *\n";
        cout << "\t\t\t*=============================================*\n";
        cout << "\n";
        cout << "\n\t\tWelcome to the Hospital Management System\n";
        cout << "\n\t\t1. SIGN UP\n";
        cout << "\t\t2. LOGIN\n";
        cout << "\t\t3. EXIT\n";
        cout << "\n\t\tEnter your choice: ";
        
        char choice = getch();
        switch (choice) {
            case '1':
                sign_up();
                break;
            case '2':
                login();
                break;
            case '3':
                cout << "\nExiting the system. Goodbye!\n";
                exit(0);
            default:
                cout << "\nInvalid input. Please try again.\n";
                Sleep(2000);
        }
    }
    return 0;
}

// Sign-up function
void sign_up() {
    system("CLS");
    string username, password;
    while (true) {
        cout << "\n\t\tHospital Management System - SIGN UP\n";
        cout << "\n\t\tEnter Username: ";
        getline(cin, username);

        cout << "\n\t\tEnter Password (at least 6 characters): ";
        char ch;
        password = "";
        while ((ch = _getch()) != '\r') { // Enter key
            if (ch >= 32 && ch <= 126) {
                cout << '*';
                password += ch;
            } else if (ch == 8 && !password.empty()) { // Backspace
                password.pop_back();
                cout << "\b \b";
            }
        }
        cout << endl;

        if (password.length() < 6) {
            cout << "\nPassword must be at least 6 characters long. Please try again.\n";
            Sleep(2000);
            continue;
        }

        ofstream file("uspass.txt", ios::app);
        if (!file.is_open()) {
            cerr << "\nError opening file for saving credentials.\n";
            return;
        }
        file << username << "\n" << password << "\n";
        file.close();

        cout << "\nYour account has been created successfully!\n";
        Sleep(2000);
        return;
    }
}

// Login function
void login() {
    system("CLS");
    string username, password, file_username, file_password;
    bool is_logged_in = false;

    cout << "\n\t\tHospital Management System - LOGIN\n";
    cout << "\n\t\tEnter Username: ";
    getline(cin, username);

    cout << "\n\t\tEnter Password: ";
    char ch;
    password = "";
    while ((ch = _getch()) != '\r') {
        if (ch >= 32 && ch <= 126) {
            cout << '*';
            password += ch;
        } else if (ch == 8 && !password.empty()) {
            password.pop_back();
            cout << "\b \b";
        }
    }
    cout << endl;

    ifstream file("uspass.txt");
    if (!file.is_open()) {
        cerr << "\nError opening credentials file.\n";
        return;
    }

    while (getline(file, file_username) && getline(file, file_password)) {
        if (file_username == username && file_password == password) {
            is_logged_in = true;
            break;
        }
    }
    file.close();

    if (is_logged_in) {
        cout << "\nLogin successful! Welcome, " << username << ".\n";
        Sleep(2000);
        main_menu();
    } else {
        cout << "\nInvalid username or password. Please try again.\n";
        Sleep(2000);
    }
}

// Main menu function
void main_menu() {
    while (true) {
        system("CLS");
        cout << "\n\t\tHospital Management System - Main Menu\n";
        cout << "\n\t\t1. Admit Patient\n";
        cout << "\t\t2. Show All Patients\n";
        cout << "\t\t3. Search Patient\n";
        cout << "\t\t4. Update Patient\n";
        cout << "\t\t5. Delete Patient\n";
        cout << "\t\t6. Logout\n";
        cout << "\n\t\tEnter your choice: ";
        
        char choice = getch();
        switch (choice) {
            case '1':
                admit_patient();
                break;
            case '2':
                show_patient_data();
                break;
            case '3':
                search_patient();
                break;
            case '4':
                update_patient_data();
                break;
            case '5':
                delete_patient_data();
                break;
            case '6':
                return; // Logout
            default:
                cout << "\nInvalid input. Please try again.\n";
                Sleep(2000);
        }
    }
}

// Admit patient function
void admit_patient() {
    system("CLS");
    cout << "Admit Patient:\n";

    cout << "Enter Patient Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear leftover newline in the input buffer
    getline(cin, name);

    cout << "Enter Address: ";
    getline(cin, address);

    cout << "Enter Patient ID (numeric): ";
    patient_id = input_validation();

    cout << "Enter Patient age (numeric): ";
    age = input_validation();

    cout << "Enter Medical History: ";
    getline(cin, medical_history);

    cout << "Enter Treatment Details: ";
    getline(cin, treatment_details);

    cout << "Enter Admission Date (YYYY-MM-DD): ";
    getline(cin, admission_date);

    ofstream file("patients.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error opening patient file.\n";
        return;
    }

    file << name << "\n" << address << "\n" << patient_id << "\n"
         << age << "\n" << medical_history << "\n"
         << treatment_details << "\n" << admission_date << "\n";
    file.close();

    cout << "\nPatient admitted successfully!\n";
    Sleep(2000);
}

// Display all patient data
void show_patient_data() {
    system("CLS");
    cout << "Displaying All Patient Data:\n";

    ifstream file("patients.txt");
    if (!file.is_open()) {
        cerr << "Error opening patient data file.\n";
        return;
    }

    int count = 0;
    while (getline(file, name)) {
        getline(file, address);
        file >> patient_id;
        file.ignore();
        file >> age;
        file.ignore();
        getline(file, medical_history);
        getline(file, treatment_details);
        getline(file, admission_date);

        cout << "\n-----------------------------\n";
        cout << "Patient ID: " << patient_id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Address: " << address << "\n";
        cout << "Age: " << age << "\n";
        cout << "Medical History: " << medical_history << "\n";
        cout << "Treatment Details: " << treatment_details << "\n";
        cout << "Admission Date: " << admission_date << "\n";
        cout << "-----------------------------\n";

        count++;
    }
    file.close();

    if (count == 0) {
        cout << "No patient data available.\n";
    }
    system("PAUSE");
}

// Search patient by ID
void search_patient() {
    system("CLS");
    cout << "Search Patient by ID:\n";

    cout << "Enter Patient ID: ";
    int search_id = input_validation();

    ifstream file("patients.txt");
    if (!file.is_open()) {
        cerr << "Error opening patient data file.\n";
        return;
    }

    bool found = false;
    while (getline(file, name)) {
        getline(file, address);
        file >> patient_id;
        file.ignore();
        file >> age;
        file.ignore();
        getline(file, medical_history);
        getline(file, treatment_details);
        getline(file, admission_date);

        if (patient_id == search_id) {
            cout << "\nPatient Found:\n";
            cout << "Patient ID: " << patient_id << "\n";
            cout << "Name: " << name << "\n";
            cout << "Address: " << address << "\n";
            cout << "Age: " << age << "\n";
            cout << "Medical History: " << medical_history << "\n";
            cout << "Treatment Details: " << treatment_details << "\n";
            cout << "Admission Date: " << admission_date << "\n";
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Patient not found.\n";
    }
    system("PAUSE");
}

// Update patient data
void update_patient_data() {
    system("CLS");
    cout << "Update Patient Data:\n";

    cout << "Enter Patient ID to update: ";
    int search_id = input_validation();

    ifstream file("patients.txt");
    ofstream temp("temp.txt");
    if (!file.is_open() || !temp.is_open()) {
        cerr << "Error opening files.\n";
        return;
    }

    bool found = false;
    while (getline(file, name)) {
        getline(file, address);
        file >> patient_id;
        file.ignore();
        file >> age;
        file.ignore();
        getline(file, medical_history);
        getline(file, treatment_details);
        getline(file, admission_date);

        if (patient_id == search_id) {
            found = true;
            cout << "\nEnter new Name (leave blank to keep current): ";
            string new_name;
            getline(cin.ignore(), new_name);
            if (!new_name.empty()) name = new_name;

            cout << "Enter new Address (leave blank to keep current): ";
            string new_address;
            getline(cin, new_address);
            if (!new_address.empty()) address = new_address;

            cout << "Enter new Age (leave blank to keep current): ";
            string age_str;
            getline(cin, age_str);
            if (!age_str.empty()) age = stoll(age_str);

            cout << "Enter new Medical History (leave blank to keep current): ";
            string new_history;
            getline(cin, new_history);
            if (!new_history.empty()) medical_history = new_history;

            cout << "Enter new Treatment Details (leave blank to keep current): ";
            string new_treatment;
            getline(cin, new_treatment);
            if (!new_treatment.empty()) treatment_details = new_treatment;

            cout << "Enter new Admission Date (leave blank to keep current): ";
            string new_date;
            getline(cin, new_date);
            if (!new_date.empty()) admission_date = new_date;
        }

        temp << name << "\n" << address << "\n" << patient_id << "\n"
             << age << "\n" << medical_history << "\n"
             << treatment_details << "\n" << admission_date << "\n";
    }

    file.close();
    temp.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (found) {
        cout << "Patient data updated successfully.\n";
    } else {
        cout << "Patient ID not found.\n";
    }
    system("PAUSE");
}

// Delete patient data
void delete_patient_data() {
    system("CLS");
    cout << "Delete Patient Data:\n";

    cout << "Enter Patient ID to delete: ";
    int search_id = input_validation();

    ifstream file("patients.txt");
    ofstream temp("temp.txt");
    if (!file.is_open() || !temp.is_open()) {
        cerr << "Error opening files.\n";
        return;
    }

    bool found = false;
    while (getline(file, name)) {
        getline(file, address);
        file >> patient_id;
        file.ignore();
        file >> age;
        file.ignore();
        getline(file, medical_history);
        getline(file, treatment_details);
        getline(file, admission_date);

        if (patient_id == search_id) {
            cout << "Patient record deleted successfully.\n";
            found = true;
            continue;
        }

        temp << name << "\n" << address << "\n" << patient_id << "\n"
             << age << "\n" << medical_history << "\n"
             << treatment_details << "\n" << admission_date << "\n";
    }

    file.close();
    temp.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (!found) {
        cout << "Patient ID not found.\n";
    }
    system("PAUSE");
}

// Input validation function
int input_validation() {
    int num;
    while (true) {
        if (!(cin >> num) || num <= 0) {
            cout << "Invalid input. Please enter a valid number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            return num;
        }
    }
}
