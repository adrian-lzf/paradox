#include <iostream>
using namespace std;

template <class T>
class MyList{
	private:
		T *a;
		int size;
		
		void quickSort(const int lh, const int rh){
		//This function can realize the sorting by a quick sort method.
			int i, j;
			T mid, t;
			i = lh; j = rh; mid = a[(i+j)/2]; 
			while (i <= j){
				while(a[j] > mid) j--;
				while(a[i] < mid) i++;
				if(i <= j){
					t = a[i]; a[i] = a[j]; a[j] = t;
					i++; j--;
				}
			}
			if(lh < j) quickSort(lh, j);
			if(i < rh) quickSort(i, rh);
		}
		
	public:
		MyList(){
		//No parameters, no elements.
			size = 0;
			a = new T [size];
		}
		
		
		MyList(int num, const T &item){
		//Fill the element "item" into an empty list by "num" times.
			try{
				a = new T [num];
				size = num;
				for (int i=0; i<num; ++i) a[i] = item;
			}
			catch(...){
				cerr << "Please input a positive number!";
				exit(1);
			}			
		}
		
		
		MyList(const MyList &l){
		//Deep copy another MyList.
			size = l.get_size();
			a = new T[size];
			for (int i=0; i<size; ++i) a[i] = l[i];	
		}
    	
		
		MyList(T *arr, int len){
		//Create a list formed by the first "len" elements of "arr".
			try{
				a = new T[len];
				size = len;
				for (int i=0; i<len; ++i) a[i] = arr[i];
			}
			catch(...){
				cerr << "Please input a positive number!";
				exit(1);
			}
		}

		
		void push(const T &item){
		//Push "item" into the last position.
			try{
				size++;
				MyList tmp(*this);
				delete [] a;
				a = new T[size];
				for (int i=0; i<size-1; ++i) a[i] = tmp[i];
				a[size-1] = item;
			}
			catch(...){
				cerr << "Please input a suitable type!";
				exit(1);
			}
		}
		
		
		T pop(){
		//Pop the last element out of the list and return it to realize the stack structure.
			try{
				size--;
				MyList tmp(*this);
				T t = a[size];
				delete [] a;
				a = new T[size];
				for (int i=0; i<size; ++i) a[i] = tmp[i];
				return t;
			}
			catch(...){
				cerr << "This is an empty set!";
				exit(1);
			}
		}
		
		
		void insert(int index, const T &item){
		//Insert the "item" in the position of "index", negative index allowed.
			try{
				if(index>size) throw 0;
			}
			catch(...){
				cerr << "This index is out of range!";
				exit(1);
			}
			if (index < 0){
				index += size;
			}
			int i;
			MyList tmp(*this);			
			size++;
			delete [] a;
			a = new T [size];
			for (i=0; i<index; ++i) a[i] = tmp[i];
			a[i++] = item;
			for (; i<size; ++i) a[i] = tmp[i-1];
		}
		
		
		void clean(){
		//Clean up the list.
			size = 0;
			delete [] a;
			a = new T [0];
		}
		
		
		int get_size() const{
		//Return the amount of the elements of the list
			return size;
		}
		
		
		void erase(int start, int end){
		//Erase the elements from the position "start" to the "end" (edges included), negative index allowed.
	    	if (start < 0){
	    		start += size;
			}
			if (end < 0){
				end += size;
			}
			try{
				if (start > end) throw 0;
			}
			catch(...){
				cerr << "Please input the reasonable index!";
				exit(1);
			}
			try{
				if (start>=size || end>=size) throw 1;
			}
			catch(...){
				cerr << "Your index is out of range!";
				exit(1);
			}
			int i;
			MyList tmp(*this);
			size -= end-start+1;
			delete [] a;
			a = new T [size];
			for (i=0; i<start; ++i) a[i] = tmp[i];
			for (; i<size; ++i) a[i] = tmp[i-start+1+end];
		}
		
		
		T get_item(int index){
		//Return the element in the position "index" of the list, negative index allowed.
			try{
				if(index >= size) throw 0;
			}
			catch(...){
				cerr << "Your index is out of range!";
				exit(1);
			}
			if (index < 0) index += size;
			return a[index];
		}
		
		
		MyList get_item(int start, int end){
		//Return the elements from the position "start" to the "end", negative index allowed.
			if (start < 0) start += size;
			if (end < 0) end += size;
			if (start > end) {MyList tmp; tmp.a = new T [0]; tmp.size = 0; return tmp;}
			else {
				int i;
				MyList tmp;
				for (i=0; i<end-start+1; ++i) tmp += a[start+i];
				return tmp;
			}
		}
		
		
		int count(const T &item){
		//Return the amount of the same elements with "item".
			int c = 0;
			for (int i=0; i<size; ++i) if(a[i]==item) c++;
			return c;
		}
		
		
		void remove(const T &item){
		//Remove the first element same with "item". If not found, do nothing.
			int i;
			for (i=0; i<size; ++i) if(a[i]==item) break;
			if(i!=size){
				MyList tmp(*this);
				size--;
				a = new T [size];
				for (int j=0; j<i; ++j) a[j] = tmp[j];
				for (int j=i+1; j<size+1; ++j) a[j-1] = tmp[j];
			}
		}


