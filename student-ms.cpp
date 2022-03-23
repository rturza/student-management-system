#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#define SIZE 200 //Max student capacity for the school.
using namespace std;
class student
{
    string first_name;
    string last_name;
    string ID;
    string department; //UPDATE?
    float cgpa; //HOW BEST TO IMPLEMENT THIS FEATURE?
public:
    void set_first_name(string first_name){this->first_name=first_name;}
    void set_last_name(string last_name){this->last_name=last_name;}
    void set_ID(string ID){this->ID=ID;}
    void set_department(string department){this->department=department;}
    void set_cgpa(float cgpa){this->cgpa=cgpa;}
    string get_first_name(){return first_name;}
    string get_last_name(){return last_name;}
    string get_ID(){return ID;}
    string get_department(){return department;}
    float get_cgpa(){return cgpa;}
};
void load_records(student[], int&);
void add_record(student[], int&);
void find_record(student[], int&);
void modify_record(student[], int&);
void delete_record(student[], int&);
void list_records(student[], int&);
void exit_program(student[], int&);
ifstream infile("data.txt");
int CHANGES=0; //GLOBAL VARIABLE TO COUNT THE NUMBER OF CHANGES MADE.
int main()
{
    if(infile.is_open())
    {
        student stdnt[SIZE];
        int total_student;
        infile >> total_student;
        load_records(stdnt, total_student);
        char choice;
        while(1)
        {
            cout << "\n\n";
            cout << "\t\t       STUDENT MANIDMENT SYSTEM";
            cout << "\n\n";
            cout << "\n\t\t\t       Main Menu";
            cout << "\n\t\t\t======================";
            cout << "\n \t\t\t  1. Add New Record";
            cout << "\n \t\t\t  2. Find Record";
            cout << "\n \t\t\t  3. Edit Record";
            cout << "\n \t\t\t  4. Delete Record";
            cout << "\n \t\t\t  5. List All Records";
            cout << "\n \t\t\t  6. Exit Program";
            cout << "\n\t\t\t======================";
            cout << "\n\n";
            cout << "\t\t\t Select Your Choice: ";
            cin  >> choice;
            cout << "\n\n";

            switch(choice)
            {
            case '1' :
                system("cls");
                add_record(stdnt, total_student);
                break;
            case '2' :
                system("cls");
                find_record(stdnt, total_student);
                break;
            case '3' :
                system("cls");
                modify_record(stdnt, total_student);
                break;
            case '4' :
                system("cls");
                delete_record(stdnt, total_student);
            case '5' :
                system("cls");
                list_records(stdnt, total_student);
                break;
            case '6' :
                system("cls");
                exit_program(stdnt, total_student);
                break;
            default  :
                system("cls");
                cout<<"\n(!)ERROR: Invalid selection.\n"<<endl;
                system("pause");
                system("cls");
                //break;
            }
        }
        return 0;
    }
    else
    {
        cout<<"(!)ERROR: Failed to open file data.txt"<<endl;
        return 0;
    }
}
void load_records(student stdnt[], int &n)
{
    string temp_first_name;
    string temp_last_name;
    string temp_ID;
    string temp_department;
    float temp_cgpa;
    for(int i=0; i<n; i++)
    {
        infile >> temp_first_name >> temp_last_name >> temp_ID >> temp_department >> temp_cgpa;
        stdnt[i].set_first_name(temp_first_name);
        stdnt[i].set_last_name(temp_last_name);
        stdnt[i].set_ID(temp_ID);
        stdnt[i].set_department(temp_department);
        stdnt[i].set_cgpa(temp_cgpa);
    }
    infile.close();
}
void add_record(student stdnt[], int &n)
{
    char another='Y';
    while(another=='y'||another=='Y')
    {
        if(n<SIZE)
        {
            string temp_first_name;
            string temp_last_name;
            string temp_ID;
            string temp_department;
            float temp_cgpa;
            cout<<endl;
            cout<< "Enter student's first name: ";
            cin >> temp_first_name;
            cout<<endl;
            cout<< "Enter student's last name: ";
            cin >> temp_last_name;
            cout<<endl;
            cout<< "Enter student's ID: ";
            cin >> temp_ID;
            cout<<endl;
            cout<< "Enter department no: ";
            cin >> temp_department;
            cout<<endl;
            cout<< "Enter student's total cgpa: ";
            cin >> temp_cgpa;
            cout<<endl;
            stdnt[n].set_first_name(temp_first_name);
            stdnt[n].set_last_name(temp_last_name);
            stdnt[n].set_ID(temp_ID);
            stdnt[n].set_department(temp_department);
            stdnt[n].set_cgpa(temp_cgpa);
            n++; //ONE NEW RECORD ADDED, i.e. total_student += 1
            CHANGES++;
            system("cls");
            cout<<"\n(!)NOTIFICATION: Records added."<<endl;
        }
        else
        {
            system("cls");
            cout<<"Maximum number of students reached."<<endl;
        }
        cout<<"\nAdd another record? (Y/N)"<<endl;
        cin >>another;
        system("cls");
    }
}
void find_record(student stdnt[], int &n)
{
    char another='Y';
    while(another=='y'||another=='Y')
    {
        string temp_first_name, temp_last_name;
        int hits=0;
        cout<<"Enter student's first name: ";
        cin>>temp_first_name;
        cout<<endl;
        cout<<"Enter student's last name: ";
        cin>>temp_last_name;
        system("cls");
        for(int i=0; i<n; i++)
        {
            if(stdnt[i].get_first_name()==temp_first_name && stdnt[i].get_last_name()==temp_last_name)
            {
                cout<<"\n(!)NOTIFICATION: student found.\n"<<endl;
                cout<<"\nShowing records for "<<temp_first_name<<" "<<temp_last_name<<":\n"<<endl;
                cout<<"Name: "<<stdnt[i].get_first_name()<<" "<<stdnt[i].get_last_name()<<endl;
                cout<<"ID : "<<stdnt[i].get_ID()<<endl;
                cout<<"department: "<<stdnt[i].get_department()<<endl;
                cout<<"cgpa: "<<stdnt[i].get_cgpa()<<endl;
                cout<<endl;
                hits++;
            }
        }
        if(hits==0)
        {
            cout<<"(!)NOTIFICATION: student not found."<<endl;
        }
        system("pause");
        system("cls");
        cout<<"\nFind another record? (Y/N)"<<endl;
        cin>>another;
        system("cls");
    }
}
void modify_record(student stdnt[], int &n)
{
    char choice;
    string temp_first_name, temp_last_name;
    string temp_ID;
    string temp_department;
    float temp_cgpa;
    int hits=0;
    cout<<"Enter student's first name: ";
    cin >>temp_first_name;
    cout<<endl;
    cout<<"Enter student's last name: ";
    cin>>temp_last_name;
    cout<<endl;
    system("cls");
    for(int i=0; i<n; i++)
    {
        if(stdnt[i].get_first_name()==temp_first_name && stdnt[i].get_last_name()==temp_last_name)
        {
            hits++;
            cout<<"\n(!)NOTIFICATION: student found.\n"<<endl;
            cout << "Edit records for "<<stdnt[i].get_first_name()<<" "<<stdnt[i].get_last_name()<<"? (Y/N)"<<endl;
            cin  >> choice;
            system("cls");
            if(choice == 'Y' || choice == 'y')
            {
                while(1)
                {
                    cout << "\n\n";
                    cout << "\n\t\t\t   Record Edit Sub-Menu";
                    cout << " \n\t\t\t=========================";
                    cout << "\n \t\t\t  1. Edit first name";
                    cout << "\n \t\t\t  2. Edit last name";
                    cout << "\n \t\t\t  3. Edit ID";
                    cout << "\n \t\t\t  4. Edit department no.";
                    cout << "\n \t\t\t  5. Edit cgpa";
                    cout << "\n \t\t\t  6. Return to Main Menu";
                  //cout << "\n \t\t\t  7. Edit another record";
                    cout << " \n\t\t\t=========================";
                    cout << "\n\n";
                    cout << "\t\t\t Select Your Choice: ";
                    cin  >> choice;
                    cout << "\n\n";
                    switch(choice)
                    {
                    case '1' :
                        system("cls");
                        cout<<"Enter new first name: ";
                        cin >> temp_first_name;
                        cout<<endl;
                        stdnt[i].set_first_name(temp_first_name);
                        CHANGES++;
                        system("cls");
                        cout<<"\n(!)NOTTIFICATION: Record updated."<<endl;
                        break;
                    case '2' :
                        system("cls");
                        cout<<"Enter new last name: ";
                        cin >> temp_last_name;
                        cout<<endl;
                        stdnt[i].set_last_name(temp_last_name);
                        CHANGES++;
                        system("cls");
                        cout<<"\n(!)NOTTIFICATION: Record updated."<<endl;
                        break;
                    case '3' :
                        system("cls");
                        cout<<"Enter updated ID: ";
                        cin >> temp_ID;
                        cout<<endl;
                        stdnt[i].set_ID(temp_ID);
                        CHANGES++;
                        system("cls");
                        cout<<"\n(!)NOTTIFICATION: Record updated."<<endl;
                        break;
                    case '4' :
                        system("cls");
                        cout<<"Enter new department no.: ";
                        cin >> temp_department;
                        cout<<endl;
                        stdnt[i].set_department(temp_department);
                        CHANGES++;
                        system("cls");
                        cout<<"\n(!)NOTTIFICATION: Record updated."<<endl;
                        break;
                    case '5' :
                        system("cls");
                        temp_cgpa = stdnt[i].get_cgpa();
                        float update; //try to add semester
                        int sem;
                        cout<<"Current cgpa   : "<<stdnt[i].get_cgpa()<<endl;
                        cout<<"Add new cgpa : ";
                        cin >> update;
                        cout<<"Enter student's semester:";
                        cin >>sem;
                        cout<<endl;
                        temp_cgpa = (temp_cgpa + update)/sem;
                        stdnt[i].set_cgpa(temp_cgpa);
                        cout<<"Updated cgpa   : "<<stdnt[i].get_cgpa()<<endl;
                        system("pause");
                        CHANGES++;
                        system("cls");
                        cout<<"\n(!)NOTTIFICATION: Record updated.\n"<<endl;
                        break;
                    case '6' :
                        system("cls");
                        return;
                    /*case '7' :
                        GOTO*/
                    default :
                        system("cls");
                        cout<<"\n(!)ERROR: Invalid selection.\n"<<endl;
                    }
                }
            }
            else
            {
                system("cls");
                return;
            }
        }
    }
    if(hits==0)
    {
        system("cls");
        cout<<"n\(!)NOTIFICATION: student not found.\n"<<endl;
    }
}
void delete_record(student stdnt[], int &n)
{
    //MAKE THIS MODULE MORE EFFICIENT.
    char another='Y';
    while(another=='y'||another=='Y')
    {
        string temp_first_name, temp_last_name;
        int hits=0;
        cout<<"Enter student's first name: ";
        cin>>temp_first_name;
        cout<<endl;
        cout<<"Enter last student's name: ";
        cin>>temp_last_name;
        cout<<endl;
        system("cls");
        for(int i=0; i<n; i++)
        {
            if(stdnt[i].get_first_name()==temp_first_name && stdnt[i].get_last_name()==temp_last_name)
            {
                hits++;
                cout<<"\n(!)NOTTIFICATION: student found.\n"<<endl;
                cout<<"Delete records for "<<stdnt[i].get_first_name()<<" "<<stdnt[i].get_last_name()<<"? (Y/N)"<<endl;
                char choice;
                cin>>choice;
                system("cls");
                if(choice == 'y' || choice == 'Y')
                {
                    for(int j=i; j<n-1; j++)
                    {
                        stdnt[j] = stdnt[j+1];
                    }
                    n--;//ONE RECORD DELETED, i.e. total_student -= 1
                    CHANGES++;
                    cout<<"\n(!)NOTTIFICATION: Records deleted.\n"<<endl;
                }
                else
                {
                    cout<<"\n(!)NOTTIFICATION: Records not deleted.\n"<<endl;
                    break;
                }
            }
        }
        if(hits==0)
        {
            system("cls");
            cout<<"\n(!)NOTTIFICATION: student not found.\n"<<endl;
        }
        cout<<"\nDelete another record? (Y/N)\n"<<endl;
        cin>>another;
        system("cls");
    }
}
void list_records(student stdnt[], int &n)
{
    cout<<"\n\t\t #"<<"\t    Name"<<"\t\t\t\tdepartment name.\n"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"\t\t "<<i+1<<".\t"<<stdnt[i].get_first_name()<<" "<<stdnt[i].get_last_name()<<"\t\t\t\t  "<<stdnt[i].get_cgpa()<<endl;
    }
    cout<<"\n\n";
    system("pause");
    system("cls");
}
void exit_program(student stdnt[], int &n)
{
    if(CHANGES!=0)
    {
        cout<<"\nSave changes before exiting? (Y/N)\n"<<endl;
        char choice;
        cin>>choice;
        system("cls");
        if(choice == 'Y' || choice == 'y')
        {
            ofstream outfile("data.txt");
            outfile << n << endl;
            for(int i=0; i<n; i++)
            {
                outfile << stdnt[i].get_first_name() << " ";
                outfile << stdnt[i].get_last_name() << " ";
                outfile << stdnt[i].get_ID() << " ";
                outfile << stdnt[i].get_department() << " ";
                outfile << stdnt[i].get_cgpa();
                outfile << endl;
            }
            outfile.close();
            cout<<"\n(!)NOTIFICATION: Changes saved."<<endl;
            cout<<"\n(!)NOTIFICATION: Program terminated."<<endl;
            exit(1);
        }
        else
        {
            cout<<"\n(!)NOTIFICATION: Changes not saved."<<endl;
            cout<<"\n(!)NOTIFICATION: Program terminated."<<endl;
            exit(1);
        }
    }
    else
    {
        cout<<"\n(!)NOTIFICATION: Program terminated."<<endl;
        exit(1);
    }
}






/*
NOTES:
        0. multiple input problem
        1. duplicate department problem
        2. add "edit another record" option
        3. fix the issue that arise when two or more students have the same name=
*/
