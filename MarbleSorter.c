#pragma config(Sensor, in1,    LightSensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  Green,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  Red,            sensorLEDtoVCC)
#pragma config(Motor,  port2,           Servo,         tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void check(){
			if(SensorValue[LightSensor]>1000){
			startMotor(Servo,-70);
			turnLEDOn(Green);
			turnLEDOff(Red);
		}
		else if(SensorValue[LightSensor]>=600 && SensorValue[LightSensor]<900){
			startMotor(Servo,70);
			turnLEDOn(Red);
			turnLEDOff(Green);
		}else{
			setServo(Servo,-5);
			turnLEDOff(Green);
			turnLEDOff(Red);
		}
}
task main()
{
	while(true){
	wait(1);
	check();

}
}
