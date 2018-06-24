/*
rtc.h - Handles real time control from hardware panels
Part of Grbl

Added by shooter64738 on GitHUB

Grbl is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Grbl is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef RTC_H_
#define RTC_H_

#include <stdint.h>
#include "system.h"
#include "cpu_map.h"
#include "report.h"

/*
Some of these are also defined in other header files. I am trying to keep all
of my additions encapsulated into one header and method file for portability
*/
//system.h also includes control pin data
#define CONTROL_PIN_INDEX_SPINDLE_DIRECTION   bit(4)
#define CONTROL_PIN_INDEX_SPINDLE_MOTION   bit(5)
//cpu.h also includes control pin data
#define CONTROL_SPINDLE_DIRECTION_BIT 4 // MEGA2560 Analog Pin 12
#define CONTROL_SPINDLE_MOTION_BIT 5 // MEGA2560 Analog Pin 13

//Determines which axis to jog. This is set via serial.c, by picking of single bytes of data.
volatile uint8_t SYS_JOG_MPG_AXIS;
volatile static int8_t JOG_HISTORY;     // default is high because the pull-up
volatile static int8_t Direction;

/*
Called when a pulse is detected on the 'CONTROL_PIN' pin. 
This method is for manual jogging 
*/
uint8_t rtc_jog_mpg(uint8_t pin);

/*
Called when a pulse is detected on the 'CONTROL_PIN' pin
This method is for coordinating a single axis motion with the spindle
*/
uint8_t rtc_spindle_sync(uint8_t pin);




#endif /* RTC_H_ */