#ifndef INT_LIST_HPP
#define INT_LIST_HPP

class IntList {
	private:
		int mLength;
	public:
		void append(int _a);
		void insert(int _idx, int _a);
		int getFirst();
		int getLast();
		int getLength();
		bool isEmpty();

};



#endif
