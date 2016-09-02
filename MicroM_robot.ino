/*####################################
#######      LIBRERIAS     #########
####################################*/
#include <microM.h>

int motorIzq = 5;
int motorDerch = 6;

int GNDIzq =7;
int GNDDerch = 8;

int leftSpeed = 0;
int rightSpeed =0;

int option;

/*####################################
#######      SETUP         #########
####################################*/

void setup() {
  
 microM.Setup(); // this must be called to initialize timer 2
 Serial.begin(9600);
 pinMode (7,OUTPUT);
 pinMode (8, OUTPUT);
 Serial.println("Ready to receive IR commands");
 
}

/*####################################
#######      MAIN LOOP     #########
#################################### */

void loop() {
 
int tiempoAtras= 1000;
int tiempoAdelante= 1000;
int tiempoIzquierda=1000;
int tiempoApagado=3000;
int tiempoDerecha=1000;

if (Serial.available()>0){
    option=Serial.read();
    
    if(option=='a') {
        atras();
        delay (tiempoAtras);
        Serial.println("Atras");
    }
    if(option=='b') {
        adelante ();
        delay(tiempoAdelante);
        Serial.println("Adelante");
    }
    if(option=='i') {
        izquierda ();
        delay (tiempoIzquierda);
        Serial.println("Izquierda");
    }
    if(option=='d') {
        derecha ();
        delay (tiempoDerecha);
        Serial.println("Derecha");
    }
    if(option=='s') {
        Stop ();
        delay (tiempoApagado);
        Serial.println("Alto");
    }
}}

/*####################################
#######      METODOS       #########
#################################### */

//#######  ATRAS   ###########
void atras(){
 
int leftSpeed =70;
int rightSpeed =70;

digitalWrite (7,HIGH);
analogWrite(5,leftSpeed);

digitalWrite (8,HIGH);
analogWrite(6,rightSpeed);

delay (100);
}

//######  ADELANTE   ###########
void adelante(){
 
int leftSpeed =70;
int rightSpeed =70;

digitalWrite (7,LOW);
analogWrite(5,leftSpeed);

digitalWrite (8,LOW);
analogWrite(6,rightSpeed);
}

//#######  IZQUIERDA   ###########
void izquierda(){
 
int leftSpeed =70;
int rightSpeed =70;

digitalWrite (7,HIGH);
analogWrite(5,leftSpeed);

digitalWrite (8,LOW);
analogWrite(6,rightSpeed);
}

//#######  DERECHA   ###########
void derecha(){
 
int leftSpeed =70;
int rightSpeed =70;

digitalWrite (7,LOW);
analogWrite(5,leftSpeed);

digitalWrite (8,HIGH);
analogWrite(6,rightSpeed);
}

//#######  STOP   ###########
void Stop(){
 
static int leftSpeed =0;
static int rightSpeed =0;

digitalWrite (7,LOW);
analogWrite(5,0);

digitalWrite (8,LOW);
analogWrite(6,0);
}
