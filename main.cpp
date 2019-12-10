#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

using namespace std;

int menu_action();
int menu_antre();

myStack Stack;
myQueue Queue;

int main(){
	srand(time(NULL));
	Queue.deQueue();
	TMP tampung[1000];
	int menu, nomor = rand()%101;
	string val;
	Stack.setawal();
	Stack.push("1 Jam mahir membuat Website");
	Stack.push("Tuntunan Shalat");
	Stack.push("Rahasia menuju kesuksesan");
	do{
		menu = menu_antre();
		switch(menu){
			case 1:
					if(Queue.isFull()){
						cout << endl<< "Queue sudah penuh !";
						cin.get();
					} else {
						cout << "Masukan Nama anda: ";getline(cin, user[nomor].nama);
						cout << "Nomor antrean anda adalah: " << nomor << endl;
						cin.get();
						Queue.enQueue(nomor);
						nomor++;
					}
					break;
			case 2:
					if(Queue.isEmpty()) {
						cout << endl << "Queue kosong !" << endl;
						cin.get();
					} else {
						do{
							menu = menu_action();
							switch(menu){
								case 1:
									cout << "Masukan Nama buku yang mau dikembalikan: ";getline(cin, val);
									Stack.push(val);
									break;
								case 2:
									if(Stack.isEmpty()){
										cout << "Tumpukan Kosong" << endl;
									}else{
										char cek;
										int i=0;
										string tmp;
										do{
											if(Stack.isEmpty()){
												cout << "Tumpukan Kosong" << endl;
												cin.get();
												cin.ignore();
												break;
											}else{
												cout << "Apakah anda ingin meminjam buku " << Stack.getTop() << ": (y/n) ";
												cin >> cek;
												if(cek!='y')
													tampung[i++].data = Stack.getTop();
												Stack.pop();
												system("cls");
											}
										}while(cek!='y');
										for(int j=0; j<i; j++){
											Stack.push(tampung[j].data);
										}
									}
									break;
								case 3:
									Stack.print();
									cin.get();
									break;
								case 4:
									Queue.deQueue();
									break;
								default:
									cout <<"\t\nPilihan tidak ada";
									cin.get();
									break;
							}
							system("clear");
						}while (menu != 4);
						menu = 5;
					}
					break;
			case 3:
					Queue.print();
					cin.get();
					break;
			case 4:
					exit(0);
		}
		system("cls");
	}while (menu != 4);

		cin.get();
		return 0;
}

int menu_action(){
	cout<<"\t\t     PERPUSTAKAAN BUKU"<<endl<<endl;
	int menu;
	cout << "Nomor Antrean: " << Queue.getTop() << endl;
	cout << "Atas Nama: " << user[Queue.getTop()].nama <<endl<<endl<<endl;
	cout << "MENU : "<<endl<<endl;
	cout << "1. Kembalikan Buku"<<endl;
	cout << "2. Pinjam Buku"<<endl;
	cout << "3. Lihat Daftar Buku"<<endl;
	cout << "4. kembali"<<endl<<endl;
	cout << "Pilihan : "; cin >> menu;
	cin.ignore();
	system("cls");
	return menu;
}

int menu_antre(){
	cout<<"\t\t     PERPUSTAKAAN BUKU"<<endl<<endl;
	int menu;
	cout << "MENU : "<<endl<<endl;
	cout << "1. Ambil Antrean"<<endl;
	cout << "2. Panggil Antrean"<<endl;
	cout << "3. Lihat Antrean"<<endl;
	cout << "4. Exit..."<<endl<<endl;
	cout << "Pilihan : "; cin >> menu;
	cin.ignore();
	system("cls");
	return menu;
}
