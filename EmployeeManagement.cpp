#include <iostream>
#include <windows.h> //for sleep()
#include <fstream>   //for file handling
#include <conio.h>   //for getch()
#include <string>
#include <iomanip> //for setw
using namespace std;

// globally declared variables
string name, address;
string designation;
int id, total_leaves;
long long number, salary;
const double Leave_deduction_perc = 0.03;

// All functions prototype
void login();
void sign_up();
void data_enter();
void show_data();
void search_data();
void leave_managment();
void update_data();
void Delete_data();
void allot_bonus();
int InputValidation(int);

int main()
{

    cout << "\n";
    cout << "\t\t\t\t*************************************************" << endl;
    cout << "\t\t\t\t**=============================================**" << endl;
    cout << "\t\t\t\t**|                                           |**" << endl;
    cout << "\t\t\t\t**|           MAG Inc, Corporation            |**" << endl;
    cout << "\t\t\t\t**|                                           |**" << endl;
    cout << "\t\t\t\t**|                                           |**" << endl;
    cout << "\t\t\t\t**=============================================**" << endl;
    cout << "\t\t\t\t*************************************************" << endl;
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t***********************************************************************************" << endl;
    cout << "\t\t\t**===============================================================================**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                        EMPLOYEE MANAGEMENT SYSTEM                           |**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                                                     - Made By Mahad Team    |**" << endl;
    cout << "\t\t\t**===============================================================================**" << endl;
    cout << "\t\t\t***********************************************************************************" << endl;
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
point: // point0 declared here will come here if username requirements not met
    system("CLS");
    string username, password;
    cout << "\n\n\t\tEmployee Managment System : " << endl;
    cout << "\n\n\t\tPlease SIGN UP by adding username and password " << endl;
    cout << "\n\n\t\tEnter Username :  ";
    getline(cin, username);
    cout << "\n\n\t\tPassword : ";
    char pass;
    while ((pass = _getch()) != '\r') // loop will execute for each character until enter is pressed
    {
        if (pass >= 32 && pass <= 126)
        {
            cout << '*';
            password.push_back(pass); // will add new character.
        }
        else if (pass == 8 && password.length() > 0) // dealing with if backspace is pressed
        {
            password.pop_back(); // will remove last charcter
            cout << "\b \b";
        }
    }
    if (password.length() < 6)
    {
        cout << " \t The password length should be more than 5  " << endl;
        Sleep(2000);
        goto point;
    }

    fstream file;
    file.open("uspass.txt", ios::out | ios::app);
    if (!file.is_open())
    {
        cout << "\tError opening file.";
    }

    file << username << "\n";
    file << password << "\n";
    file.close();
    cout << "\n\n\t\tYour ID is being created.Please Wait ";
    for (int i = 0; i < 4; i++)
    {
        cout << ".";
        Sleep(1000);
    }
    cout << "\n\n\t\tYour ID HAS BEEN CREATED ";

    login(); // login function called.
}

