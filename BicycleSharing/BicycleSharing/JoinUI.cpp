#include "JoinUI.h"

JoinUI::JoinUI(JoinController* controller) {
	this->join_controller = controller;
}

void JoinUI::inputInfo(std::ifstream& in_fp) {
	std::string id, password, phone;
	// 입력 형식 : id, password, phone을 파일로부터 읽음
	in_fp >> id >> password >> phone;

	// 새 member 생성을 위해 controller로 정보를 전달
	join_controller->inputInfo(id, password, phone);
}
void JoinUI::printMenuAndInfo(std::ofstream& out_fp, Member member) {
	std::string id, password, phone;
	// 정보 출력을 위해 member정보를 가져온다.
	id = member.getID();
	password = member.getPassword();
	phone = member.getPhone();

	// 출력 형식
	out_fp << "1.1. 회원가입" << std::endl;
	out_fp << id << " " << password << " " << phone << std::endl;
}
