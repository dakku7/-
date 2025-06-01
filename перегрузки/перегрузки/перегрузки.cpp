#include <iostream>

using namespace std;

class Point {

private:

	int x, y;

public:

	Point() {
		x = 0;
		y = 0;
	}

	Point(int valueX, int valueY) {
		x = valueX;
		y = valueY;
	}

	Point & operator +(int value){
		this->x += value;
		this->y += value;

		return *this;
	}

	Point& operator -(int value) {
		this->x -= value;
		this->y -= value;

		return *this;
	}


	Point& operator ++(int value) {

		Point temp(*this);

		this->x++;
		this->y++;

		return temp;
	}

	Point(const Point &other) {

		this->x = other.x;
		this->y = other.y;

	}

	Point& operator =(const Point &other) {
		
		this->x = other.x;
		this->y = other.y;

		return *this;

	}


	~Point() {

	}


	void showInfo() {
		cout << "\tthis - " << this << endl;
		cout << "\t\tx = " << this->x << endl;
		cout << "\t\ty = " << this->y << endl;

		cout << endl;
	}
};

class myArray {
private:
	int* data;

public:
	int size = 0;
	
	myArray(int value) {
		size = value;
		data = new int[value];

		for (int i = 0; i < this->size; i++) {
			data[i] = i+1;
		}
	}

	myArray(const myArray &other) {
		this->size = other.size;

		this->data = new int[other.size];

		for (int i = 0; i < other.size; i++) {
			this->data[i] = other.data[i];
		}
	}

	myArray & operator =(const myArray& other) {
		this->size = other.size;

		if (this->data != nullptr) {
			delete[] data;

		}
		this->data = new int[other.size];

		for (int i = 0; i < other.size; i++) {
			(this->data[i]) = other.data[i];
		}

		return *this;
	}


	myArray operator +(const myArray& other) {

		myArray temp(this->size);

		if (this->data == nullptr) {
			this->data = new int[other.size];
			for (int i = 0; i < this->size; i++) {
				this->data[i] = 0;
			}
		}

		for (int i = 0; i < this->size; i++) {
			if (i < other.size) {
				temp.data[i] = this->data[i] + other.data[i];
			}

			else {
				temp.data[i] = this->data[i];
			}
		}
		return temp;
	}


	myArray operator -(const myArray& other) {

		myArray temp(this->size);

		if (this->data == nullptr) {
			this->data = new int[other.size];
			for (int i = 0; i < this->size; i++) {
				this->data[i] = 0;
			}
		}

		for (int i = 0; i < this->size; i++) {
			if (i < other.size) {
				temp.data[i] = this->data[i] - other.data[i];
			}

			else {
				temp.data[i] = this->data[i];
			}
		}
		return temp;
	}


	myArray operator *(const myArray& other) {

		myArray temp(this->size);

		if (this->data == nullptr) {
			this->data = new int[other.size];
			for (int i = 0; i < this->size; i++) {
				this->data[i] = 0;
			}
		}

		for (int i = 0; i < this->size; i++) {
			if (i < other.size) {
				temp.data[i] = this->data[i] * other.data[i];
			}

			else {
				temp.data[i] = 0;
			}
		}
		return temp;
	}

	myArray operator /(const myArray& other) {

		myArray temp(this->size);

		if (this->data == nullptr) {
			this->data = new int[other.size];
			for (int i = 0; i < this->size; i++) {
				this->data[i] = 0;
			}
		}

		for (int i = 0; i < this->size; i++) {
			if (i < other.size) {
				temp.data[i] = this->data[i] / other.data[i];
			}

			else {
				temp.data[i] = 0;
			}
		}
		return temp;
	}

	int& operator [](int index) {
		return this->data[index];
	}

	~myArray() {
		delete[] data;
	}




	void showData() {

		cout << "\tThis - " << this << endl;

		cout << "Numbers: ";
		for (int i = 0; i < this->size; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}

};

int main(int argc, char* argv[]) {
	
	/*Point a;
	
	a = a + 5;

	a.showInfo();

	a = a - 2;

	a.showInfo();
	Point b;
	b = a++; 	
	a.showInfo();
	b.showInfo();
*/



	myArray xd(5);
	xd.showData();

	myArray b(2);
	b.showData();

	xd = xd / b;

	xd.showData();


	xd[3] = xd[3] - 10;
	xd[1] = 100;


	xd.showData();

	return 0;
}