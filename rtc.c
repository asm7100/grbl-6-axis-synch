/*
rtc.c - Handles real time control from hardware panels
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

#include "rtc.h"

/*
This is a jog method that uses pulse inputs from an mpg wheel. Determining which axis
to jog, and the increment of each pulse is determined by sending values via serial to
grbl. Jogging is a 'side effect' of the spindle synch. It works because it can, and
seemed useful.
*/
uint8_t rtc_jog_mpg(uint8_t pin)
{
	uint8_t changedbits;
	changedbits = CONTROL_PIN ^ JOG_HISTORY;
	JOG_HISTORY = CONTROL_PIN;
	
	//Only allow mpg jogging when we are idle.. This would be BAD during a program..
	if (sys.state == STATE_IDLE)
	{			
		//if (bit_is_set(changedbits,CONTROL_SPINDLE_MOTION_BIT) && bit_is_clear(CONTROL_PIN, CONTROL_SPINDLE_MOTION_BIT))
		//{
			//Direction = CONTROL_PIN & (1<<CONTROL_SPINDLE_DIRECTION_BIT)?0:1;
		//}
		//
		////Update system position, even though we haven't actually moved just yet
		//sys_position[SYS_JOG_MPG_AXIS]+= Direction>0?-1:1;		
		//DIRECTION_PORT ^= (-Direction ^ DIRECTION_PORT) & (1UL << SYS_JOG_MPG_AXIS);
		//STEP_PORT ^= _BV(SYS_JOG_MPG_AXIS);
		//
		///*
		//Update the planner position. If we don't do this, the displayed coordinate will
		//be correct on a report ? message, but when gcode is sent, grbl will not know we
		//are actually at a new position.
		//*/
		//plan_sync_position();
	}
}
/*
the above cnc program code would cause the axis to advance 0.02mm for every revolution of the spindle.
When G95 is active the feed values will be programmed as follows: F0.05, F0.15, F0.3, F0.5 and so forth.
N11 ……
N12 G95 ; Program with G95 (F= mm/rev.)
N13 G1 Z-20 F0.2
N14 ……
*/
uint8_t rtc_spindle_sync(uint8_t pin)
{
	
	//Only allow spindle drive during a cycle state.
	if (sys.state == STATE_CYCLE)
	{
		st_drive();
		
	}
}