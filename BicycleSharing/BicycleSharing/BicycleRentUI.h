#pragma once
#include "BicycleRentController.h"
#include <fstream>
#include "Bicycle.h"
//전방선언
class BicycleRentController;

// 사용자와의 자전거 대여 상호작용을 처리하는 boundary class
class BicycleRentUI
{
private:
	BicycleRentController* bicycle_rent_controller;	// control class와 연결하기위한 포인터
public:
	// 생성자 : collection class 연결
	BicycleRentUI(BicycleRentController* controller);

	// 파일에서 정보를 읽고 controller로 전달
	void inputBicycleID(std::ifstream& in_fp);

	// rent메뉴와 대여한 자전거의 정보를 파일에 출력
	void printMenuAndInfo(std::ofstream& out_fp, Bicycle bicycle);
};

