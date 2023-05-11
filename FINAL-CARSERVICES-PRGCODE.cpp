#include <iostream>         //Including Library for inputs and outputs
#include <fstream>          //Including library to read and write files.
#include <windows.h>
#include<string>            //Including library for string characters
#include<stdio.h>           //Including library to clear screen
#include <cstdio>
#include <chrono>           //Including library to keep the screen (wait)
#include <thread>
#include <cwchar>
using namespace std;

void Header();                  //prototype Declaration for Header
void Welcome_Page();            //prototype Declaration for Welcome interface function
void Wait();                    //prototype Declaration for Wait function
void Admin_menu();              //prototype Declaration for Admin main menu
void login();                   //prototype Declaration for login function to the system
void Register_Vehicles();       //prototype Declaration for Registering Vehicles function
void View_Vehicle_services();   //prototype Declaration for Viewing available services
         
void Display_Item();            //prototype Declaration for displaying items in order to add items next
void Main_Menu_Selection();     //prototype Declaration for main menu of vehicle services
void add_item();                //prototype Declaration for adding vehicle services 
void Display_Bill();            //prototype Declaration for displaying the bill

string ans;                     // Declaration of data types for main menu selection

int quantity[100];              //Global structure array declared to store quantity upto 100
int total[100];
int id;                         // Declaration of data types for calcualting bill function
int price[26];
int Discount = 0;
int Final_Bill_price = 0;

void Save_bill();               //prototype Declaration for saving bill function
string Service_Name[26];        //Data members of the structure
void Print_his_rep();           //prototype Declaration for printing the history report



void Header() {                 // Header function
    cout << "\n\t\t\t        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\t\t\t|                 SD AUTOWORLD        	          |" << endl;
    cout << "\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "" << endl;
}

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);     

int main()      //consists of the main and initial function to run the system. 
                //inside this function the rest of the functions are placed so there 
                //  is no need to mention all the functions in the main program
{
    //LOG IN
    {
        printf("                          =====================WELCOME TO SD AUTOWORLD=================\n\n\n");
        string user_name;       //local variable declaration for inputs
        string password;

        Header();

        int attempt = 3;

        while (attempt >= 1)            //while loop used to give 3 attempts to login.

        {
            SetConsoleTextAttribute(h, FOREGROUND_GREEN);      // insert colour
            cout << "\t""\t""\t""\t""Username    :""\t";
            cin >> user_name;
            cout << "\t""\t""\t""\t""password    :""\t";
            cin >> password;


            if ((user_name == "admin") && (password == "1234"))  // if loop to check password and username

            {
                cout << "\n""\t""\t""\t""\t""LOGIN SUCCESSFUL! WELCOME!-----------------\n";
                void Wait();
                {
                    this_thread::sleep_for(chrono::seconds(2)); //retards the next interface appearing for 2 seconds
                }
                break;// break the while loop
                system("pause");
            }

            else

            {
                cout << "\t""\t""\t""\t""INVALID LOGIN PLEASE TRY AGAIN!" << endl;
                cout << "\n";
                system("pause");
                cout << "\n";

            }

            attempt = attempt - 1;
        }

        if (attempt == 0)
        {
            cout << "\t""\t""\t""\t""Unauthorized user!" << endl;
            cout << "\n";
            system("pause");
            exit(0);/*exit*/
        }

    }
    system("cls");
    Welcome_Page();         //once the login is success the system jumps out of the loop and calls the welcome page main interface
    system("pause");
}

void Welcome_Page()   //initial welcome interface
{
    cout << "\n""\n""\n""\n""\n""\n""\n""\t""\t""\t""\t" << " =====================  = = = = = = = = = = = = = = ===================";
    cout << "\n""\n""\n""\n""\n""\n""\n""\t""\t""\t""\t" << "===================== WELCOME TO SD AUTOWORLD SYSTEM! ===================";
    cout << "\n""\n""\n""\n""\n""\n""\n""\t""\t""\t""\t" << " =====================  = = = = = = = = = = = = = = ===================";
    Wait();
    system("cls"); /*clears the screen*/
    Admin_menu();
}

