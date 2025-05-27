#pragma once
#include <string>

// 자전거의 정보를 저장하는 클래스
class Bicycle
{
private:
	std::string id = "";		// 자전거 ID
	std::string name = "";		// 자전거 제품명

public:
	Bicycle(std::string id = "", std::string name = "");
	std::string getID();		// 자전거의 ID를 반환
	std::string getName();		// 자전거의 제품명을 반환
};

