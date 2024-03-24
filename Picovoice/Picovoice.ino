#include <Picovoice_EN.h>

#include "params.h"

int ledState = 0;

#define MEMORY_BUFFER_SIZE (70 * 1024)

static const char* ACCESS_KEY = "SplkOd3zj3P25jAreS6mFIepTrlqIikylrNfkvMisYG5Gq86TtO73Q=="; //AccessKey string obtained from Picovoice Console (https://picovoice.ai/console/)

static pv_picovoice_t *handle = NULL;

static int8_t memory_buffer[MEMORY_BUFFER_SIZE] __attribute__((aligned(16)));

static const float PORCUPINE_SENSITIVITY = 0.75f;
static const float RHINO_SENSITIVITY = 0.5f;

static void wake_word_callback(void) {
//    Serial.println("Wake word detected!");
      Serial.println("Yes Sir");
      digitalWrite(4, HIGH);
      delay(500);
      digitalWrite(4, LOW);
      delay(500);
}

static void inference_callback(pv_inference_t *inference) {
    Serial.println("{");
    Serial.print("    is_understood : ");
    Serial.println(inference->is_understood ? "true" : "false");
    if (inference->is_understood) {
        Serial.print("    intent : ");
        Serial.println(inference->intent);
        if (inference->num_slots > 0) {
            Serial.println("    slots : {");
            for (int32_t i = 0; i < inference->num_slots; i++) {
                Serial.print("        ");
                Serial.print(inference->slots[i]);
                Serial.print(" : ");
                Serial.println(inference->values[i]);
                ledState = !ledState;
                digitalWrite(5, ledState);
//                digitalWrite(5, HIGH);
//                delay(500);
//                digitalWrite(5, LOW);
//                delay(500);

               Serial.println(i);   

            

                


            }
            Serial.println("    }");
        }
    }
    Serial.println("}\n");
    pv_inference_delete(inference);
}

void setup() {
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    digitalWrite(3, HIGH);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    Serial.begin(9600);
    while (!Serial);

    pv_status_t status = pv_audio_rec_init();
    if (status != PV_STATUS_SUCCESS) {
        Serial.print("Audio init failed with ");
        Serial.println(pv_status_to_string(status));
        while (1);
    }

    status = pv_picovoice_init(
        ACCESS_KEY,
        MEMORY_BUFFER_SIZE,
        memory_buffer,
        sizeof(KEYWORD_ARRAY),
        KEYWORD_ARRAY,
        PORCUPINE_SENSITIVITY,
        wake_word_callback,
        sizeof(CONTEXT_ARRAY),
        CONTEXT_ARRAY,
        RHINO_SENSITIVITY,
        1.0,
        true,
        inference_callback,
        &handle);
    if (status != PV_STATUS_SUCCESS) {
        Serial.print("Picovoice init failed with ");
        Serial.println(pv_status_to_string(status));
        while (1);
    }

    const char *rhino_context = NULL;
    status = pv_picovoice_context_info(handle, &rhino_context);
    if (status != PV_STATUS_SUCCESS) {
        Serial.print("retrieving context info failed with");
        Serial.println(pv_status_to_string(status));
        while (1);
    }
    Serial.println("Wake word: Picovoice");
    Serial.println(rhino_context);
}

void loop()
{
    const int16_t *buffer = pv_audio_rec_get_new_buffer();
    if (buffer) {
        const pv_status_t status = pv_picovoice_process(handle, buffer);
        if (status != PV_STATUS_SUCCESS) {
            Serial.print("Picovoice process failed with ");
            Serial.println(pv_status_to_string(status));
            while(1);
        }
    }
}
