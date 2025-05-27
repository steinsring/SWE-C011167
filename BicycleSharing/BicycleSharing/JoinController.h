#pragma once
#include "JoinUI.h"
#include "AccountCollection.h"
#include "Member.h"
#include <string>
#include <fstream>

//전방선언
class JoinUI;
class AccountCollection;

// 회원가입(join) 프로세스를 제어
// 사용자입력(JoinUI)과 AccountCollection 사이를 제어
class JoinController
{
private:
	JoinUI* join_UI;						// UI를 위한 boundary class pointer
	AccountCollection* account_collection;	// 모든 계정을 저장하는 collection class
	Member join_member;						// 가장 최근에 join한 member, 정보 출력을 위한 임시 저장
public:
	// 생성자 : boundary class 생성 및 초기화, collection class 초기화
	JoinController(AccountCollection* collection);

	// 사용자 입력 값을 받아 account_collection에 새 member를 저장
	void inputInfo(std::string id, std::string password, std::string phone);

	// 입력/출력 파일을 받아 join 프로세스를 시작
	void join(std::ifstream& in_fp, std::ofstream& out_fp);
};

