#pragma once
#include "LoginUI.h"
#include "AccountCollection.h"
#include "Account.h"
#include <string>
#include <fstream>

// 전방선언
class LoginUI;
class AccountCollection;

// 로그인(login) 프로세스를 제어
// 사용자입력(LoginUI)과 AccountCollection 사이를 제어
class LoginController
{
private:
	LoginUI* login_UI;						// UI를 위한 boundary class pointer
	AccountCollection* account_collection;	// 모든 계정을 저장하는 collection class
	Account* login_account;					// 가장 최근에 login한 account, 현재 로그인 계정 정보 저장
public:
	// boundary class 생성 및 초기화, collection class 멤버 변수 초기화 생성자
	LoginController(AccountCollection* collection);

	// 사용자 입력 값을 받아 account를 찾고 login_account에 저장
	void inputInfo(std::string id, std::string password);

	// 입력/출력 파일을 받아 login 프로세스를 시작
	void login(std::ifstream& in_fp, std::ofstream& out_fp);

	// 현재 로그인한 account 반환
	Account* getLoginAccount();

	// 현재 로그인한 account 정보 수정
	void setLoginAccount(Account* account);
};

