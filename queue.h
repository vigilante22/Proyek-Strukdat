#include <iostream>
#include "peminjam.h"
#define MAX_SIZE 10
using namespace std;

struct myQueue {
private:
	int myqueue[MAX_SIZE], front, rear;

public:
	myQueue(){
		front = -1;
		rear = -1;
	}

	bool isFull(){
		if(front == 0 && rear == MAX_SIZE - 1){
			return true;
		}
		return false;
	}

	bool isEmpty(){
		if(front == -1) return true;
		else return false;
	}

	void enQueue(int value){
			if(front == -1) front = 0;
			rear++;
			myqueue[rear] = value;
	}

	int deQueue(){
		int value;
		if(isEmpty()) {
            return(-1);
		} else {
			value = myqueue[front];
			if(front >= rear){
				front = -1;
				rear = -1;
			} else {
				front++;
		}
		return(value);
		}
	}

	int getTop(){
		return myqueue[front];
	}

	void print(){
		if(isEmpty()) {
			cout << endl << "Queue kosong !" << endl;
		} else {
			cout << "Antrean Sekarang: " << getTop() << endl << endl;
			cout << "============================================================================" << endl;
			cout << "NOMOR ANTRE: " << endl;
			for(int i=front; i<=rear; i++)
				cout << myqueue[i] << "\t";
			cout << endl<< "============================================================================" << endl;
			cout << endl << endl;
			cout << "Antrean Selanjutnya: " << myqueue[front+1]<< endl;
		}
	}
};
