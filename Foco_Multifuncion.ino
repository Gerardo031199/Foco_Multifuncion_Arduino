int rele1 = 7;
int rele2 = 8;
int buzzer = 11;
int pir = 3;

void setup () {
  pinMode(rele1, OUTPUT); //rele1 como salida
  pinMode(rele2, OUTPUT); //rele2 como salida
  pinMode(buzzer, OUTPUT); //buzzer como salida
  pinMode(pir, INPUT);
  Serial.begin(9600); //Inicializo el puerto serial a 9600 baudios
}

void loop () {
  if (Serial.available()) { //Si está disponible el puerto serial
    char c = Serial.read(); //Guardamos la lectura en una variable char

    if (c == 'H') { //Si se digita en la consola la letra H el rele1 se encendera
      digitalWrite(rele1, LOW);
      Serial.println("FOCO 1 ENCENDIDO");

    } else if (c == 'L'){ //Si se digita en la consola la letra L el rele1 se apagara
      digitalWrite(rele1, HIGH);
    Serial.println("FOCO 1 APAGADO");

  } else if (c == 'E') { //Si se digita en la consola la letra E el rele2 se encendera
    digitalWrite(rele2, LOW);
    Serial.println("FOCO 2 ENCENDIDO");

  } else if (c == 'A') { //Si se digita en la consola la letra 'A' el rele2 se apagara
    digitalWrite(rele2, HIGH);
    Serial.println("FOCO 2 APAGADO");

  } else while (c == 'R') { //Si se digita en la consola la letra 'R' entrara al bucle infinito
      int valor = digitalRead(pir);
      if (valor == HIGH) {
        Serial.println("¿Quien anda ahí?"); //Se muestra en la consola cada segundo el mensaje "¿Quien anda ahí?"
        digitalWrite(rele2, LOW);
        digitalWrite(buzzer, HIGH);
        tone(buzzer, 2603, 600);
        tone(buzzer, 4603, 300);
        delay(1000);

      } else { //Si no hay movimiento se mandara en consola una linea de puntos

        char j = Serial.read(); //Guardamos la lectura en una variable char

        if (j == 'S') { //Si se digita en la consola la letra 'S' se saldra del bucle
          Serial.println("SALIDA"); //Se muestra en consola el mensaje "SALIDA"
          break;
        }
        Serial.println("."); //Se muestra en la consola cada segundo un punto
        digitalWrite(rele2, HIGH); //El rele2 se mantiene apagado mientras no hay movimiento
        digitalWrite(buzzer, LOW); //El buzzer se mantiene apagado mientras no hay movimiento

      }
      delay(1000);
    }
}
}
