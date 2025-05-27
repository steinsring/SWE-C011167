#include "ExitController.h"

ExitController::ExitController() {
    this->exit_UI = new ExitUI(this);
}

void ExitController::deleteAllInfo() {
    exit = true;
}

bool ExitController::isProgramExit(std::ifstream& in_fp, std::ofstream& out_fp) {
    // 입력 파일을 ExitUI로 전송해 상호작용처리
    exit_UI->requestExit(in_fp);

    // 프로그램 종료 메뉴를 출력
    exit_UI->printMenu(out_fp);

    // 프로그램 종료
    return exit;
}