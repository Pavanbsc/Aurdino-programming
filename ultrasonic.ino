int greenpin = 12;
int bluepin = 8;
int redpin = 2;
int triggerpin = 9;
int echopin = 10;

void setup() {
    pinMode(echopin, INPUT);
    pinMode(triggerpin, OUTPUT);
    pinMode(bluepin, OUTPUT);
    pinMode(redpin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(triggerpin, LOW);
delay(2);
digitalWrite(triggerpin, HIGH);
delay(10);
digitalWrite(triggerpin, LOW);

long Dur = pulseIn(echopin, HIGH);
long dist = Dur * 0.034 / 2;

if(dist > 20){
    digitalWrite(redpin, LOW);
    digitalWrite(greenpin, HIGH);
    digitalWrite(bluepin, LOW);
}

if(dist <= 20 && dist >= 10){
    digitalWrite(redpin, LOW);
    digitalWrite(greenpin, LOW);
    digitalWrite(bluepin, HIGH); 
}

if(dist < 10){
    digitalWrite(bluepin, LOW);
    digitalWrite(redpin, HIGH);
    digitalWrite(greenpin, LOW);
}

Serial.print("Distance: ");
Serial.print(dist);
Serial.print("\n");
}
