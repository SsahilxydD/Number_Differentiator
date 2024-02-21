#include <iostream>
#include <windows.h>

using namespace std;

int x;

void print(const char* message)
{
    cout << message << endl;
}

bool isEnterPressed() {
    return GetAsyncKeyState(VK_RETURN) & 0x8000;
}

bool isEscPressed() {
    return GetAsyncKeyState(VK_ESCAPE) & 0x8000;
}

void Check()
{
    while (!isEnterPressed()) 
    {        
        if (isEscPressed()) {
            break;           
        }        
    }
}
int main()
{
    while (true)
    {
        print("Enter a number: ");
        if (!(cin >> x)) {
            cin.clear(); 
            while (cin.get() != '\n'); 
            system("cls");
            print("Error: Please enter a numerical value.");            
            Sleep(2500);
            system("cls");
            continue; 
        }

        if (x > 0)
        {
            print("Number is Positive");
            Sleep(1000);
            system("cls");
            print("Press ENTER to continue and ESC to exit the program.");
            Check();
            system("cls");
        }

        else if (x < 0)
        {
            print("Number is Negative");
            Sleep(1000);
            system("cls");
            print("Press ENTER to continue and ESC to exit the program.");
            Check();
            system("cls");
        }

        else
        {
            print("Number is Zero");
            Sleep(1000);
            system("cls");
            print("Press ENTER to continue and ESC to exit the program.");
            Check();
            system("cls");
        }

        // Wait for Enter key press
        while (!isEnterPressed()) {
            if (isEscPressed()) {
                return 0; 
            }
        }
    }
    return 0;
}
