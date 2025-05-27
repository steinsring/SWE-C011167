#include "AccountCollection.h"

AccountCollection::AccountCollection() {
	Admin* admin = new Admin("admin", "admin");
	account_list[account_count++] = admin;
}

void AccountCollection::addNewMember(std::string id, std::string password, std::string phone) {
	// 받아온 id, password, phone으로 새로운 member를 생성 및 저장
	Member* new_member = new Member(id, password, phone);
	account_list[account_count++] = new_member;
}

Account* AccountCollection::getAccount(std::string id, std::string password) {
	// id와 password가 일치하는 account를 account_list에서 찾아 반환
	int i = 0;
	for (; i < account_count; i++) {
		if (account_list[i]->getID() == id && account_list[i]->getPassword() == password) {
			break;
		}
	}
	return account_list[i];
}
