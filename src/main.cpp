
#include<main.h>



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  for (int mode = 0; mode< sizeof(RidingModes); mode++)
  {
    pinMode(RidingModes[mode], INPUT);
    //digitalWrite(RidingModes[mode], LOW); //all mode off
  }
  pinMode(A13, INPUT);
}

void loop() {

  // put your main code here, to run repeatedly:
  uint16_t ADC = analogRead(A13);
  double speedKmh = ADC*coef;
  // Check the percentage of the actual speed based on the maximum speed
	double percentageOfMaxSpeed = (speedKmh / speedLimit )* 100;

  uint8_t x = 0;
	for (x = 0; x < numCurrentOutDiv; x++)
	{
		if (percentageOfMaxSpeed < currentOutDiv[x])
		{
			break;
		}
	}

	// Keep x between 1 and the (number of divisions)-1, to not have overflow
	if (x < 1)
		x = 1;
	if (x > (numCurrentOutDiv - 1))
		x = (numCurrentOutDiv - 1);
  
  // Calculates the currentOut, keeping linear between the power informed in the arrays
  
   for (int mode = 0; mode< sizeof(RidingModes); mode++)
  {
 
    if( digitalRead(CITY)){
      ridingMode =1;
    }
    else if( digitalRead(PRO)){
      ridingMode =2;
    }
    else if( digitalRead(ECO)){
      ridingMode =0;
    }
    else{ ridingMode =1;}
  }
	switch (ridingMode)
	{
	// City mode
	case 1 :
    Serial.print("City Mode: ");
		currentOut = map(percentageOfMaxSpeed, currentOutDiv[x - 1], currentOutDiv[x], currentOutCityMode[x - 1], currentOutCityMode[x]);
		break;

	// Pro mode
	case 2:
    Serial.print("Pro Mode:  ");
		currentOut = map(percentageOfMaxSpeed, currentOutDiv[x - 1], currentOutDiv[x], currentOutProMode[x - 1], currentOutProMode[x]);
		break;

	// Eco mode
	default:
    Serial.print("ECO Mode:  ");
		currentOut = map(percentageOfMaxSpeed, currentOutDiv[x - 1], currentOutDiv[x], currentOutEcoMode[x - 1], currentOutEcoMode[x]);
		break;
	}
 
  Serial.println(currentOut);
  delay(100); // this speeds up the simulation
}
