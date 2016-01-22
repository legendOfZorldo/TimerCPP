// Subject.h 

#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>
#include "Observer.h"

class Subject {
public: 
	virtual ~Subject() {}
	virtual void subscribe(Observer *obs); 			// subscribe an observer
	virtual void unsubscribe(Observer *obs);		// unsubscribe an observer
	virtual void notify();							// ask each subscribed observer to update itself
protected:
	Subject() {};
private:
	std::list<Observer *> observers_;				// list of observers
};

inline void
Subject::subscribe(Observer *obs) {
	observers_.push_back(obs);
}

inline void
Subject::unsubscribe(Observer *obs) {
	observers_.remove(obs);
}

inline void
Subject::notify() {
	for (auto& p : observers_) {
		p->update(this);
	}
}
#endif