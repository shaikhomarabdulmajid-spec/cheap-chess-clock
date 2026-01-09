♟️ Precision Arduino Chess Clock
A robust, low-latency digital chess clock built on the Arduino framework. This project implements a state-machine architecture to handle dual-timer precision, interrupt-driven input, and real-time display updates.

🚀 Overview
Most DIY chess clocks suffer from "drift" or "input lag." This project focuses on high-accuracy timing and debounced hardware interrupts to ensure that every millisecond is accounted for during competitive play.

Key Features
Dual-State Logic: Seamlessly toggles between two independent countdown timers.

Interrupt-Driven Input: Uses hardware interrupts for player buttons to ensure zero missed presses, even during rapid "blitz" play.

Safety Reset: A dedicated global reset button to re-initialize game states.

🛠️ Technical Stack & Architecture
Microcontroller: Arduino (Uno/Nano)

Language: Arduino

Logic Pattern: Finite State Machine (FSM)

Hardware Components: 16x2 LCD (I2C), Momentary Tactile Switches, Arduino UNO Board, breadboard.
