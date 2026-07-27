# Arduino Smoothed Servo Potentiometer Controller

A standalone Arduino hardware project that reads continuous analog voltage sweeps from a rotary potentiometer and translates them into responsive, jitter-free angular movements on a standard hobby servo motor.

## 🛠️ Hardware Requirements

* **Microcontroller:** Arduino Uno, Nano, Leonardo, or any compatible development board.
* **Actuator:** 1x 5V Hobby Servo Motor (e.g., SG90, MG90S, or MG996R).
* **Analog Input:** 1x 10kΩ Rotary Potentiometer.
* **Power Supply:** 5V external power source recommended (servos can draw high current spikes that may reset your Arduino if powered solely via USB).

### 📌 Physical Wiring Diagram

#### 1. Rotary Potentiometer Connections

| Potentiometer Terminal | Arduino Pin | Description |
| :--- | :--- | :--- |
| **Left Pin (Pin 1)** | `GND` | Ground Reference |
| **Wiper Pin (Pin 2)** | `A0` | Analog Read Voltage Input (`potPin`) |
| **Right Pin (Pin 3)** | `5V` | 5V Power Supply |

#### 2. Servo Motor Connections

| Servo Wire Color | Connection Destination | Purpose |
| :--- | :--- | :--- |
| 🟤 **Brown / Black** | `GND` (Shared Common Ground) | Ground Return |
| 🔴 **Red** | `5V` (External Power Source) | Operating Voltage |
| 🟡 **Yellow / Orange** | Arduino Pin `D9` | PWM Signal Control Pin |

---

## ⚙️ Signal Processing & Smoothing Logic

This firmware features built-in signal conditioning to remove twitching or jitter caused by noisy potentiometer contacts:

1. **Resolution Mapping:** The controller samples the physical potentiometer using its internal 10-bit analog-to-digital converter (ADC), reading values from `0` to `1023`. It maps this raw spectrum linearly down to servo-friendly angular degrees (`0` to `180`).
2. **Low-Pass Digital Filter:** Instead of sending raw, jumping coordinates directly to the actuator, the script applies an Exponential Moving Average (EMA) algorithm:
   $$\text{smoothAngle} = (\text{smoothAngle} \times 0.8) + (\text{angle} \times 0.2)$$
   This mathematical weighting dampens high-frequency signal noise, ensuring fluid and stable mechanical sweeps.

---

## 📦 Software Setup & Deployment

### 1. Library Dependencies
This project uses the official **`Servo.h`** library, which comes pre-installed in the standard Arduino IDE ecosystem. No external library manager downloads are required.

### 2. Flashing the Firmware
* Launch your Arduino IDE and open this sketch file.
* Connect your microcontroller to your computer using a compatible USB cable.
* Select your specific board type and COM Port via the **Tools** menu.
* Press **Upload** (`Ctrl + U`) to compile and flash the code.

---

## 🚀 Live Operation

1. Complete the circuit assembly as detailed in the wiring guide, ensuring the servo shares a common ground with the Arduino.
2. Power up the board.
3. Slowly turn the rotary potentiometer knob left and right.
4. Observe the horn of the servo motor sweep gracefully across its 180-degree rotation axis without mechanical stuttering or electrical oscillations.

## 📄 License
This mechanical tracking automation logic is open-source and shared under the standard [MIT License](LICENSE).
