#define ESC 0x1B

enum FGCOLORS {BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
// function prototypes
void setColor(int);

void clearScreen(void);

void gotoxy(int, int);

void bar(double, int);
