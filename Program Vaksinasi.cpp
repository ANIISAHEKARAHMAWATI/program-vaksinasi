#include <iostream>

using namespace std;

struct vaksin{
	string namaperusahaan;
	string namavaksin;
	int volume;
	int sisa;
};

struct pasien{
    string nama;
    string NIK;
	pasien *next;
};

struct Linkedlist{
    pasien *head, *tail;
    int size;
    void init(){
		head = tail = NULL;
		size = 0;
	}
	bool is_empty(){
		return size==0;
	}
    void add(pasien data){
		pasien *tmp = new pasien();
		tmp->nama = data.nama;
		tmp->NIK = data.NIK;
		if (is_empty()){
			head=tail=tmp;
		} else {
            tmp->next = NULL;
            tail->next = tmp;
            tail = tmp;
		}
		size++;
	}
	void removefirst(){
	    if(is_empty()){
            return;
	    }
	    if(size==1){
            head = tail = NULL;
            size--;
	    }
	    else{
            pasien *p = head;
            head=head->next;
            delete p;
            size--;
	    }
	}
};

struct Stack{
    vaksin stack[10];
    int max=10;
    int top=-1;
    void push(vaksin vak) {
       if(top>=max-1)
       cout<<"Stack Overflow"<<endl;
       else {
          top++;
          stack[top]=vak;
       }
    }
    vaksin pop() {
        if(top<=-1)
        cout<<"Stack Underflow"<<endl;
        else {
            top--;
            return stack[top+1];
        }
    }
    void viewall(){
        if(top>=0) {
            cout<<"Vaksin yang tersedia adalah : "<<endl;
            cout<<"======================================= "<<endl;
            for(int i=top; i>=0; i--){
                cout<<"Vaksin  : "<<endl;
                cout<<"Nama perusahaan : "<<stack[i].namaperusahaan<<endl;
                cout<<"Nama vaksin     : "<<stack[i].namavaksin<<endl;
                cout<<"Volume          : "<<stack[i].volume<<" ml"<<endl;
                cout<<"Sisa Penggunaan : "<<stack[i].sisa<<endl<<endl;
            }
        } else
        cout<<"Tidak ada vaksin yang tersedia"<<endl<<endl;
    }
};
int main()
{
    Stack stk;
    Linkedlist ll;
    ll.init();
    int menu = -1;
    while(true){
        cout<<"Menu : "<<endl;
        cout<<"1. Insert Vaksin "<<endl;
        cout<<"2. lihat semua vaksin"<<endl;
        cout<<"3. Insert Pasien "<<endl;
        cout<<"4. Vaksinasi pasien "<<endl;
        cout<<"5. Exit "<<endl;
        cout<<"Masukkan Inputan : ";
        cin >> menu;
        system("CLS");
        if(menu == 1){
            if(stk.top == 9){
                cout << "Vaksin Penuh"<<endl<<endl;
                system("pause");
            }
            else{
                vaksin vk;
                cout<<"Masukkan nama perusahaan : ";
                cin.sync();
                getline(cin,vk.namaperusahaan);
                cout<<"Masukkan nama vaksin : ";
                cin.sync();
                getline(cin,vk.namavaksin);
                cout<<"Masukkan volume(ml) : ";
                cin >> vk.volume;
                cout <<endl;
                vk.sisa = 3;
                stk.push(vk);
                system("pause");
                system("CLS");
            }
        }else if(menu == 2){
            stk.viewall();
            system("pause");
            system("CLS");
        }else if(menu == 3){
            if(ll.size == 12){
                cout << "antrian pasien penuh"<<endl<<endl;
                system("pause");
                system("CLS");
            }else{
                pasien pas;
                cout<<"Masukkan nama pasien : ";
                cin.sync();
                getline(cin,pas.nama);
                cout<<"Masukkan NIK pasien : ";
                cin >> pas.NIK;
                ll.add(pas);
                cout <<endl;
                system("pause");
                system("CLS");
            }

        }else if(menu == 4){
            if(ll.size == 0){
                cout << "Tidak Ada Pasien"<<endl<<endl;
                system("pause");
                system("CLS");
            }else if(stk.top == -1){
                cout << "Vaksin Habis"<<endl<<endl;
                system("pause");
                system("CLS");
            }else{
                cout<<"Vaksinasi pasien : "<<endl;
                cout<<"================================== "<<endl;
                cout<<"Data Pasien "<<endl;
                cout<<"Nama pasien : " <<ll.head->nama <<endl;
                cout<<"NIK pasien : " <<ll.head->NIK <<endl;
                cout<<"================================== "<<endl;
                vaksin vak = stk.pop();
                cout<<"Vaksin yang digunakan "<<endl;
                cout<<"Nama Perusahaan : "<<vak.namaperusahaan<<endl;
                cout<<"Nama Vaksin : "<<vak.namavaksin<<endl;
                cout<<"Volume : "<<vak.volume<<" ml"<<endl;
                cout<<"================================== "<<endl;
                vak.sisa--;
                if(vak.sisa > 0){
                    stk.push(vak);
                }
                ll.removefirst();
                system("pause");
                system("CLS");
            }
        }else if(menu == 5){
            return 0;
        }else {
            cout<<"Inputan Salah"<<endl<<endl;
        }
    }
    return 0;
}
