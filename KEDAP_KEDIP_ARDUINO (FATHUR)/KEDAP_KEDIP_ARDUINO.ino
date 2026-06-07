int merah = 5;
int kuning = 6;
int hijau = 7;

void setup()
{
  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
}

void loop()
{
  // Semua lampu menyala
  digitalWrite(merah, HIGH);
  digitalWrite(kuning, HIGH);
  digitalWrite(hijau, HIGH);

  delay(500);

  // Semua lampu mati
  digitalWrite(merah, LOW);
  digitalWrite(kuning, LOW);
  digitalWrite(hijau, LOW);

  delay(500);
}