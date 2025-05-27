#pragma once
#include <string>

class Bicycle
{
private:
	std::string id = "";			// 사용자 ID
	std::string name = "";		// 사용자 비밀번호

public:
	Bicycle(std::string id = "", std::string name = "");
	std::string getID();			// 계정의 ID를 반환
	std::string getName();		// 계정의 비밀번호를 반환
};

