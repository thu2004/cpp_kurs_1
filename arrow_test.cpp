#include <iostream>
#include <termios.h>
#include <unistd.h>

class Terminal {
public:
    Terminal() {
        // Save the current terminal settings
        tcgetattr(STDIN_FILENO, &old_term);
        struct termios new_term = old_term;

        // Set the terminal to raw mode
        new_term.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
    }

    ~Terminal() {
        // Restore the original terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
    }

    char getch() {
        char ch;
        read(STDIN_FILENO, &ch, 1);
        return ch;
    }

private:
    struct termios old_term;
};

void handleArrowKeys() {
    Terminal terminal;

    while (true) {
        char ch = terminal.getch(); // Get a character from the console

        if (ch == '\033') { // Escape sequence
            char next = terminal.getch(); // Get the next character
            if (next == '[') {
                char arrow = terminal.getch(); // Get the actual arrow key code
                switch (arrow) {
                    case 'A': // Up arrow
                        std::cout << "Up arrow pressed" << std::endl;
                        break;
                    case 'B': // Down arrow
                        std::cout << "Down arrow pressed" << std::endl;
                        break;
                    case 'C': // Right arrow
                        std::cout << "Right arrow pressed" << std::endl;
                        break;
                    case 'D': // Left arrow
                        std::cout << "Left arrow pressed" << std::endl;
                        break;
                    default:
                        break;
                }
            }
        } else {
            // Handle other keys (e.g., exit on 'q')
            if (ch == 'q') {
                break; // Exit the loop
            } else {
                std::cout << "Key pressed: " << ch << std::endl;
            }
        }
    }
}

int main() {
    std::cout << "Press arrow keys (up, down, left, right) or 'q' to quit." << std::endl;
    handleArrowKeys();
    return 0;
}