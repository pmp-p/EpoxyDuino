/*
 * A program to reproduce https://github.com/bxparks/EpoxyDuino/issues/2, where
 * piping to a pager program like 'less' or 'more' fails if too much data is
 * written to the SERIAL_PORT_MONITOR.
 *
 * To run:
 *
 * $ make clean
 * $ make
 * $ ./PipeFail.out | less # this fails
 * $ ./PipeFail.out < /dev/null | less # this works
 */

#include <Arduino.h>

// Fails for NUM_LINES >= 274 on Ubuntu 20.04.
const int NUM_LINES = 1000;
const char LINE[] = "Reproduce https://github.com/bxparks/EpoxyDuino/issues/2";

void setup() {
#if ! defined(EPOXY_DUINO)
  delay(1000); // some boards reboot twice
#endif
  SERIAL_PORT_MONITOR.begin(115200);
  while (!SERIAL_PORT_MONITOR); // For Leonardo/Micro

  size_t totalCharacters = 0;
  for (int i = 0; i < NUM_LINES; i++) {
    SERIAL_PORT_MONITOR.print(i);
    SERIAL_PORT_MONITOR.print(" (");
    SERIAL_PORT_MONITOR.print(totalCharacters);
    SERIAL_PORT_MONITOR.print("): ");
    SERIAL_PORT_MONITOR.println(LINE);
    totalCharacters += sizeof(LINE) + 10; // line is variable, so take a guess
  }

#if defined(EPOXY_DUINO)
  exit(0);
#endif
}

void loop() {
}
