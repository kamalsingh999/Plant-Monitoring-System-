#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

 int moistureValue = 0 ;
// Replace with your network credentials
const char* ssid = "GURUJI";
const char* password = "12345678";

// Replace with your DHT sensor information
#define DHT_PIN 26           // GPIO pin connected to the DHT sensor
#define DHT_TYPE DHT11     // DHT sensor type (DHT22 or DHT11)


#define led 4 
// Replace with your moisture sensor pin
#define MOISTURE_SENSOR_PIN 34 // Analog pin connected to the moisture sensor

// Create an instance of the DHT sensor
DHT dht(DHT_PIN, DHT_TYPE);

// Create an instance of the web server
AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");

    pinMode(led,OUTPUT);
  }
  Serial.println("Connected to WiFi");

  // Define routes for web server
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<html><head>";
    html += "<meta http-equiv='refresh' content='3'>"; // Auto-refresh every 3 seconds
    html += "<style>";
    html += "  body { font-family: Arial, Helvetica, sans-serif; text-align: center; }";
    html += "  .button { background-color: #008CBA; border: none; color: white; padding: 15px 32px;";
    html += "    text-align: center; text-decoration: none; display: inline-block; font-size: 16px;";
    html += "    margin: 4px 2px; cursor: pointer; }";
    html += "</style>";
    html += "</head><body>";
    html += "<h1>ESP32 Sensor Data</h1>";
    html += "<p>Temperature (C): " + String(getTemperature()) + "</p>";
    html += "<p>Humidity (%): " + String(getHumidity()) + "</p>";
    html += "<p>Moisture Value: " + String(getMoistureValue()) + "</p>";
    html += "<a href='/image'><button class='button'>Take a Picture</button></a>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  server.on("/image", HTTP_GET, [](AsyncWebServerRequest *request){
    // Add code to capture an image or send a static image file here
    // You may use the ESP32-CAM or another camera module for this purpose
    // Provide an appropriate image or image capture logic
    // For example:
    // request->send(SPIFFS, "/image.jpg", "image/jpeg"); // If using SPIFFS filesystem
    // or
    // request->send(SD, "/image.jpg", "image/jpeg"); // If using an SD card
  });

  // Start the server
  server.begin();
}

void loop() {
 //digitalWrite(led,HIGH);
     if (getMoistureValue()> 3000)
{
    digitalWrite(led,HIGH);
}
else 
{
  digitalWrite(led,LOW);
 }
  // Your main loop code here
}

float getTemperature() {
  return dht.readTemperature();
}

float getHumidity() {
  return dht.readHumidity();
}

int getMoistureValue() {
  // Read moisture value from analog pin
  int moistureValue = analogRead(MOISTURE_SENSOR_PIN);
  return moistureValue;

}
