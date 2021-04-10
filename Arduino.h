/*
 * Copyright (c) 2021 Brian T. Park
 * MIT License
 *
 * Parts derived from the Arduino SDK
 * Copyright (c) 2005-2013 Arduino Team
 */

#ifndef EPOXY_DUINO_ARDUINO_H
#define EPOXY_DUINO_ARDUINO_H

// The default Arduino header file is <ArduinoGeneric.h>. It can be changed by
// setting the ARDUINO_HEADER variable in the Makefile, which sets the
// EPOXY_DUINO_ARDUINO_HEADER preprocessor macro to the string
// '<$(ARDUINO_HEADER)>'. That string is passed into the '#include' directive
// below.
#ifndef EPOXY_DUINO_ARDUINO_HEADER
#define EPOXY_DUINO_ARDUINO_HEADER <ArduinoGeneric.h>
#endif

#include EPOXY_DUINO_ARDUINO_HEADER

#endif
