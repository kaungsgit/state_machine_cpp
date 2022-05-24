#include <iostream>
#include "state.h"

using namespace std;
# define STR_LENGTH 20

extern char stopped_state_name[] = "stopped_state";
extern Stopped stopped_state(stopped_state_name);

extern char active_state_name[] = "active_state";
extern Active active_state(active_state_name);

extern char moving_forward_state_name[] = "moving_forward_state";
extern MovingForward moving_forward_state(moving_forward_state_name);

int strlength(char* s) {
	int c = 0;
	while (*s != '\0')
	{
		c++;
		s++;
	}
	return c;
}



State::State(char* name) {
	this->name = name;
	cout << "Created state: ";
	print_name(this->name);
}

void State::print_name(char* name) {
	//name = this->name;
	for (int i = 0; i < strlength(name); ++i)
	{
		cout << name[i];
	}
	cout << endl;
}

//void State::perform_action() {
//	cout << "Performing state: ";
//	print_name(this->name);
//
//}

State* State::on_event(char* event) {
	cout << "Handling event: ";
	print_name(event);
	return this;

}
//void State::perform_action(void) {
//
//}


// Derived class

Stopped::Stopped(char* name) :State(name) {
}

State* Stopped::on_event(char* event) {
	if (strcmp(event, "seven") == 0) {
		cout << "return active state\n";

		return &active_state;
	}
	else {
		return this;
	}

}
void Stopped::perform_action(void) {
	cout << "Performing state: ";
	print_name(this->name);
}


Active::Active(char* name) :State(name) {
}

State* Active::on_event(char* event) {
	if (strcmp(event, "go") == 0) {
		cout << "return moving forward state\n";

		return &moving_forward_state;
	}
	else {
		return this;
	}

}
void Active::perform_action(void) {
	cout << "Performing state: ";
	print_name(this->name);
}


MovingForward::MovingForward(char* name) :State(name) {
}

State* MovingForward::on_event(char* event) {
	if (strcmp(event, "stop") == 0) {
		cout << "return stopped state\n";

		return &stopped_state;
	}
	else {
		return this;
	}

}
void MovingForward::perform_action(void) {
	cout << "Performing state: ";
	print_name(this->name);
}