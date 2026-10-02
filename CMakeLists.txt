cmake_minimum_required(VERSION 3.10)

# Tên dự án
project(PharmacyManagement CXX)

# Thiết lập chuẩn C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Thêm thư mục include để tìm các file .h
include_directories(include)

# Lấy tất cả các tệp .cpp trong thư mục src/
file(GLOB SOURCES "src/*.cpp")

# Tạo tệp thực thi ứng dụng
add_executable(PharmacyApp ${SOURCES})
