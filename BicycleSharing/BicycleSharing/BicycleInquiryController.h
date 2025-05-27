#pragma once
#include "BicycleInquiryUI.h"
#include "LoginController.h"
#include <fstream>
#include <string>

//전방선언
class BicycleInquiryUI;

// 자전거 대여 리스트(inquiry) 프로세스를 제어
// 사용자입력(BicycleInquiryUI)와 LoginController에 접근해서 현재 로그인된 Member에 등록된 대여 리스트를 출력한다.
class BicycleInquiryController
{
private:
	BicycleInquiryUI* bicycle_inqury_UI;		// UI를 위한 boundary class pointer
	LoginController* login_controller;			// 대여한 자전거를 출력하기 위해 현재 로그인한 계정 연결을 위함
	int rent_bicycle_count;
	Bicycle* rent_bicycle_list;					// 현재 자전거 대여 리스트 정보 임시 저장
public:
	// 생성자 : boundary class 생성 및 초기화, contorl class 연결
	BicycleInquiryController(LoginController* controller);

	// 사용자 요청을 받아 Member의 대여리스트를 찾음
	void requestInquiry();

	// 입력/출력 파일을 받아 자전거 대여 리스트 출력을 시작
	void bicycleRentList(std::ifstream& in_fp, std::ofstream& out_fp);
};

