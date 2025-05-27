#include "LoginUI.h"

LoginUI::LoginUI(LoginController* controller) {
	this->login_contorller = controller;
}

void LoginUI::inputInfo(std::ifstream& in_fp) {
	std::string id, password;
	// 입력 형식 : id, password을 파일로부터 읽음
	in_fp >> id >> password;

	// 로그인을 위해 controller로 정보를 전달
	login_contorller->inputInfo(id, password);
}
void LoginUI::printMenuAndInfo(std::ofstream& out_fp, Account* account) {
	std::string id, password;
	// 정보 출력을 위해 member정보를 가져온다.
	id = account->getID();
	password = account->getPassword();

	// 출력 형식
	out_fp << "2.1. 로그인" << std::endl;
	out_fp << id << " " << password << std::endl;
}