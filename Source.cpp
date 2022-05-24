#include <iostream>
#include "state.h"
using namespace std;


void print_hello() {
	cout << "Hello World!\n";
}


// 
//char stopped_state_name[] = "stopped_state";
//Stopped stopped_state(stopped_state_name);
//
//char active_state_name[] = "active_state";
//Active active_state(active_state_name);
//
//char moving_forward_state_name[] = "moving_forward_state";
//MovingForward moving_forward_state(moving_forward_state_name);



//class State {
//public:
//	char* name;
//
//	State(char* name) {
//		this->name = name;
//		cout << "Created state: ";
//		print_name(this->name);
//	}
//
//	void print_name(char* name) {
//		//name = this->name;
//		for (int i = 0; i < strlength(name); ++i)
//		{
//			cout << name[i];
//		}
//		cout << endl;
//	}
//
//	void perform_action() {
//		cout << "Performing state: ";
//		print_name(this->name);
//
//	}
//
//	void on_event(char* event) {
//		cout << "Handling event: ";
//		print_name(event);
//
//	}
//};
//
//
//// Derived class
//class Stopped : public State {
//public:
//	Stopped(char* name) :State(name) {
//	}
//
//	void on_event(char* event) {
//		if (strcmp(event, "seven") == 0) {
//			cout << "return active state\n";
//
//			//return active_state;
//		}
//
//	}
//};
//
//
//class Active : public State {
//public:
//	Active(char* name) :State(name) {
//	}
//
//	void on_event(char* event) {
//		if (strcmp(event, "go") == 0) {
//			cout << "return moving forward state\n";
//
//			//return moving_forward_state;
//		}
//
//	}
//};
//
//
//class MovingForward : public State {
//public:
//	MovingForward(char* name) :State(name) {
//	}
//
//	void on_event(char* event) {
//		if (strcmp(event, "stop") == 0) {
//			cout << "return stopped state\n";
//
//			//return stopped_state;
//		}
//
//	}
//};

// just use this simple switch statement...
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
	this->state = this->state->on_event(event);
}




int main() {
	char test_state_name[] = "test_state123";
	//char stopped_state_name[] = "stopped_state";
	//char active_state_name[] = "active_state";
	//char moving_forward_state_name[] = "moving_forward_state";

	char event1[] = "seven";


	print_hello();

	State state_test(test_state_name);
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

	//my_robot.on_event();
	Robot my_robot;
	//Line line;
	//line.setLength(0.6);
	my_robot.on_event(event1);


	return 1;
}



//// abstract base class
//#include <iostream>
//using namespace std;

//class Polygon {
//protected:
//	int width, height;
//public:
//	void set_values(int a, int b)
//	{
//		width = a; height = b;
//	}
//	virtual int area(void) = 0;
//	//virtual Polygon return_derived_obj(void) = 0;
//};
//
//class Rectangle : public Polygon {
//public:
//	int area(void)
//	{
//		return (width * height);
//	}
//
//	Polygon* return_derived_obj(void) {
//		return new Triangle;
//	}
//};
//
//class Triangle : public Polygon {
//public:
//	int area(void)
//	{
//		return (width * height / 2);
//	}
//};
//
//int main() {
//	Rectangle rect;
//	Triangle trgl;
//	Polygon* ppoly1 = &rect;
//	Polygon* ppoly2 = &trgl;
//	ppoly1->set_values(4, 5);
//	ppoly2->set_values(4, 5);
//	cout << ppoly1->area() << '\n';
//	cout << ppoly2->area() << '\n';
//	return 0;
//}
