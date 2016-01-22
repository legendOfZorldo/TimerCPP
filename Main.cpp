// Main.cpp

#include "Timer.h"
#include "KeyboardController.h"
#include "SecView.h"
#include "MinSecView.h"
#include "TickView.h"
using namespace std;

int main() {
	KeyboardController kc;
	Timer *t = new Timer();
	SecView sv(t);
	MinSecView msv(t);
	TickView tv(t);
	kc.subscribe(t);
	kc.start();
}