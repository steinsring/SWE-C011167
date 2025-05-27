#pragma once
#include "ExitController.h"
#include <fstream>

//전방선언
class ExitController;

// 시스템 종료를 출력하는 boundary class
class ExitUI
{
private:
	ExitController* exit_controller;		// control class와 연결하기위한 포인터
public:
	// controller와 연결하기 위한 초기화 생성자
	ExitUI(ExitController* controller);

	// 파일에서 정보를 읽고 controller로 전달
	void requestExit(std::ifstream& in_fp);	

	// exit메뉴를 파일에 출력
	void printMenu(std::ofstream& out_fp);
};

