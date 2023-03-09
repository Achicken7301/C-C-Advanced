# Compiler gcc IDE/EDITOR 
## COMPILER
Dịch từ ngôn ngữ do lập trình viên viết (C/C++, PHP, HTML, ) sang ngôn ngữ máy.

Từ file `main.c/cpp, main.h`,... nó **perprocess** sang file `main.i` từ đây các file MACRO hay include sẽ được thêm vào `main.i`.

Sau đó `main.i` sẽ được compiler dịch sang file `main.s` dưới dạng assembly.

=> được assembler sang file object.

=> Linker tạo ra exucutable file. `main.exe`

## IDE/EDITOR
IDE: Phần mềm + compiler 

Vd: devC, mấy cái ấn cái là chạy.

Editor: lưu code.

# MACRO

Trong quá trình tiền xử lý, tất cả các chữ được `#define` sẽ thay thế vào.
VD: file main.c
```c
#define MAX_ARR_LENGTH 100

int a[MAX_ARR_LENGTH];

int main(){
    printf("MAX_ARR_LENGTH: %d", MAX_ARR_LENGTH);
    return 0;
}
```

Sau quá trình tiền xử lý, nó sẽ thay thế **tất cả** các chữ `MAX_ARR_LENGTH` bằng `100`, trong file `main.i` sẽ như sau:
```c
int a[100];

int main(){
    printf("MAX_ARR_LENGTH: %d", 100);
    return 0;
}
```

## #if #endif

```c
#define BLUETOOTH A24

#if BLUETOOTH == 0

a = 2;

#elif BLUETOOTH == 1

a = 3;

#else

a = 4;

#endif

```

## Truyền tham số

Dùng `##` để nối chuổi trong MACRO 
```c
#define typeVar(type, name) type var_##name

```
nếu `name = a` thì `var_##name` sẽ là `var_a`

Có thể định nghĩ nhiều dòng bằng `\`

```c
#define typeVar(type, name) type var_##name\
                            type var1_##name\
                            type var2_##name

```

## Define 1 hàm
## Cấu trúc đặt tên 
Có 2 files: 1 header và 1 source.

VD: `knight.h` và `knight.cpp` 

## Tránh define trùng

```cpp
#ifndef __knight_H // Cái tên này chỉ đặt tránh trùng với các thư viện khác.
#define __knight_H

#endif
```

# Multiples parameters in function

```c
int sum(int number_of_sum, ...){
    int sum = 0;
    va_list ptr;
    va_start(ptr, number_of_sum);
    for(int i = 0; i < number_of_sum; i++){
        sum += sum + va_arg(ptr, int);
                //  va_arg(ptr, int)
                // -------------^--- Kiểu dữ liệu của cái `...`
                // Gọi lần 1 thì in ra thằng đầu tiên, gọi lần 2 thì ra input thứ 2
    }
    va_end(ptr);
}
```

- BTVN1: `sum(3, 1, 2, 5.2);`
Tính cổng mà có nhiểu kiểu dữ liệu vừa `int` vừa `double`
- BTVN2: input nhiều hơn số lượng cần thiết `sum(100, 1, 2, 3.2);` nhưng vẫn ra `sum` đúng.

# Variables types (volatile, register, static, auto)

## static 

### static vs mormal and auto

Biến static tồn tại cho đến khi hết vòng đời của chương trình. Nó sẽ không bị mất khi kết thúc lời gọi hàm.

VD:
```c
#include <stdio.h>

void count(){
    int count = 0;      // Biến bình thường
    printf("count: %d\n",count);
    count = count + 1;
}

int main() {
    count(); // output: count = 0
    /*
        1. Khởi tạo biến count ở địa chỉ nào đó trên vùng nhớ.
        2. In giá trị nó ra.
        3. Cộng giá trị ở vùng nhớ đó lên 1 -> vô nghĩa vì
        4. Giải phóng địa chỉ của biến count.
        Tương tự cho những lời gọi hàm ở dưới.
    */

    count(); // output: count = 0


    count(); // output: count = 0
    return 0;
}
```

Ở vd khác.
```c
#include <stdio.h>

void count(){
    static int count = 0;      // Biến static
    printf("count: %d\n",count);
    count = count + 1;
}

int main() {
    count(); // output: count = 0
    /*
        1. Khởi tạo biến count ở địa chỉ nào đó trên vùng nhớ.
        2. In giá trị nó ra.
        3. Cộng giá trị ở vùng nhớ đó lên 1
        4. Không giải phóng vùng nhớ ở Stack vì static là khởi tạo ở "data segment"
        Tương tự cho những lời gọi hàm ở dưới.
    */

    count(); // output: count = 1


    count(); // output: count = 2
    return 0;
}
```

### Static được gọi trong hàm **chỉ có nghĩa trong hàm** đó.
```c
#include <stdio.h>

void count(){
    static int count = 0;      // Biến static
    printf("count: %d\n",count);
    count = count + 1;
}

int main() {
    count(); // output: count = 0

    printf("count: %d\n",count); // output: lỗi vì không biết count là thằng nào.
    count(); // output: count = 1

    count(); // output: count = 2
    return 0;
}
```
Cho nên ta sử dụng 1 con trỏ để truy câp vào địa chỉ đó.
```c
#include <stdio.h>

int *ptr;

void count(){
    static int count = 0;      // Biến static
    ptr = &count;
    printf("count: %d\n",count);
    count = count + 1;
}

int main() {
    count();    // output: count = 0
    
    *ptr = 100;
    count();    // output: count = 100
    
    count();    // output: count = 101
    
    return 0;
}
```

## extern

Truy cập biến cục bộ từ 1 file khác.