#include "BicycleRentController.h"

BicycleRentController::BicycleRentController(LoginController* controller, BicycleCollection* bicycle_collection) {
	// control class, collection class 멤버 변수 연결
	this->login_controller = controller;
	this->bicycle_collection = bicycle_collection;

	bicycle_rent_UI = new BicycleRentUI(this);						// boundary class 생성
}

void BicycleRentController::inputBicycleID(std::string id) {
	// 사용자 입력 값으로 등록되어있는 bicycle을 찾고 멤버 변수에 저장
	rent_bicycle = bicycle_collection->getBicycle(id);

	// 현재 로그인된 계정을 Member로 다운캐스팅 후 Member의 대여한 자전거를 대여 리스트에 저장
	Member* member = dynamic_cast<Member*>(login_controller->getLoginAccount());
	member->rentBicycle(rent_bicycle);
}

void BicycleRentController::bicycleRent(std::ifstream& in_fp, std::ofstream& out_fp) {
	// 입력 파일을 BicycleRentUI로 전송해 상호작용처리
	bicycle_rent_UI->inputBicycleID(in_fp);

	// 현재 대여한 자전거의 정보를 출력
	bicycle_rent_UI->printMenuAndInfo(out_fp, rent_bicycle);
}