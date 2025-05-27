#include "BicycleCollection.h"

void BicycleCollection::addNewBicycle(std::string id, std::string name) {
	// 받아온 id, name으로 새로운 bicycle을 생성 및 저장
	Bicycle new_bicycle(id, name);
	bicycle_list[bicycle_count++] = new_bicycle;
}

Bicycle BicycleCollection::getBicycle(std::string id) {
	// id가 일치하는 bicycle을 bicycle_list에서 찾아 반환
	Bicycle bicycle;
	for (int i = 0; i < bicycle_count; i++) {
		if (bicycle_list[i].getID() == id) {
			bicycle = bicycle_list[i];
			break;
		}
	}
	return bicycle;
}