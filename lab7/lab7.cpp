// lab7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include "lab7.h"

using namespace std;

class Rect : public CObject {
public:
	Rect() {}
	Rect(const Rect& w){
		this->qq = w.qq;
	}
	Rect(long qq) { ((Rect*) this)->qq = qq; }
	long qq = 0;
	friend std::ostream &operator<<(std::ostream &output, Rect &rect);
	
	Rect& operator=(const Rect& r) {
		//проверка на самоприсваивание
		if (this == &r) {
			return *this;
		}
		qq = r.qq;
		return *this;
	}
};

std::ostream &operator<<(std::ostream &output, Rect &rect) {
	output << rect.qq << "\n";
	return output;
}


void print_vector(vector<long>& v) {
	cout << "Printing vector:" << endl;
	for (long i : v) {
		cout << i << endl;
	}
}

void print_vector_2(vector<long>& v) {
	cout << "Printing vector:" << endl;
	for (vector<long>::iterator it = v.begin(), end = v.end(); it != end; ++it) {
		std::cout << *it << std::endl;
	}
}

void print_vector(vector<Rect>& v) {
	cout << "Printing vector:" << endl;
	for (vector<Rect>::iterator it = v.begin(), end = v.end(); it != end; ++it) {
		std::cout << (*it).qq << std::endl;
	}
}

int main()
{
	vector<long> long_vec;

	for (int i = 0; i < 5; ++i) {
		long_vec.push_back(i + 111);
	}

	cout << "Printing vector:" << endl;
	for (int i = 0; i < long_vec.size(); ++i) {
		cout << long_vec[i] << endl;
	}

	print_vector(long_vec);
	print_vector_2(long_vec);
	
	long_vec.insert(long_vec.end(), 999);

	print_vector(long_vec);

	long_vec.erase(long_vec.begin() + 1);

	print_vector(long_vec);

	cout << long_vec.empty() << endl;
	long_vec.clear();
	cout << long_vec.empty() << endl;

	vector<Rect> rect_vec;

	for (int i = 0; i < 5; ++i) {
		rect_vec.push_back(Rect(i + 2));
	}

	cout << "Printing vector:" << endl;
	for (int i = 0; i < rect_vec.size(); ++i) {
		cout << rect_vec[i].qq << endl;
	}

	print_vector(rect_vec);

	rect_vec.insert(rect_vec.end(), Rect(111));

	print_vector(rect_vec);

	rect_vec.erase(rect_vec.begin() + 1);

	print_vector(rect_vec);

	cout << rect_vec.empty() << endl;
	rect_vec.clear();
	cout << rect_vec.empty() << endl;

	CObArray arr;
	arr.Add(new Rect(1));
	arr.Add(new Rect(2));
	arr.Add(new Rect(3));

	cout << "Printing CObArray:" << endl;
	for (int i = 0; i < arr.GetCount(); ++i) {
		cout << *((Rect*) arr.GetAt(i));
	}

	arr.SetAt(1, new Rect(333));

	cout << "Printing CObArray:" << endl;
	for (int i = 0; i < arr.GetCount(); ++i) {
		cout << *((Rect*)arr.GetAt(i));
	}

	arr.RemoveAt(1);

	cout << "Printing CObArray:" << endl;
	for (int i = 0; i < arr.GetCount(); ++i) {
		cout << *((Rect*)arr.GetAt(i));
	}

	CObArray arr2;
	arr2.Add(new Rect(444));

	arr.Append(arr2);

	cout << "Printing CObArray:" << endl;
	for (int i = 0; i < arr.GetCount(); ++i) {
		cout << *((Rect*)arr.GetAt(i));
	}

	arr2.Copy(arr);

	cout << "Printing CObArray2:" << endl;
	for (int i = 0; i < arr2.GetCount(); ++i) {
		cout << *((Rect*)arr2.GetAt(i));
	}

	system("pause");
	return 0;
}
