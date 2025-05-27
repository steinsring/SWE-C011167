#include "BicycleRegistUI.h"

BicycleRegistUI::BicycleRegistUI(BicycleRegistController* controller) {
	this->bicycle_regist_controller = controller;
}

// 파일에서 정보를 읽고 controller로 전달
void BicycleRegistUI::inputBicycleInfo(std::ifstream& in_fp) {
	std::string id, name;
	// 입력 형식 : id, name을 파일로부터 읽음
	in_fp >> id >> name;

	// 새 bicycle 생성을 위해 controller로 정보를 전달
	bicycle_regist_controller->inputBicycleInfo(id, name);
}

// 자전거 등록 메뉴와 등록한 자전거의 정보를 파일에 출력
void BicycleRegistUI::printMenuAndInfo(std::ofstream& out_fp, Bicycle bicycle) {
	std::string id, name;
	// 정보 출력을 위해 bicycle정보를 가져온다.
	id = bicycle.getID();
	name = bicycle.getName();

	// 출력 형식
	out_fp << "3.1. 자전거 등록" << std::endl;
	out_fp << id << " " << name << std::endl;
}