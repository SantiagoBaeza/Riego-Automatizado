[⬅️ Volver a "Arduino"](https://github.com/SantiagoBaeza/-Portfolio-de-proyectos-Arduino-Embebidos)
## Sistema de Riego Automatizado con LCD y Sensor de Humedad

Este proyecto implementa un sistema de riego automático utilizando un **sensor de humedad de suelo**, **rele**, **LEDs indicadores**, y una **pantalla LCD 16x2** para mostrar el estado en tiempo real. Fue desarrollado y probado en [Tinkercad](https://www.tinkercad.com/things/7xR8ddvjRx1-riego-automatizado) (simulacion)con miras a ser usado en un entorno real.

---

### 📌 Objetivo

Detectar el nivel de humedad del suelo y **activar una bomba de agua automáticamente** si el suelo está seco, mostrando mensajes informativos en una pantalla LCD para que el usuario tenga feedback visual claro.

---

### Componentes utilizados

| Componente                   | Cantidad |
| ---------------------------- | -------- |
| Arduino Uno                  | 1        |
| Sensor de humedad de suelo   | 1        |
| Pantalla LCD 16x2            | 1        |
| Potenciómetro                | 1        |
| LEDs (rojo, amarillo, verde) | 3        |
| Resistencias 220Ω            | 3        |
| Relay 5V                     | 1        |
| Transistor NPN (ej. 2N2222)  | 1        |
| Protoboard + cables          | varios   |

---

###  Esquema de conexión

🧠 El circuito se encuentra simulado en Tinkercad.
📸 A continuación se muestra el diseño con sus respectivas etiquetas explicativas:

![Circuito Tinkercad](https://github.com/SantiagoBaeza/Riego-Automatizado/blob/main/01%20esquema%20en%20tinkercad%20.jpg)

> 💡 **Importante**: El relay está activado con un transistor para evitar que el Arduino suministre directamente corriente excesiva al módulo.

---

### Lógica del funcionamiento

* El sensor de humedad entrega un valor entre **0 y 1023**.
* Según ese valor se clasifican tres estados:

  * **0–300** → Suelo seco → Bomba encendida + LED rojo
  * **301–700** → Humedad media → Bomba apagada + LED amarillo
  * **701–1023** → Suelo húmedo → Bomba apagada + LED verde
* En cada caso, la **pantalla LCD** muestra un mensaje diferente informando el estado y si la bomba está activada o no.

---

### Pantalla LCD

Se utiliza la librería `LiquidCrystal.h` con los siguientes pines:

```cpp
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
```

Mensajes que se muestran:

| Estado del suelo | Mensaje LCD línea 1 | Mensaje LCD línea 2 |
| ---------------- | ------------------- | ------------------- |
| Suelo seco       | `Suelo seco.`       | `Bomba encendida`   |
| Humedad media    | `Suelo medio.`      | `Bomba apagada`     |
| Suelo húmedo     | `Suelo humedo.`     | `Bomba apagada`     |

---

### Código

El código completo se puede encontrar en este repositorio bajo `codigo.ino`. A continuación se muestra un fragmento relevante:

```cpp
if(analogRead(A0)<300){
  digitalWrite(rojo, HIGH);
  digitalWrite(2, HIGH);
  lcd.setCursor(0,0); lcd.clear(); lcd.print("Suelo seco.");
  lcd.setCursor(0,1); lcd.print("Bomba encendida");
}
```

---

### Aprendizajes personales

> *"Este fue mi primer proyecto con pantalla LCD y también mi primer uso de un transistor NPN para controlar un relay. El hecho de que haya funcionado para resolver un problema real de consumo fue un gran logro personal. Me siento muy motivado de poder integrar poco a poco más sensores, componentes y control visual en mis sistemas."*

---

### Posibles mejoras

* Agregar un botón para modo manual de riego
* Incorporar un módulo Wi-Fi (ESP8266/ESP32) para control remoto
* Añadir sensor de temperatura o humedad ambiental
* Guardar lecturas en una tarjeta SD
* Implementar este circuito a una pantalla lcd I2C 

---

### 📂 Archivos

* `codigo.ino` – Código principal
* `diagrama.png` – Imagen del circuito
* `README.md` – Este archivo

---

