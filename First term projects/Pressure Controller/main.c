#include<stdint.h>
#include "driver.h"
#include "Alarm_control.h"

int main ()
{
		GPIO_INITIALIZATION();
		int threshold=20;
	    int volatile PressureVal;

	while (1)
	{
		PressureVal=getPressureVal();
		if (PressureVal>threshold)
		{
			High_Pressure_Detected();
		}
		Delay(200000);
	}

}
