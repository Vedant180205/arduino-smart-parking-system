#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); // RX, TX
int M1_F = 9;
int M1_R = 10;
int M2_F = 11;
int M2_R = 12;
int incomingByte;

void setup() {
  pinMode(M1_F, OUTPUT);
  pinMode(M1_R, OUTPUT);
  pinMode(M2_F, OUTPUT);
  pinMode(M2_R, OUTPUT);
  BT.begin(9600);
}

void loop() {
  if (BT.available() > 0) {
    incomingByte = BT.read();
    
    // Check for incoming commands
    if (incomingByte == 'F') {
      forward();  // Move forward when 'F' is received
    }
    else if (incomingByte == 'S') {
      Stop();  // Stop when 'S' is received
    }
    else if (incomingByte == 'L') {
      left();  // Turn left when 'L' is received
    }
    else if (incomingByte == 'R') {
      Right();  // Turn right when 'R' is received
    }
    else if (incomingByte == 'P') {
      parking();  // Execute the parking function when 'P' is received
    }
  }
}

// Stop the motors
void Stop() {
  BT.println("STOP");
  digitalWrite(M1_F, LOW);
  digitalWrite(M1_R, LOW);
  digitalWrite(M2_F, LOW);
  digitalWrite(M2_R, LOW);
}

// Move forward
void forward() {
  BT.println("FORWARD");
  digitalWrite(M1_F, HIGH);
  digitalWrite(M1_R, LOW);
  digitalWrite(M2_F, HIGH);
  digitalWrite(M2_R, LOW);
}

// Move backward
void backward() {
  BT.println("BACKWARD");
  digitalWrite(M1_F, LOW);
  digitalWrite(M1_R, HIGH);
  digitalWrite(M2_F, LOW);
  digitalWrite(M2_R, HIGH);
}

// Turn right
void Right() {
  BT.println("RIGHT");
  digitalWrite(M1_F, LOW);   // Left motor forward
  digitalWrite(M1_R, LOW);   // Left motor reverse
  digitalWrite(M2_F, HIGH);  // Right motor forward
  digitalWrite(M2_R, LOW);   // Right motor reverse
}

// Turn left
void left() {
  BT.println("LEFT");
  digitalWrite(M1_F, HIGH);  // Left motor forward
  digitalWrite(M1_R, LOW);   // Left motor reverse
  digitalWrite(M2_F, LOW);   // Right motor forward
  digitalWrite(M2_R, LOW);   // Right motor reverse
}

// Parking function as per the requirement
void parking() {
  // Left turn for 190 milliseconds
  left();
  delay(190);

  // Backward move for 100 milliseconds
  backward();
  delay(100);

  // Left turn again for 190 milliseconds
  left();
  delay(240);

  // Backward move for 1000 milliseconds
  backward();
  delay(750);

  // Optionally stop after parking
  Stop();
}
