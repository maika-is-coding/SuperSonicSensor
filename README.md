# 超音波距離感測器 LED 控制專案

這是一個基於 Arduino 的超音波距離感測器與 LED 控制專案，當距離小於設定的閾值時，LED 會亮起，否則關閉。此專案使用了超音波感測器來測量物體與感測器的距離，並根據距離來控制 LED 的開關。

## 硬體需求

- Arduino 板（例如 Arduino UNO）
- 超音波距離感測器（HC-SR04）
- LED
- 220Ω 電阻
- 跳線

## 接腳連接

- **超音波感測器 (HC-SR04)**：
  - `Trig` 接腳 -> Arduino Pin 9
  - `Echo` 接腳 -> Arduino Pin 10
  - `VCC` 接腳 -> Arduino 5V
  - `GND` 接腳 -> Arduino GND

- **LED**：
  - 正極（長腳） -> Arduino Pin 8
  - 負極（短腳） -> 220Ω 電阻，再接至 Arduino GND

## 程式碼說明

### 1. 設定腳位
- `trigPin`：超音波感測器的 Trig 輸出腳，設為 Pin 9
- `echoPin`：超音波感測器的 Echo 輸入腳，設為 Pin 10
- `ledPin`：LED 控制腳，設為 Pin 8

### 2. 測距過程
- 通過 Trig 腳發送 10 微秒的高電位脈衝來啟動超音波發射。
- 超音波會反射回來，經由 Echo 腳接收回波，使用 `pulseIn()` 函數來測量回波時間。
- 根據回波時間計算距離，公式為：  
  `distance = duration * 0.034 / 2`
  - `duration` 是回波時間（微秒）。
  - `0.034` 是聲音在空氣中的速度（cm/μs）。
  - 除以 2 是因為回波是來回的時間。

### 3. 控制 LED
- 當計算出來的距離小於設定的閾值（`threshold = 15.0` 公分）時，LED 亮起。
- 否則，LED 熄火。

### 4. 重複測量
- 每 500 毫秒測量一次距離並更新 LED 狀態。

## 安裝與運行

1. 確保你的 Arduino IDE 已安裝並且可以正常連接你的 Arduino 板。
2. 將程式碼複製到 Arduino IDE 中。
3. 選擇對應的 Arduino 板型與連接埠。
4. 點擊上傳並開始執行。

當物體靠近超音波感測器時，LED 會亮起；當物體遠離感測器時，LED 會熄火。

## 調整閾值

若要改變 LED 開關的觸發距離，可以調整程式中的 `threshold` 變數。這個變數設置了 LED 亮起的距離閾值，單位為公分。

```cpp
const float threshold = 15.0; // 小於15公分就亮紅燈
