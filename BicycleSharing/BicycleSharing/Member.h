#pragma once
#include "Account.h"
#include "Bicycle.h"

// 일반 회원을 나타내는 클래스
// Account 클래스를 상속받으며, phone을 추가로 포함
class Member : public Account
{
private:
	std::string phone = "";			// 회원의 전화번호
	int rent_bicycle_count = 0;		// 현재 대여하고 있는 자전거 개수
	Bicycle rent_bicycle_list[100];	// 현재 대여하고 있는 자전거 리스트
public:
	// ID, 비밀번호, 전화번호를 받아 회원 객체를 생성
	Member(std::string id = "", std::string password = "", std::string phone = ""); 

	// 회원의 전화번호를 반환
	std::string getPhone();

	// // 회원이 대여한 자전거를 현재 대여중인 리스트에 추가
	void rentBicycle(Bicycle bicycle);

	// 회원이 현재 대여중인 자전거 리스트 반환
	Bicycle* getRentBicycleList();

	// 회원이 현재 대여중인 자전거 개수 반환
	int getRentBicycleCount();
};