void Wait()
{
    this_thread::sleep_for(chrono::seconds(4)); /*retards the next interface for 4s for the user to see*/
}



void Admin_menu()

{
    //ADMIN MAIN MENU  - includes of the features and the components of the main menu allowing users to make their selections

    int selection;

    string var;
    system("cls");/*we can clear the display*/
    Header();
    cout << "\n\n\n                                   ADMIN MAIN MENU" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t""\t""\t""\t""1. Register Vehicles\n"
        "\t""\t""\t""\t""2. View Vehicle Services\n"
        "\t""\t""\t""\t""3. Add vehicle services\n"
        "\t""\t""\t""\t""4. Calculate and save the total bill\n"
        "\t""\t""\t""\t""5. Print History report\n"
        "\t""\t""\t""\t""6. Exit program\n";

    cout << "\n""\t""\t""\t""\t""Select and Enter any option from 1 to 6""\t"":";

    cin >> selection;    //Allowing the selection function to input selection
    if (selection == 1)     //users are given access to their requirements by clicking on the corresponding 
                            //number infront of the information

    {
        Register_Vehicles();
    }
    else if (selection == 2)
    {
        View_Vehicle_services();
    }
    else if (selection == 3)
    {
        add_item();
    }
    else if (selection == 4)
    {
        Display_Bill();
    }
    else if (selection == 5)
    {
        Print_his_rep();
    }
    else if (selection == 6);
    {
        exit(0);
    }
    

}




void Register_Vehicles()        //function to register vehicles
{
    string name("20");          //declaring variables of register vehicles function
    string vID("7");
    string vID_new;
    string mName("20");
    string mYear("15");
    string Mile("8");
    string reg_owner("15");

    //creating file 
    fstream registeredV("registered.txt", ios::app);     //creating an instance of the fstream class
    if (registeredV.is_open())      
    {
        registeredV << vID;                             //inserting vehicle id as the input
        registeredV << "\n";                            //\n used for a new line
        registeredV.close();

        change:
        system("cls");


        //getting vehicle registration data from the user

        cout << "\n\n\n\n\n""\t""\t""\t""\t""\t""\t" << "             - VEHICLE REGISTRATION FORM -""\n\n\n" << endl;
        cout << "\n""\t""\t""\t""\t" << "Please do fill the form to proceed." << endl;

        cout << endl << endl;
        cout << "\t""\t""\t""\t" << "1. Vehical Name      : ";
        cin >> name; cout << endl << endl;
        cout << "\t""\t""\t""\t" << "2. Vehical Number    : ";
        cin >> vID; cout << endl << endl;
        cout << "\t""\t""\t""\t" << "3. Manufacturer      : ";
        cin >> mName; cout << endl << endl;
        cout << "\t""\t""\t""\t" << "4. Manufactured year  : ";
        cin >> mYear; cout << endl << endl;
        cout << "\t""\t""\t""\t" << "5. Mileage(km)        : ";
        cin >> Mile; cout << endl << endl;
        cout << "\t""\t""\t""\t" << "6. Registered owner   : ";
        cin >> reg_owner; cout << endl << endl;

        cout << "\t""\t""\t" << "        Vehicle Registered Succesfully !" << endl << endl << endl;
        cout << "\tFile Created... File name : " << vID << endl << endl << endl;
        //file create

        vID_new = vID + ".txt";
        fstream reg_vehicle(vID_new.c_str(), ios::app);

        //writing into the file

        Wait();

        system("cls");
        cout << "\t""\t""\t""\t" << "              Welcome Register Form" << endl << endl << endl;
        cout << endl << endl;
      //writing user inputs in the file
        reg_vehicle << "==================================================\n";
        reg_vehicle << "\t\t SD Auto World \n";
        reg_vehicle << "==================================================\n";
        reg_vehicle << "\t\t Vehicle Details \n";
        reg_vehicle << "Vehical Name: " + name;
        reg_vehicle << "\n";
        reg_vehicle << "Manufacturer: " + mName;
        reg_vehicle << "\n";
        reg_vehicle << "Manufactured year:  ";
        reg_vehicle << mYear;
        reg_vehicle << "\n";
        reg_vehicle << "Mileage(km): ";
        reg_vehicle << Mile;
        reg_vehicle << "\n";
        reg_vehicle << "Registered owner: " + reg_owner;
        reg_vehicle << "\n";
        reg_vehicle << "\n";
        reg_vehicle << "==================================================\n";

        //after the file is written displays that the file is created as the output
        cout << "\tSaving Details..." << endl;
        cout << "\tFile Created... File name : " << vID << endl << endl << endl; 
        
    }
    system("cls");
    cout << "\n""\t""\t""\t""\t" "Do you want to Continue ?" << endl;   //asking the users requirements
    cout << "\n""\t""\t""\t" " press 1>>>> Exit Program " << endl;
    cout << "\n""\t""\t""\t" " press 2>>>> Admin Main Menu ";
correct:
    int Input_Number;
    cin >> Input_Number;                                           //taking an input from the global character type variable
    cout << endl;

    switch (Input_Number)        //switch case statements given to do the required task accordingly
    {
    case 1: exit(0);            //as case 1 program will exit and end
        break;
    case 2: Admin_menu();       // as case 2 directs back to admin menu

        break;
    default:                
        cout << "\t""\t""\t""invalid Type Please enter 1,2 !" << endl;
        goto correct;
        break;
    }
}





