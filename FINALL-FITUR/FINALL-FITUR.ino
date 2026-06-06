int led_merah = 8;
int led_kuning = 9;
int led_hijau = 10;

String mode = "1";

void setup()
{
  pinMode(led_merah, OUTPUT);
  pinMode(led_kuning, OUTPUT);
  pinMode(led_hijau, OUTPUT);

  Serial.begin(9600);

  Serial.println("=== KONTROL LAMPU ===");
  Serial.println("1 = Lampu lalu lintas");
  Serial.println("2 = Lampu kedap-kedip");
}

void loop()
{
  if (Serial.available() > 0)
  {
    mode = Serial.readStringUntil('\n');
    mode.trim();

    Serial.print("Mode: ");
    Serial.println(mode);
  }

  // MODE 1 : Lampu lalu lintas
  if (mode == "1")
  {
    digitalWrite(led_merah, HIGH);
    digitalWrite(led_kuning, LOW);
    digitalWrite(led_hijau, LOW);
    delay(1000);

    digitalWrite(led_merah, LOW);
    digitalWrite(led_kuning, HIGH);
    digitalWrite(led_hijau, LOW);
    delay(1000);

    digitalWrite(led_merah, LOW);
    digitalWrite(led_kuning, LOW);
    digitalWrite(led_hijau, HIGH);
    delay(1000);

    digitalWrite(led_merah, LOW);
    digitalWrite(led_kuning, HIGH);
    digitalWrite(led_hijau, LOW);
    delay(1000);
  }

  // MODE 2 : Semua lampu kedap-kedip
  else if (mode == "2")
  {
    digitalWrite(led_merah, HIGH);
    digitalWrite(led_kuning, HIGH);
    digitalWrite(led_hijau, HIGH);
    delay(500);

    digitalWrite(led_merah, LOW);
    digitalWrite(led_kuning, LOW);
    digitalWrite(led_hijau, LOW);
    delay(500);
  }
}