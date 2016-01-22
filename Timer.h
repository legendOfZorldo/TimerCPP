// Timer.h

#ifndef TIMER_H
#define TIMER_H
#include <iostream>
#include <thread>
#include <atomic>
#include <string>
#include <unistd.h>
#include "Subject.h"
#include "Observer.h"
#include "KeyboardController.h"

class Timer: public Observer, public Subject {
public:
	Timer() {
		sec_ = 0;
		ticking_ = false;
		std::thread timerThread(&Timer::run, this);
		timerThread.detach();
	}

	virtual void start();							// start the timer
	virtual void stop();							// stop the timer
	virtual void reset();							// reset timer to 0

	unsigned long get() const {						// returns number of seconds elapsed
		return sec_;
	}

	Timer(const Timer&) = delete;
	Timer& operator=(const Timer&) = delete;

	virtual void update(Subject *);

private:
	std::atomic_ulong sec_;							// number of seconds elapsed
	std::atomic_bool ticking_;						// is timer ticking or not
	void run();										// function executed by thread
};

inline void
Timer::start() {
	ticking_ = true;
}

inline void
Timer::stop() {
	ticking_ = false;
}

inline void
Timer::reset() {
	sec_ = 0;
}
 
inline void
Timer::update(Subject *s) {
	std::string cmd = ((KeyboardController *) s)->getCommand();
	if (cmd == "start") {
		start();
	} else if (cmd == "halt") {
		stop();
	} else if (cmd == "reset") { 
		reset();
	}
}

inline void
Timer::run() {
	while(1) {
		if (ticking_) {
			sec_++;
			notify();
		}
		sleep(1);	
	}
}
#endif