#include <stdio.h>
#include <stdint.h>

uint8_t GIO_HANG;

typedef enum
{
    DEP = 1 << 0,      // 0b0000.0001
    AO = 1 << 1,       // 0b0000.0010
    QUAN = 1 << 2,     // 0b0000.0100
    TAT = 1 << 3,      // 0b0000.1000
    VONG_TAY = 1 << 4, // 0b0001.0000
    NON = 1 << 5,      // 0b0001.0000
    MAT_KINH = 1 << 6, // 0b0100.0000
    GIAY = 1 << 7      // 0b1000.0000
} DO_DUNG_CA_NHAN;

void THEM_SAN_PHAM(uint8_t *gio_hang, DO_DUNG_CA_NHAN ten_do_dung)
{
    printf("Them san pham\n");
    *gio_hang |= ten_do_dung;
}

void XOA_SAN_PHAM(uint8_t *gio_hang, DO_DUNG_CA_NHAN ten_do_dung)
{
    printf("Xoa san pham\n");
    *gio_hang &= ~ten_do_dung;
}

void HIEN_THI_GIO_HANG(uint8_t gio_hang)
{
    printf("gio hang(2): ");
    for (int bit = 7; bit >= 0; bit--)
    {
        printf("%d", (gio_hang >> bit) & 1);
    }
    printf("\n");
    /*
    DEP = 1 << 0,      // 0b0000.0001
    AO = 1 << 1,       // 0b0000.0010
    QUAN = 1 << 2,     // 0b0000.0100
    TAT = 1 << 3,      // 0b0000.1000
    VONG_TAY = 1 << 4, // 0b0001.0000
    NON = 1 << 5,      // 0b0001.0000
    MAT_KINH = 1 << 6, // 0b0100.0000
    GIAY = 1 << 7      // 0b1000.0000
    */
    if ((gio_hang & DEP) != 0)
    {
        printf("Co dep\n");
    }
    if ((gio_hang & AO) != 0)
    {
        printf("Co AO\n");
    }
    if ((gio_hang & QUAN) != 0)
    {
        printf("Co QUAN\n");
    }
    if ((gio_hang & TAT) != 0)
    {
        printf("Co TAT\n");
    }
    if ((gio_hang & VONG_TAY) != 0)
    {
        printf("Co VONG_TAY\n");
    }
    if ((gio_hang & NON) != 0)
    {
        printf("Co NON\n");
    }
    if ((gio_hang & MAT_KINH) != 0)
    {
        printf("Co MAT_KINH\n");
    }
    if ((gio_hang & GIAY) != 0)
    {
        printf("Co GIAY\n");
    }
}

void KIEM_TRA_SAN_PHAM(uint8_t gio_hang, DO_DUNG_CA_NHAN ten_do_dung)
{
    HIEN_THI_GIO_HANG(gio_hang & ten_do_dung);
}

int main(int argc, char const *argv[])
{
    THEM_SAN_PHAM(&GIO_HANG, AO | QUAN | DEP | MAT_KINH);
    KIEM_TRA_SAN_PHAM(GIO_HANG, AO | QUAN | DEP | MAT_KINH);
    XOA_SAN_PHAM(&GIO_HANG, AO | DEP);
    KIEM_TRA_SAN_PHAM(GIO_HANG, AO | QUAN | DEP | MAT_KINH);
    return 0;
}
