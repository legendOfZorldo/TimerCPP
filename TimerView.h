// TimerView.h

#ifndef TIMERVIEW_H
#define TIMERVIEW_H
#include <iostream>
#include "Observer.h"
#include "Timer.h"

class TimerView: public Observer {
public: 
	explicit TimerView(Timer *timer) 
		: timer_(timer) {
			timer_->subscribe(this);
		}

	virtual void update(Subject *s);					// from Observer class
	virtual void display(std::ostream& os) const = 0;

protected:
	Timer *timer_;
};

inline void
TimerView::update(Subject *s) {
	display(std::cout);
}	
#endif