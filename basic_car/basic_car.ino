int trigpin,echopin,m1_pwm,m1_h,m1_l,m2_pwm,m2_h,m2_l;
double duration;







void setup() {
 pinMode(trigpin,OUTPUT);
 pinMode(echopin, INPUT);
 pinMode(m1_pwm,OUTPUT);
 pinMode(m1_h,OUTPUT);
 pinMode(m1_l,OUTPUT);
pinMode(m2_pwm,OUTPUT);
pinMode(m2_h,OUTPUT);
pinMode(m2_l,OUTPUT);
Serial.begin(9600);

}
// m1 is right
// m2 is left
void loop() {
 digitalWrite(m2_h,HIGH);
 digitalWrite(m2_l,LOW);
 /*set speed for car here, taking pwm to be 100; range is from 0-255*/
 analogWrite(m1_pwm, 100);
 analogWrite(m2_pwm, 100);
digitalWrite(trigpin,LOW);
delay(1.50);
 digitalWrite(trigpin,HIGH);
 delay(6);
 digitalWrite(trigpin,LOW);
 duration = pulseIn(echopin,HIGH);
 /*we'll set duration as the min dist we need obstacle, assuming it to be 3 cm */
 duration = duration*(0.017);
 if(duration <=3.0)
 { digitalWrite(m1_l,HIGH);
 digitalWrite(m1_h,LOW);
  }
  else
  {digitalWrite(m1_h,HIGH);
 digitalWrite(m1_l,LOW);
    }

}
