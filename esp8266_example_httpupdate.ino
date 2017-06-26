/*  Roberto Biegelmeyer                                     */
/*  Configure a ESP8266 para o maximo de flash disponivel.  */
/*  Exemplo: Flash Size: "1M(64SPIFFS)"                     */

/*  Modifique o metodo de entrada do parametro da funcao    */
/*  firmwareUpdate para modificar o local na web.           */

/*  Se desejar, use um acionamento por algum protocolo de   */

/*  comunicacaoo web (Firebase, MQTT, etc) para disparar a  */
/*  funcao          */


#include <ESP8266httpUpdate.h>

String ssid = "ssid";        //Nome da rede
String pass = "pass";  //Senha da rede

void firmwareUpdate(String url) {
  delay(100);
  Serial.println("Updating...");

  t_httpUpdate_return ret = ESPhttpUpdate.update(url);
  
  switch (ret) {
    case HTTP_UPDATE_FAILED:
      Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
      break;

    case HTTP_UPDATE_NO_UPDATES:
      Serial.println("HTTP_UPDATE_NO_UPDATES");
      break;

    case HTTP_UPDATE_OK:
      Serial.println("HTTP_UPDATE_OK");
      break;
  }
}

void setup(){
  Serial.begin(115200);
  delay(5);

  WiFi.begin(ssid.c_str(), pass.c_str());
  delay(500);

  while ((WiFi.status() != WL_CONNECTED) ) {
    Serial.print(".");
    delay(75);
  }
  Serial.println("Conectado");
  
  //Mudar endereço dentro do parametro da chama de funcao abaixo
  firmwareUpdate("http://centralsigma.com.br/eletronica/update/aUpdate.bin");
  
  delay(1000);
}

void loop(){
  
}

