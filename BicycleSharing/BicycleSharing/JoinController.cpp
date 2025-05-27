#include <string>
#include "JoinController.h"

JoinController::JoinController(AccountCollection* collection) {
	this->account_collection = collection;			// collection class 멤버 변수 초기화
	join_UI = new JoinUI(this);						// boundary class 생성
}


void JoinController::inputInfo(std::string id, std::string password, std::string phone) {
	// 사용자 입력값을 JoinUI로부터 받아 새 member를 생성 및 등록
	account_collection->addNewMember(id, password, phone);

	// 현재 join한 member의 임시 정보 저장
	Member member(id, password, phone);
	this->join_member = member;
}

void JoinController::join(std::ifstream& in_fp, std::ofstream& out_fp) {
	// 입력 파일을 JoinUI로 전송해 상호작용처리
	join_UI->inputInfo(in_fp);

	// 현재 join한 member의 정보를 출력
	join_UI->printMenuAndInfo(out_fp, join_member);
}
