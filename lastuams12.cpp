#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;
void uamsheader();
void main_menuheader();
void adminloginheader();
void admin_menuheader();
void changeadminpasswordheader();
void viewallteachersheader();
void teacher_menuheader();
void teacher_signupheader();
void removeaccountheader();
void std_profileheader();
void aggheader();
void preferencesheader();
void addheader();
void updateheader();
void deletheader();
void viewheader();
void searchheader();
string stdregno[100];
string stdname[100];
string stdaggrigate[100];
string tpassword[100];
string temail[100];
string checkname;
string checkregno;
string checkagg;
int trows = 0;
int stdrows = 0;
int counter = 0;
string line;
fstream stddata;
fstream tdata;
int option;
void hardeffect()
{
    system("color 04");
    Sleep(1000);
    system("color 03");
}
void softeffect()
{
    system("color 02");
    Sleep(1000);
    system("color 03");
}
void localeffect()
{
    system("color 05");
    Sleep(1000);
    system("color 03");
}
void stdaddtofile()
{
    stddata.open("uamsdata.txt", ios::out);
    for (int i = 0; i <= stdrows; i++)
    {
        stddata << stdregno[i] << ",";
        stddata << stdname[i] << ",";
        stddata << stdaggrigate[i] << endl;
    }
    stddata.close();
}
void teacheraddtofile()
{
    tdata.open("uamsdata_login.txt", ios::out);
    for (int i = 0; i <= trows; i++)
    {
        tdata << tpassword[i] << ",";
        tdata << temail[i] << endl;
    }
    tdata.close();
}
int main_menu()
{
    cout << "What you want to do ?" << endl;
    cout << "(Press the specific number)" << endl;
    cout << "1. Admin portal" << endl;
    cout << "2. Teacher's portal" << endl;
    cout << "3. Student portal" << endl;
    cout << "9. Exit" << endl;
    cin >> option;
}
bool adminlogin2(string adminpassword, string adminemail)
{
    adminpassword = adminpassword + "A";
    adminemail = adminemail + "A";
    if (tpassword[0] == adminpassword && temail[0] == adminemail)
    {
        return 1;
    }
    else
        return 0;
}
bool adminlogin()
{
    for (int i = 3; i > 0; i--)
    {
        string adminpassword, adminemail;
        cout << "Enter login password: ";
        cin >> adminpassword;
        cout << "Enter login Email: ";
        cin >> adminemail;
        // return adminlogin2(adminpassword, adminemail);
        if (adminlogin2(adminpassword, adminemail))
        {
            return true;
        }
        else
        {
            cout << endl;
            cout << "      --------Invalid---------                  " << endl;
            cout << endl;
            cout << "You have remainingattempts are\t" << (i - 1) << endl;
            hardeffect();
        }
    }
    return false;
}
void change()
{
    string password, email;
    cout << "Enter new login password: ";
    cin >> password;
    cout << "Enter new login Email: ";
    cin >> email;
    tpassword[0] = password + "A";
    temail[0] = email + "A";
    teacheraddtofile();
}
void changeadminpassword()
{
    system("color 02");
    string password, email;
    cout << "Enter Existed login password: ";
    cin >> password;
    cout << "Enter Existed login Email: ";
    cin >> email;
    if (adminlogin2(password, email))
    {
        change();
        cout << "----Successfully added----" << endl;
        softeffect();
    }
    else
    {
        cout << "----Invalid Password----" << endl;
        hardeffect();
    }
}
void admin_menu()
{
    cout << "0. View all teachers" << endl;
    cout << "1. Add new student\n2. Update existing student" << endl;
    cout << "3. Delete the existing student\n4. View all students" << endl;
    cout << "5. Search any record\n6.Back to Main menu" << endl;
    cout << "7. Change login password" << endl;
    cout << "9. Exit" << endl;
}
void viewallteachers()
{
    for (int i = 1; i <= trows; i++)
    {
        tpassword[i] = tpassword[i];
        cout << tpassword[i] << "\t" << temail[i] << endl;
    }
}
bool addmore(string more)
{
    if (more == "yes" || more == "Yes" || more == "YES")
    {
        return 1;
    }
    else if (more == "no" || more == "No" || more == "NO")
    {
        return 0;
    }
    else
    {
        return 0;
    }
}
void arrayadd()
{
    stdregno[stdrows] = checkregno;
    stdname[stdrows] = checkname;
    stdaggrigate[stdrows] = checkagg;
}
bool checkreg()
{
    for (int i = 0; i <= stdrows; i++)
    {
        if (stdregno[i] == checkregno)
        {
            return 1;
        }
    }
    return 0;
}
int add()
{
    while (true)
    {
        cout << "Enter the student registration number: ";
        cin >> checkregno;
        if (checkreg())
        {
            cout << "----Error----" << endl;
            cout << "----ALREADY EXISTED----" << endl;
            hardeffect();
            cout << "Enter again" << endl;
            continue;
        }
        else
        {
            cout << "Enter the student name: ";
            cin.ignore();
            getline(cin, checkname);
            cout << "Enter the student aggrigate: ";
            cin >> checkagg;
            stdrows++;
            arrayadd();
            stdaddtofile();
            cout << "----SUCCESSFULLY ADDED----" << endl
                 << endl;
            softeffect();
            cout << "Do you want to add more students? :";
            cout << "(Yes/No)" << endl;
            string more;
            cin >> more;
            if (addmore(more))
            {
                system("cls");
                addheader();
                continue;
            }
            else
            {
                localeffect();
                cout << "OK" << endl;
            }
            break;
        }
    }
}
int arrayupdate(int a)
{
    stdregno[a] = checkregno;
    stdname[a] = checkname;
    stdaggrigate[a] = checkagg;
}
bool findreg()
{
    for (int i = 0; i <= stdrows; i++)
    {
        if (stdregno[i] == checkregno)
        {
            counter = i;
            return 1;
        }
    }
    return 0;
}
int update()
{
    cout << "Enter your registration number: ";
    cin >> checkregno;
    if (findreg())
    {
        int a = counter;
        cout << "Record exists....." << endl
             << endl;
        cout << "Enter the updated REGISTRATION NUMBER: ";
        cin >> checkregno;

        if (findreg())
        {
            cout << "----This registration number already exists----" << endl
                 << endl;
            hardeffect();
            return update();
        }
        else
        {
            stdrows++;
            cout << "Enter the updated name: ";
            cin.ignore();
            getline(cin, checkname);
            cout << "Enter the updated aggrigate: ";
            cin >> checkagg;
            arrayupdate(a);
            cout << "----Record successfully updated!----" << endl
                 << endl;
            stdaddtofile();
            softeffect();
        }
    }
    else
    {
        cout << "----Record not found----" << endl
             << endl;
        hardeffect();
    }
}
void arraydelet()
{
    stdregno[counter] = "\0";
    stdname[counter] = "\0";
    stdaggrigate[counter] = "\0";
    stdaddtofile();
}
int delet()
{
    cout << "Enter the registration number to delete the record: ";
    cin >> checkregno;
    if (!findreg())
    {
        cout << "----Invalid Registration number----" << endl;
        cout << "----OR Record is not existing----" << endl
             << endl;
        hardeffect();
    }
    else
    {
        arraydelet();
        cout << "----DELETED SUCCESSFULLY----" << endl;
        softeffect();
    }
}
int view()
{
    for (int i = 0; i <= stdrows; i++)
    {
        cout << stdregno[i] << "\t";
        cout << stdname[i] << "\t";
        cout << stdaggrigate[i] << endl;
    }
}
int searchreg()
{
    cout << "Enter the registration number to find the data: ";
    cin >> checkregno;
    if (!findreg())
    {
        cout << "----NOT EXISTED----" << endl;
        system("color 04");
    }
    else
    {
        cout << stdregno[counter] << "\t";
        cout << stdname[counter] << "\t";
        cout << stdaggrigate[counter] << endl;
        system("color 05");
    }
}
void showsearcheddata()
{
    cout << stdregno[counter] << "\t";
    cout << stdname[counter] << "\t";
    cout << stdaggrigate[counter] << endl;
}
int findoutname()
{
    for (int i = 0; i <= stdrows; i++)
    {
        if (stdname[i] == checkname)
        {
            counter = i;
            showsearcheddata();
        }
    }
}
int searchname()
{
    cout << "Enter the name to find the data: ";
    cin.ignore();
    getline(cin, checkname);
    findoutname();
    system("color 05");
}
int findoutagg()
{
    for (int i = 0; i <= stdrows; i++)
    {
        if (stdaggrigate[i] == checkagg)
        {
            counter = i;
            showsearcheddata();
        }
    }
}
int searchagg()
{
    cout << "Enter the aggrigate to find the data: ";
    cin >> checkagg;
    findoutagg();
    system("color 05");
}
bool tcheck(string thname, string themail)
{
    for (int i = 1; i <= trows; i++)
    {
        if (tpassword[i] == thname && temail[i] == themail)
        {
            counter = i;
            return 1;
        }
    }
    return 0;
}
void tsignup2(string thname, string themail)
{
    trows++;
    tpassword[trows] = thname;
    temail[trows] = themail;
    teacheraddtofile();
}
void tsignup()
{
    string thname;
    string themail;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, thname);
    cout << "Enter your email: ";
    cin >> themail;
    if (tcheck(thname, themail))
    {
        cout << "----ALREADY EXISTS----" << endl;
        hardeffect();
    }
    else
    {
        tsignup2(thname, themail);
        cout << "----Registerd successfully----" << endl;
        softeffect();
    }
}
int teacher_profile(int n)
{
    system("cls");
    teacher_signupheader();
    tsignup();
}
void removeaccount()
{
    string thname;
    string themail;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, thname);
    cout << "Enter your email: ";
    cin >> themail;
    if (tcheck(thname, themail))
    {
        tpassword[counter] = "\0";
        temail[counter] = "\0";
        cout << "----Deleted Successfully----" << endl;
        softeffect();
        
    }
    else
    {
        cout << "----Not existed----" << endl;
        hardeffect();
    }
}
void aggcalculater(float mmarks, float imarks, float ecatmarks, float tmmarks, float timarks, float tecatmarks)
{
    float aggri;
    aggri = ((mmarks / tmmarks * 0.25) + (imarks / timarks * 0.45) + (ecatmarks / tecatmarks * 0.30)) * 100;
    cout << "Your aggrigate is" << aggri << "%" << endl
         << endl;
    system("color 02");
}
void aggvalues()
{

    float mmarks, imarks, ecatmarks;
    float tmmarks, timarks, tecatmarks;
    cout << "Enter obtained Matriculation marks: ";
    cin >> mmarks;
    cout << "Enter Total Matriculation marks: ";
    cin >> tmmarks;
    cout << "Enter obtained First Year marks: ";
    cin >> imarks;
    cout << "Enter Total First Year marks: ";
    cin >> timarks;
    cout << "Enter obtained Ecat marks: ";
    cin >> ecatmarks;
    cout << "Enter Total Ecat marks: ";
    cin >> tecatmarks;
    if (mmarks > tmmarks || imarks > timarks || ecatmarks > tecatmarks)
    {
        cout << "----Error----" << endl;
        cout << "----Invalid marks----" << endl
             << endl;
        hardeffect();
    }
    else
        aggcalculater(mmarks, imarks, ecatmarks, tmmarks, timarks, tecatmarks);
}
float list(float agg)
{
    if (agg >= 80.0 && agg <= 100.0)
    {
        cout << "You can get admission in.........." << endl
             << endl;
        cout << "1.UET Lahore\n2. UET KSK" << endl;
        cout << "3.UET FSD\n4.UET Narowal\n5. UET RCET" << endl
             << endl;
    }
    else if (agg >= 70.0 && agg < 80.0)
    {
        cout << "You can get admission in.........." << endl
             << endl;
        cout << "1.UET FSD\n2.UET Narowal\n3. UET RCET" << endl
             << endl;
    }
    else if (agg >= 60.0 && agg < 70.0)
    {
        cout << "You can get admission in.........." << endl
             << endl;
        cout << "1.UET Narowal\n2. UET RCET" << endl
             << endl;
    }
    else
    {
        cout << "----No admmion criteria for this aggrigate----" << endl
             << endl;
        system("color 04");
    }
}
void preferences()
{
    float agg;
    cout << "Enter the aggrigate: ";
    cin >> agg;
    system("color 06");
    list(agg);
}
int stdprofile(int num)
{
    if (num == 1)
    {
        system("cls");
        std_profileheader();
        searchreg();
        getch();
    }
    else if (num == 2)
    {
        system("cls");
        aggheader();
        aggvalues();
        getch();
    }
    else if (num == 3)
    {
        system("cls");
        preferencesheader();
        preferences();
        getch();
    }
    else
    {
        cout << "----Invalid number----" << endl;
        system("color 04");
    }
}
void colors()
{
    system("color 05");
    Sleep(200);
    system("color 06");
    Sleep(200);
    system("color 02");
    Sleep(200);
    system("color 04");
    Sleep(200);
    system("color 01");
    Sleep(200);
    system("color 02");
    Sleep(200);
    system("color 03");
    Sleep(200);
}
void stdvalues_inarray()
{
    int coma = 1;
    stddata.open("uamsdata.txt", ios::in);
    while (getline(stddata, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ',')
                coma++;
            else if (coma == 1)
                stdregno[stdrows] += line[i];
            else if (coma == 2)
                stdname[stdrows] += line[i];
            else if (coma == 3)
                stdaggrigate[stdrows] += line[i];
            else
                break;
        }
        coma = 1;
        stdrows++;
    }
    stddata.close();
}
void teachervalues_inarray()
{
    int coma = 1;
    tdata.open("uamsdata_login.txt", ios::in);
    while (getline(tdata, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ',')
                coma++;
            else if (coma == 1)
                tpassword[trows] += line[i];
            else if (coma == 2)
                temail[trows] += line[i];
            else
                break;
        }
        coma = 1;
        trows++;
    }
    tdata.close();
}
int main()
{
    stdvalues_inarray();
    teachervalues_inarray();
    system("cls");
    uamsheader();
    colors();
    while (true)
    {
        system("cls");
        system("color 03");
        main_menuheader();
        main_menu();
        if (option == 1)
        {
            system("cls");
            adminloginheader();
            if (!adminlogin())
            {
                cout << "----Invalid Password!----" << endl;
                system("color 04");
                Sleep(1000);
                break;
            }
            while (true)
            {
                system("cls");
                system("color 03");
                admin_menuheader();
                admin_menu();
                cin >> option;
                if (option == 0)
                {
                    system("cls");
                    system("color 05");
                    viewallteachersheader();
                    viewallteachers();
                    getch();
                }
                else if (option == 1)
                {
                    system("cls");
                    system("color 05");
                    addheader();
                    add();
                }
                else if (option == 2)
                {
                    system("cls");
                    updateheader();
                    update();
                }
                else if (option == 3)
                {
                    system("cls");
                    deletheader();
                    delet();
                }
                else if (option == 4)
                {
                    system("cls");
                    viewheader();
                    view();
                    system("color 02");
                    getch();
                    system("color 03");
                }
                else if (option == 5)
                {
                    system("cls");
                    searchheader();
                    cout << "1. Search via Reistration number" << endl;
                    cout << "2. Search via name" << endl;
                    cout << "3. Search via aggrigate" << endl;
                    cout << "4. Back to admin menu" << endl;
                    cout << "9. Exit" << endl;
                    cin >> option;
                    if (option == 1)
                    {
                        system("cls");
                        searchheader();
                        searchreg();
                        getch();
                    }
                    else if (option == 2)
                    {
                        system("cls");
                        searchheader();
                        searchname();
                        getch();
                    }
                    else if (option == 3)
                    {
                        system("cls");
                        searchheader();
                        searchagg();
                        getch();
                    }
                    else if (option == 4)
                    {
                        continue;
                    }
                    else if (option == 9)
                    {
                        return 0;
                    }
                    else
                    {
                        cout << "----Invalid option----" << endl;
                        Sleep(1000);
                    }
                }
                else if (option == 6)
                    break;
                else if (option == 7)
                {
                    system("cls");
                    changeadminpasswordheader();
                    changeadminpassword();
                }
                else if (option == 9)
                {
                    return 0;
                }
            }
        }
        else if (option == 2)
        {
            while (true)
            {
                system("cls");
                teacher_menuheader();
                cout << "1. Sign up\n2. Remove account" << endl;
                cout << "4. main menu\n9. Exit" << endl;
                int n;
                cin >> n;
                if (n == 1)
                    teacher_profile(n);
                else if (n == 2)
                {
                    system("cls");
                    removeaccountheader();
                    removeaccount();
                }
                else if (n == 4)
                {
                    break;
                }
                else if (n == 9)
                {
                    return 0;
                }
                else
                {
                    cout << "----Invalid number!----" << endl;
                    hardeffect();
                }
            }
        }
        else if (option == 3)
        {
            while (true)
            {
                system("cls");
                system("color 03");
                std_profileheader();
                int num;
                cout << "1. Profile\n2. Aggrigate calculater" << endl;
                cout << "3. Preference list\n4. Back to main menu" << endl;
                cout << "9. Exit" << endl;
                cin >> num;
                if (num == 9)
                    return 0;
                else if (num == 4)
                    break;
                else
                    stdprofile(num);
            }
        }
        else if (option == 9)
        {
            return 0;
        }
        else
        {
            cout << "----Invalid number----" << endl
                 << endl;
            hardeffect();
        }
    }
    return 0;
}
void uamsheader()
{
    cout << "________________________________________________________________\n";
    cout << "________________________________________________________________ \n"
         << endl;

    cout << "##         ##         ####        ####     ####      ##########  " << endl
         << "##         ##        ##  ##       ## ##   ## ##      ##      ##  " << endl
         << "##         ##       ##    ##      ##  ## ##  ##      ##          " << endl
         << "##         ##      ##########     ##   ###   ##      ##########  " << endl
         << " ##       ##      ##        ##    ##         ##              ##  " << endl
         << "  ##     ##      ##          ##   ##         ##      ##      ##  " << endl
         << "    #####       ##            ##  ##         ##      ########## \n"
         << endl;
    cout << "________________________________________________________________\n";
    cout << "0000000000000000000000000000000000000000000000000000000000000000\n";
    cout << "________________________________________________________________\n";
    cout << endl
         << endl;
    cout << "          WELLCOME TO THE " << endl;
    cout << "UNIVERISTY ADMISSION MANAGEMENT SYSTEM" << endl
         << endl;
}
void main_menuheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "       MAIN MENU        " << endl
         << "________________________" << endl;
    cout << endl;
}
void adminloginheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "     LOGIN PASSWORD     " << endl
         << "________________________" << endl;
    cout << endl;
}
void admin_menuheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "       ADMIN MENU       " << endl
         << "________________________" << endl;
    cout << endl;
}
void changeadminpasswordheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "    CHANGE PASSWORD     " << endl
         << "________________________" << endl;
    cout << endl;
}
void viewallteachersheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "      ALL TEACHERS      " << endl
         << "________________________" << endl;
    cout << endl;
}
void addheader()
{
    cout << "_______________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "          ADD          " << endl
         << "_______________________" << endl;
    cout << endl;
}
void updateheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "         UPDATE          " << endl
         << "________________________" << endl;
    cout << endl;
}
void deletheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "         DELETE          " << endl
         << "________________________" << endl;
    cout << endl;
}
void viewheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "     VIEW PROFILES      " << endl
         << "________________________" << endl;
    cout << endl;
}
void searchheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "     SEARCH RECOERD     " << endl
         << "________________________" << endl;
    cout << endl;
}
void teacher_menuheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "   TRACHER'S MENU    " << endl
         << "________________________" << endl;
    cout << endl;
}
void teacher_signupheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "        SIGN UP         " << endl
         << "________________________" << endl;
    cout << endl;
}
void removeaccountheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "     REMOVE ACCOUNT     " << endl
         << "________________________" << endl;
    cout << endl;
}
void std_profileheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "    STUDENT PROFILES    " << endl
         << "________________________" << endl;
    cout << endl;
}
void aggheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "  AGGRIGATE CALCULATER  " << endl
         << "________________________" << endl;
}
void preferencesheader()
{
    cout << "________________________" << endl
         << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl
         << endl
         << "       PERFERENCES      " << endl
         << "________________________" << endl;
}