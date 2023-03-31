#include "TFifo.h"

/*
TFifo::TFifo(int nSize) {

	mFQItems = new FQINFO * [nSize];
	mMaxElem = nSize;
	mNoElem = 0;
	mHead = 0;
	mTail = 0;

}


TFifo::~TFifo() {
	delete[] mFQItems;
}


bool TFifo::IsEmpty() {
	if(this->mNoElem == 0) return true;
	return false;

}


void TFifo::Enqueue(FQINFO* pItem) {

	if(this->mNoElem == this->mMaxElem) {
		cout << "Tfifo is full" << endl;
		return;
	}
	
	this->mFQItems[this->mTail] = pItem;
	this->mTail = (this->mTail + 1) % this->mMaxElem;
	
	++(this->mNoElem);

}


void  TFifo::FQDel() {

	if(this->IsEmpty()) {
		cout << "Queue is empty\n" << endl;
		return;
	}

	this->mFQItems[this->mHead] = NULL;
	this->mHead = (this->mHead + 1) % (this->mMaxElem);

	--(this->mNoElem);
}



FQINFO* TFifo::FQDequeue() {

	if(this->IsEmpty()) {
		return NULL;
	}

	FQINFO* v = this->mFQItems[this->mHead];
	this->FQDel();
	 return v;
}


void TFifo::FQClear(void(__cdecl* freeMem)(const void*)) {
	
	if(!freeMem) {
		cout << "Invalid function address\n" <<  endl;
		return;
	}

	if(this->IsEmpty()) {
		cout << "Queue is empty\n" << endl;
		return;
	}

	while(!this->IsEmpty()) freeMem(this->FQDequeue());
	return;
}


void TFifo::printQueue() {

	if(this->IsEmpty()) {
		cout << "Queue is empty\n" << endl;
	}

	
		for(int i = 0; i < this->mNoElem; ) {
			int k = (this->mHead + i) % this->mMaxElem;
			cout << "Item" << ++i << ": nKey1: " << this->mFQItems[k]->mKey << " nKey2: " << this->mFQItems[k]->mKey2 << endl;
		}
	
}


void TFifo::freeInfo(const void* ItemInfo) {
	delete (( FQINFO* )ItemInfo);
}
*/