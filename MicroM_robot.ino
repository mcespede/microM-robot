#include <microM.h>

int motorIzq = 5;
int motorDerch = 6;

int GNDIzq =7;
int GNDDerch = 8;

int leftSpeed = 0;
int rightSpeed =0;


void setup() {
 
 Serial.begin(9600);
 pinMode (7,OUTPUT);
 pinMode (8, OUTPUT);
}

void loop() {
int tiempoAtras= 3000;
int tiempoAdelante= 000;
int tiempoIzquierda=1000;
int tiempoApagado=5000;
 
int leftSpeed =80;
int rightSpeed =80;
 
//atras();
//delay (tiempoAtras);

//adelante ();
//delay(tiempoAdelante);

izquierda ();
delay (tiempoIzquierda);

Stop ();

delay (tiempoApagado);

}

void atras()

{
int leftSpeed =100;
int rightSpeed =100;

digitalWrite (7,HIGH);
analogWrite(5,leftSpeed);

digitalWrite (8,HIGH);
analogWrite(6,rightSpeed);

delay (100);
}

void adelante()

{
int leftSpeed =100;
int rightSpeed =100;

digitalWrite (7,LOW);
analogWrite(5,leftSpeed);

digitalWrite (8,LOW);
analogWrite(6,rightSpeed);
}

void izquierda()

{
int leftSpeed =100;
int rightSpeed =100;

digitalWrite (7,HIGH);
analogWrite(5,leftSpeed);

digitalWrite (8,LOW);
analogWrite(6,rightSpeed);
}

void Stop()

{
static int leftSpeed =0;
static int rightSpeed =0;

digitalWrite (7,LOW);
analogWrite(5,0);

digitalWrite (8,LOW);
analogWrite(6,0);
}
