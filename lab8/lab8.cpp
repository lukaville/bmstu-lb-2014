#include "stdafx.h"
#include "lab8.h"
#include <list>
#include "event.h"
#include "events.h"

using namespace std;

typedef list<double> double_list;

void lPrint(list<double>& input_list)
{
	list<double>::iterator iter;

	int i = 0;
	if (!input_list.empty()) {
		for (iter = input_list.begin(); iter != input_list.end(); iter++, i++)
		{
			cout << "input_list(" << i << ") = " << *iter << endl;
		}
	}
	else {
		cout << "List is empty" << endl;
	}
};

bool greater(double x, double y){
	return x > y;
}

template <typename T> void LPrint(list<T> l){
	list<T>::iterator iter;
	int i = 0;
	for (iter = l.begin(); iter != l.end(); iter++, i++)
	{
		cout << "l(" << i << ") = " << *iter << endl;
	}
}

bool is_greater_ten(double x){
	return (x > 10.0);
}

bool is_test(Event<> *e) {
	return e->getEventType() > 2;
}

bool comp(Event<> *x, Event<> *y) {
	return x->getEventType() > y->getEventType();
}


int main(){
	system("chcp 1251 > nul");

	list<double> l1(2);
	list<double> l2(4, 5);
	list<double> l3(l2);
	list<double> l4;

	lPrint(l2);
	for (int i = 0; i < 6; ++i){
		l4.push_back(9.0034 + i);
	}

	int i = 0;
	for (list<double>::iterator it = l4.begin(); it != l4.end(); ++it){
		cout << "l(" << i++ << ") = " << *it << endl;
	}

	cout << endl;

	l4.push_front(0.234);
	lPrint(l4);
	cout << '\n';
	LPrint<double>(l4);
	cout << endl;

	double_list l5;
	l5.assign(l4.begin(), l4.end());
	lPrint(l5);

	cout << endl;
	double_list::iterator iter;
	iter = l5.begin();
	l5.insert(iter, 65.5434);
	lPrint(l5);

	cout << endl;
	l5.erase(iter);
	lPrint(l5);
	l5.remove(65.5434);
	cout << endl;
	lPrint(l5);

	cout << endl;
	l5.remove_if(is_greater_ten);
	lPrint(l5);

	cout << "\nSorting\n";

	l4.sort();
	l4.sort(less<double>());
	lPrint(l4);
	cout << endl;
	l4.sort(greater);
	lPrint(l4);

	cout << "\nIs list empty? " << ((l4.empty()) ? "Yes" : "No") << endl;

	l4.clear();

	cout << "Is list empty? " << ((l4.empty()) ? "Yes" : "No") << endl;

	std::list<Event<>*> myList;
	myList.push_back(new Event<>("Тест 1", "Москва", 0, EVENT_TYPE_CONFERENCE));
	myList.push_back(new Event<>("Тест 2", "Москва", 0, EVENT_TYPE_CONFERENCE));

	myList.reverse();

	for (auto i = myList.begin(); i != myList.end(); ++i) {
		cout << **i << endl;
	}

	myList.sort(comp);
	myList.remove_if(is_test);
	myList.reverse();
	myList.insert(myList.begin(), new Event<>("Тест 3", "Москва", 0, EVENT_TYPE_CONFERENCE));
	myList.pop_front();
	myList.erase(myList.begin());
	myList.push_back(new Event<>("Тест 4", "Москва", 0, EVENT_TYPE_CONFERENCE));
	myList.clear();

	cout << "Is list empty? " << ((myList.empty()) ? "Yes" : "No") << endl;

	CObList list;
	list.AddTail(new Event<>("Тест 1", "Москва", 0, EVENT_TYPE_CONFERENCE));
	list.AddTail(new Event<>("Тест 2", "Москва", 0, EVENT_TYPE_CONFERENCE));
	list.AddHead(new Event<>("Тест 3", "Москва", 0, EVENT_TYPE_CONFERENCE));
	list.InsertAfter(list.GetHeadPosition(), new Event<>("Тест 4", "Москва", 0, EVENT_TYPE_CONFERENCE));
	list.InsertBefore(list.GetTailPosition(), new Event<>("Тест 5", "Москва", 0, EVENT_TYPE_CONFERENCE));

	POSITION pos;
	for (pos = list.GetHeadPosition(); pos != NULL;)
	{
		cout << *((Event<>*) list.GetNext(pos)) << endl << endl;
	}

	for (pos = list.GetTailPosition(); pos != NULL;)
	{
		cout << *((Event<>*) list.GetPrev(pos)) << endl << endl;
	}

	list.RemoveHead();
	list.RemoveTail();

	cout << "Elements count: " << list.GetCount() << endl;

	cout << "Is list empty? " << ((list.IsEmpty()) ? "Yes" : "No") << endl;

	Events* evts = new Events();
	evts->Add(new Event<>("Тест 1", "Москва", 0, EVENT_TYPE_CONFERENCE));
	evts->Add(new Event<>("Тест 2", "Москва", 0, EVENT_TYPE_CONFERENCE));
	evts->Add(new Event<>("Тест 3", "Москва", 0, EVENT_TYPE_CONFERENCE));
	evts->AddToEnd(new Event<>("Тест 4", "Москва", 0, EVENT_TYPE_CONFERENCE));
	evts->Add(new Event<>("Тест 5", "Москва", 0, EVENT_TYPE_CONFERENCE));

	cout << *evts << endl;

	system("pause");
	return 0;
}
