#define COMMAND "sudo iwlist wlan0 scan | egrep \"Channel|Frequency|Quality|ESSID\" > scan.txt"

// function prototypes
void process(char filename[]);

void display(char filename[]);