void View_Vehicle_services()        //function that ONLY views the available vehicle services only as an output

{
    SetConsoleTextAttribute(h, FOREGROUND_BLUE);    //changes the colour to blue
    cout << "\n\n";
    cout << "\t""\t""\t""\t""==================================================\n";
    cout << "\t""\t""\t""\t""\t\t SD Auto World Vehicle Services \n";
    cout << "\t""\t""\t""\t""==================================================\n";

    cout << endl;
    cout << "\tVehicle Services" << endl;
    cout << "\t________________" << endl;
    cout << "" << endl;
    cout << "\t""\t""\t""\t""ID                                        "  "        Name" "                                    "  "Price" << "      " << endl;
    cout << "\t""\t""\t""\t""------------------------------------------------------------------------------------------------------ " << endl;
    cout << "\t""\t""\t""\t""0001                                      " << "Change the oil" << "                    ""      ""\t""1000" << "        " << endl << endl;
    cout << "\t""\t""\t""\t""0002                                      " << "'Change the oil filter" << "            ""      ""\t""1100" << "        " << endl << endl;
    cout << "\t""\t""\t""\t""0003                                      " << "'Inspect the fan belt" << "             ""      ""\t""1200" << "        " << endl << endl;
    cout << "" << endl;
    cout << "\tVehicle Repairs" << endl;
    cout << "\t________________" << endl;
    cout << "" << endl;
    cout << "\t""\t""\t""\t""0004                                      " << "Inspect the hoses for cracks" << "      ""      ""\t""1300" << "        " << endl << endl;
    cout << "\t""\t""\t""\t""0005                                      " << "'Check the battery and cables" << "     ""      ""\t""1400" << "        " << endl << endl;
    cout << "\t""\t""\t""\t""0006                                      " << "Check the power steering fluid" << "    ""      ""\t""1500" << "        " << endl << endl;
    cout << "" << endl;
    cout << "\tVehicle Cleaning" << endl;
    cout << "\t________________" << endl;
    cout << "" << endl;
    cout << "\t""\t""\t""\t""0007                                      " << "'Exterior Cleaning" << "                ""      ""\t""1600" << "        " << endl << endl;
    cout << "\t""\t""\t""\t""0008                                      " << "Interior Cleaning" << "                ""       ""\t""1700" << "        " << endl << endl;
    cout << "\t""\t""\t""\t""0009                                      " << "'Body Paint" << "                      ""       ""\t""1800" << "        " << endl << endl;

    void Wait();
    {
        this_thread::sleep_for(chrono::seconds(4));  /*retards the next interface for 4s for the user to see*/
    }

    cout << "\n""\t""\t""\t""\t" "Do you want to Continue ?" << endl;   //asking the users requirements
    cout << "\n""\t""\t""\t" " press 1>>>> Exit Program " << endl;   
    cout << "\n""\t""\t""\t" " press 2>>>> Admin Main Menu ";
correct:
    int Input_Number;
    cin >> Input_Number;      //taking an input from the global character type variable
    cout << endl;

    switch (Input_Number)
    {
    case 1: exit(0);        //ends program
        break;
    case 2: Admin_menu();   // as case 2 directs back to admin menu

        break;
    default:
        cout << "\t""\t""\t""invalid Option Please enter 1 or 2 !" << endl;
        goto correct;
        break;  //breaks the switch case
    }

}


