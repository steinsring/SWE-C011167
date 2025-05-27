#pragma once
#include "BicycleInquiryController.h"
#include "Bicycle.h"
#include <fstream>

//전방선언
class BicycleInquiryController;

class BicycleInquiryUI
{
private:
	BicycleInquiryController* bicycle_inquiry_controller;	// control class와 연결하기위한 포인터
public:
	// 생성자 : collection class 연결
	BicycleInquiryUI(BicycleInquiryController* controller);

	// 파일에서 정보를 읽고 controller로 전달
	void requestInquiry(std::ifstream& in_fp);

	void printBicycleList(std::ofstream& out_fp, Bicycle* bicycle_list, int bicycle_count);
};

