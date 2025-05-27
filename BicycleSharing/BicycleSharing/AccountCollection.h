#pragma once
#include <string>
#include "Member.h"
#include "Admin.h"

// 관리자와 회원을 저장하고있는 collection class
class AccountCollection
{
private:
	int account_count = 0;		// 현재 가지고 있는 account 개수
	Account* account_list[100];	// Account가 실제로 저장되는 배열
public:
	// 생성자 : 관리자 계정 생성 및 저장
	AccountCollection();

	// 새로운 멤버를 생성해서 배열에 저장
	void addNewMember(std::string id, std::string password, std::string phone);

	// 배열에서 조건에 맞는 account를 반환
	Account* getAccount(std::string id, std::string password);
};

