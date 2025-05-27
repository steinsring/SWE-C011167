// 헤더 선언
#include <iostream>
#include <fstream>
#include <string>
#include "AccountCollection.h"
#include "JoinController.h"
#include "LoginController.h"
#include "LogoutController.h"
#include "BicycleCollection.h"
#include "BicycleRegistController.h"
#include "BicycleRentController.h"
#include "BicycleInquiryController.h"
#include "ExitController.h"

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask(std::ifstream& in_fp, std::ofstream& out_fp);   // 프로그램 시작

int main() {   
    // 변수 선언
    std::ifstream in_fp;
    std::ofstream out_fp;

    // 파일 입출력을 위한 초기화
    in_fp.open(INPUT_FILE_NAME);
    out_fp.open(OUTPUT_FILE_NAME);

    // 프로그램 시작
    doTask(in_fp, out_fp);

    // 파일 입출력 종료
    in_fp.close();
    out_fp.close();

    // 프로그램 종료
    return 0;
}

void doTask(std::ifstream& in_fp, std::ofstream& out_fp) {
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = false;

    // 계정 리스트 생성 및 초기화
    AccountCollection account_collection;

    // 프로그램의 모든 컨트롤러 생성 및 초기화
    JoinController join_controller(&account_collection);
    LoginController login_controller(&account_collection);
    LogoutController logout_controller(&login_controller);
    BicycleCollection bicycle_collection;
    BicycleRegistController bicycle_regist_controller(&bicycle_collection);
    BicycleRentController bicycle_rent_controller(&login_controller, &bicycle_collection);
    BicycleInquiryController bicycle_inquiry_controller(&login_controller);
    ExitController exit_controller;

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        in_fp >> menu_level_1 >> menu_level_2;

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1) {
            case 1: {
                switch (menu_level_2) {
                    case 1: {       // "1.1. 회원가입“ 메뉴 부분
                        // 해당 기능 수행 
                        join_controller.join(in_fp, out_fp);
                        break;
                    }
                }
                break;
            }
            case 2: {
                switch (menu_level_2) {
                    case 1: {       // "2.1. 로그인“ 메뉴 부분
                        // 해당 기능 수행 
                        login_controller.login(in_fp, out_fp);
                        break;
                    }
                    case 2: {       // "2.2. 로그아웃“ 메뉴 부분
                        // 해당 기능 수행 
                        logout_controller.logout(out_fp);
                        break;
                    }
                }
                break;
            }
            case 3: {
                switch (menu_level_2) {
                    case 1: {     // "3.1. 자전거 등록“ 메뉴 부분
                        bicycle_regist_controller.bicycleRegist(in_fp, out_fp);
                        break;
                    }
                }
                break;
            }
            case 4: {
                switch (menu_level_2) {
                    case 1: {     // "4.1. 자전거 대여“ 메뉴 부분
                        bicycle_rent_controller.bicycleRent(in_fp, out_fp);
                        break;
                    }
                }
                break;
            }
            case 5: {
                switch (menu_level_2) {
                    case 1: {     // "5.1. 자전거 대여 리스트“ 메뉴 부분
                        bicycle_inquiry_controller.bicycleRentList(in_fp, out_fp);
                        break;
                    }
                }
                break;
            }
            case 6: {
                switch (menu_level_2) {
                    case 1: {     // "6.1. 종료“ 메뉴 부분
                        is_program_exit = exit_controller.isProgramExit(in_fp, out_fp);
                        break;
                    }
                }
                break;
            }
        }
    }
}
