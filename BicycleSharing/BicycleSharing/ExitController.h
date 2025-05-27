#pragma once
#include "ExitUI.h"
#include <fstream>

//전방선언
class ExitUI;

// 시스템 종료(exit) 프로세스를 제어
class ExitController
{
private:
	ExitUI* exit_UI;		// UI를 위한 boundary class pointer
	bool exit = false;		// 시스템 종료 bool값
public:
	// 생성자 : boundary class 생성 및 초기화
	ExitController();

	// 사용자 입력 값을 받아 시스템 종료 bool값을 변경
	void deleteAllInfo();

	// 입력/출력 파일을 받아 exit 프로세스를 시작
	bool isProgramExit(std::ifstream& in_fp, std::ofstream& out_fp);
};

