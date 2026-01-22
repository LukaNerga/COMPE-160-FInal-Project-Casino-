# Casino Final Project 🎰

A simple terminal-based casino game written in C.  
Play **Slots**, **Roulette**, or **Aviator** with a virtual budget and see how far your luck takes you.

---

## 🎮 Features

- Starting budget of **$1000**
- Three different games in one program:
  - Slot Machine
  - Roulette
  - Aviator (crash-style multiplier game)
- Random **motivational quotes** each round
- Random **bankruptcy messages** when you lose it all
- Simple text-based UI in the terminal

---

## 🧱 Games Overview

### 1. Slots
- Choose your bet: **50, 100, 500, or All in (0)**
- Spin 3 reels with symbols: `Cherry`, `Lemon`, `Orange`, `Bell`, `Seven`
- Payouts:
  - 3 matching symbols → **10x** your bet (jackpot)
  - 2 matching symbols → **2x** your bet
  - No match → you lose your bet

---

### 2. Roulette
- Choose your bet: **50, 100, 500, or All in (0)**
- Pick:
  - A **number** between 0–36
  - Optional **color** bet:  
    - `1` = Red (odd numbers)  
    - `2` = Black (even numbers)
  - Optional **odd/even** bet:  
    - `1` = Odd  
    - `2` = Even
- Payouts:
  - Correct number → **36x** your bet
  - Correct color → **2x** your bet
  - Correct odd/even → **2x** your bet

> Note: 0 behaves like a special number (no color, not odd/even in standard roulette, but here it follows the basic modulo logic in the code).

---

### 3. Aviator ✈️
- Choose your bet: **50, 100, 500, or All in (0)**
- A multiplier starts at **x1.0** and keeps increasing over time
- Each “tick”:
  - Multiplier goes up
  - You choose to **cash out (`y`)** or **keep flying (`n`)**
- The plane can **crash at any moment** based on rising probability:
  - If you cashed out → you win `bet * multiplier`
  - If it crashes before cashout → you lose your bet

---

## ⚙️ Requirements

- C compiler (e.g. `gcc`, `clang`)
- A POSIX-like environment for `unistd.h` and `sleep()`  
  - Works on **Linux** and **macOS**
  - On Windows, use WSL or replace `sleep()` with `Sleep()` and adjust includes.

---

## 🛠️ Build & Run

### Linux / macOS

```bash
gcc casino.c -o casino
./casino
