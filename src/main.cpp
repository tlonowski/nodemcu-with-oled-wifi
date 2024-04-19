#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <U8g2_for_Adafruit_GFX.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266Ping.h>

const char* ssid = ""; //replace this with your WiFi network name
const char* password = ""; //replace this with your WiFi network password

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Deklaracja obiektu wyświetlacza
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

U8G2_FOR_ADAFRUIT_GFX ada;


void setup() {
  delay(2000);
  Serial.begin(74880);
  // Inicjalizacja magistrali I2C z niestandardowymi pinami
  Wire.begin(D5, D6); // D5 jako SDA, D6 jako SCL
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Start the display
  ada.begin(display);       // Połączenie U8g2 z Adafruit GFX
  ada.setFont(u8g2_font_helvR08_te); // Ustawienie czcionki z polskimi znakami
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0); // Ustawienie pozycji kursora
  display.clearDisplay();
  display.display();
  Serial.println();
  Serial.println();
  WiFi.begin(ssid, password);
  display.print("Connecting");
  display.display();
while (WiFi.status() != WL_CONNECTED)
  {
delay(500);
    display.print(".");
    display.display();
  }
  display.println("success!");
  Serial.print("IP Address is: ");
  Serial.println(WiFi.localIP());
    IPAddress dnsIP = WiFi.dnsIP();
  Serial.print("DNS IP Address: ");
  Serial.println(dnsIP);
}

void loop() {
  display.clearDisplay();
  display.setCursor(0,0); // Ustawienie pozycji kursora
  display.println("Adres IP: "); // Wyświetlenie tekstu
  display.println(WiFi.localIP()); // Wyświetlenie adresu IP
  display.println("SSID: " + String(WiFi.SSID()));
  display.println("AP: " + String(WiFi.BSSIDstr()));
  display.println("Signal: " + String(WiFi.RSSI()) + " dBm");
  
  bool pingResult = Ping.ping("8.8.8.8", 4); // Pinguj 4 razy

  if (pingResult) {
    display.print("Ping Average RTT: ");
    display.print(Ping.averageTime());
    display.println(" ms");

    display.print("Minimum RTT: ");
    display.print(Ping.minTime());
    display.println(" ms");

    display.print("Maximum RTT: ");
    display.print(Ping.maxTime());
    display.println(" ms");
  } else {
    display.println("Ping failed!");
  }
display.display();

  delay(10000);
}
