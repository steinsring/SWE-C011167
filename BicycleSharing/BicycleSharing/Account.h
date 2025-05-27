#pragma once
#include <string>

// Member와 Admin의 공통 속성을 나타내는 super class
// Member 및 Admin 클래스가 상속받아 사용
class Account
{
protected:
	std::string id = "";			// 계정 ID
	std::string password = "";		// 계정 비밀번호

public:
	std::string getID();			// 계정의 ID를 반환
	std::string getPassword();		// 계정의 비밀번호를 반환
	virtual ~Account() {}			// 소멸자
};

