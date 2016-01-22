// SecView.h

#ifndef SECVIEW_H
#define SECVIEW_H
#include <iostream>
#include "TimerView.h"

class SecView: public TimerView {
public:
	explicit SecView(Timer *timer): TimerView(timer) {}
	virtual void display(std::ostream& os) const;
};

inline void
SecView::display(std::ostream& os) const {
	int sec = timer_->get();
	os << sec << std::endl;
}
#endif