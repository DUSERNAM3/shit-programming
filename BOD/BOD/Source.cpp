#include "iostream"
using namespace std;

class proverka {
	int a;
protected:
	int b;
public:
	int c;
	void print() {
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}
};

class nasl: protected proverka {
	int d;
public:
	nasl(int bb) : d(bb) {}
	void prikol() {
		d = b;
	}
};

class nasl2 : nasl {
	int e;
public:
	void pr(){
		e = b;
	}
};

//class salieva {
//	int a, b;
//public:
//	salieva(int aa, int bb) : a(aa), b(bb) { }
//	void operator = (const salieva&);
//};
//void salieva :: operator = (const salieva& q) {
//	a = q.a + 111;
//	b = q.b - 111;
//}
//void main() {
//	salieva net(25, 25);
//	salieva tochnonet = net;
//	net = tochnonet;
//	tochnonet = net;
//}

//class salieva {
//	int a, b;
//public:
//	salieva(int aa, int bb) : a(aa), b(bb) {}
//	friend void print();
//};
//
//void print() {
//	cout << "kruto";
//}

//class Class_Two;
//
//class Class_One {
//	int a, b, c;
//public:
//	Class_One(int x, int y, int z) : a(x), b(y), c(z) {}
//};
//
//class Class_Two {
//	int a2, b2, c2;
//	std::string str;
//public:
//	Class_Two(int x, int y, int z) : a2(x), b2(y), c2(z) {
//		str = "None";
//	}
//	friend int FuncCl1_1(Class_Two nek_obj);
//};
//
//int FuncCl1_1(Class_Two nek_obj) {
//	std::cout << nek_obj.a2 + nek_obj.b2 + nek_obj.c2;
//	return 0;
//}
//
//void main() {
//	Class_Two obj2(10, 15, 20);
//	Class_One  obj1(1, 2, 3);
//	FuncCl1_1(obj2);
//}

//using namespace std;
//class Bogdan {
//public:
//	virtual double trup(float x) { return 5 * x; }
//	double giena(float x) { return 2 + trup(x); }
//};
//class Oleg : public Bogdan {
//public:
//	virtual double trup(float x) { return 50 * x; }
//};
//void main(void) {
//	Oleg pohod;
//	cout << pohod.giena(2) << endl;
//}

class Class_One {
	int a, b, c;
	std::string answer;
public:
	Class_One(int x, int y, int z) : a(x), b(y), c(z) {
		answer = "None";
	}
	Class_One(int x) {
		a = x / 2;
		b = x / 2;
		c = 1;
		answer = "May be";
		cout << "PRIKOL" << endl;
	}
	Class_One(std::string str) {
		a = 1;
		b = 0;
		c = 1;
		answer = str;
		cout << "HUY" << endl;
	}
};


void main() {
	string lol = "d";
	Class_One obj1 = 333;
	Class_One obj2 = lol;
}



//#include<iostream>
//class Class_One {
//	int a, b, c;
//public:
//	Class_One(int x, int y, int z) : a(x), b(y), c(z) {}
//	operator float() {
//		return (float)a + (float)b + (float)c;
//	}
//};
//void main() {
//	Class_One obj1(10, 15, 20);
//	float F;
//	F = obj1;
//	std::cout << F;
//}
//


//void main() {
//	salieva net(25, 25);
//	salieva tochnonet(1, 1);
//	net = tochnonet;
//	print();
//}


//void main() {
//	//int* dima;
//	//dima = new int[1];
//	//dima[0] = 1;
//	//cout << dima[0] << endl;
//	//delete []dima;
//	//int* sovest = new int(25);
//	//cout << *sovest << endl;
//	//proverka* pr = new proverka(25, 25);
//	//pr->print();
//	proverka dima;
//	nasl bog(2);
//	bog.c = 3;
//}