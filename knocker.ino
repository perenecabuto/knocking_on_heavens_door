/* encoding: utf-8 */

const uint8_t PIEZO = A0;
const uint16_t KNOCK_CYCLE = 50;
const uint16_t SHORT_INTERVAL = 200;
const uint16_t MEDIUM_INTERVAL = 400;

uint16_t knockVal;
uint16_t knockInterval;
uint32_t lastKnock = 0;
uint32_t currentKnock = 0;

String getIntervalLengthName(uint16_t interval);


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

        Serial.print(getIntervalLengthName(knockInterval) + " :\t");
        Serial.print("Knock at ");
        Serial.print(knockInterval, DEC);
        Serial.println("ms");

        delay(KNOCK_CYCLE);
    }
}


String getIntervalLengthName(uint16_t interval) {
    String intervalLengthName = "START";

    if (interval > 0 && interval < SHORT_INTERVAL) {
        intervalLengthName = "SHORT";
    }
    else if (interval > SHORT_INTERVAL && interval < MEDIUM_INTERVAL) {
        intervalLengthName = "MEDIUM";
    }
    else if (interval > MEDIUM_INTERVAL) {
        intervalLengthName = "LONG";
    }

    return intervalLengthName;
}
