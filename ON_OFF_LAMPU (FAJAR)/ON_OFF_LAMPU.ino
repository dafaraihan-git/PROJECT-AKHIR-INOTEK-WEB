int led_merah = 8;
int led_kuning = 9;
int led_hijau = 10;

void setup() {
  pinMode(led_merah, OUTPUT);
  pinMode(led_kuning, OUTPUT);
  pinMode(led_hijau, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available() > 0) {
    char perintah = Serial.read();
    
    if (perintah == '1') {  
      digitalWrite(led_merah, HIGH);
      digitalWrite(led_kuning, HIGH);
      digitalWrite(led_hijau, HIGH);
    }
    
    if (perintah == '0') {  
      digitalWrite(led_merah, LOW);
      digitalWrite(led_kuning, LOW);
      digitalWrite(led_hijau, LOW);
    }
  }
}