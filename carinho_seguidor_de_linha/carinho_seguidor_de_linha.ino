///////////////////Carrinho desvia de obstaculos com LDR//////////////////////////
///////////////////////////codigo por: Sarah Ramos////////////////////////////////

//Valor do LDR usando o simbolo de maior é para linhas claras
//Valor do LDR usando o simbolo de menor é para linhas escuras
//Mas isso depende dos seus sesores e da iluminação do ambiente
//TESTE ANTES!

//velocidade dos motores - alterar aqui
const int velocidademotor1 = 80; 
const int velocidademotor2 = 80;

// Os fotoresistores (LDR's) são conectados aos pinos analógicos 0, 1, 2
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
 
// Armazena o valor de leitura analógica
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
 
void setup() {
  
  pinMode(sensor1, INPUT);// Define o fotoresistor 1 como uma entrada
  pinMode(sensor2, INPUT);// Define o fotoresistor 2 como uma entrada
  pinMode(sensor3, INPUT);// Define o fotoresistor 3 como uma entrada
  pinMode(4, OUTPUT); //Define pino do led branco como saida
  pinMode(6, OUTPUT); //pino motor 1
  pinMode(7, OUTPUT); //pino motor 1
  pinMode(8, OUTPUT); //pino motor 2
  pinMode(9, OUTPUT); //pino motor 2
  pinMode(5, OUTPUT); //pino velocidade do motor 1
  pinMode(10, OUTPUT);//pino velocidade do motor 2
  
  // Inicia a comunicação serial com uma taxa de transmissão de 9600 boud rate
  Serial.begin(9600);
}
 
void loop(){
  
  // Lê o valor atual do fotoresistor
  sensorValue1 = analogRead(sensor1);
  sensorValue2 = analogRead(sensor2);
  sensorValue3 = analogRead(sensor3);
  
  digitalWrite(4, HIGH); //led sempre ligado
  
  analogWrite(5, velocidademotor1);
  analogWrite(10, velocidademotor2);

  //condições dos LDR's para seguir a linha
  //aqui voce tem que testar os seus LDR's e pensar na logica para funcionamento do seguidor de linha

  if(sensorValue2 > 600) //para frente
  {
      digitalWrite(6, HIGH); 
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
  }else{
    if(sensorValue1 > 400) //para direita
  { 
    digitalWrite(6, LOW); 
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
  }else{ 
    if(sensorValue3 > 460) //para esquerda
  {
    digitalWrite(6,HIGH); 
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }
  else{ //parado
      digitalWrite(6, LOW); 
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
  }}}

  // Imprime as leituras atuais no monitor serial da IDE do Arduino (use para os testes dos valores dos LDR's)
  Serial.print ("Leitura atual do sensor 1: ");
  Serial.println(sensorValue1);
  Serial.print ("Leitura atual do sensor 2: ");
  Serial.println(sensorValue2);
  Serial.print ("Leitura atual do sensor 3: ");
  Serial.println(sensorValue3);
  delay(100); //tempo de espera
}
