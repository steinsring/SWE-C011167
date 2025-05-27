#include "LoginController.h"

LoginController::LoginController(AccountCollection* account_collection) {
	this->account_collection = account_collection;	// collection class 멤버 변수 초기화
	login_UI = new LoginUI(this);					// boundary class 생성
}

void LoginController::inputInfo(std::string id, std::string password) {
	// 사용자 입력값을 LoginUI로부터 받아 account를 찾고 저장
	Account* account = account_collection->getAccount(id, password);
	setLoginAccount(account);
}

void LoginController::login(std::ifstream& in_fp, std::ofstream& out_fp) {
	// 입력 파일을 LoginUI로 전송해 상호작용처리
	login_UI->inputInfo(in_fp);

	// 현재 login한 member의 정보를 출력
	login_UI->printMenuAndInfo(out_fp, login_account);
}

Account* LoginController::getLoginAccount() {
	return login_account;
}

void LoginController::setLoginAccount(Account* account) {
	login_account = account;
}