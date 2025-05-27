#pragma once
#include "BicycleInquiryController.h"
#include "Bicycle.h"
#include <fstream>

//전방선언
class BicycleInquiryController;

// 사용자와 상호작용하여 자전거 대여 리스트를 출력하는 boundary class
class BicycleInquiryUI
{
private:
	BicycleInquiryController* bicycle_inquiry_controller;	// control class와 연결하기위한 포인터
public:
	// 생성자 : collection class 연결
	BicycleInquiryUI(BicycleInquiryController* controller);

	// 파일에서 정보를 읽고 controller로 전달
	void requestInquiry(std::ifstream& in_fp);

	// 자전거 리스트 출력
	void printBicycleList(std::ofstream& out_fp, Bicycle* bicycle_list, int bicycle_count);
};

