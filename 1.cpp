#include <iostream>
#include <windows.h> //for sleep()
#include <fstream>   //for file handling
#include <conio.h>   //for getch()
#include <string>
#include <iomanip> //for setw
#include <limits>
using namespace std;

// globally declared variables
string name, address, medical_history, treatment_details, admission_date;
int patient_id;
long long phone_number;
const double Treatment_cost_per_day = 0.03;

// All functions prototype
void login();
void sign_up();
void admit_patient();
void show_patient_data();
void search_patient();
void update_patient_data();
void delete_patient_data();
int input_validation(int);

int main()
{

    cout << "\n";
    cout << "\t\t\t\t" << endl;
    cout << "\t\t\t\t*=============================================*" << endl;
    cout << "\t\t\t\t*|                                           |*" << endl;
    cout << "\t\t\t\t*|                                           |*" << endl;
    cout << "\t\t\t\t*|               HOPE HOSPITAL               |*" << endl;
    cout << "\t\t\t\t*|                                           |*" << endl;
    cout << "\t\t\t\t*|                                           |*" << endl;
    cout << "\t\t\t\t*=============================================*" << endl;
    cout << "\t\t\t\t" << endl;
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t" << endl;
    cout << "\t\t\t*===============================================================================*" << endl;
    cout << "\t\t\t*|                                                                             |*" << endl;
    cout << "\t\t\t*|                                                                             |*" << endl;
    cout << "\t\t\t*|                                                                             |*" << endl;
    cout << "\t\t\t*|                                                                             |*" << endl;
    cout << "\t\t\t*|                        HOSPITAL MANAGEMENT SYSTEM                           |*" << endl;
    cout << "\t\t\t*|                                                                             |*" << endl;
    cout << "\t\t\t*|                                                                             |*" << endl;
    cout << "\t\t\t*|                                                                             |*" << endl;
    cout << "\t\t\t*|                                                     - Made By Phoenix Team  |*" << endl;
    cout << "\t\t\t*===============================================================================*" << endl;
    cout << "\t\t\t" << endl;
    cout << "\n";
    cout << "\n\n\t\tSystem is loading pls wait";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(1000); // will freeze the program for given time stores time in millisec
    }

    system("CLS"); // Clear the screen
    char select;
    cout << "\n\n\t\tSelect 1 to SIGN UP by adding username and password." << endl;
    cout << "\n\n\t\tSelect 2 to Login." << endl;
    select = getch(); // to get small characters without displaying them.
    switch (select)
    {
    case '1':
        sign_up();
        break;
    case '2':
        login();
        break;
    default:
        cout << "\n\n\t\tEnter a valid option ";
        Sleep(2000);
        system("CLS");
        main();
    }

    return 0;
}

void sign_up()
{
    while(true){
        system("CLS");
        string username, password;
        cout << "\n\n\t\tHospital Managment System : " << endl;
        cout << "\n\n\t\tPlease SIGN UP by adding username and password " << endl;
        cout << "\n\n\t\tEnter Username :  ";
        getline(cin, username);
        cout << "\n\n\t\tPassword : ";
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
            cout << "\n\tPassword must be at least 6 characters long. Please try again.";
            Sleep(2000);
            continue; // Retry sign-up
        }

        ofstream file("uspass.txt", ios::app);
        if (!file.is_open()) {
            cerr << "\n\tError opening file for saving credentials.";
            return;
        }

        file << username << "\n" << password << "\n";
        file.close();
        cout << "\n\n\t\tYour ID has been created successfully!";
        Sleep(2000);
        login(); // Proceed to login
        break;
    }
}

