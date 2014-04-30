#include "event.h"

class Events : public CObList {
	public : Events() {}

	Events(const Events &e) {}

	void Add(Event<> *e) {
		this->AddHead((CObject*) e);
	}

	void AddToEnd(Event<> *e) {
		this->AddTail((CObject*)e);
	}

	friend std::ostream &operator<<(std::ostream &output, Events &ev){

		POSITION pos;
		for (pos = ev.GetHeadPosition(); pos != NULL;)
		{
			std::cout << *((Event<>*) ev.GetNext(pos)) << std::endl << std::endl;
		}

		return output;
	}
};