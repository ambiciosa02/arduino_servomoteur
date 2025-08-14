#include <Servo.h>
const int gasPin = A0; //Capteur de gaz connecté à l'entrée analogique A0
const int threshold = 400;//Seuil au-dela duquel le servomoteur se déclenche
const int servoPin = 13;// Servomoteur connecté à la broche 7
Servo myServo; // Creation d'un objet Servo
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//Initialisation du port série à 9600 bauds
myServo.attach(servoPin); //Attacher le servomoteur à la broche définie
myServo.write(0);//Assurez-vous que le servomoteur est à sa position initiale
}

void loop() {
  // put your main code here, to run repeatedly:
int gaslevel = analogRead(gasPin);//Lecture de al valeur du capteur de gaz
Serial.println(gaslevel);//affichage de la valeur lue
  //verification du seuil et deplacement sus servomoteur si necessaire
  if(gaslevel > threshold) {
    myServo.write(90);// deplacer le servomoteur à 90°(ajustable selon l'application)
  }else {
    myServo.write(0);//Remettre le servomteur à sa position initiale
  }
  delay(1000);
}
