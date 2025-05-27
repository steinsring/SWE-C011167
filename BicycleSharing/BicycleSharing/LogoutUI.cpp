#include "LogoutUI.h"

LogoutUI::LogoutUI(LogoutController* controller) {
	this->logout_controller = controller;
}

void LogoutUI::requestLogout() {
	logout_controller->requestLogout();
}

void LogoutUI::printMenuAndInfo(std::ofstream& out_fp, Account* account) {
	std::string id;
	id = account->getID();

	// 출력 형식
	out_fp << "2.2. 로그아웃" << std::endl;
	out_fp << id << std::endl;
}
