#pragma once
#include <string>
#include "Bicycle.h"

// 모든 자전거를 저장하고있는 collection class
class BicycleCollection
{
private:
	int bicycle_count = 0;		// 현재 가지고 있는 Bicycle 개수
	Bicycle bicycle_list[100];	// Bicycle이 실제로 저장되는 배열
public:
	// 새로운 자전거를 생성해서 배열에 저장
	void addNewBicycle(std::string id, std::string name);

	// 배열에서 조건에 맞는 자전거를 반환
	Bicycle getBicycle(std::string id);
};

