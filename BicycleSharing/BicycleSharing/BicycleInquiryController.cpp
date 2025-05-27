#include "BicycleInquiryController.h"

BicycleInquiryController::BicycleInquiryController(LoginController* controller) {
	this->login_controller = controller;
	bicycle_inqury_UI = new BicycleInquiryUI(this);		// boundary class 생성
}

// 사용자 요청을 받아 Member의 대여리스트를 찾음
void BicycleInquiryController::requestInquiry() {

	// 현재 로그인된 계정을 Member로 다운캐스팅
	Member* member = dynamic_cast<Member*>(login_controller->getLoginAccount());

	// Member의 자전거 대여 리스트와 대여중인 자전거 개수를 저장
	rent_bicycle_list = member->getRentBicycleList();
	rent_bicycle_count = member->getRentBicycleCount();
}

// 입력/출력 파일을 받아 자전거 대여 리스트 출력을 시작
void BicycleInquiryController::bicycleRentList(std::ifstream& in_fp, std::ofstream& out_fp) {
	// 입력 파일을 BicycleInquiryUI로 전송해 상호작용처리
	bicycle_inqury_UI->requestInquiry(in_fp);

	// 현재 대여한 자전거 대여 리스트를 출력
	bicycle_inqury_UI->printBicycleList(out_fp, rent_bicycle_list, rent_bicycle_count);
}