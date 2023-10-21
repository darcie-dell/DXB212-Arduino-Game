// Pin Setup
// Signal Pins
int game_1_sig_p1 = 2; 
int game_1_sig_p2 = 3;
int game_2_sig_p1 = 4; 
int game_2_sig_p2 = 5;
int game_3_sig_p1 = 6; 
int game_3_sig_p2 = 7;

int game_buzzer_sig_p1 = 8;
int game_buzzer_sig_p2 = 9;

// LED Pins
int game_1_led_p1 = A0; 
int game_1_led_p2 = A1;
int game_2_led_p1 = A2; 
int game_2_led_p2 = A3;
int game_3_led_p1 = A4; 
int game_3_led_p2 = A5;


// Buzzer Pin
int game_2_buzzer = 10;


// Game 1 counters
int game_1_counter_p1 = 0; 
int game_1_counter_p2 = 0; 


// Win Flags
bool game_1_win_p1 = false;
bool game_1_win_p2 = false;

bool game_2_win_p1 = false;
bool game_2_win_p2 = false;

bool game_3_win_p1 = false;
bool game_3_win_p2 = false;

void setup() {
  // Signal Pins
  pinMode(game_1_sig_p1, INPUT);
  pinMode(game_1_sig_p2, INPUT);
  pinMode(game_2_sig_p1, INPUT); 
  pinMode(game_2_sig_p2, INPUT);
  pinMode(game_3_sig_p1, INPUT); 
  pinMode(game_3_sig_p2, INPUT);
  // LED
  pinMode(game_1_led_p1, OUTPUT);
  pinMode(game_1_led_p2, OUTPUT);
  pinMode(game_2_led_p1, OUTPUT);
  pinMode(game_2_led_p2, OUTPUT);
  pinMode(game_3_led_p1, OUTPUT);
  pinMode(game_3_led_p2, OUTPUT);

  // Buzzer
  pinMode(game_2_buzzer, OUTPUT);

  Serial.begin(9600);
}

void LEDS() {
  if (game_1_win_p1 == true) digitalWrite(game_1_led_p1, HIGH);
  if (game_1_win_p2 == true) digitalWrite(game_1_led_p2, HIGH);

  if (game_2_win_p1 == true) digitalWrite(game_2_led_p1, HIGH);
  if (game_2_win_p2 == true) digitalWrite(game_2_led_p2, HIGH);
  
  if (game_3_win_p1 == true) digitalWrite(game_3_led_p1, HIGH);
  if (game_3_win_p2 == true) digitalWrite(game_3_led_p2, HIGH);
}

void game_1() {
  if (digitalRead(game_1_sig_p1) == HIGH) {
    game_1_counter_p1++;
    if (game_1_counter_p1 > 30000) {
      game_1_win_p1 = true;  
    }
  } else {
    if (game_1_counter_p1 > 0) {
        game_1_counter_p1--;
    }
  }
  
  if (digitalRead(game_1_sig_p2) == HIGH) {
    game_1_counter_p2++;
    if (game_1_counter_p2 > 30000) {
      game_1_win_p2 = true;  
    }
  } else {
    if (game_1_counter_p2 > 0) {
        game_1_counter_p2--;
    }
  }  
}

void game_2() {
  if (digitalRead(game_buzzer_sig_p1) == HIGH) {
    tone(game_2_buzzer, 300, 100);
  }

  if (digitalRead(game_buzzer_sig_p2) == HIGH) {
    tone(game_2_buzzer, 800, 100);
  }

  if (digitalRead(game_2_sig_p1) == HIGH) {
    game_2_win_p1 = true;
  }
  if (digitalRead(game_2_sig_p2) == HIGH) {
    game_2_win_p2 = true;
  }
  
}

void game_3() {
  
  if (digitalRead(game_3_sig_p1) == HIGH) {
    game_3_win_p1 = true;
  }
  if (digitalRead(game_3_sig_p2) == HIGH) {
    game_3_win_p2 = true;
  }
}

void loop() {
  game_1();
  game_2();
  game_3();

  LEDS();
}
