#include "Recognizer.h"


void Recognizer::run(const std::string& s) {
	line str(false, std::shared_ptr<std::string>(new std::string(s)));
	if (std::regex_match(s, wholeString)) {
		auto goalsBegin = std::sregex_iterator(s.begin(), s.end(), goal);
		auto goalsEnd = std::sregex_iterator();
		if (!check_equals(goalsBegin, goalsEnd)) {
			push_goals(goalsBegin, goalsEnd);
			str.first = true;
		}
	}
	correctness_report.push_back(str);
}
void Recognizer::timing(const std::string& s) {
	line str(false, std::shared_ptr<std::string>(new std::string(s)));
	auto t = std::chrono::steady_clock::now();


	std::cout << time.count() << std::endl;


	if (std::regex_match(s, wholeString)) {
		auto goalsBegin = std::sregex_iterator(s.begin(), s.end(), goal);
		auto goalsEnd = std::sregex_iterator();
		if (!check_equals(goalsBegin, goalsEnd)) {
			time += std::chrono::steady_clock::now() - t;
			//push_goals(goalsBegin, goalsEnd);
			str.first = true;
		}
		else
			time += std::chrono::steady_clock::now() - t;
	}
	else
		time += std::chrono::steady_clock::now() - t;
	//correctness_report.push_back(str);
}
void Recognizer::fix_result() {
	for (auto j : mainGoals) {
		for (auto i = result.cbegin(); i < result.cend(); i++) {
			if (**i == *j) {
				result.erase(i);
				break;
			}
		}
	}
}
bool Recognizer::check_equals(const std::sregex_iterator& begin, const std::sregex_iterator& end) {
	for (std::sregex_iterator i = begin; i != end; i++) {
		std::sregex_iterator j = i;
		j++;
		for (; j != end; j++) {
			if ((*i).str() == (*j).str())
				return true;
		}
	}
	return false;
}
void Recognizer::push_goals(const std::sregex_iterator& begin, const std::sregex_iterator& end) {
	if (std::distance(begin, end) > 1) {
		auto str = std::shared_ptr<std::string>(new std::string((*begin).str()));
		mainGoals.push_back(str);
		//Если цель из нового списка требований уже есть
		//в результирующем массиве, то ее вставлять не надо
		auto i = begin;
		i++;
		for (; i != end; i++) {
			push_goal_to_result(i);
		}
	}
	else if (std::distance(begin, end) == 1) {
		//если строка состоит из одной цели, значит у этой
		//цели нет списка требований => тоже включаем ее в результат
		push_goal_to_result(begin);
	}
}
void Recognizer::push_goal_to_result(const std::sregex_iterator& it) {
	auto j = result.begin();
	for (; j < result.end(); j++) {
		if (**j == (*it).str())
			break;
	}
	if (j == result.end())
		result.push_back(std::shared_ptr<std::string>(new std::string((*it).str())));
}
void Recognizer::write()
{
	std::string out1 = filename + ".check";
	std::string out2 = filename + ".result";
	std::ofstream outFile1(out1);
	std::ofstream outFile2(out2);
	for (auto i : correctness_report) {
		outFile1 << "String \"" << *i.second << (i.first ? "\" is correct" : "\" is not correct") << std::endl;
	}
	for (auto i : result) {
		outFile2 << *i << std::endl;
	}
}