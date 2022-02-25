char data = 0;                //Variable for storing received data
int water;
const int sensor_pin = A1;  /* Soil moisture sensor O/P pin */
void setup() 
{
Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
pinMode(4, OUTPUT);        //Sets digital pin 13 as output pin
pinMode(2,OUTPUT);
}

void loop()
{
float moisture_percentage;
int sensor_analog;
sensor_analog = analogRead(sensor_pin);
moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
Serial.print("Moisture Percentage = ");
Serial.print(moisture_percentage);
Serial.print("%\n\n");
water = digitalRead(A1); // reading the coming signal from the soil sensor
if(water == HIGH) // if water level is full then cut the relay
{
digitalWrite(2,HIGH); // low is to cut the relay
}
else
{
digitalWrite(2,LOW); //high to continue proving signal and water supply
}
delay(400);
delay(500);
if(Serial.available() > 0)  // Send data only when you receive data:
{
data = Serial.read();      //Read the incoming data and store it into variable data
Serial.print(data);        //Print Value inside data in Serial monitor
Serial.print("\n");        //New line 
if(data == '1')            //Checks whether value of data is equal to 1 
digitalWrite(4, HIGH);  //If value is 1 then LED turns ON
else if(data == '0')       //Checks whether value of data is equal to 0
digitalWrite(4, LOW);   //If value is 0 then LED turns OFF
}                            

}
