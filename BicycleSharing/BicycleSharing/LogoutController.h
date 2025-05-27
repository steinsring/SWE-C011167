#pragma once
#include "LogoutUI.h"
#include "LoginController.h"
#include "Account.h"
#include <fstream>

//전방선언
class LogoutUI;	
class LoginController;

// 로그아웃(logout) 프로세스를 제어
// 사용자입력(logoutUI)을 받아 LoginController에 접근해 시스템 접속을 종료한다.
class LogoutController
{
private:
	LogoutUI* logout_UI;					// UI를 위한 boundary class pointer
	LoginController* login_controller;		// 현재 로그인 계정 정보를 가지고있는 control class
	Account* logout_account;				// 로그아웃하는 계정 정보 임시 저장
	
public:
	// 생성자 : boundary class 생성 및 loginController 연결
	LogoutController(LoginController* controller);

	// 현재 로그인된 계정을 로그아웃 및 시스템 접속 종료
	void requestLogout();

	// 출력 파일을 받아 logout 프로세스를 시작
	void logout(std::ofstream& out_fp);
};

