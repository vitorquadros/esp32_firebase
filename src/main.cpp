#include <Arduino.h>

//Firebase Arduino Client Library for ESP8266 and ESP32@
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Wi-fi
#define WIFI_SSID "pipoca"
#define WIFI_PASSWORD "seu_password"

//Firebase
#define API_KEY "AIzaSyBI4MM7N9IzKylgObu5q_L9-YCTYNc91sc"
#define DATABASE_URL "https://projetoesp32-37dad-default-rtdb.firebaseio.com/" //a URL deve ser bem formada https://domínio/
//Variáveis globais para manipular o Firebase
FirebaseData fbdo; //Define Firebase Data object
FirebaseAuth auth; //Define Firebase Auth object
FirebaseConfig config; //Define Firebase Config object

// Leds
#define LED_AZUL 2
#define LED_BWC_1 1
#define LED_BWC_2 1
#define LED_QUARTO_1 1
#define LED_QUARTO_2 1
#define LED_QUARTO_3 1
#define LED_SALA 1
#define LED_VARANDA 1
#define LED_COZINHA 1

// AC


// Projeto



void init() {

}

//Inicializa o wifi
void wifiSetup() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }

  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

//inicializa e authentica no Firebase
void firebaseSetup(){
  
  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  // Assign the user sign in credentials
  auth.user.email = "teste@teste.com";
  auth.user.password = "Teste123";

  // Initialize the library with the Firebase authentication and config
  Firebase.begin(&config, &auth);

  // Optional, set AP reconnection in setup()
  Firebase.reconnectWiFi(true);
}

void setup() {
  //inicializando o terminal
  Serial.begin(9600);
  //inicializa o Wifi e o Firebase
  Serial.println();
  Serial.println("Setup Wifi e Firebase");
  wifiSetup();
  firebaseSetup();
  pinMode(LED_AZUL,OUTPUT); //seta o pino 2 do led azul para output
}