void login()
{
start: // start point will come here in case of logging out
    system("ClS");
    string username_1, pass_1, password, username;
    bool match = false; // bool found used to check conditions
    cout << "\n\n\t\tHospital Managment System : " << endl;
    cout << "\n\n\t\tPlease Login by adding username and password " << endl;
    cout << "\n\n\t\tEnter Username :  ";
    getline(cin, username_1);
    cout << "\n\n\t\tPassword : ";
    char pass;
    while ((pass = _getch()) != '\r')
    {
        if (pass >= 32 && pass <= 126)   // ASCII values of the characters
        {
            cout << '*';
            pass_1.push_back(pass); // push_back moves to the next character
        }
        else if (pass == 8 && pass_1.length() > 0) // 8 referes to the ASCII value of backspace
        {
            pass_1.pop_back(); // pop back moves to the previos character
            cout << "\b \b";
        }
    }
    cout << "\n";

    ifstream file;
    file.open("uspass.txt");

    if (!file.is_open())
    {
        cout << "\t Error opening file ";
    }

    while (getline(file, username) && file >> password)
    {
        if (username == username_1 && password == pass_1)
        {
            match = true;
            cout << "\n";
            cout << " \t \t \t \t Login Successful " << endl
                 << endl;
            cout << "\t\t\t===============================================================" << endl;
            cout << "\t\t\t                         Welcome Admin                        " << endl;
            cout << "\t\t\t===============================================================" << endl;
            cout << "\n";
            Sleep(3000);
        }
        file.ignore(1000, '\n'); // setting a limit of ignoring unwanted characters until newline characters(removes input buffer)
    }
    file.close();
    if (match == true)
    {
        system("cls");
    point:        // will come here if default case is used using goto
        while (1) // Condition is true  and the loop will iterate until break statement is executed
        {   system("cls");
            char choose;
            cout << "\t\t\t   --------------Choose from below-------------- " << endl;
            cout << "\t\t\t    ____________________________________________ " << endl;
            cout << "\t\t\t   |                                            |" << endl;
            cout << "\t\t\t   |   Press 1 to Admit Patient                 |" << endl;
            cout << "\t\t\t   |   Press 2 to Show Patient Data             |" << endl;
            cout << "\t\t\t   |   Press 3 for Search Patient               |" << endl;
            cout << "\t\t\t   |   Press 4 to Update Patienr  Data          |" << endl;
            cout << "\t\t\t   |   Press 5 to Delete Patient Data           |" << endl;
            cout << "\t\t\t   |   Press 6 to Logout                        |" << endl;
            cout << "\t\t\t   |____________________________________________|" << endl;
            cout<< endl;
            choose = getch();

            system("cls");
            switch (choose)
            {
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
                cout << "\n\n\t\tlogging out.Please Wait ";
                for (int y = 0; y < 4; y++)
                {
                    cout << ".";
                    Sleep(1000);   // Causes a delay in the run-time more seemed as a animation
                }
                goto start;
                break;
            default:
                cout << "\tENTER A VALID INPUT ";
                Sleep(1000);
                system("cls");
                goto point;
            }
        }
    }
    else if (match == false)
    {
        cout << "\tThe username or password is not valid";
        Sleep(1000);
        goto start;
    }
}

void admit_patient(){
    system("cls");
    cout << "Admit Patient\n";
    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Address: ";
    getline(cin, address);

    cout << "Enter Patient ID (numeric): ";
    cin >> patient_id;

    cout << "Enter Phone Number (numeric): ";
    cin>>phone_number;
    cin.ignore(); // Clear input buffer

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

    file << name << "\n" << address << "\n" << patient_id << "\n" << phone_number
         << "\n" << medical_history << "\n" << treatment_details << "\n" << admission_date << "\n";
    file.close();

    cout << "Patient admitted successfully!" << endl;
    Sleep(2000);
}

void show_patient_data(){
    system("CLS");
    cout << "Displaying All Patient Data:\n";

    ifstream file("patients.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open patient data file.\n";
        return;
    }

    string line;
    int record_count = 0;

    while (getline(file, name)) {
        getline(file, address);
        file >> patient_id;
        file.ignore();
        file >> phone_number;
        file.ignore();
        getline(file, medical_history);
        getline(file, treatment_details);
        getline(file, admission_date);
        cout << "\n";
        cout << "\n\t\t *************************************************************************" << endl;
        cout << "\t\t ||\t    Data of Patient  : " << "\t\t|| " << endl;
        cout << "\t\t ||_____________________________________________________________________||" << endl;
        cout << "\t\t ||                                                                     ||" << endl;
        cout << "\t\t || \tPatient ID: " << setw(25) << left << patient_id << "\t\t|| " << endl;
        cout << "\t\t || \tPatient Name: " << setw(25) << left << name << "\t\t|| " << endl;
        cout << "\t\t || \tAddress: " << setw(25) << left << address << "\t\t || " << endl;
        cout << "\t\t || \tPhone Number: " << setw(25) << left << phone_number << "\t\t|| " << endl;
        cout << "\t\t || \tMedical History: "<<setw(25) << left <<medical_history << "\t\t|| " << endl;
        cout << "\t\t || \tTreatment Details: " << setw(25) << left << admission_date << "\t\t|| " << endl;
        cout << "\t\t ||                                                                     ||" << endl;
        cout << "\t\t *************************************************************************" << endl;
        cout << "\n";
        record_count++;
    }
    file.close();

    if (record_count == 0) {
        cout << "No patient data available.\n";
    } else {
        cout << "Total Records: " << record_count << endl;
    }
    system("PAUSE");
}