void login()
{
start: // start point will come here in case of logging out
    system("ClS");
    string username_1, pass_1, password, username;
    bool match = false; // bool found used to check conditions
    cout << "\n\n\t\tEmployee Managment System : " << endl;
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
            break;
            cout << "\n";
            cout << " \t \t \t \t Login Successful " << endl
                 << endl;
            cout << "\t\t\t===============================================================" << endl;
            cout << "\t\t\t                         Welcome Admin                         " << endl;
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
        {

            char choose;
            cout << "\t\t\t   --------------Choose from below-------------- " << endl;
            cout << "\t\t\t    ____________________________________________ " << endl;
            cout << "\t\t\t   |                                            |" << endl;
            cout << "\t\t\t   |   Press 1 to Add Employee  Data            |" << endl;
            cout << "\t\t\t   |   Press 2 to Show Employee Data            |" << endl;
            cout << "\t\t\t   |   Press 3 to Search Employee  Data         |" << endl;
            cout << "\t\t\t   |   Press 4 for Leave managment              |" << endl;
            cout << "\t\t\t   |   Press 5 to Update Employee  Data         |" << endl;
            cout << "\t\t\t   |   Press 6 to Delete Employee Data          |" << endl;
            cout << "\t\t\t   |   Press 7 to Allot bonus                   |" << endl;
            cout << "\t\t\t   |   Press 8 to Logout                        |" << endl;
            cout << "\t\t\t   |____________________________________________|" << endl;
            choose = getch();

            system("CLS");
            switch (choose)
            {
            case '1':
                data_enter();
                break;
            case '2':
                show_data();
                break;
            case '3':
                search_data();
                break;
            case '4':
                leave_managment();
                break;
            case '5':
                update_data();
                break;
            case '6':
                Delete_data();
                break;
            case '7':
                allot_bonus();
                break;
            case '8':
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

void data_enter()
{
    int choice;
    cout << "\tEnter the number of employees whose data you want to enter ";
    cin >> choice;

    for (int i = 0; i < choice; i++)
    {
        cout << "\tEnter data of employee : " << i + 1 << endl;
        cout << "\tEnter the name of the employee :";
        cin.ignore();
        getline(cin, name);
        cout << "\tEnter Employee designation :";
        getline(cin, designation);
        cout << "\tEnter Employee id : ";
        cin >> id;
        if (cin.fail())
        {
            cout << "Please provide id in integers only ";
            return;
        }
        cout << "\tEnter employee address : ";
        cin.ignore();
        getline(cin, address);
        cout << "\tEnter employee Phone number :";
        cin >> number;
        cout << "\tEnter Employee Salary :$";
        cin >> salary;
    back: // point back declared here will come come here if input total leave is -ive
        cout << "\tNumber of leaves alloted to the employee :";
        cin >> total_leaves;
        cout << " \n";
        if (total_leaves < 0)
        {
            cout << "\tInvalid input. total leaves cannot be negative." << endl;
            Sleep(1000);
            goto back;
        }
        ofstream file;
        file.open("employees.txt", ios::app);

        if (!file.is_open())    // If the file is not opened also help in debugging by getting a prompt of faliure in file opwening
        {
            cout << "\tError opening file.";
        }

        file << " " << name << "\n";
        file << " " << designation << "\n";
        file << " " << id << "\n";
        file << " " << address << "\n";
        file << " " << number << "\n";
        file << " " << salary << "\n";
        file << " " << total_leaves << "\n";
        file.close();
    }
}

void show_data()
{

    fstream file;
    bool match = false;
    int i = 0;
    file.open("employees.txt", ios::in);

    if (file.is_open())
    {

        file.ignore();
        getline(file, name);
        getline(file, designation);
        file >> id;
        file.ignore();
        getline(file, address);
        file >> number;
        file >> salary;
        file >> total_leaves;

        while (!file.eof())   // .eof() take us to the end of the file having a ! with it reverse the functioning and we get started frim the start of the file
        {
            cout << "\n";
            cout << "\n\t\t *************************************************************************" << endl;
            cout << "\t\t ||\t    Data of Employee  : " << i + 1 << "\t\t\t\t\t|| " << endl;
            cout << "\t\t ||_____________________________________________________________________||" << endl;
            cout << "\t\t ||                                                                     ||" << endl;
            cout << "\t\t || \tEmployee Name         : " << setw(25) << left << name << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee Designation  : " << setw(25) << left << designation << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee ID           : " << setw(25) << left << id << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee Address      : " << setw(25) << left << address << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee Phone Number : " << setw(25) << left << number << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee Salary       : $" << setw(25) << left << salary << "\t\t|| " << endl;
            cout << "\t\t || \tAllocated leaves      : " << setw(25) << left << total_leaves << "\t\t|| " << endl;
            cout << "\t\t ||                                                                     ||" << endl;
            cout << "\t\t *************************************************************************" << endl;
            cout << "\n";
            file.ignore();
            getline(file, name);
            getline(file, designation);
            file >> id;
            file.ignore();
            getline(file, address);
            file >> number;
            file >> salary;
            file >> total_leaves;
            match = true;
            i++;
        }
        file.close();
    }
    else
    {
        cout << "\tError opening file " << endl;
    }
    if (match == false)
    {
        cout << "\t No data present to show " << endl;
    }
}

void leave_managment()
{
    int search_id, availed_leaves, left_leaves, extra_leaves, deducted_salary, approved_leaves;
    char leave_approval;

    bool found = false;
    cout << "\tEnter the id of the employee whose leaves want to managed : ";
    cin >> search_id;

    
    fstream file; // USed for reading and writing data to file
    int i = 0;
    file.open("employees.txt", ios::in);

    if (!file.is_open())
    {
        cout << "\tError opening file.";
    }

    file.ignore();
    getline(file, name);
    getline(file, designation);
    file >> id;
    file.ignore();
    getline(file, address);
    file >> number;
    file >> salary;
    file >> total_leaves;

    while (!file.eof())
    {
        if (search_id == id)
        {

            cout << "\n";
            cout << "\n\t\t *************************************************************************" << endl;
            cout << "\t\t ||\t    Data of Employee  : " << search_id << "\t\t\t\t\t|| " << endl;
            cout << "\t\t ||_____________________________________________________________________||" << endl;
            cout << "\t\t ||                                                                     ||" << endl;
            cout << "\t\t || \tEmployee Name         : " << setw(25) << left << name << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee Designation  : " << setw(25) << left << designation << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee ID           : " << setw(25) << left << id << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee Address      : " << setw(25) << left << address << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee Phone Number : " << setw(25) << left << number << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee Salary       : $" << setw(25) << left << salary << "\t\t|| " << endl;
            cout << "\t\t || \tAllocated leaves      : " << setw(25) << left << total_leaves << "\t\t|| " << endl;
            cout << "\t\t ||                                                                     ||" << endl;
            cout << "\t\t *************************************************************************" << endl;
            cout << "\n";
            found = true;
            break;
        }

        file.ignore();
        getline(file, name);
        getline(file, designation);
        file >> id;
        file.ignore();
        getline(file, address);
        file >> number;
        file >> salary;
        file >> total_leaves;
    }
    file.close();

    if (found == false)
    {
        cout << "\tData of this id id not present";
    }
    if (found == true)
    {
    start: // start declared here will come here if avialed leaves is negative.
        cout << "\n\tEnter the no of leaves availed ";
        cin >> availed_leaves;
        if (availed_leaves < 0)
        {
            cout << "\tInvalid input. Leaves availed cannot be negative." << endl;
            Sleep(2000);
            goto start;
        }

        // The given statements are executed when the leave are greater than 0
        if (availed_leaves <= total_leaves)
        {
            left_leaves = total_leaves - availed_leaves;
            cout << "\tleaves remaining " << left_leaves;
        }
        else if (total_leaves < availed_leaves)
        {
            extra_leaves = availed_leaves - total_leaves;
            cout << "\tYour extra leaves are " << extra_leaves << endl;
            cout << "\tIf leave was approved [Y or y for approval] :";
            cin >> leave_approval;

            if (leave_approval == 'y' || leave_approval == 'Y')
            {
                cout << "\tHow many leaves have been approved ";
                cin >> approved_leaves;
                extra_leaves = extra_leaves - approved_leaves;
            }
            else
            {
                cout << "\tleave not approved " << endl;
                extra_leaves = extra_leaves;
            }

            cout << "\tYour extra leaves are " << extra_leaves << endl;

            deducted_salary = salary * Leave_deduction_perc; // 0.03 percent will be deducted in case of a extra leave if not approved.

            for (int i = 0; i < extra_leaves; i++)
            {
                salary = salary - deducted_salary;
            }

            cout << "\tSalary after deduction is :" << salary << endl;
        }
    }
}

void search_data() 
{

    int search_id;
    cout << "\tSearch the data by entering the id : ";
    cin >> search_id;

    fstream file;
    int i = 0;
    file.open("employees.txt", ios::in);

    // Faliure in opening of the file
    if (!file.is_open())
    {
        cout << "\tError opening file.";
    }

    file.ignore();
    getline(file, name);
    getline(file, designation);
    file >> id;
    file.ignore();
    getline(file, address);
    file >> number;
    file >> salary;
    file >> total_leaves;

    while (!file.eof())
    {
        if (search_id == id)
        {

            cout << "\n";
            cout << "\n\t\t *************************************************************************" << endl;
            cout << "\t\t ||\t    Data of Employee  : " << search_id << "\t\t\t\t\t|| " << endl;
            cout << "\t\t ||_____________________________________________________________________||" << endl;
            cout << "\t\t ||                                                                     ||" << endl;
            cout << "\t\t || \tEmployee Name         : " << setw(25) << left << name << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee Designation  : " << setw(25) << left << designation << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee ID           : " << setw(25) << left << id << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee Address      : " << setw(25) << left << address << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee Phone Number : " << setw(25) << left << number << "\t\t|| " << endl;
            cout << "\t\t || \tEmployee Salary       : $" << setw(25) << left << salary << "\t\t|| " << endl;
            cout << "\t\t || \tAllocated leaves      : " << setw(25) << left << total_leaves << "\t\t|| " << endl;
            cout << "\t\t ||                                                                     ||" << endl;
            cout << "\t\t *************************************************************************" << endl;
            cout << "\n";
            i++;
            break;
        }

        file.ignore();
        getline(file, name);
        getline(file, designation);
        file >> id;
        file.ignore();
        getline(file, address);
        file >> number;
        file >> salary;
        file >> total_leaves;
    }

    file.close();

    if (i == 0)
    {
        cout << "\tData of this id id not present";
    }
}

void update_data()
{
    int promote_id, choice, choose;
    int i = 0;

    cout << "\tEnter the employee ID to update data: ";
    cin >> promote_id;

    fstream file, file_1;
    file.open("employees.txt", ios::in);

    if (!file.is_open())
    {
        cout << "\tError opening file.";
    }

    file_1.open("promote.txt", ios::out);

    if (!file_1.is_open())
    {
        cout << "\tError opening file.";
    }

    file.ignore();
    getline(file, name);
    getline(file, designation);
    file >> id;
    file.ignore();
    getline(file, address);
    file >> number;
    file >> salary;
    file >> total_leaves;

    while (!file.eof())
    {
        if (promote_id == id)
        {
            cout << "\n\t\t   Employee ID found. Update the information" << endl;
            cout << "\n\t\t  What do you want to update ";
            cout << "\n\t\t\t   -------------Choose from below------------- " << endl;
            cout << "\n\t\t    __________________________________________ ";
            cout << "\n\t\t   |                                          |";
            cout << "\n\t\t   |  1--> Designation                        |"
                 << "\n\t\t   |  2--> Address                            |"
                 << "\n\t\t   |  3--> Phone Number                       |"
                 << "\n\t\t   |  4--> Salary                             |"
                 << "\n\t\t   |  5--> Total Leaves                       |";
            cout << "\n\t\t   |__________________________________________|" << endl;
            cin >> choose;

            choice = InputValidation(choose); // Function called for input validation

            system("CLS");
            switch (choice)
            {
            case 1:
                cout << "\tEnter the new designation: ";
                cin.ignore();
                getline(cin, designation);
                break;

            case 2:
                cout << "\n\tEnter the new address: ";
                cin.ignore();
                getline(cin, address);
                break;

            case 3:
                cout << "\n\tEnter the new phone number: ";
                cin >> number;
                break;

            case 4:
                cout << "\n\tEnter the new salary: ";
                cin >> salary;
                break;

            case 5:
                cout << "\n\tEnter the new total leaves: ";
                cin >> total_leaves;
                break;

            default:
                cout << "\n\t Invalid Input .No such update of data available" << endl;
                system("CLS");
            }

            i++;
        }

        file_1 << " " << name << "\n";
        file_1 << " " << designation << "\n";
        file_1 << " " << id << "\n";
        file_1 << " " << address << "\n";
        file_1 << " " << number << "\n";
        file_1 << " " << salary << "\n";
        file_1 << " " << total_leaves << "\n";

        file.ignore();
        getline(file, name);
        getline(file, designation);
        file >> id;
        file.ignore();
        getline(file, address);
        file >> number;
        file >> salary;
        file >> total_leaves;
    }

    file.close();
    file_1.close();

    remove("employees.txt");
    rename("promote.txt", "employees.txt");

    // Show prompt that the data of the employee is updated successfully
    if (i++)
    {
        cout << "\tData Updated Successfully."
             << " Employee Promoted Successfully " << endl;
    }
    else
    {
        cout << "\tEmployee ID not found." << endl;
    }
}

void Delete_data()
{
    int delete_id;
    bool found = false;
    cout << "\tEnter the ID of the employee you want to fire and delete the data: ";
    cin >> delete_id;

    fstream file, file_1;
    file.open("employees.txt", ios::in);
    if (!file.is_open())
    {
        cout << "\tError opening file.";
    }

    file_1.open("upordel.txt", ios::out | ios::app);     // Created a file for storing all the data of the employee of the company that you donot want to delete
    if (!file_1.is_open())                               // and then this file is renamed
    {
        cout << "\tError opening file.";
    }

    file.ignore();
    getline(file, name);
    getline(file, designation);
    file >> id;
    file.ignore();
    getline(file, address);
    file >> number;
    file >> salary;
    file >> total_leaves;

    while (!file.eof())  
    {
        // The employes whose ID do not match the delete_ID their data is saved in another file named upordel by using the trick of reversing the .eof() built-in function
        if (delete_id != id)
        {
            file_1 << " " << name << "\n";
            file_1 << " " << designation << "\n";
            file_1 << " " << id << "\n";
            file_1 << " " << address << "\n";
            file_1 << " " << number << "\n";
            file_1 << " " << salary << "\n";
            file_1 << " " << total_leaves << "\n";
        }
        if (delete_id == id) // only to check wheter the id exsists or not
        {
            found = true;
        }

        file.ignore();
        getline(file, name);
        getline(file, designation);
        file >> id;
        file.ignore();
        getline(file, address);
        file >> number;
        file >> salary;
        file >> total_leaves;
    }

    file.close();
    file_1.close();

    remove("employees.txt");
    rename("upordel.txt", "employees.txt");    // Renamed the file so donot get confusede in accessing the files containing the data of the employee
    if (found == false)
    {
        cout << "\tTheir is no data of any employee with this id " << endl;
    }
    else
    {
        cout << "\tData Deleted Successfully." << endl;
    }
}

void allot_bonus()
{
    int bonus_id, year;
    char bonus_type;
    string month;
    double bonus_amount, total_salary, Bonus_percentage;
    bool found = false;

    cout << "\n\tEnter the employee ID to allot bonus: ";
    cin >> bonus_id;

    fstream file, file_1;
    file.open("employees.txt", ios::in);
    if (!file.is_open())
    {
        cout << "\tError opening file.xx";
    }

    file_1.open("bonus.txt", ios::out | ios::app);    // Doing the same as did in the previous Delete_Data()
    if (!file_1.is_open())
    {
        cout << "\tError opening file.";
    }

    file.ignore();
    getline(file, name);
    getline(file, designation);
    file >> id;
    file.ignore();
    getline(file, address);
    file >> number;
    file >> salary;
    file >> total_leaves;

    while (!file.eof())
    {
        if (bonus_id == id)
        {
            cout << "\n\tEnter the month: ";
            cin >> month;
            cout << "\n\tEnter the year: ";
            cin >> year;
            cout << "\n";
            cout << "\t  ____________________________________" << endl;
            cout << "\t||     Enter the type of bonus        ||" << endl;
            cout << "\t||____________________________________||" << endl;
            cout << "\t|| Select:  1--> for Sign-on bonus    ||" << endl;
            cout << "\t|| Select:  2--> for holidays bonus   ||" << endl;
            cout << "\t|| Select:  3--> for team incentives  ||" << endl;
            cout << "\t|| Select:  4--> for milestones bonus ||" << endl;
            cout << "\t||____________________________________||" << endl;
            bonus_type = getch();
            switch (bonus_type)
            {
            case '1':
                Bonus_percentage = 0.05;
                break;
            case '2':
                Bonus_percentage = 0.07;
                break;
            case '3':
                Bonus_percentage = 0.10;
                break;
            case '4':
                Bonus_percentage = 0.10;
                break;
            default:
                cout << "\n\tEnter a valid input " << endl;
            }

            bonus_amount = salary * Bonus_percentage;
            total_salary = salary + bonus_amount;
            cout << "\n\tBonus allotted successfully : " << bonus_amount << endl;
            cout << "\n\tSalary before bonus : " << salary << endl;
            cout << "\n\tSalary after adding bonus : " << total_salary << endl;
            found = true;

            file_1 << " " << name << "\n";
            file_1 << " " << designation << "\n";
            file_1 << " " << id << "\n";
            file_1 << " " << month << "\n";
            file_1 << " " << year << "\n";
            file_1 << " " << salary << "\n";
            file_1 << " " << bonus_amount << "\n";
            file_1 << " " << total_salary << "\n";
            break;
        }

        file.ignore();
        getline(file, name);
        getline(file, designation);
        file >> id;
        file.ignore();
        getline(file, address);
        file >> number;
        file >> salary;
        file >> total_leaves;
    }

    file.close();
    file_1.close();

    if (found == false)
    {
        cout << "\tEmployee ID not found." << endl;
    }
}

int InputValidation(int num)
{
    while (1) // Condition is true  and the loop will iterate until break statement is executed
    {
        if (cin.fail())
        {
            cout << " \n";
            cout << " \t\t\t   Error! Please choose from the below " << endl;
            cout << " \n";
            cout << "\n\t\t\t   -------------Choose from below------------- " << endl;
            cout << "\n\t\t    ___________________________________________ ";
            cout << "\n\t\t   |                                           |";
            cout << "\n\t\t   |  1--> Designation                         |"
                 << "\n\t\t   |  2--> Address                             |"
                 << "\n\t\t   |  3--> Phone Number                        |"
                 << "\n\t\t   |  4--> Salary                              |"
                 << "\n\t\t   |  5--> Total Leaves                        |";
            cout << "\n\t\t   |___________________________________________|" << endl;
            // Built-in function   This function returns true when an input failure occurs. In this case it would be an input that is not an integer.
            //  If the cin fails then the input buffer is kept in an error state.  Buffer is region of memory used to store data temporarily
            cin.clear();

            // Built-in function    This function to remove undesirable characters from the input buffer
            cin.ignore(132, '\n');
            cin >> num;
        }
        else if (!cin.fail())
        {
            return num;
            break;
        }
    }
}
