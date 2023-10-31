#include "OTA.hpp"


OTA::OTA(char* usuario, char* senha) {
    this-> usuario = usuario;
    this-> senha = senha;

    void OTA::setup_wifi() {
        Serial.print("connect ");
        Serial.println(this-> ssid);

        WiFi.mode(WIFI_STA);
        WiFi.begin(this-> ssid, this-> password);
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.println(".");
        }
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.print("IP addredd: ");
        Serial.println(WiFi.localIP());
    }

    void OTA::setup_ota(){
        ArduinoOTA.onStart([]() {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH) {
            type = "sketch";
        } else { // U_FS
            type = "filesystem";
        }

        Serial.println("Start updating " + type);
        });
        ArduinoOTA.onEnd([]() {
            Serial.println("\nEnd");
        });
        ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
            Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
        });
        ArduinoOTA.onError([](ota_error_t error) {
            Serial.printf("Error[%u]: ", error);
            if (error == OTA_AUTH_ERROR) {
            Serial.println("Auth Failed");
            } else if (error == OTA_BEGIN_ERROR) {
            Serial.println("Begin Failed");
            } else if (error == OTA_CONNECT_ERROR) {
            Serial.println("Connect Failed");
            } else if (error == OTA_RECEIVE_ERROR) {
            Serial.println("Receive Failed");
            } else if (error == OTA_END_ERROR) {
            Serial.println("End Failed");
            }
        });
        
        ArduinoOTA.begin();
        Serial.println("OTA Ready");
    }

    void OTA::ota_handle(){

    }
}