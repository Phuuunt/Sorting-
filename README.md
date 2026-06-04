# Báo cáo Đồ án: Thuật toán sắp xếp
**Trường Đại học Khoa học Tự nhiên - VNU-HCM (Khoa Công nghệ Thông tin)**

## Thông tin sinh viên
* **Tên môn học:** Cấu trúc Dữ liệu và Giải thuật
* **Thời gian học:** HKII - Năm học: 2025-2026
* **Họ và tên:** Nguyễn Trọng Phú
* **MSSV:** 24120410

---

## 1. Thuật toán cài đặt tốt nhất ở lần chạy đầu tiên (Run 1)

* **Thuật toán:** Merge Sort.
* **Các phương thức tối ưu hóa:**
    * **Mảng tạm dùng chung (Global/Referenced Temp Array):** Khởi tạo một mảng tạm duy nhất có kích thước N ngay từ đầu và truyền tham chiếu xuyên suốt quá trình đệ quy. Việc này loại bỏ hoàn toàn chi phí (overhead) của việc liên tục xin cấp phát và giải phóng bộ nhớ động ở mỗi bước chia trị.
    * **Truyền tham chiếu:** Sử dụng `vector<int>&` để tránh thao tác sao chép toàn bộ mảng dữ liệu một cách vô ích mỗi khi gọi hàm.
    * **Tối ưu I/O:** Bổ sung `ios_base::sync_with_stdio(false); cin.tie(NULL);` để đẩy tốc độ đọc/ghi dữ liệu lên mức tối đa.
* **Lý giải sự vượt trội:** So với các thuật toán sắp xếp cơ bản ở những vòng chạy đầu, Merge Sort luôn đảm bảo độ phức tạp thời gian ổn định tuyệt đối ở mức O(N log N) cho mọi trường hợp (Tốt nhất, Trung bình, Xấu nhất). Việc tối ưu mảng tạm như trên giúp thuật toán này có thời gian thực thi cực kỳ đáng tin cậy trên các bộ test chuẩn, không bị rủi ro rớt xuống O(N^2).
---

## 2. Trình sinh Test (test_gen.cpp)

* **Thuật toán mục tiêu:** Quick Sort cơ bản (với chiến lược chọn pivot cố định).
* **Lý do chọn mục tiêu:** Quick Sort thường là lựa chọn số 1 về tốc độ, nhưng lại chứa điểm yếu chí mạng về cách chọn phần tử chốt (pivot). Việc nhắm vào thuật toán này giúp kiểm chứng tính bền vững của code khi đối mặt với các kịch bản dữ liệu cực đoan.
* **Cách thức sinh test và tác động (Killer Test Cases):**
    * **Mảng đã được sắp xếp (Tăng dần/Giảm dần):** Nếu pivot luôn được chọn ở đầu hoặc cuối mảng, thuật toán sẽ không thể chia mảng thành hai nửa, mà chỉ cắt được 1 phần tử mỗi lần đệ quy.
    * **Mảng chứa toàn các giá trị trùng lặp (All Equal):** Nếu vòng lặp phân mảnh (partition) không xử lý tốt toán tử so sánh bằng, mảng cũng sẽ bị dồn toàn bộ về một phía.
    * **Hiệu ứng:** Những bộ test này ép thuật toán Quick Sort bị suy biến (degrade), trượt từ độ phức tạp trung bình $O(N \log N)$ xuống trường hợp tồi tệ nhất là $O(N^2)$. Kết quả là thời gian chạy tăng theo cấp số nhân và hệ thống có thể báo lỗi Time Limit Exceeded hoặc Stack Overflow (do gọi đệ quy quá sâu).

---

## 3. Thuật toán tốt nhất ở lần chạy thứ hai (Run 2)

* **Thuật toán:** Randomized Quick Sort (Quick Sort với Pivot ngẫu nhiên) kết hợp cơ chế Cắt tỉa đệ quy.
* **Các phương thức tối ưu hóa bổ sung:**
    * **Random Pivot:** Thay vì lấy phần tử cố định, chốt được chọn ngẫu nhiên trong khoảng đang xét (`l + rand() % (r - l + 1)`).
    * **Tối ưu hóa Hoare Partitioning:** Dùng hai con trỏ di chuyển ngược chiều để chia đều các phần tử có giá trị bằng nhau sang hai nhánh đệ quy.
* **Cách thức cải thiện so với lần 1:** * Cơ chế Random Pivot phá vỡ hoàn toàn cấu trúc của các "Killer Test Cases" sinh ra từ `test_gen.cpp`, đưa xác suất rơi vào vòng lặp $O(N^2)$ về gần bằng 0, đảm bảo thời gian chạy luôn ổn định.

