#pragma once
// A2DD.h
#ifndef STATE_H
#define STATE_H

class State {
public:
	char* name;
	State(char* name);
	void print_name(char* name);
	void perform_action();
	virtual State* on_event(char* event);
};

class Stopped : public State {
public:
	Stopped(char* name);
	State* on_event(char* event);
};

class Active :public State {
public:
	Active(char* name);
	State* on_event(char* event);
};

class MovingForward :public State {
public:
	MovingForward(char* name);
	State* on_event(char* event);
};




#endif
