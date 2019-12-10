#include <iostream>
#include "Buku.h"
#define MAX_STACK_SIZE 10
using namespace std;

struct Element{
	buku data;
	int top;
	Element *next;
};

struct TMP{
	string data;
};

class myStack{
	private:
	Element tumpuk;
	Element *head = NULL;

	public:
	void setawal(){
		tumpuk.top = -1;
	}

	bool isEmpty(){
        if(tumpuk.top == -1){
			return 1;
		}else{
			return 0;
		}
    }

	bool isFull(){
        if(tumpuk.top == MAX_STACK_SIZE-1){
			return 1;
		}else{
			return 0;
		}
    }

    void push(string input){
		if(isFull()){
			cout << "Tumpukan Penuh";
			cin.get();
		}else{
			Element *tmp = new Element;
			tmp->data.judul = input;
			tmp->next=NULL;
			if(isEmpty())
			{
				head=tmp;
				head->next=NULL;
			}else{
				tmp->next=head;
				head=tmp;
			}
			tumpuk.top++;
		}
	}

	void pop(){
		if (isEmpty()){
			cout<<"\nTumpukan Kosong\n";
		}else{
			Element *tmp = new Element;
			tmp = head;
			head = head->next;
			delete tmp;
			tumpuk.top--;
		}
	}

	string getTop(){
		if(isEmpty()){
			return "Tumpukan Kosong";
		}else{
			return head->data.judul;
		}
	}

	void print(){
		if(isEmpty()){
			cout << "Tumpukan Kosong" << endl;
		}else{
			cout << "Daftar Buku: " << endl;
			Element *tmp = new Element;
			tmp = head;
			int i=0;
			while(tmp!=NULL)
			{
				cout<< i+1 <<". " << tmp->data.judul<< endl;
				tmp=tmp->next;
				i++;
			}
		}
	}
};