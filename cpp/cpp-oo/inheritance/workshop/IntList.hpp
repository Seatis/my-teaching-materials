#ifndef INT_LIST_HPP
#define INT_LIST_HPP

class IntList {
	private:
		int mLength;
	//We dont' want others to set the lenght of this list
	protected:
		void setLength(int _length);
	public:
		// We want the descendant classes to implement (defin)
		// How these methods will actually work. 
		virtual void append(int _a) = 0;
		virtual void insert(int _idx, int _a) = 0;
		virtual int getFirst() = 0;
		virtual int getLast() = 0;
		int getLength();
		virtual bool isEmpty() = 0;

};

void IntList::setLength(int _length) {
	mLength = _length;
}

int IntList::getLength() {
	return mLength;
}


#endif
