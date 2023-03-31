#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T, class U> class FQINFO {

public:
	

	FQINFO( T key, U key2 ) {
		mKey1 = key;
		mKey2 = key2;
	}

	virtual ~FQINFO() {}

	template <class T, class U> friend class TFifo;

private:

	T   mKey1;
	U   mKey2;

};


template <class T, class U> class TFifo
{
public:

	TFifo( int nSize );
	virtual ~TFifo();
	bool IsEmpty();
	void Enqueue(FQINFO<T,U>* pItem);
	void  FQDel();
	FQINFO<T,U>* FQDequeue();
	void FQClear(void(__cdecl* freeMem)(const void*));
	void freeInfo(const void*);


	void printQueue();

 private:


	FQINFO<T,U>** mFQItems;					
	int mHead;
	int mTail;
	int mMaxElem;
	int mNoElem;
};

template <class T, class U> TFifo<T,U>::TFifo( int nSize ) {

	mFQItems = new FQINFO<T,U> * [nSize];
	mMaxElem = nSize;
	mNoElem = 0;
	mHead = 0;
	mTail = 0;

}


template <class T, class U> TFifo<T,U>::~TFifo() {
	delete[] mFQItems;
}


template <class T, class U> bool TFifo<T,U>::IsEmpty() {
	if( this->mNoElem == 0 ) return true;
	return false;

}


template <class T, class U> void TFifo<T, U>::Enqueue( FQINFO<T, U>* pItem ) {

	if( this->mNoElem == this->mMaxElem ) {
		cout << "Tfifo is full" << endl;
		return;
	}

	this->mFQItems[ this->mTail ] = pItem;
	this->mTail = ( this->mTail + 1 ) % this->mMaxElem;

	++(this->mNoElem);

}


template <class T, class U> void TFifo<T,U>::FQDel() {

	if( this->IsEmpty() ) {
		cout << "Queue is empty\n" << endl;
		return;
	}

	this->mFQItems[ this->mHead ] = NULL;
	this->mHead = ( this->mHead + 1 ) % ( this->mMaxElem );

	--(this->mNoElem);
}



template <class T, class U> FQINFO<T,U>* TFifo<T,U>::FQDequeue() {

	if( this->IsEmpty() ) {
		return NULL;
	}

	FQINFO* v = this->mFQItems[ this->mHead ];
	this->FQDel();
	return v;
}


template <class T, class U> void TFifo<T,U>::FQClear( void(__cdecl* freeMem)(const void*) ) {

	if( !freeMem ) {
		cout << "Invalid function address\n" << endl;
		return;
	}

	if(this->IsEmpty()) {
		cout << "Queue is empty\n" << endl;
		return;
	}

	while(!this->IsEmpty()) freeMem(this->FQDequeue());
	return;
}


template< class T, class U> void TFifo<T,U>::printQueue() {

	if( this->IsEmpty() ) {
		cout << "Queue is empty\n" << endl;
	}


	for( int i = 0; i < this->mNoElem;  ) {
		int k = ( this->mHead + i ) % this->mMaxElem;
		cout << "Item" << ++i << ": nKey1: " << this->mFQItems[k]->mKey1 << " nKey2: " << this->mFQItems[k]->mKey2 << endl;
	}

}


template <class T, class U> void TFifo<T,U>::freeInfo( const void* ItemInfo ) {
	delete ( ( FQINFO* )ItemInfo );
}

