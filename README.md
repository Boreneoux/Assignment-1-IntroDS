# Assignment-1-IntroDS

Program ini digunakan untuk mengakses customer pada Hotel-del-jojo, user bisa menambahkan customer, melihat / reading customer yang tersedia, dan mengubah / update customer yang ada, program ini sudah connect kedalam file txt yang berfungsi sebagai database yang tersedia di folder customer dan room.

# main.cpp

**import_data_from_file()**
sebuah fungsi dimana program mengambil atau importing semua data yang ada didalam data_customer.txt (didalam folder customer) dan didalam room.txt (didalam folder room), kemudian dimasukkan kedalam Attribute pada struct yang ada di program main.cpp

**menu()**
sebuah fungsi untuk menampilkan main menu menggunakan do while loop dan switch case.

**void read()**
sebuah fungsi untuk membaca data customer yang sudah tersedia. 

**void create()**
sebuah fungsi untuk membuat customer baru dan juga memasukkan semua atribut yang sudah di input ke dalam file customer_data.txt
dimana program hanya menerima lowercase pada inputan nama, dan hanya menerima umur >0 && <100. dan juga memvalidasi jika user memasukkan Pantai = R001, Rooftop = R002, Taman = R003, Bar = R004.

**void update()**
fungsi untuk memperbarui data customer yang sudah tersedia, dengan menggunakan Customer ID.

