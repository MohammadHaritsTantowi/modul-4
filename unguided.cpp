#include <iostream>
using namespace std;

class Mahasiswa {
public:
    string nama;
    string nim;
    Mahasiswa* next;

    Mahasiswa(string n, string i) {
        nama = n;
        nim = i;
        next = NULL;
    }
};

class LinkedList {
private:
    Mahasiswa* head;
    Mahasiswa* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void tambahDepan(string n, string i) {
        Mahasiswa* baru = new Mahasiswa(n, i);
        if (head == NULL) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head = baru;
        }
    }

    void tambahBelakang(string n, string i) {
        Mahasiswa* baru = new Mahasiswa(n, i);
        if (head == NULL) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
        }
    }

    void tambahTengah(string n, string i, int pos) {
        Mahasiswa* baru = new Mahasiswa(n, i);
        if (pos == 0) {
            baru->next = head;
            head = baru;
        } else {
            Mahasiswa* bantu = head;
            for (int a = 1; a < pos; a++) {
                if (bantu->next == NULL) {
                    cout << "Posisi tidak ditemukan!" << endl;
                    return;
                }
                bantu = bantu->next;
            }
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }

    void ubahDepan(string n, string i) {
        if (head == NULL) {
            cout << "List kosong!" << endl;
            return;
        }
        head->nama = n;
        head->nim = i;
    }

    void ubahBelakang(string n, string i) {
        if (head == NULL) {
            cout << "List kosong!" << endl;
            return;
        }
        if (head == tail) {
            head->nama = n;
            head->nim = i;
        } else {
            Mahasiswa* bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail->nama = n;
            tail->nim = i;
        }
    }

    void ubahTengah(string n, string i, int pos) {
        if (head == NULL) {
            cout << "List kosong!" << endl;
            return;
        }
        if (pos == 0) {
            head->nama = n;
            head->nim = i;
            return;
        }
        Mahasiswa* bantu = head;
        for (int a = 1; a < pos; a++) {
            if (bantu->next == NULL) {
                cout << "Posisi tidak ditemukan!" << endl;
                return;
            }
            bantu = bantu->next;
       }
        bantu->nama = n;
        bantu->nim = i;
    }

    void hapusDepan() {
        if (head == NULL) {
            cout << "List kosong!" << endl;
            return;
        }
        Mahasiswa* hapus = head;
        head = head->next;
        delete hapus;
    }

    void hapusBelakang() {
        if (head == NULL) {
            cout << "List kosong!" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Mahasiswa* bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            delete tail;
            tail = bantu;
            tail->next = NULL;
        }
    }

    void hapusTengah(int pos) {
        if (head == NULL) {
            cout << "List kosong!" << endl;
            return;
        }
        if (pos == 0) {
            Mahasiswa* hapus = head;
            head = head->next;
            delete hapus;
            return;
        }
        Mahasiswa* bantu = head;
        for (int a = 1; a < pos; a++) {
            if (bantu->next == NULL) {
                cout << "Posisi tidak ditemukan!" << endl;
                return;
            }
            bantu = bantu->next;
        }
        Mahasiswa* hapus = bantu->next;
        bantu->next = bantu->next->next;
        delete hapus;
    }

    void hapusList() {
        while (head != NULL) {
            Mahasiswa* hapus = head;
            head = head->next;
            delete hapus;
        }
        tail = NULL;
    }

    void tampilkan() {
        Mahasiswa* bantu = head;
        int i = 1;
        while (bantu != NULL) {
            cout << "DATA MAHASISWA" << endl;
            cout << "NO. " << i << endl;
            cout << "NAMA\t: " << bantu->nama << endl;
            cout << "NIM\t: " << bantu->nim << endl;
            bantu = bantu->next;
            i++;
        }
    }
};

int main() {
    LinkedList list;
    int pilihan, pos;
    string nama, nim;

    // Masukkan data sesuai urutan
    list.tambahBelakang("Jawad", "23300001");
    list.tambahBelakang("harits", "2311102016");
    list.tambahBelakang("Farrel", "23300003");
    list.tambahBelakang("Denis", "23300005");
    list.tambahBelakang("Anis", "23300008");
    list.tambahBelakang("Bowo", "23300015");
    list.tambahBelakang("Gahar", "23300040");
    list.tambahBelakang("Udin", "23300048");
    list.tambahBelakang("Ucok", "23300050");
    list.tambahBelakang("Budi", "23300099");

    do {
        system("cls");
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan"<< endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Tambah Depan" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.tambahDepan(nama, nim);
                system("pause");
                break;
            case 2:
                cout << "Tambah Belakang" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.tambahBelakang(nama, nim);
                system("pause");
                break;
            case 3:
                cout << "Tambah Tengah" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> pos;
                list.tambahTengah(nama, nim, pos);
                system("pause");
                break;
            case 4:
                cout << "Ubah Depan" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.ubahDepan(nama, nim);
                system("pause");
                break;
            case 5:
                cout << "Ubah Belakang" << endl;
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.ubahBelakang(nama, nim);
                system("pause");
                break;
            case 6:
                cout << "Ubah Tengah" << endl;
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan posisi : ";
                cin >> pos;
                list.ubahTengah(nama, nim, pos);
                system("pause");
                break;
            case 7:
                cout << "Hapus Depan" << endl;
                list.hapusDepan();
                system("pause");
                break;
            case 8:
                cout << "Hapus Belakang" << endl;
                list.hapusBelakang();
                system("pause");
                break;
            case 9:
                cout << "Hapus Tengah" << endl;
                cout << "Masukkan posisi : ";
                cin >> pos;
                list.hapusTengah(pos);
                system("pause");
                break;
            case 10:
                cout << "Hapus List" << endl;
                list.hapusList();
                system("pause");
                break;
            case 11:
                cout << "TAMPILKAN" << endl;
                list.tampilkan();
                system("pause");
               break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                system("pause");
        }
    } while (pilihan != 0);

    return 0;
}
