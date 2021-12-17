#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctype.h>

using namespace std;

// #include "customer.h"

struct Room
{
    string room_type_id[10];
    string room_type_name[10];
    long long int room_type_price[10];
};
struct Customer
{
    string customer_id[10];
    string customer_name[255];
    int customer_age[10];
    string customer_cause_of_death[255];
    string customer_resting_place[255];
    int customer_died_year[10];
    Room r;
};

int lengthCust = 0, lengthRoom = 0;
Customer C[100];
// Customer *C = new Customer();
void import_data_from_file(Customer *C)
{

    ifstream dataCustomer("../customer/customer_data.txt");
    if (!dataCustomer.is_open())
    {
        cout << "File tidak dapat dibuka" << endl;
    }

    string line, temp1, temp2;
    int i = 0, x = 0;

    while (getline(dataCustomer, line))
    {
        istringstream ss(line);
        getline(ss, C->customer_id[i], ',');
        getline(ss, C->customer_name[i], ',');
        getline(ss, temp1, ',');
        C->customer_age[i] = stoi(temp1);
        getline(ss, C->customer_cause_of_death[i], ',');
        getline(ss, C->customer_resting_place[i], ',');
        getline(ss, temp2, ',');
        C->customer_died_year[i] = stoi(temp1);
        ++i;
        ++lengthCust;
    }

    ifstream dataRoom("../room/room.txt");
    if (!dataRoom.is_open())
    {
        cout << "File tidak dapat dibuka" << endl;
    }

    while (getline(dataRoom, line))
    {
        istringstream ss(line);
        getline(ss, C->r.room_type_id[x], ',');
        getline(ss, C->r.room_type_name[x], ',');
        getline(ss, temp1, ',');
        C->r.room_type_price[x] = stoi(temp1);

        ++x;
        ++lengthRoom;
    }

    dataCustomer.close();
    dataRoom.close();
}

void read(Customer *C)
{

    cout << "|   | ID   |  Name |  Age  |  Room  |" << endl;
    cout << "|---|------|-------|-------|--------|" << endl;
    for (int i = 0; i < lengthCust; i++)
    {
        cout << "| " << i + 1 << " |  " << C->customer_id[i] << "| " << C->customer_name[i] << " |   " << C->customer_age[i] << "   |  " << C->r.room_type_id[i] << "  |" << endl;
    }
}

void create(Customer *C)
{

    ofstream dataCustomer;

    string cause_of_death[255];
    string resting_place[255];
    char room_type_name[255];
    string a = "Pantai";
    string b = "Rooftop";
    string c = "Taman";
    string d = "Bar";

    dataCustomer.open("../customer/customer_data.txt", ios::app);

    cout << "Customer ID : ";
    cin >> C->customer_id[lengthCust];
    dataCustomer << C->customer_id[lengthCust] << ",";
    cout << "Name (lowercase letters): ";
    cin >> namaCustomer;
    C->customer_name[lengthCust] = namaCustomer;
    dataCustomer << C->customer_name[lengthCust] << ",";
    do
    {
        cout << "Age (0 - 100) : ";
        cin >> umurCustomer;

    } while (umurCustomer >= 100 || umurCustomer < 0);
    C->customer_age[lengthCust] = umurCustomer;
    dataCustomer << C->customer_age[lengthCust] << ",";

    cout << "Cause of Death (max 255 letters): ";
    cin >> C->customer_cause_of_death[lengthCust];
    dataCustomer << C->customer_cause_of_death[lengthCust] << ",";

    cout << "Resting Place (max 255 letters): ";
    getline(cin, C->customer_resting_place[lengthCust]);
    dataCustomer << C->customer_resting_place[lengthCust] << ",";

    do
    {
        cout << "Room Type (Pantai, Rooftop, Taman, Bar): ";
        cin >> room_type_name;
    } while (room_type_name != a && room_type_name != b && room_type_name != c && room_type_name != d);
    C->r.room_type_name[lengthCust] = room_type_name;
    dataCustomer << C->r.room_type_name[lengthCust] << ",";

    if (room_type_name == a)
    {
        C->r.room_type_id[lengthCust] = "R001";
    }
    else if (room_type_name == b)
    {
        C->r.room_type_id[lengthCust] = "R002";
    }
    else if (room_type_name == c)
    {
        C->r.room_type_id[lengthCust] = "R003";
    }
    else if (room_type_name == d)
    {
        C->r.room_type_id[lengthCust] = "R004";
    }
    dataCustomer << C->r.room_type_id[lengthCust] << "\n";

    ++lengthCust;
    dataCustomer.close();

    cout << "Welcome to Hotel del Jojo!" << endl;
}

// void menu()
// {
//     int choice;
//     Customer C;

//     do
//     {
//         cout << "Hotel del Jojo" << endl;
//         cout << "1. Add New Customer" << endl;
//         cout << "2. Read data" << endl;
//         cout << "3. Update data" << endl;
//         cout << "4. Remove data" << endl;
//         cout << "5. Exit" << endl;

//         cin >> choice;

//         switch (choice)
//         {
//         case 1:

//             break;

//         case 2:
//             read(C);
//             break;

//         case 3:

//             break;

//         case 4:

//             break;
//         }
//     } while (choice != 5);

//     cout << "Thanks" << endl;
// }

int getOption()
{
    int choice;

    cout << "Hotel del Jojo" << endl;
    cout << "1. Add New Customer" << endl;
    cout << "2. Read data" << endl;
    cout << "3. Update data" << endl;
    cout << "4. Remove data" << endl;
    cout << "5. Exit" << endl;
    cout << "\nChoice [1-5] >> ";
    cin >> choice;

    return choice;
}

int main()
{
    import_data_from_file(C);

    // for (int i = 0; i < 4; i++)
    // {
    //     cout << " Data ke- " << i << " :" << endl;
    //     cout << C->customer_age[i] << "," << C->customer_cause_of_death[i] << "," << C->customer_died_year[i] << "," << C->customer_id[i] << "," << C->customer_name[i] << "," << C->customer_resting_place[i] << endl;
    // }

    // Customer C;

    int pilihan = getOption();

    while (pilihan != 5)
    {

        switch (pilihan)
        {
        case 1:
            create(C);
            break;
        case 2:
            read(C);
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            cout << "Pilihan tak tersedia!" << endl;
        }
        pilihan = getOption();
    }

    cout << "Thank you" << endl;

    // menu();

    return 0;
}