int cafeteira = 9; //Declarando porta serial
char c; //Declarando variavel que ira receber um caracter
String codigo; //Variavel que armazena os caracteres 

void setup(){
  Serial.begin(9600);
  pinMode(cafeteira, OUTPUT); 
  digitalWrite(cafetira, HIGH); //Iniciando a cafeteira desligada 
}
void loop(){
  codigo = "";
  while(true){
    if(Serial.available() > 0){
      char c = Serial.read();
      if(c == '\n'){ //Flag de saida
        break;
      }else{
        codigo += c; //Armazenando o caracter recebido
      }
    }
  }  

  //Comparando os codigos informados 
  if(codigo == "nao quero"){
    digitalWrite(cafeteira, HIGH); //Desligando a cafeteira 
  }
  if(codigo == "quero cafe"){
    digitalWrite(cafeteira, LOW); //Ligando a cafeteira 
  }


}
