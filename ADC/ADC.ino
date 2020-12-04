
int val = A0;           // variable to store the value read
int zero_offset,zerobuf = 0;;
float I;

void setup()

{
  pinMode(7, OUTPUT);
  pinMode(val, INPUT);
  Serial.begin(9600);          //  setup serial


  
  

}


int a=0;
int val_buff;
void loop()

{
  if(a==0)
  {
for (int i = 0; i < 10; i++) {
    zerobuf += analogRead(A0);
    delay(10);
  }
  zerobuf /= 10;
  zero_offset = zerobuf;
  a=1;}
  digitalWrite(7, HIGH);   
  //delay(1000);                       
  //digitalWrite(7, LOW);    
  //delay(1000);  
  for (int i = 0; i < 50; i++) {
    
     // read the input pin
   val_buff+=analogRead(A0);
  }
  
  val=val_buff/50;
  val_buff=0;
  if(val<524)I=0;
  else
  //I = (val - zero_offset) / 1023.0 * 5.0 / 0.004; // (zero - analogRead(pin)) / ADC_SCALE * VREF / sensitivity;
I=(0.25*val)-130.5;
  Serial.print("adc offset=");   
  Serial.print(zero_offset);   
  Serial.print("  adc=");   
  Serial.print(val);   
  Serial.print("  I=");   
  Serial.println(I);            
  delay(500);


  
}
