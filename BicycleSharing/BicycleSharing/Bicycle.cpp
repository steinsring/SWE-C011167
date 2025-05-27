#include "Bicycle.h"

Bicycle::Bicycle(std::string id, std::string name) {
	this->id = id;
	this->name = name;
}

std::string Bicycle::getID() {
	return this->id;
}
std::string Bicycle::getName() {
	return this->name;
}