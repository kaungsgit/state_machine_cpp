#include <iostream>
#include "state.h"
using namespace std;


void print_hello() {
	cout << "Hello World!\n";
}


// just use this simple switch statement... if this doesn't compile on Arduino.
// https://www.youtube.com/watch?v=R2gIVQZU24U&ab_channel=NicolaiNielsen-ComputerVision%26AI

//extern char stopped_state_name;
extern Stopped stopped_state;

//extern char active_state_name[] = "active_state";
extern Active active_state;

//extern char moving_forward_state_name[] = "moving_forward_state";
extern MovingForward moving_forward_state;

class Robot {
public:
	State* state;
	Robot(void);
	void on_event(char* event);
};


Robot::Robot() {
	this->state = &stopped_state;
}
void Robot::on_event(char* event) {
	State* prev_state = state;
	this->state = this->state->on_event(event);
	State* curr_state = state;
	if (prev_state != curr_state) {
		state->perform_action();
	}
}




int main() {
	char test_state_name[] = "test_state123";

	char event1[] = "seven";

	print_hello();

	//State state_test(test_state_name);
	//Stopped stopped_state(stopped_state_name);
	//Active active_state(active_state_name);
	//MovingForward moving_forward_state(moving_forward_state_name);

	//state_test.on_event(event1);

	State* stop_state_ptr;
	State* active_state_ptr;
	State* moving_state_ptr;

	stop_state_ptr = stopped_state.on_event(event1);
	active_state_ptr = active_state.on_event(event1);
	moving_state_ptr = moving_forward_state.on_event(event1);

	Robot my_robot;

	my_robot.on_event(event1);


	return 1;
}




