<img width="1016" height="721" alt="image" src="https://github.com/user-attachments/assets/aebd79f3-b985-4c24-8dd8-bb647675f4cc" />
(Arduino Chess Clock wiring)




<br/>

## ♟️ Precision Arduino Chess Clock
A robust, low-latency digital chess clock built on the Arduino framework. This project implements a state-machine architecture to handle dual-timer precision, interrupt-driven input, and real-time display updates.

## 🚀 Overview
Most DIY chess clocks suffer from "drift" or "input lag." This project focuses on high-accuracy timing and debounced hardware interrupts to ensure that every millisecond is accounted for during competitive play.

## 🔑 Key Features 
<strong>Dual-State Logic</strong>: Seamlessly toggles between two independent countdown timers.

<strong>Interrupt-Driven Input</strong>: Uses hardware interrupts for player buttons to ensure zero missed presses, even during blitz plays.

<strong>Safety Reset</strong>: A dedicated global reset button to re-initialize game states.
<strong>Logic Pattern</strong>: : Finite State Machine (FSM)

## 🛠️ Technical Stack & Architecture
<strong>Microcontroller</strong>: Arduino UNO R3 <br />
<strong>Additional components</strong>: 16x2 LCD (I2C) Screen, tactile switches, breadboard (and don't forget the wires!).

## ⚔️Challenges Faced
At first the buttons didn't work when pressed. I then wrote some code to test the input received by the board from the buttons. I thought that maybe there was a problem with the buttons, but then it quickly became clear that the wiring was incorrect, which caused no change in voltage when the buttons are pressed. After a couple minutes of re-wiring, the buttons seemed to work perfectly.


## 📥 Installation & Usage
Clone the repo: git clone https://github.com/shaikhomarabdulmajid-spec/arduino-chess-clock.git

Open in Arduino IDE and install the LiquidCrystal_I2C library via the Library Manager. Now you can start playing around with the clock.
