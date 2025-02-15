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
#define WIFI_PASSWORD "rafa2011"

//Firebase
#define API_KEY "AIzaSyBI4MM7N9IzKylgObu5q_L9-YCTYNc91sc"
#define DATABASE_URL "https://projetoesp32-37dad-default-rtdb.firebaseio.com/" //a URL deve ser bem formada https://domínio/
//Variáveis globais para manipular o Firebase
FirebaseData fbdo; //Define Firebase Data object
FirebaseAuth auth; //Define Firebase Auth object
FirebaseConfig config; //Define Firebase Config object

#define LED_AZUL 2

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

int count_int = 0;

void loop() {
  delay(2000);
  if (Firebase.ready()) {


    // // BANHEIRO 1
    // Serial.println("Estado da luz do banheiro 1:");
    // Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa/bwc1/estado"))
    // ? String(fbdo.to<int>()).c_str() 
    // : fbdo.errorReason().c_str()
    // );

    // // BANHEIRO 2
    // Serial.println("Estado da luz do banheiro 2:");
    // Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa/bwc2/estado"))
    // ? String(fbdo.to<int>()).c_str() 
    // : fbdo.errorReason().c_str()
    // );

    // // COZINHA
    // Serial.println("Estado da luz da cozinha:");
    // Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa/cozinha/estado"))
    // ? String(fbdo.to<int>()).c_str() 
    // : fbdo.errorReason().c_str()
    // );

    // // QUARTO 1
    // Serial.println("Estado da luz do quarto 1:");
    // Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa/quarto1/estado"))
    // ? String(fbdo.to<int>()).c_str() 
    // : fbdo.errorReason().c_str()
    // );

    //   // ar condicionado
    // Serial.println("Estado do ar do quarto 1:");
    // Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa/quarto1/estado_ar"))
    // ? String(fbdo.to<int>()).c_str() 
    // : fbdo.errorReason().c_str()
    // );

    // // QUARTO 2
    // Serial.println("Estado da luz do quarto 2:");
    // Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa/quarto2/estado"))
    // ? String(fbdo.to<int>()).c_str() 
    // : fbdo.errorReason().c_str()
    // );

    //   // ar condicionado
    // Serial.println("Estado do ar do quarto 2:");
    // Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa/quarto2/estado_ar"))
    // ? String(fbdo.to<int>()).c_str() 
    // : fbdo.errorReason().c_str()
    // );

    // // QUARTO 3
    // Serial.println("Estado da luz do quarto 3:");
    // Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa/quarto3/estado"))
    // ? String(fbdo.to<int>()).c_str() 
    // : fbdo.errorReason().c_str()
    // );

    //   // ar condicionado
    // Serial.println("Estado do ar do quarto 3:");
    // Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa/quarto3/estado_ar"))
    // ? String(fbdo.to<int>()).c_str() 
    // : fbdo.errorReason().c_str()
    // );

    //  // SALA
    // Serial.println("Estado da luz da sala:");
    // Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa/sala/estado"))
    // ? String(fbdo.to<int>()).c_str() 
    // : fbdo.errorReason().c_str()
    // );

     // VARANDA
    Serial.println("Estado da luz da varanda:");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa/varanda/estado"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str()
    );
  
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);
  
  }
}

void setup() {
  //inicializando o terminal
  Serial.begin(9600);
  //inicializa o Wifi e o Firebase
  Serial.println();
  Serial.println("Setup Wifi e Firebase");
  wifiSetup();
  firebaseSetup();
  pinMode(LED_AZUL, OUTPUT); //seta o pino 2 do led azul para output
  loop();
}




