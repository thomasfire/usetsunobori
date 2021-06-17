
#define PORTS_N 5

typedef struct {
  uint16_t data_0;
  uint16_t data_1;
  uint16_t data_2;
  uint16_t data_3;
  uint16_t data_4; 
} emg_data_t;

emg_data_t storage;

void sendData() {
  storage.data_0 = analogRead(A0);
  storage.data_1 = analogRead(A1);
  storage.data_2 = analogRead(A2);
  storage.data_3 = analogRead(A3);
  storage.data_4 = analogRead(A4);
  
  Serial.write((byte*)&storage, sizeof(storage));

}

// функция setup вызывается однократно при запуске Arduino
void setup() {
  Serial.begin(115200);
}

void loop(){
  delay(1);
  sendData();
}
