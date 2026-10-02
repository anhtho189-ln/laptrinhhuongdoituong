# Hệ Thống Quản Lý Danh Sách Thuốc
Ứng dụng quản lý danh sách thuốc viết bằng ngôn ngữ C++ theo phương pháp Lập trình hướng đối tượng (OOP).
---
## Tính Năng Chính
- **1. Nhập danh sách thuốc:** Thêm mới danh sách thuốc với đầy đủ thông tin (Mã, Tên, Hoạt chất, ĐVT, Giá, Số lượng tồn, Hạn sử dụng).
- **2. Hiển thị danh sách:** In danh sách thuốc hiện có dưới dạng danh mục rõ ràng.
- **3. Sắp xếp theo hạn sử dụng:** Sắp xếp danh sách thuốc theo thứ tự tăng dần của HSD (ngày/tháng/năm).
- **4. Tìm kiếm thuốc:** Tìm kiếm chính xác theo **Mã thuốc** hoặc **Tên thuốc**.
- **5. Bổ sung thuốc:** Chèn 1 loại thuốc mới vào vị trí bất kỳ trong danh sách.
- **6. Xóa thuốc:** Xóa 1 loại thuốc tại vị trí chỉ định.
---
## Cấu Trúc Dự Án
Pharmacy Management/
│
├── include/            # Chứa các tệp header (.h)
│   ├── Thuoc.h
│   └── QuanLyThuoc.h
│
├── src/                # Chứa các tệp mã nguồn (.cpp)
│   ├── Thuoc.cpp
│   ├── QuanLyThuoc.cpp
│   └── main.cpp
│
├── .gitignore          # Cấu hình bỏ qua các tệp không cần thiết
├── CMakeLists.txt      # Cấu hình biên dịch tự động bằng CMake
├── LICENSE             # Giấy phép bản quyền
└── README.md           # Tệp hướng dẫn sử dụng