		friend MyList operator + (const MyList &l1, const MyList &l2){
		//Merge two Mylists.
			MyList tmp(l1);
			tmp += l2;
			return tmp;
		}
		
    	
		friend MyList operator + (const MyList &l1, const T &item){
    	//Push "item" into the last position of the list, original list preserved.
			MyList tmp();
			tmp.size = l1.size + 1;
			delete [] tmp.a;
			for (int i = 0; i < l1.size; ++i) tmp.a[i] = l1.a[i];
			tmp.a[tmp.size-1] = item;
			return tmp;
		}
		
		
		MyList &operator = (const MyList &l){
		//Give the value.
			if (&l==this) return *this;
			size = l.get_size();
			delete [] a;
			a = new T [size];
			for (int i=0; i<size; ++i){
				a[i] = l[i];
			}
			return *this;
		}
		
				
		MyList &operator += (const T &item){
		//Add the item to the last position.
			push(item);
			return *this;
		}
		
		
		MyList &operator += (const MyList &l){
		//Merge two MyLists.
			for(int i=0; i<l.size; i++) push(l.a[i]);
			return *this;
		}
		
		
		T &operator [](int index) const {
		//Return the element of the position "index", negative index allowed.
			try{
				if(index>=size) throw 0;
			}
			catch(...){
				cerr << "Your index is out of range!";
				exit(1);
			}
			if (index < 0) index += size;
			return a[index];
		}
		
		
		friend ostream & operator<<(ostream &os, const MyList &obj){
		//Output MyList in a way like that of Python. For example, [1, 2, 5, 4, 1].
			if(obj.size > 0){
				os << "[";
				for (int i=0; i<obj.size-1; ++i) os << obj.a[i] << ", ";
				os << obj.a[obj.size-1] << "]" << endl;
				return os;
			}
			else{
				os << "[]";
				return os;
			}
		}


		void sort(bool less=true){
		//Use quick sort method to sort the list.
		//If less == false, then reverse the list.
			quickSort(0, size-1);
			if (!less) reverse();
		}
		
		
		void reverse(){
		//Reverse the list.
			int i;
			MyList tmp(*this);
			delete [] a;
			a = new T [size];
			for(i=0; i<size; ++i) a[i] = tmp[size-1-i];
		}
		
		
		void double_space(){
		//Double the space of the list.
			try{
				if (size==0) throw 0;
			}
			catch(...) {
				cout << "Since the size is zero, it cannot be doubled!"; 
				return;
			}
			size *= 2;
			MyList tmp(*this);
			delete [] a;
			a = new T [size];
			for (int i=0; i<size/2; ++i) a[i] = tmp[i]; 
		}

		~MyList(){delete [] a;}
};
		
int main(){
	MyList<int> a, b;
	int i;
	for (i=0; i<5; ++i)
		a.push(i); // a = [0, 1, 2, 3, 4]
	a[3] = 15; // a = [0, 1, 2, 15, 4]
	a.sort();// a = [0, 1, 2, 4, 15]
	a.reverse(); // a = [15, 4, 2, 1, 0]
	a += 12; // a = [15, 4, 2, 1, 0, 12]
	for (i=0; i<a.get_size(); ++i)
			cout<<a[i]<<endl;
    b = a.get_item(4, -3); // b = [] *Èôstart > end£¬·µ»Ø¿ÕÊý×é
   	b = a.get_item(3, -1); // b = [1, 0, 12] 
	a += b; // a = [15, 4, 2, 1, 0, 12, 1, 0, 12]
	for (i=0; i<a.get_size(); ++i)
		cout<<a.get_item(i)<<endl;
	cout<<a.count(5)<<endl; // 0
	b.clean(); // b = []
	cout<<b.get_size()<<endl; // 0
	a.erase(2, 5); // a = [15, 4, 1, 0, 12]
	b = a + a; // b = [15, 4, 1, 0, 12, 15, 4, 1, 0, 12]
	b.insert(3, 116); // b = [15, 4, 1, 116, 0, 12, 15, 4, 1, 0, 12]
	b.remove(4); // b = [15, 1, 116, 0, 12, 15, 4, 1, 0, 12]
	cout<<b<<endl;
	MyList<double> c(10, 3.14); // c = [3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14]
	for (i=0; i<100; ++i)
		c.push(1.1*i); // c = [3.14, 3.14 ... 3.14, 0, 1.1, 2.2, ...]
	cout<<c.get_item(100, 105)<<endl;  // c = [... 99, 100.1, 101.2, 102.3, 103.4, 104.5, ...]
	return 0;	
}
