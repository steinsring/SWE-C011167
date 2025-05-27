#include "BicycleRegistController.h"

BicycleRegistController::BicycleRegistController(BicycleCollection* collection) {
	this->bicycle_collection = collection;				// collection class 멤버 변수 초기화
	bicycle_regist_UI = new BicycleRegistUI(this);		// boundary class 생성
}

void BicycleRegistController::inputBicycleInfo(std::string id, std::string name) {
	// 사용자 입력값을 BicycleRegistUI로부터 받아 새 bicycle을 생성 및 등록
	bicycle_collection->addNewBicycle(id, name);

	// 현재 등록한 bicycle의 임시 정보 저장
	Bicycle bicycle(id, name);
	this->regist_bicycle = bicycle;
}

void BicycleRegistController::bicycleRegist(std::ifstream& in_fp, std::ofstream& out_fp) {
	// 입력 파일을 BicycleRegistUI로 전송해 상호작용처리
	bicycle_regist_UI->inputBicycleInfo(in_fp);

	// 현재 등록한 bicycle의 정보를 출력
	bicycle_regist_UI->printMenuAndInfo(out_fp, regist_bicycle);
}