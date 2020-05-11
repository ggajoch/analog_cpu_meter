
void setup() {
// put your setup code here, to run once:
    pinMode(3, OUTPUT);
    Serial.begin(9600);
    Serial.println("Test");
}

void loop() {
    if (Serial.available()) {
        int val = Serial.read();
        if (val > 120) { val = 120; }

        float f = val;
        f /= 10;
        float corrected = -0.5856*f*f + 25.082*f;

        val = corrected;
        
        Serial.println(val);
        analogWrite(3, val);
    }
}
