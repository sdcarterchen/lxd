﻿#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include "fileio.h"
#include "encoding.h"
#include "timer.h"

unsigned int Factorial(unsigned int number) {
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]") {
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("Create Dir", "[lxd::CreateDir]") {
    REQUIRE(lxd::CreateDir(L"D:\\Download\\test_lxd"));
}

TEST_CASE("Exists Dir", "[lxd::DirExists]") {
    REQUIRE(lxd::DirExists(L"D:\\Download\\test_lxd"));
}

TEST_CASE("Write string to file", "[WriteIntoString]") {
    char const* text = u8"你好！";
    REQUIRE(lxd::WriteFile(L"D:\\Download\\test_lxd\\test.txt", text, strlen(text)));
}

TEST_CASE("Read file into string", "[ReadIntoString]") {
    auto str = lxd::ReadFile(L"D:\\Download\\test_lxd\\test.txt");
    printf("%s\n", lxd::utf8_decode(str).c_str());
}

TEST_CASE("Delete Dir", "[lxd::DeleteDir]") {
    REQUIRE(0 == lxd::DeleteDir(L"D:\\Download\\test_lxd"));
}

TEST_CASE("Timer ", "[Timer]") {
    auto start = lxd::millisecond();
    lxd::sleep(1000);
    auto end = lxd::millisecond();
    printf("timer: %f\n", end - start);
}
