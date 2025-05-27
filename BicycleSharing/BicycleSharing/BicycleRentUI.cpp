#include "BicycleRentUI.h"

BicycleRentUI::BicycleRentUI(BicycleRentController* controller) {
	this->bicycle_rent_controller = controller;
}

void BicycleRentUI::inputBicycleID(std::ifstream& in_fp) {
	std::string id;
	// 입력 형식 : id를 파일로부터 읽음
	in_fp >> id;

	// bicycle대여 정보를 저장하기 위해 controller로 정보를 전달
	bicycle_rent_controller->inputBicycleID(id);
}

void BicycleRentUI::printMenuAndInfo(std::ofstream& out_fp, Bicycle bicycle) {
	std::string id, name;
	// 정보 출력을 위해 bicycle정보를 가져온다.
	id = bicycle.getID();
	name = bicycle.getName();

	// 출력 형식
	out_fp << "4.1. 자전거 대여" << std::endl;
	out_fp << id << " " << name << std::endl;
}