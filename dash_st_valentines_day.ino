//Dash Pins

int zero = D15;
int one = D30;
int two = D28;
int three = D29;
int four = D26;
int five = D07;
int six = D06;
int seven = D05;
int eight = D02;
int nine = D16;
int ten = D17;


//variables
int sms_queue = 0;


void setup() {

  //set pins to output
  pinMode(zero, OUTPUT);
  pinMode(one, OUTPUT);
  pinMode(two, OUTPUT);
  pinMode(three, OUTPUT);
  pinMode(four, OUTPUT);
  pinMode(five, OUTPUT);
  pinMode(six, OUTPUT);
  pinMode(seven, OUTPUT);
  pinMode(eight, OUTPUT);
  pinMode(nine, OUTPUT);
  pinMode(ten, OUTPUT);

  digitalWrite(zero, HIGH);
  digitalWrite(one, HIGH);
  digitalWrite(two, HIGH);
  digitalWrite(three, HIGH);
  digitalWrite(four, HIGH);
  digitalWrite(five, HIGH);
  digitalWrite(six, HIGH);
  digitalWrite(seven, HIGH);
  digitalWrite(eight, HIGH);
  digitalWrite(nine, HIGH);
  digitalWrite(ten, HIGH);

  // initialize Serial communication for debugging
  Serial.begin(9600);
  Serial.println("Starting");



  //send a starting messge to the Hologram cloud
  HologramCloud.sendMessage("Starting", "St.Valentines");

  //attach the SMS Handler Funciton
  HologramCloud.attachHandlerSMS(cloud_sms);

}

void loop() {

  //print loop to let us know we are running in serial
  Serial.println("loop");
  delay(3000);

}


//On received SMS, print the sender, timestamp and message
//Send a message to the cloud that an SMS was received with the sender number
//as the content and the tag SMSRX
void cloud_sms(const String &sender, const rtc_datetime_t &timestamp, const String &message) {
  Serial.println("CLOUD SMS RECEIVED:");
  Serial.print("SMS SENDER: ");
  Serial.println(sender);
  Serial.print("SMS TIMESTAMP: ");
  Serial.println(timestamp);
  Serial.println("SMS TEXT: ");
  Serial.println(message);
  String message2 = message;
  message2.toLowerCase();

  if (message2 == "zero" || message2 == "0" || message2 == "atm") {
    Serial.println("Play Pin 0");
    digitalWrite(zero, LOW);
    delay(300);
    digitalWrite(zero, HIGH);
  }

  else if (message2 == "one" || message2 == "1" || message2 == "Im all shook up") {
    Serial.println("Play Pin 1");
    digitalWrite(one, LOW);
    delay(300);
    digitalWrite(one, HIGH);
  }
  else if (message2 == "two" || message2 == "2" || message2 == "I feel good") {
    Serial.println("Play Pin 2");
    digitalWrite(two, LOW);
    delay(300);
    digitalWrite(two, HIGH);
  }

  else if (message2 == "three" || message2 == "3" || message2 == "Kiss the sky") {
    Serial.println("Play Pin 3");
    digitalWrite(three, LOW);
    delay(300);
    digitalWrite(three, HIGH);
  }

  else if (message2 == "four" || message2 == "4" || message2 == "Te Amo") {
    Serial.println("Play Pin 4");
    digitalWrite(four, LOW);
    delay(300);
    digitalWrite(four, HIGH);
  }

  else if (message2 == "five" || message2 == "5" || message2 == "Kiss") {
    Serial.println("Play Pin 5");
    digitalWrite(five, LOW);
    delay(300);
    digitalWrite(five, HIGH);
  }

  else if (message2 == "six" || message2 == "6" || message2 == "Hold Your Hand") {
    Serial.println("Play Pin 0");
    digitalWrite(six, LOW);
    delay(300);
    digitalWrite(six, HIGH);
  }

  else if (message2 == "seven" || message2 == "7" || message2 == "Heartbeat") {
    Serial.println("Play Pin 7");
    digitalWrite(seven, LOW);
    delay(300);
    digitalWrite(seven, HIGH);
  }

  else if (message2 == "eight" || message2 == "8" || message2 == "Chu") {
    Serial.println("Play Pin 8");
    digitalWrite(eight, LOW);
    delay(300);
    digitalWrite(eight, HIGH);
  }

  else if (message2 == "nine" || message2 == "9" || message2 == "Be my valentine") {
    Serial.println("Play Pin 9");
    digitalWrite(nine, LOW);
    delay(300);
    digitalWrite(nine, HIGH);
  }

  else if (message2 == "ten" || message2 == "10" || message2 == "Wonderwall") {
    Serial.println("Play Pin 10");
    digitalWrite(ten, LOW);
    delay(300);
    digitalWrite(ten, HIGH);
  }



  else if (message2 == "plz help") {
    HologramCloud.sendMessage("0-Atm, 1-Im all shook up, 2-I feel good, 3-Kiss the sky, 4-Te amo, 5-Kiss, 6-I wanna hold your hand, 7-Heartbeat, 8-Chu, 9-Be my valentine, 10-Wonderwall ", "Help");
    Serial.println("0 - Atm ");
    Serial.println("1- Im all shook up");
    Serial.println("2- I feel good");
    Serial.println("3- Kiss the sky");
    Serial.println("4- Te amo");
    Serial.println("5- Kiss");
    Serial.println("6- I wanna hold your hand");
    Serial.println("7- Heartbeat");
    Serial.println("8- Chu");
    Serial.println("9- Be my valentine");
    Serial.println("10- Wonderwall");
  }
  else {
    Serial.println("Invalid Input");
  }


  if (HologramCloud.sendMessage(message, "SMSRX")) {
    Serial.println("SMS received message sent to cloud.");
  } else {
    Serial.println("Notification send failed.");
  }
}
