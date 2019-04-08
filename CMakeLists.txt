# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

# 项目信息
project (Leetcode)

# 第一题：two-sum
add_executable(two-sum 1.two-sum.cpp)

# 第七题: reverse-integer
add_executable(reverse-integer 7.reverse-integer.cpp)

# 第九题：palidrome-number
add_executable(palindrome-number 9.palindrome-number.cpp)

# 第十三题：roman-to-integer
add_executable(roman-to-integer 13.roman-to-integer.cpp)

# 第十四题：longest-common-prefix
add_executable(longest-common-prefix 14.longest-common-prefix.cpp)

# 第四题：median-of-two-sorted-arrays
add_executable(median-of-two-sorted-arrays 4.median-of-two-sorted-arrays.cpp)

# 第26题：remove-duplicates-from-sorted-array
add_executable(remove-duplicates-from-sorted-array 26.remove-duplicates-from-sorted-array.cpp)

# 第27题：remove-element
add_executable(remove-element 27.remove-element.cpp)

# 第35题：search-insert-position
add_executable(search-insert-position 35.search-insert-position.cpp)


# 三数之和
add_executable(3-sum 15.3-sum.cpp)

# 第66题：plus-one
add_executable(plus-one 66.plus-one.cpp)

add_executable(string-to-integer-atoi 8.string-to-integer-atoi.cpp)

add_executable(longest-palindromic-substring 5.longest-palindromic-substring.cpp)