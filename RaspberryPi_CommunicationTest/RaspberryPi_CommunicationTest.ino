const int led_pin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello Pi");
  if(Serial.available()) {
    flash(Serial.read() - '0');
  }
  delay(1000);
}

void flash(int n) {
  for(int i = 0; i < n; i++) {
    digitalWrite(led_pin, HIGH);
    delay(100);
    digitalWrite(led_pin, LOW);
    delay(100);
  }
}
