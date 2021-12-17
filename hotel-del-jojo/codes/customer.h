void read(Customer *C)
{

    cout << "|   | ID   |  Name |  Age  |  Room  |" << endl;
    cout << "|---|------|-------|-------|--------|" << endl;
    for (int i = 0; i < lengthCust; i++)
    {
        cout << "| " << i << " |  " << C->customer_id[i] << "| " << C->customer_name[i] << " |   " << C->customer_age[i] << "   |  " << C->r.room_type_id[i] << "  |" << endl;
    }
}

void create()
{
}