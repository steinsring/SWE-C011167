#pragma once
#include "Account.h"

// 관리자를 나타내는 클래스
// Account 클래스를 상속받는다.
class Admin : public Account
{
public:
	// ID와 비밀번호를 받아 관리자 객체를 생성
	Admin(std::string id, std::string password);
};

