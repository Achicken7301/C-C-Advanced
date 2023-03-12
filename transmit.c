#include <stdio.h>
#include <string.h>

typedef union {
  struct {
    char uid[4];
    char data[8];
  } frame;

  char data_frame[12];
} frame_nfc;

void transmit(frame_nfc *nfc, char *uid, char *data) {
  // TODO
  strcpy(nfc->frame.uid, uid);
  strcpy(nfc->frame.data, data);
}

int main(int argc, char const *argv[]) {
  frame_nfc data;

  transmit(&data, (char *)"1011", (char *)"10011001");

  printf("data.data_frame: %s\n", data.data_frame);

  return 0;
}
