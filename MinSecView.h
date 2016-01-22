// MinSecView.h

#ifndef MINSECVIEW_H
#define MINSECVIEW_H
#include <iostream>
#include "TimerView.h"

class MinSecView: public TimerView {
public:
	explicit MinSecView(Timer *timer): TimerView(timer) {}
	virtual void display(std::ostream& os) const;
};

inline void
MinSecView::display(std::ostream& os) const {
	int sec = timer_->get();
	int min = sec / 60;
	sec = sec % 60;
	os << min << ":" << sec << std::endl;
}
#endif