void Display_Item()  //This function again displays the available vehicle services ALLOWING THE USER TO ADD ITEMS AS WELL

{
    Header();       //Displays the header in the interface

    //Vehicle services are interpreted with there ids, prices, names and categories
    cout << endl;
    cout << "\tVehicle Services" << endl;
    cout << "\t________________" << endl;
    cout << "" << endl;
    cout << "\t""\t""\t""\t""VEHICLE SERVICE ID                        "  "        Name" "                                 ""Price" << "      " << endl;
    cout << "\t""\t""\t""\t""----------------------------------------------------------------------------------------------- " << endl;
    cout << "\t""\t""\t""\t""0001                                      " << "Change the oil" << "                     ""\t""\t" << price[0] << "        " << endl << endl;
    cout << "\t""\t""\t""\t""0002                                      " << "'Change the oil filter" << "             ""\t""\t" << price[1] << "        " << endl << endl;
    cout << "\t""\t""\t""\t""0003                                      " << "'Inspect the fan belt" << "              ""\t""\t" << price[2] << "        " << endl << endl;
    cout << "" << endl;
    cout << "\tVehicle Repairs" << endl;
    cout << "\t________________" << endl;
    cout << "" << endl;
    cout << "\t""\t""\t""\t""0004                                      " << "Inspect the hoses for cracks" << "      ""\t""\t" << price[3] << "        " << endl << endl;
    cout << "\t""\t""\t""\t""0005                                      " << "'Check the battery and cables" << "     ""\t""\t" << price[4] << "        " << endl << endl;
    cout << "\t""\t""\t""\t""0006                                      " << "Check the power steering fluid" << "    ""\t""\t" << price[5] << "        " << endl << endl;
    cout << "" << endl;
    cout << "\tVehicle Cleaning" << endl;
    cout << "\t________________" << endl;
    cout << "" << endl;
    cout << "\t""\t""\t""\t""0007                                      " << "'Exterior Cleaning" << "                ""\t""\t" << price[6] << "        " << endl << endl;
    cout << "\t""\t""\t""\t""0008                                      " << "Interior Cleaning" << "                 ""\t""\t" << price[7] << "        " << endl << endl;
    cout << "\t""\t""\t""\t""0009                                      " << "'Body Paint" << "                       ""\t""\t" << price[8] << "        " << endl << endl;




}



void add_item() //Adds items from the displayed services list


