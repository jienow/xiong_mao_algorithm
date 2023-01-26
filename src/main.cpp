// #include "fmt/format.h"
#include <format>
#include <iostream>
#include <string_view>

template<typename... Args>
void print(const std::string_view fmt_str, Args... args) {
	auto fmt_args{ std::make_format_args(args...) };
	std::string outstr{ std::vformat(fmt_str,fmt_args) };
	fputs(outstr.c_str(), stdout);
}

int main() {
	print("hello\n");
	print("hi,{}\n", "shen");
	return 0;
}