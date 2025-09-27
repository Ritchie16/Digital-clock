# Digital Clock System

A feature-rich digital clock application written in C with alarm functionality, manual and automatic time setting, and real-time display.

![C](https://img.shields.io/badge/Language-C-blue)
![Windows](https://img.shields.io/badge/Platform-Windows-lightgrey)
![Console](https://img.shields.io/badge/Interface-Console-green)

## 📋 Features

### ⏰ **Core Clock Functions**
- **Real-time Display**: Shows current system time with AM/PM indicator
- **Manual Time Setting**: Custom time configuration option
- **Automatic Time Sync**: Uses system time as reference

### 🔔 **Alarm System**
- **Custom Alarm Setting**: Set specific hour, minute, and second for alarms
- **Visual & Audio Alert**: Flashing messages with beep sounds
- **Easy Dismissal**: Press any key to stop alarm

### 🎯 **User Interface**
- **Menu-driven Navigation**: Intuitive number-based menu system
- **Input Validation**: Robust error handling for invalid inputs
- **Real-time Updates**: Continuous time display with second-by-second updates

## 🚀 Getting Started

### Prerequisites
- Windows OS (uses Windows-specific headers)
- GCC compiler or any C compiler
- Console application support

### Compilation and Execution

```bash
# Compile the program
gcc -o digital_clock digital_clock.c

# Run the executable
digital_clock.exe

Alternative Compilation
bash

# With specific flags for Windows features
gcc -o clock digital_clock.c -lwinmm

📖 Usage
Main Menu Options

When you run the program, you'll see:
text

*******DIGITAL CLOCK SYSTEM*******
___________________________________________________________________________________________

 Clock Options

 1. Reset Time
 2. Set Alarm
 3. Exit Clock

Current Time: 14:30:25 PM



Setting the Time Manually

    Press 1 for "Reset Time"

    Choose 1 for manual update

    Enter hours (0-23), minutes (0-59), seconds (0-59)

    Clock will display with your custom time

Setting an Alarm

    Press 2 for "Set Alarm"

    Confirm with 1 to set alarm

    Enter alarm time (hours, minutes, seconds)

    Alarm will ring at the specified time with visual and audio alerts

Exiting the Program

    Press 3 and confirm with Y to exit

🏗️ Project Structure
Main Functions

    main() - Program entry point

    display_time() - Main clock display loop

    manual_update() - Manual time setting interface

    alam() - Alarm setting functionality

Input Handling

    get_hours_manual(), get_minutes_manual(), get_seconds_manual() - Manual time input

    get_hours(), get_minutes(), get_seconds() - Alarm time input

Utility Functions

    display_clock_options() - Main menu display

    setting_alam_comfirm() - Alarm confirmation dialog

    display_manual_time() - Custom time display

🔧 Technical Details
Key Libraries Used

    stdio.h - Standard input/output operations

    stdlib.h - Standard library functions

    time.h - Time manipulation and formatting

    conio.h - Console input/output (Windows-specific)

    windows.h - Windows API for system functions

Platform Specific Features

    Beep() function for audio alerts

    Sleep() for timing delays

    system("cls") for screen clearing

    _kbhit() and _getch() for keyboard input

🎮 Control Scheme
Keyboard Shortcuts

    1 - Access time reset options

    2 - Set alarm functionality

    3 - Exit the application

    Y/N - Confirm exit choices

    Any key - Dismiss ringing alarm

Navigation

    Number-based menu selection

    Automatic return to main clock after operations

    Input validation with error messages

🐛 Known Issues & Limitations

    Windows Dependency: Uses Windows-specific headers and functions

    Console-based: Limited to command-line interface

    24-hour Format: Time displayed in 24-hour format with AM/PM indicator

    Input Validation: Basic character input validation implemented

👥 Development
Code Style

    Structured procedural programming

    Extensive comments for clarity

    Modular function design

    Error handling throughout

Contributing

This was a first-year academic project, 2024. Feel free to fork and enhance!
📄 License

Academic project - free to use for educational purposes.
🙏 Acknowledgments

    First Year Project - Bachelor of Science in ICT

    C programming fundamentals

    Windows console programming concepts
