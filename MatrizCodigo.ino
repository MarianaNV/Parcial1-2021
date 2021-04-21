//--------------------------DESCRIPCION-----------------------------------------------------------
/*
El presente circuito es la implementación de una matriz 8x8 junto con el circuito integrado 74HC595.

Además, se van a mostrar los siguientes caracteres:

- Números (0-9): Ingrese el numero que quiere ver 
- Letras (A-Z) exceptuando Ñ; para ello ingrese la letra que quiere ver en mayúscula.
- Caracteres especiales: corazón , rombo , ►. 
  Si va a imprimir el corazón ingrese h, para el rombo ingrese r y para ► ingrese p
  
  




*/


//----------------Pines---------------------------------------------------------------------------
int SERF = 2; //Entrada 
int SRCLKF = 4; //Registro de entrada 
int RCLKF = 3; // Registro de salida 

//Arreglo para recorrer las filas

int Filas[] = {127, 191, 223, 239, 247, 251, 253, 254};
//Caracteres a mostra

int A[] = {0,60,102,102,126,102,102,102};
int B[] = {120,72,72,112,72,68,68,124};
int C[] = {0,30,32,64,64,64,32,30};
int D[] = {0,56,36,34,34,36,56,0};
int E[] = {0,56,32,56,32,32,60,0};
int F[] = {0,60,32,56,32,32,32,0};
int G[] = {0,62,32,32,46,34,62,0};
int H[] = {0,36,36,60,36,36,36,0};
int I[] = {0,56,16,16,16,16,56,0};
int J[] = {0,28,8,8,8,40,56,0};
int K[] = {0,36,40,48,40,40,40,0};
int L[] = {0,32,32,32,32,32,60,0};
int M[] = {0,0,68,170,146,130,130,0};
int N[] = {0,34,50,42,38,34,0,0};
int O[] = {0,60,66,66,66,66,60,0};
int P[] = {0,56,36,36,56,32,32,0};
int Q[] = {0,60,66,66,66,70,62,1};
int R[] = {0,56,36,36,56,36,36,0};
int S[] = {0,60,32,60,4,4,60,0};
int T[] = {0,124,16,16,16,16,16,0};
int U[] = {0,66,66,66,66,36,24,0};
int V[] = {0,34,34,34,20,20,8,0};
int W[] = {0,130,146,84,84,40,0,0};
int X[] = {0,66,36,24,24,36,66,0};
int Y[] = {0,68,40,16,16,16,16,0};
int Z[] = {0,60,4,8,16,32,60,0};

//NUMEROS
int N1[] = {24, 28, 26,24,24,24,126};
int N2[] = {60, 102, 96, 48,24,76,126,126};
int N3[] = {60, 102, 96, 60 ,96 , 102,102,60};
int N4[] = {112, 104, 100, 98, 126,96,96,96};
int N5[] = {126,102,6,126,96,102,102,60};
int N6[] = {56,12,4,6,126,70,68,56};
int N7[] = {62,34,32,24,8,8,8,8};
int N8[] = {60,60,195,195,60,195,195,60};
int N9[] = {28,34,34,60,32,32,24,12};
int N0[] = {60, 195, 227, 211, 203,199, 195, 60};

//CARACTERES ESPECIALES
int CORAZON[] = {0,54,127,127,62,28,8,0};
int ROMBO[] = {8, 28,62,127,127,62,28,8};
int PLAY[] = {4,12,28,60,60,28,12,4};
 
void verificacion();
void apagar();
void imagen(char);
void publik(char *, int);

void setup(){
  // Entradas y registros 
  int puertos[]={ 2, 3 , 4}; 

  for(int i = 2; i<5; i++){
    pinMode(puertos[i], OUTPUT);
  }
  
  Serial.begin(9600);
  /*
  Serial.print("Ingrese una letra A-Z: ");  //Se debe de modificar (MENU)
  Serial.println();*/
  
  delay(1000); //Tiempo para que muestre la funcion de verificacion
  verificacion();
  delay(50);
  apagar();

}


void loop(){

  int cantP;
  float tmp;
  
  delay(1000);
  while(Serial.available()>0){ //Recibir la cantidad de protrones
    cantP=Serial.parseInt(); 
    Serial.println(cantP);
  }
  
  delay(1000);
  while(Serial.available()>0){ //Para ingresarlo se pone .
    tmp=Serial.parseFloat();
    Serial.println(tmp);
  }

  char patrones[10];
  for(int i=0; i<cantP; i++){
    delay(1000);
    while(Serial.available()>0){
      char car=Serial.read();
      patrones[i]=car;
      Serial.println(patrones[i]);
    }
  }
  Serial.println("Datos recibidos.");

}
  
void verificacion(){
  int matriz[]={255,255,255,255,255,255,255,255};
  
  for(int i=0; i<8; i++){
    digitalWrite(RCLKF,LOW);
    shiftOut(SERF, SRCLKF, LSBFIRST, matriz[i]);
    shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
    digitalWrite(RCLKF,HIGH);
  }
  
}

void apagar(){
  int matriz[]={0,0,0,0,0,0,0,0};
  for(int i=0; i<8; i++){
    digitalWrite(RCLKF,LOW);
    shiftOut(SERF, SRCLKF, MSBFIRST, matriz[i]);
    shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
    digitalWrite(RCLKF,HIGH);
  }
  
}

void publik(char *array, int n, float t){
	
  for(int s=0; s<n; s++){
    imagen(array[s]);
    delay(t);
  
  }

}

void imagen(char let){
  switch (let){
    
    case '1':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, MSBFIRST, N1[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
    
    case '2':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, MSBFIRST, N2[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
    
    case '3':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, MSBFIRST, N3[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
    
    case '4':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, MSBFIRST, N4[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
    
    case '5':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, MSBFIRST, N5[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
    
    case '6':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, MSBFIRST, N6[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
    
    case '7':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, MSBFIRST, N7[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
    
    case '8':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, MSBFIRST, N8[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
    
    case '9':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, MSBFIRST, N9[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
      
    case 'A':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, A[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
  	
    case 'B':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, B[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
    
    case 'C':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, C[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
    
    case 'D':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, D[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
    
    case 'E':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, E[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;

    case 'F':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, F[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
    
    case 'G':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, G[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
    
    case 'H':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, H[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
    
    case 'I':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, I[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;

    
    case 'J':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, J[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
    
    case 'K':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, K[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
    
    case 'L':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, L[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
    
    case 'M':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, M[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
    
    case 'N':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, N[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
    
    case 'O':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, O[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
    
    case 'P':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, P[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }

    break;
    
    case 'Q':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, Q[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }

    break;
    
    case 'R':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, R[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }

    break;
    
    case 'S':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, S[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }

    break;
    
    case 'T':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, T[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }

    break;

    case 'U':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);   
      shiftOut(SERF, SRCLKF, LSBFIRST, U[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }

    break;
    
    case 'V':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, V[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }

    break;
    
    case 'W':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, W[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }

    break;
    
    case 'X':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, X[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }

    break;
    
    case 'Y':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, Y[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
  
    break;
    case 'Z':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, LSBFIRST, Z[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    } 
    break; 
    
    case 'h':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, MSBFIRST, CORAZON[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
    case 'r':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, MSBFIRST, ROMBO[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
    case 'p':
    for(int i=0; i<8; i++){

      digitalWrite(RCLKF,LOW);    
      shiftOut(SERF, SRCLKF, MSBFIRST, PLAY[i]);
      shiftOut(SERF, SRCLKF, LSBFIRST, Filas[i]);
      digitalWrite(RCLKF,HIGH);    
    }
    break;
  }

}