{
    system("cls");
add:

    //calling the add item function to input vehicle services
    Service_Name[0] = "'Change the oil - vehicle service'";
    Service_Name[1] = "'Change the oil filter - vehicle service";
    Service_Name[2] = "'Inspect the fan belt - vehicle service";


    Service_Name[3] = "'Inspect the hoses for cracks - Vehicle Repairs";
    Service_Name[4] = "'Check the battery and cables - Vehicle Repairs";
    Service_Name[5] = "'Check the power steering fluid - Vehicle Repairs";

    Service_Name[6] = "Exterior Cleaning";
    Service_Name[7] = "Interior Cleaning";
    Service_Name[8] = "Body Paint";
    //vehicle service ids given from 0 to 8


    //price of each vehicle service connected with the vehicle service
    price[0] = 1000;
    price[1] = 1100;
    price[2] = 1200;
    price[3] = 1300;
    price[4] = 1400;
    price[5] = 1500;
    price[6] = 1600;
    price[7] = 1700;
    price[8] = 1800;
    price[9] = 1900;
    price[10] = 2000;


    Display_Item();  //This acts as a subfunction to display the vehicle services until add items function is done
    cout << endl;
    cout << "\t""\t""\t""\t" "Do you want to add service?(y or n) >>>>>>>> "; cin >> ans; //taking an input from the global character type variable
    while (ans == "y" || ans == "Y")    //while loop for yes and no inputs
    {
        cout << "\t""\t""\t""\t""Enter vehicle service ID from above" << endl;      //asking user requirements only to input a number
        cout << "\n""\t""\t""\t""\t" "ENTER ID      : "; cin >> id;

        for (int i = 0; i < 9; i++)    //this main for loop will run until it is tallied with the number 
                                        //that user has entered as the vehicle service 

        {

            cout << "\t""\t""\t""\t" "SERVICE NAME  : ";        
            cout << Service_Name[id - 1] << endl;  //displays the service name of the service according to the input vehicle service id
            cout << "\t""\t""\t""\t" "PRICE         : ";
            cout << price[id - 1] << endl;          // outputs priceof the vehicle service 
            cout << "\t""\t""\t""\t" "QUANTITY      : ";
            cin >> quantity[id - 1];                //inputs the user required quantity 
                                                //displays the total price for the added service 
            cout << "\t""\t""\t""\t" "YOUR TOTAL IS(RS)          :" << price[id - 1] * quantity[id - 1] << endl; 

            void Wait();
            {
                this_thread::sleep_for(chrono::seconds(4));    /*retards the next interface for 4s for the user to see*/
            }

            if (quantity[id - 1] == 1) //the if statement will check whether the user entered code is tallied with 
                                       //the code stored in any of the arrays
            {
                // quantity
                for (int i = 0; i < 24; i++)

                {
                    total[id] = price[id - 1] * quantity[id - 1]; //total price will be the product of quantity into price
                    break; //breaks for loop
                }/*quantity end*/

                break;
                for (int i = 0; i < 24; i++)

                {
                    cin >> total[id - 1];  //inputs total of one service 

                    break; // breaks for loop
                }
                break;
            }

            else

            {
                cout << "Invalid Service ID";
                add_item();                   // if user inputs an invalid id directs back to add item menu
            }


        }

        //system("cls");
        cout << "\t""\t""\t""\t" "Welcome To Main Menu" << endl;
        Display_Item();                                                             //allows the user 
        cout << "\t""\t""\t""\t" "---- DO YOU WANT TO ADD ANOTHER SERVICE?(Y or N)>>>"; cin >> ans;//taking an input from the global
                                                                                                    //character type variable
    }

    //system("cls");

    char y;
    //asks user requirments to complete billing
    cout << "\n""\n""\n""\t""\t""\t""\t" << "      Do You Want To Complete The Billing Process ? " << endl;
    cout << endl;
    cout << "\t""\t""\t""\t" << "        Press Y if 'yes' or Press N if 'no' >>>>>>" << endl;
    cout << endl;
    cout << "\t""\t""\t""\t" << "                      "; cin >> y;

    if ((y == 'Y') || (y == 'y'))//the if statement will check whether the user entered code is tallied with the code stored in the array
    {
        system("cls");
        Display_Bill(); //back to displayt bill function

    }
    else if ((y == 'N') || (y == 'n'))
    {
        system("cls");
        Admin_menu(); // paths to admin menu again
    }

}



void Main_Menu_Selection() //This is a function used to get requirments to switch between interfaces

                            //this function will be included in other functions as a subfunction inbetween interfaces
{

    cout << "\t""\t""\t""\t"  " " << "  Do You Want To Select Item in Main Menu?" << endl << endl;
    cout << "\t""\t""\t""\t    " " press 1 to ""'Yes'"" or press 2 to ""'Exit'"" " << endl;


    int Input_Number;

    cout << endl << "\t""\t""\t""\t    "; cin >> Input_Number;
    cout << endl;

    switch (Input_Number)
    {
    case 1:add_item();
        break;

    case 2:exit(0);
        break;

    default:
        cout << "\t""\t""\t " "Invalid Type Please enter 1,2 !" << endl;
        break;
    }

}




