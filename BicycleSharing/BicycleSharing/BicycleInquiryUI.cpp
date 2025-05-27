#include "BicycleInquiryUI.h"

BicycleInquiryUI::BicycleInquiryUI(BicycleInquiryController* controller) {
	this->bicycle_inquiry_controller = controller;
}

void BicycleInquiryUI::requestInquiry(std::ifstream& in_fp) {
	bicycle_inquiry_controller->requestInquiry();
}

void BicycleInquiryUI::printBicycleList(std::ofstream& out_fp, Bicycle* bicycle_list, int bicycle_count) {
	std::string id, name;

	// 출력 형식
	out_fp << "5.1. 자전거 대여 리스트" << std::endl;
	for (int i = 0; i < bicycle_count; i++) {
		// 정보 출력을 위해 bicycle정보를 가져온다.
		// 회원의 모든 자전거 대여리스트를 순환하며 출력한다.
		id = bicycle_list[i].getID();
		name = bicycle_list[i].getName();
		out_fp << id << " " << name << std::endl;
	}
}