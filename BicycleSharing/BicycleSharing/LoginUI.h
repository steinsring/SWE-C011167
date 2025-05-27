#pragma once
#include "LoginController.h"
#include "Account.h"

class LoginController; // 전방선언

class LoginUI
{
private:
	LoginController* login_contorller;	// control class와 연결하기위한 포인터

public:
	// controller와 연결하기 위한 초기화 생성자
	LoginUI(LoginController* controller);

	// 파일에서 정보를 읽고 controller로 전달
	void inputInfo(std::ifstream& in_fp);

	// login메뉴와 login한 account의 정보를 파일에 출력
	void printMenuAndInfo(std::ofstream& out_fp, Account* account);
};

