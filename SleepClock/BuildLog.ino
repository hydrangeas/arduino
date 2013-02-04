#include "sc.h"

String Log = "";
String Now = "";

void outputSerial() {
  Serial.println(Log);
}

void buildLog(int8_t value) {
  String tmp = Now + String(value) + "\n";
  if (tmp.length() == 14) {
    Log = Log + Now + String(value) + "\n";
  }
}

