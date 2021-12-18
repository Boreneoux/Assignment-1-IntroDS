#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctype.h>
// #include "customer.h"

using namespace std;

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
Room r[4];

void import_data_from_file(Customer *C, Room *r)
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
        C->customer_died_year[i] = stoi(temp2);
        getline(ss, C->r.room_type_id[i], ',');
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
        getline(ss, r->room_type_id[x], ',');
        getline(ss, r->room_type_name[x], ',');
        getline(ss, temp1, ',');
        r->room_type_price[x] = stoi(temp1);

        ++x;
        ++lengthRoom;
    }

    dataCustomer.close();
    dataRoom.close();
}

void read(Customer *C)
{
    cin.ignore();
    cout << "|   | ID   |  Name |  Age  |  Room  |" << endl;
    cout << "|---|------|-------|-------|--------|" << endl;
    for (int i = 0; i < lengthCust; i++)
    {
        C->customer_name[i][0] = toupper(C->customer_name[i][0]);
        cout << "| " << i + 1 << " |  " << C->customer_id[i] << "| " << C->customer_name[i] << " |   " << C->customer_age[i] << "   |  " << C->r.room_type_id[i] << "  |" << endl;
    }
}

void update(Customer *C)
{

    string ID;
    char room_type_name[255];

    cin.ignore();
    cout << "Enter ID: ";
    getline(cin, ID);

    for (int i = 0; i <= lengthCust; i++)
    {
        if (ID == C->customer_id[i])
        {
            do
            {
                cout << "Room Type (Pantai, Rooftop, Taman, Bar): ";
                cin >> room_type_name;
            } while (room_type_name != r->room_type_name[0] && room_type_name != r->room_type_name[1] && room_type_name != r->room_type_name[2] && room_type_name != r->room_type_name[3]);
            C->r.room_type_name[i] = room_type_name;
            if (room_type_name == r->room_type_name[0])
            {
                C->r.room_type_id[i] = r->room_type_id[0];
            }
            else if (room_type_name == r->room_type_name[1])
            {
                C->r.room_type_id[i] = r->room_type_id[1];
            }
            else if (room_type_name == r->room_type_name[2])
            {
                C->r.room_type_id[i] = r->room_type_id[2];
            }
            else if (room_type_name == r->room_type_name[3])
            {
                C->r.room_type_id[i] = r->room_type_id[3];
            }
        }
    }
    ofstream dataCustomer;
    dataCustomer.open("../customer/customer_data.txt", ios::trunc);
    for (int i = 0; i <= lengthCust - 1; i++)
    {
        dataCustomer << C->customer_id[i] << ",";
        dataCustomer << C->customer_name[i] << ",";
        dataCustomer << C->customer_age[i] << ",";
        dataCustomer << C->customer_cause_of_death[i] << ",";
        dataCustomer << C->customer_resting_place[i] << ",";
        dataCustomer << C->customer_died_year[i] << ",";
        dataCustomer << C->r.room_type_id[i] << "\n";
    }
    dataCustomer.close();
}

void create(Customer *C)
{

    ofstream dataCustomer;
    char namaCustomer[255];
    int umurCustomer;
    string cause_of_death[255];
    string resting_place[255];
    char room_type_name[10];
    int i = 0;

    dataCustomer.open("../customer/customer_data.txt", ios::app);

    cout << "Customer ID : ";
    cin >> C->customer_id[lengthCust];
    dataCustomer << C->customer_id[lengthCust] << ",";
    cin.ignore();
    do
    {
        cout << "Name (lowercase letters): ";
        cin >> namaCustomer;
    } while (namaCustomer[i] != tolower(namaCustomer[i]));

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

    cin.ignore();
    cout << "Resting Place (max 255 letters): ";
    getline(cin, C->customer_resting_place[lengthCust]);
    dataCustomer << C->customer_resting_place[lengthCust] << ",";

    do
    {
        cout << "Room Type (Pantai, Rooftop, Taman, Bar): ";
        cin >> room_type_name;
    } while (room_type_name != r->room_type_name[0] && room_type_name != r->room_type_name[1] && room_type_name != r->room_type_name[2] && room_type_name != r->room_type_name[3]);
    C->r.room_type_name[lengthCust] = room_type_name;

    C->customer_died_year[lengthCust] = 0;
    dataCustomer << C->customer_died_year[lengthCust] << ",";

    if (room_type_name == r->room_type_name[0])
    {
        C->r.room_type_id[lengthCust] = r->room_type_id[0];
    }
    else if (room_type_name == r->room_type_name[1])
    {
        C->r.room_type_id[lengthCust] = r->room_type_id[1];
    }
    else if (room_type_name == r->room_type_name[2])
    {
        C->r.room_type_id[lengthCust] = r->room_type_id[2];
    }
    else if (room_type_name == r->room_type_name[3])
    {
        C->r.room_type_id[lengthCust] = r->room_type_id[3];
    }
    dataCustomer << C->r.room_type_id[lengthCust] << "\n";

    ++lengthCust;
    dataCustomer.close();

    cout << "Welcome to Hotel del Jojo!" << endl;
}

// void remove(Customer *C)
// {
//     string ID;

//     cin.ignore();
//     cout << "Enter ID: ";
//     getline(cin, ID);

//     for (int i = 0; i <= lengthCust; i++)
//     {
//         if (ID == C->customer_id[i])
//         {
//             do
//             {
//                 C->customer_id[i] = C->customer_id[i + 1];
//                 C->customer_name[i] = C->customer_name[i + 1];
//                 C->customer_age[i] = C->customer_age[i + 1];
//                 C->customer_cause_of_death[i] = C->customer_cause_of_death[i + 1];
//                 C->customer_resting_place[i] = C->customer_resting_place[i + 1];
//                 C->customer_died_year[i] = C->customer_died_year[i + 1];
//                 C->r.room_type_id[i] = C->r.room_type_id[i + 1];
//                 C->r.room_type_name[i] = C->r.room_type_name[i + 1];
//             } while (i <= lengthCust);
//             --lengthCust;
//         }
//     }

//     ofstream dataCustomer;
//     dataCustomer.open("../customer/customer_data.txt", ios::trunc);
//     for (int i = 0; i <= lengthCust - 1; i++)
//     {
//         dataCustomer << C->customer_id[i] << ",";
//         dataCustomer << C->customer_name[i] << ",";
//         dataCustomer << C->customer_age[i] << ",";
//         dataCustomer << C->customer_cause_of_death[i] << ",";
//         dataCustomer << C->customer_resting_place[i] << ",";
//         dataCustomer << C->customer_died_year[i] << ",";
//         dataCustomer << C->r.room_type_id[i] << "\n";
//     }
//     dataCustomer.close();
// }

int getOption()
{
    int choice;
    // system("clear");
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
    import_data_from_file(C, r);

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
            update(C);
            break;
        case 4:
            break;
        default:
            cout << "Pilihan tak tersedia!" << endl;
            break;
        }
        pilihan = getOption();
    }

    cout << "Thank you" << endl;

    return 0;
}