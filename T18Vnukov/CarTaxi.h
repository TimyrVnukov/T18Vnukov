#pragma once
#include <iostream>
#include <string>
using namespace std;
class CarTaxi
{
	string id;
	string mark;
	string name;
	bool isFree;
public:
	CarTaxi(string id, string mark, string name, bool isFree) {
		this->id = id;
		this->mark = mark;
		this->name = name;
		this->isFree = isFree;
	}
	~CarTaxi() {};
	string getId()const& { return id; };
	string getMark()const& { return mark; };
	string getName()const& { return name; };
	bool getIsFree()const& { return isFree; };
	
	void setId(string id) { this->id = id; };
	void setMark(string mark) { this->mark = mark; };
	void setName(string name) { this->name = name; };
	void setIsFree(bool isFree) { this->isFree = isFree; };

	void showInfo() {
		cout << "Id: " << this->id << endl;
		cout << "Mark: " << this->mark << endl;
		cout << "Name: " << this->name << endl;
		cout << "IsFree: " << this->isFree << endl;
		cout << endl;
	}
};

