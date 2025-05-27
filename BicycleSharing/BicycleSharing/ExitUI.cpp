#include "ExitUI.h"

ExitUI::ExitUI(ExitController* controller) {
	this->exit_controller = controller;
}

void ExitUI::requestExit(std::ifstream& in_fp) {
	exit_controller->deleteAllInfo();
}

void ExitUI::printMenu(std::ofstream& out_fp) {
	out_fp << "6.1. 종료" << std::endl;
}