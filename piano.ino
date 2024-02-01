const int buzzerPin = 9; // Collega il buzzer al pin 9

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char note = Serial.read();
    playNote(getNoteFrequency(note), 500);
  }
}

void playNote(int frequency, int duration) {
  tone(buzzerPin, frequency, duration);
  delay(duration + 50);
  noTone(buzzerPin);
}

int getNoteFrequency(char note) {
  switch (note) {
    case 'c':
      return 262;
    case 'd':
      return 294;
    case 'e':
      return 330;
    case 'f':
      return 349;
    case 'g':
      return 392;
    case 'a':
      return 440;
    case 'b':
      return 494;
    case 'C':
      return 523;
    default:
      return 0; // Nota non valida
  }
}
