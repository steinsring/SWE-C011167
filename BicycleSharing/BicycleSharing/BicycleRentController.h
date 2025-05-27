#pragma once
#include "BicycleRentUI.h"
#include "BicycleCollection.h"
#include "LoginController.h"
#include <string>
#include <fstream>

//전방선언
class BicycleRentUI;

// 자전거 대여(rent) 프로세스를 제어
// 사용자입력(BicycleRentUI)와 LoginController, BicycleCollection, Member 사이를 제어
class BicycleRentController
{
private:
	BicycleRentUI* bicycle_rent_UI;			// UI를 위한 boundary class pointer
	LoginController* login_controller;		// 대여한 자전거를 저장하기 위해 현재 로그인한 계정 연결을 위함
	BicycleCollection* bicycle_collection;	// 모든 자전거를 저장하는 collection class
	Bicycle rent_bicycle;					// 현재 빌리고 있는 자전거 정보 임시 저장
public:
	// 생성자 : boundary class 생성 및 초기화, contorl class, collection class 연결
	BicycleRentController(LoginController* controller, BicycleCollection* collection);

	// 사용자 입력 값을 받아 대여한 자전거를 찾아 로그인된 Member의 대여리스트에 저장
	void inputBicycleID(std::string id);

	// 입력/출력 파일을 받아 자전거 대여 프로세스를 시작
	void bicycleRent(std::ifstream& in_fp, std::ofstream& out_fp);
};

