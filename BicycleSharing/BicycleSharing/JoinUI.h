#pragma once
#include "JoinController.h"
#include "Member.h"

class JoinController; //전방선언

// 사용자와의 회원가입 상호작용을 처리하는 boundary class
class JoinUI
{
private:
	JoinController* join_controller; // control class와 연결하기위한 포인터
public:
	// controller와 연결하기 위한 초기화 생성자
	JoinUI(JoinController* controller);

	// 파일에서 정보를 읽고 controller로 전달
	void inputInfo(std::ifstream& in_fp);

	// join메뉴와 join한 member의 정보를 파일에 출력
	void printMenuAndInfo(std::ofstream& out_fp, Member member);
};

