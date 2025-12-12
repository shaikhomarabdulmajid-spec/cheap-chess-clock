#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------------- Pins ----------------
const int playerAButton = 2;  // D2  → A's button
const int playerBButton = 4;  // D4  → B's button
const int resetButton   = 3;  // D3  → reset button

// ---------------- Time ----------------
int playerATime = 5 * 60;   // 5 minutes each
int playerBTime = 5 * 60;
bool playerATurn = false;   // A starts after first press
bool gameStarted = false;
bool gameOver = false;
unsigned long prevMillis = 0;
const long interval = 1000; // 1 second

// ------------------------------------------------
void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(playerAButton, INPUT_PULLUP);
  pinMode(playerBButton, INPUT_PULLUP);
  pinMode(resetButton,   INPUT_PULLUP);

  displayTimes();
}

// ------------------------------------------------
void loop() {
  unsigned long now = millis();

  // ---------- Reset ----------
  if (digitalRead(resetButton) == LOW) {
    resetGame();
    delay(300);
    return;
  }

  // ---------- Start the game ----------
  if (!gameStarted && !gameOver && digitalRead(playerAButton) == LOW) {
    gameStarted = true;
    playerATurn = true; // A starts first
    delay(50);
  }

  // ---------- If game over, do nothing ----------
  if (gameOver) return;

  // ---------- Switch turns ----------
  if (gameStarted) {
    if (playerATurn && digitalRead(playerAButton) == LOW) {
      playerATurn = false;  // switch to B
      delay(50);
    }
    else if (!playerATurn && digitalRead(playerBButton) == LOW) {
      playerATurn = true;   // switch to A
      delay(50);
    }
  }

  // ---------- Countdown ----------
  if (gameStarted && (now - prevMillis >= interval)) {
    prevMillis = now;

    if (playerATurn && playerATime > 0) playerATime--;
    else if (!playerATurn && playerBTime > 0) playerBTime--;

    // Stop everything when one player's time ends
    if (playerATime == 0 || playerBTime == 0) {
      gameOver = true;
      gameStarted = false;
    }

    displayTimes();
  }
}

// ------------------------------------------------
void resetGame() {
  playerATime = 5 * 60;
  playerBTime = 5 * 60;
  playerATurn = false;
  gameStarted = false;
  gameOver = false;
  displayTimes();
}

// ------------------------------------------------
void displayTimes() {
  lcd.clear();

  // ----- Top row: Player A -----
  if (playerATurn || (!gameStarted && !gameOver)) lcd.print(">");
  else lcd.print(" ");
  lcd.print("A: ");
  lcd.print(formatTime(playerATime));

  // ----- Bottom row: Player B -----
  lcd.setCursor(0, 1);
  if (!playerATurn && gameStarted) lcd.print(">");
  else lcd.print(" ");
  lcd.print("B: ");
  lcd.print(formatTime(playerBTime));

  // ----- Show TIME UP if game ended -----
  if (gameOver) {
    lcd.setCursor(10, playerATime == 0 ? 0 : 1);
    lcd.print("TIME UP!");
  }
}

// ------------------------------------------------
String formatTime(int totalSeconds) {
  int m = totalSeconds / 60;
  int s = totalSeconds % 60;
  char buf[6];
  sprintf(buf, "%02d:%02d", m, s);
  return String(buf);
}
