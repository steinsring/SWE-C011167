#pragma once
#include "BicycleRegistController.h"
#include "Bicycle.h"

//전방선언
class BicycleRegistController;

// 사용자의 입력을 받아 자전거 등록을 처리하고 정보를 출력하는 boundary class
class BicycleRegistUI
{
private:
	BicycleRegistController* bicycle_regist_controller; // control class와 연결하기위한 포인터

public:
	// controller와 연결하기 위한 초기화 생성자
	BicycleRegistUI(BicycleRegistController* controller);

	// 파일에서 정보를 읽고 controller로 전달
	void inputBicycleInfo(std::ifstream& in_fp);

	// 자전거 등록 메뉴와 등록한 자전거의 정보를 파일에 출력
	void printMenuAndInfo(std::ofstream& out_fp, Bicycle bicycle);
};

