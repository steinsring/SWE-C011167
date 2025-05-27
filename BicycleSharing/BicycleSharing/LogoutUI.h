#pragma once
#include "LogoutController.h"
#include "Account.h"
//#include <fstream>

class LogoutController; // 전방선언

// 사용자와 상호작용해 로그아웃 정보를 입력받고 로그아웃 ID를 출력한다.
class LogoutUI
{
private:
	LogoutController* logout_controller; // control class와 연결하기위한 포인터
public:
	// controller와 연결하기 위한 초기화 생성자
	LogoutUI(LogoutController* controller);

	// controller로 로그아웃 요청
	void requestLogout();

	// logout메뉴 및 로그아웃 정보 출력
	void printMenuAndInfo(std::ofstream& out_fp, Account* account);
};

