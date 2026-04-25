<img width="1016" height="721" alt="image" src="https://github.com/user-attachments/assets/aebd79f3-b985-4c24-8dd8-bb647675f4cc" />




<br/>

<h3>♟️ Precision Arduino Chess Clock </h3>
A robust, low-latency digital chess clock built on the Arduino framework. This project implements a state-machine architecture to handle dual-timer precision, interrupt-driven input, and real-time display updates.

<h3>🚀 Overview</h3>
Most DIY chess clocks suffer from "drift" or "input lag." This project focuses on high-accuracy timing and debounced hardware interrupts to ensure that every millisecond is accounted for during competitive play.

Key Features: 
Dual-State Logic: Seamlessly toggles between two independent countdown timers.

Interrupt-Driven Input: Uses hardware interrupts for player buttons to ensure zero missed presses, even during rapid "blitz" play.

Safety Reset: A dedicated global reset button to re-initialize game states.

🛠️ Technical Stack & Architecture
Microcontroller: Arduino UNO R3

Language: Arduino

Logic Pattern: Finite State Machine (FSM)

Hardware Components: 16x2 LCD (I2C), Momentary Tactile Switches, Arduino UNO Board, breadboard, and wires (that's all!).

📥 Installation & Usage
Clone the repo: git clone https://github.com/shaikhomarabdulmajid-spec/arduino-chess-clock.git

Open in Arduino IDE.

Install Library: LiquidCrystal_I2C via the Library Manager.

Upload to your board and start playing!
