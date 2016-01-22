// TickeView.h

#ifndef TICKVIEW_H
#define TICKVIEW_H
#include <iostream>
#include "TimerView.h"

class TickView: public TimerView {
public: 
	explicit TickView(Timer *timer): TimerView(timer) {}
	virtual void display(std::ostream& os) const;
};

inline void
TickView::display(std::ostream& os) const {
	os << "*" << std::endl;
}
#endif