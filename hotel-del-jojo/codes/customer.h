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