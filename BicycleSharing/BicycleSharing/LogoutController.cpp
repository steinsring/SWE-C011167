#include "LogoutController.h"
#include "LogoutUI.h"

LogoutController::LogoutController(LoginController* controller) {
	logout_UI = new LogoutUI(this);
	this->login_controller = controller;
}

void LogoutController::requestLogout() {
	// 로그아웃하는 계정의 정보 임시 저장
	logout_account = login_controller->getLoginAccount();
	// 시스템 접속 종료
	login_controller->setLoginAccount(nullptr);
}


void LogoutController::logout(std::ofstream& out_fp) {
	// logoutUI로 상호작용처리
	logout_UI->requestLogout();

	// 로그아웃 메뉴 및 계정 정보 출력
	logout_UI->printMenuAndInfo(out_fp, logout_account);
	
}