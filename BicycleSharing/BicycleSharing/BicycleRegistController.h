#pragma once
#include "BicycleRegistUI.h"
#include "BicycleCollection.h"
#include "Bicycle.h"
#include <string>
#include <fstream>

//전방선언
class BicycleRegistUI;
class BicycleCollection;

class BicycleRegistController
{
private:
	BicycleRegistUI* bicycle_regist_UI;		// UI를 위한 boundary class pointer
	BicycleCollection* bicycle_collection;	// 모든 자전거를 저장하는 collection class
	Bicycle regist_bicycle;					// 가장 최근에 regist한 bicycle, 정보 출력을 위한 임시 저장
public:
	// 생성자 : boundary class 생성 및 초기화, collection class 초기화
	BicycleRegistController(BicycleCollection* collection);

	// 사용자 입력 값을 받아 bicycle_collection에 새 bicycle을 저장
	void inputBicycleInfo(std::string id, std::string name);

	// 입력/출력 파일을 받아 BicycleRegist 프로세스를 시작
	void bicycleRegist(std::ifstream& in_fp, std::ofstream& out_fp);
};

