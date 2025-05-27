#include "Member.h"

// 생성자: 입력된 id, password, phone으로 Member 객체를 초기화
Member::Member(std::string id, std::string password, std::string phone) : phone(phone) {
	this->id = id;
	this->password = password;
}

std::string Member::getPhone() {
	return phone;
}

void Member::rentBicycle(Bicycle bicycle) {
	rent_bicycle_list[rent_bicycle_count++] = bicycle;
}

Bicycle* Member::getRentBicycleList() {
	return rent_bicycle_list;
}

int Member::getRentBicycleCount() {
	return rent_bicycle_count;
}