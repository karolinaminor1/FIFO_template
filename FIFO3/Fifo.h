#pragma once
#include <iostream>
using namespace std;



template <class T> class FQItem {

public:
	FQItem(T key) {
		mKey1 = key;
		pNext = NULL;
	}

	template <class T> friend class Fifo;
	
private:

	T   mKey1;
	FQItem<T>* pNext;
};



template <class T> class Fifo{

public:

	Fifo();
	virtual ~Fifo();
	bool IsEmpty();
	void Enqueue(T pItem);
	void  FQDel();
	void FQClear();


	void printQueue();


private:
	FQItem<T>* pHead;
	FQItem<T>* pTail;
};




template<class T> Fifo<T>::Fifo() {

	pHead = NULL;
	pTail = NULL;
}



template <class T> Fifo<T>::~Fifo() {
   FQClear();
}



template <class T> bool Fifo<T>::IsEmpty() {

	return !(pHead);
}



template <class T> void Fifo<T>::Enqueue(T pinfo) {


	FQItem<T>* p = new FQItem<T>(pinfo);

	if(!p) {
		cout << "memory allocation error" << endl;
		return;
	}

	
	if(this->IsEmpty()) {
		this->pHead = p;
	}

	else  this->pTail->pNext = p;
	this->pTail = p;
	return;
}



template <class T> void  Fifo<T>::FQDel() {
	if(this->IsEmpty()) {
		cout << "Queue is empty" << endl;
		return;
	}

	FQItem<T>* v = this->pHead;
	this->pHead = v->pNext;
	delete v;

	if(this->IsEmpty()) this->pTail = NULL;

}




template <class T> void Fifo<T>::FQClear() {

	

	if(this->IsEmpty()) {
		cout << "Queue is empty" << endl;
	}

	while(!(this->IsEmpty()))   FQDel();

}



template <class T> void Fifo<T>::printQueue() {

	FQItem<T>* p = this->pHead;

	if(!p) {
		cout << "Queue is empty" << endl;
	}

	int i = 0;
	while(p) {

		cout << "Item" << ++i << ": nKey1: " << p->mKey1 << endl;
		p = p->pNext;
	}
	return;

}

