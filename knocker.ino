/* encoding: utf-8 */

const uint8_t PIEZO = A0;
const uint32_t KNOCK_CYCLE = 50;
const uint32_t SHORT_INTERVAL = 200;
const uint32_t MEDIUM_INTERVAL = 400;

uint32_t knockVal;
uint32_t knockInterval;
uint32_t lastKnock = 0;
uint32_t currentKnock = 0;

String getIntervalLengthName(uint32_t interval);


void setup(){
    Serial.begin(9600);
    pinMode(13, OUTPUT);

    Serial.println("Start");
}

void loop(){
    knockVal = analogRead(PIEZO);

    if (knockVal > 0) {
        currentKnock = millis();
        knockInterval = abs(currentKnock - lastKnock);
        lastKnock = currentKnock;

        if (knockInterval > 1000) {
            knockInterval = 0;
            Serial.println("\nRestarting");
            Serial.println("------------");
        }

        Serial.print(getIntervalLengthName(knockInterval) + " :");
        Serial.print("Knock at ");
        Serial.print(knockInterval, DEC);
        Serial.println("ms");

        delay(KNOCK_CYCLE);
    }
}


String getIntervalLengthName(uint32_t interval) {
    String intervalLengthName = "LONG";

    if (interval >= 0 && interval < SHORT_INTERVAL) {
        intervalLengthName = "SHORT";
    }
    else if (interval > SHORT_INTERVAL && interval < MEDIUM_INTERVAL) {
        intervalLengthName = "MEDIUM";
    }

    return intervalLengthName;
}
