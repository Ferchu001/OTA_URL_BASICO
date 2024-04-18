#include <HTTPClient.h>
#include <Update.h>
#include <ESP32HTTPUpdate.h>

const char *ssid = "InsoltechPB";
const char *password = "Hola1234";

const char *url = "https://vm.serverqst.com/c2/bootloader/firmware.bin";

void setup()
{
  Serial.begin(115200);
  Serial.println("Iniciando...");
  // Inicia la conexión WiFi
  // Configura la conexión WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conexión WiFi establecida");
  Serial.println("Version Nueva>>>>>>>>>>>>>>>>");
  // Descarga el archivo de actualización OTA
  Serial.printf("Descargando archivo de %s...\n", url);
  t_httpUpdate_return ret = ESPhttpUpdate.update(url);
  if (ret == HTTP_UPDATE_OK)
  {
    Serial.println("Actualización OTA exitosa");
  }
  else
  {
    Serial.printf("Error durante la actualización OTA: %d\n", ret);
  }
}

void loop()
{
  // Tu código aquí
}
