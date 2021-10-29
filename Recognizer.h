#pragma once
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <chrono>

typedef std::vector<std::shared_ptr<std::string>> goal_vector;
typedef std::pair<bool, std::shared_ptr<std::string>> line;

class Recognizer {
private:
	const std::regex wholeString = std::regex("(\ )*[A-Za-z_.][A-Za-z0-9_.]*(\ )*(:(\ )*([A-Za-z_.][A-Za-z0-9_.]*(\ )*)*)?");
	const std::regex goal = std::regex("[A-Za-z_\.][A-Za-z0-9_\.]*");
	goal_vector mainGoals;
	std::vector<line> correctness_report;
	std::chrono::steady_clock::duration time;
	goal_vector result;
	std::string filename;
	bool check_equals(const std::sregex_iterator&, const std::sregex_iterator&);
	void push_goals(const std::sregex_iterator&, const std::sregex_iterator&);
	void push_goal_to_result(const std::sregex_iterator& it);
public:
	Recognizer(const std::string& f) :filename(f),time(std::chrono::steady_clock::duration::zero()) {}
	std::chrono::steady_clock::duration showTime() { return time; }
	void fix_result();
	void run(const std::string&);
	void timing(const std::string&);
	void write();
};