void Display_Bill() //displays the total bill

{
    int x;
    int Main_menu_total = 0;
    for (int i = 0; i < 100; i++)
    {
        Main_menu_total += total[i]; //increment statement ---> main menu total = total + main menu total
    }

    Final_Bill_price = Main_menu_total; //main manu total will be the total of all the added services

    if (Final_Bill_price > 2500)
    {
        Discount = (10 * Final_Bill_price) / 100; //offers  a discount for the final bill including an if condition of more than 2500

    }
    else
    {
        Discount = 0;
    }
    // displaying the invoice with final billing
    Final_Bill_price = Final_Bill_price - Discount;

    Display_Item();
    cout << "\n""\t""\t""\t""\t" << "  =========================================================== " << endl;
    cout << "\t""\t""\t""\t" << "  ==================  SD Auto World Billing  ================== " << endl;
    cout << "\n""\t""\t""\t""\t" << "  INVOICE NO:001 " << endl;
    
    //displays the total bill with discount if applicable according to the if condition
    cout << "\t""\t""\t""\t" << "  ----------------------------------------------------------- " << endl;
    cout << "\t""\t""\t""\t""                     Total Discount    :     ""  " << Discount << endl << endl;
    cout << "\t""\t""\t""\t""                     Total             : ""  " << Final_Bill_price << endl << endl;
    cout << "\n""\t""\t""\t""\t" << "  ----------------------------------------------------------- " << endl;

correct:
    int Input_Number1; //inputs user requirment to print or to edit bill
    cout << "\t""\t""\t""\t" << " 1. Edit Bill" << endl;     
    cout << "\t""\t""\t""\t" << " 2. Print & Save Bill" << endl; cin >> Input_Number1;
    cout << endl;

    switch (Input_Number1)//switch case statements given to do the required task accordingly
    {
    case 1:Main_Menu_Selection();
        break;
    case 2: Save_bill();
        break;
    default:
        cout << "\t""\t""\t""\t""invalid Type Please enter 1,2 !" << endl;
        goto correct;
        break;
    }

}

void Save_bill() //saving bill process



{
    system("cls"); /*clears the display*/

    cout << "\n""\n""\t""\t""\t""\t""\n""\n" << "         ======             Bill Saved successfully !          ======" << endl;
    ofstream myfile;                                     //creating an instance of the ofstream class
    myfile.open("example.txt");
    myfile << "Writing this to a file.\n";               //writing the bill into the file
    myfile << "\t""\t""\t""\t" << "                      SD Auto World Services" << endl;
    myfile << endl;
    myfile << "\t""\t""\t""\t" << "  ----------------------------------------------------------- " << endl;
    myfile << "\t""\t""\t""t""                     Total Discount      ""  " << Discount << endl << endl;
    myfile << "\t""\t""\t""t""                     Total              ""  " << Final_Bill_price << endl << endl;
    myfile << "\t""\t""\t""\t" << "  ----------------------------------------------------------- " << endl;
    myfile.close();           //closes ones done with file reading
    Wait();
}


void Print_his_rep() //Printing the history report as a file
{
    system("cls");
    cout << "\n\n\n""\t""\t""\t""\t""Enter Vehicle Number:" << endl;

    {

        cout << "\n\n\n""\t""\t""\t""\t"  " " << " Get back to admin menu ?" << endl << endl;
        cout << "\t""\t""\t""\t    " " press 1 if ""'Yes'"" or press 2 to ""'Exit'"" " << endl;


        int Input_Number;

        cout << endl << "\t""\t""\t""\t    "; cin >> Input_Number;
        cout << endl;

        switch (Input_Number)
        {
        case 1:Admin_menu();
            break;

        case 2:exit(0);
            break;

        default:
            cout << "\t""\t""\t " "Invalid Type Please enter 1,2 !" << endl;
            break;
        }

    }

    //  PROGRAM END
}