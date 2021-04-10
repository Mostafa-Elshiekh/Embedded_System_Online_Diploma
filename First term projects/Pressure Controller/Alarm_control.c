#include "Alarm_control.h"
#define waiting_time 200000

void High_Pressure_Detected()
{
	Set_Alarm_actuator(1);
	Delay(waiting_time);
	Set_Alarm_actuator(0);
	Delay(waiting_time);
}