
#define BLYNK_PRINT Serial

// setting library
#include <ESP8266WiFi.h> // file untuk modul wifi
#include <BlynkSimpleEsp8266.h> // file untuk blynk
#include <Servo.h> // library untuk servo

char auth[] = "mrO7DRPIA-nTrG-1yLB9QYaSwabxMU_C"; //token yang dikirim dari blynk ke email masing masing
char ssid[] = "WiFi";
char pass[] = "apaandahh";

// definisi fungsi servo
Servo gerak_servo;

BLYNK_WRITE(V1)
{
  gerak_servo.write(param.asInt());
} // Fungsi blynk untuk mengatur nilau servo dengan pin virtual V1 yang ada pada aplikasi blynk

void setup() // fungsi utama dijalankan
{
  // Debug console
  Serial.begin(9600); // memulai serial monitor dengan boudrate 9600

  Blynk.begin(auth, ssid, pass); // menjalankan blynk sesuai token, wifi, dan passwordnya

  gerak_servo.attach(2); // setting pin gpio 2 ke servo, D4 = 2
}
 
void loop() // fungsi utama dijalankan berulang kali
{
  Blynk.run(); // memulai blynk 
}
