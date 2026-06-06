// C++ code
//

  int led_merah = 8; 
  int led_kuning = 9; 
  int led_hijau = 10; 


void setup()
{
  pinMode (led_merah, OUTPUT);
  pinMode (led_kuning, OUTPUT);
  pinMode (led_hijau, OUTPUT);
}

void loop()
{
  digitalWrite(led_merah, HIGH);
  delay(1000); 
  digitalWrite(led_merah, LOW);
  delay(1000);
  digitalWrite(led_kuning, HIGH);
  delay(1000); 
  digitalWrite(led_kuning, LOW);
  delay(1000);
  digitalWrite(led_hijau, HIGH);
  delay(1000); 
  digitalWrite(led_hijau, LOW);
  delay(1000);
  digitalWrite(led_kuning, HIGH);
  delay(1000); 
  digitalWrite(led_kuning, LOW);
  delay(1000);
 
}