void search_patient() {
    system("CLS");
    cout << "Search Patient by ID:\n";

    int search_id;
    cout << "Enter Patient ID to search: ";
    cin >> search_id;

    ifstream file("patients.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open patient data file.\n";
        return;
    }
    bool found = false;

    while (getline(file, name)) {
        getline(file, address);
        file >> patient_id;
        file.ignore();
        file >> phone_number;
        file.ignore();
        getline(file, medical_history);
        getline(file, treatment_details);
        getline(file, admission_date);
        if (patient_id == search_id){
            cout << "\n";
            cout << "\n\t\t ********************************************************************************" << endl;
            cout << "\t\t ||\t    Data of Patient  : " << "\t\t\t                              ||" << endl;
            cout << "\t\t ||___________________________________________________________________________||" << endl;
            cout << "\t\t ||                                                                           ||" << endl;
            cout << "\t\t || \tPatient ID            : " << setw(25) << left << patient_id << "\t\t      || " << endl;
            cout << "\t\t || \tPatient Name          : " << setw(25) << left << name << "\t\t       || " << endl;
            cout << "\t\t || \tPatient Address       : " << setw(25) << left << address << "\t\t     || " << endl;
            cout << "\t\t || \tPatient Phone number  : " << setw(25) << left << phone_number << "\t\t    || " << endl;
            cout << "\t\t || \tMedical History       : "<< setw(25) << left << medical_history << "\t\t      || " << endl;
            cout << "\t\t || \tTreatment Details     : "<<setw(25) << left << treatment_details<< "\t\t      || " << endl;
            cout << "\t\t || \tAdmission Date        : "  << setw(25) << left << admission_date<< "\t\t      || " << endl;
            cout << "\t\t ||                                                                           ||" << endl;
            cout << "\t\t *******************************************************************************" << endl;
            cout << "\n";
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "No patient found with ID: " << search_id << endl;
    }

    system("PAUSE");
}

void update_patient_data() {
    system("CLS");
    cout << "Update Patient Data:\n";

    int search_id;
    cout << "Enter Patient ID to update: ";
    cin >> search_id;
    cin.ignore();

    ifstream file("patients.txt");
    ofstream temp_file("temp.txt");

    if (!file.is_open() || !temp_file.is_open()) {
        cerr << "Error: Unable to open files.\n";
        return;
    }

    bool found = false;

    while (getline(file, name)) {
        getline(file, address);
        file >> patient_id;
        file.ignore();
        file >> phone_number;
        file.ignore();
        getline(file, medical_history);
        getline(file, treatment_details);
        getline(file, admission_date);

        if (patient_id == search_id) {
            found = true;
            cout << "\nUpdating Patient ID: " << patient_id << endl;

            cout << "Enter new Name (press Enter to keep current): ";
            string new_name;
            getline(cin, new_name);
            if (!new_name.empty()) name = new_name;

            cout << "Enter new Address (press Enter to keep current): ";
            string new_address;
            getline(cin, new_address);
            if (!new_address.empty()) address = new_address;

            cout << "Enter new Phone Number (press Enter to keep current): ";
            string phone_str;
            getline(cin, phone_str);
            if (!phone_str.empty()) phone_number = stoll(phone_str);

            cout << "Enter new Medical History (press Enter to keep current): ";
            string new_history;
            getline(cin, new_history);
            if (!new_history.empty()) medical_history = new_history;

            cout << "Enter new Treatment Details (press Enter to keep current): ";
            string new_treatment;
            getline(cin, new_treatment);
            if (!new_treatment.empty()) treatment_details = new_treatment;

            cout << "Enter new Admission Date (press Enter to keep current): ";
            string new_date;
            getline(cin, new_date);
            if (!new_date.empty()) admission_date = new_date;
        }

        temp_file << name << "\n" << address << "\n" << patient_id << "\n"
                  << phone_number << "\n" << medical_history << "\n"
                  << treatment_details << "\n" << admission_date << "\n";
    }

    file.close();
    temp_file.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (found) {
        cout << "\nPatient data updated successfully.\n";
    } else {
        cout << "\nPatient ID not found.\n";
    }

    system("PAUSE");
}

void delete_patient_data() {
    system("CLS");
    cout << "Delete Patient Data:\n";

    int search_id;
    cout << "Enter Patient ID to delete: ";
    cin >> search_id;

    ifstream file("patients.txt");
    ofstream temp_file("temp.txt");

    if (!file.is_open() || !temp_file.is_open()) {
        cerr << "Error: Unable to open files.\n";
        return;
    }

    bool found = false;

    while (getline(file, name)) {
        getline(file, address);
        file >> patient_id;
        file.ignore();
        file >> phone_number;
        file.ignore();
        getline(file, medical_history);
        getline(file, treatment_details);
        getline(file, admission_date);

        if (patient_id == search_id) {
            cout << "\nPatient ID " << search_id << " deleted successfully.\n";
            found = true;
            continue; // Skip writing this record to the temp file
        }

        temp_file << name << "\n" << address << "\n" << patient_id << "\n"
                  << phone_number << "\n" << medical_history << "\n"
                  << treatment_details << "\n" << admission_date << "\n";
    }

    file.close();
    temp_file.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (!found) {
        cout << "\nPatient ID not found.\n";
    }

    system("PAUSE");
}

int input_validation(int num) {
    while (true) {
        if (cin.fail()) {
            cout << "Error! Please enter a valid integer." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(132, '\n'); // Ignore invalid input
            cin >> num; // Try to read again
        } else {
            return num; // Valid input received
        }
    }
}