#include<stdio.h>
#include<stdint.h>  // For uint8_t and uint32_t

//LEDSettings structure definition
//This structure holds the settings for an individual LED,
// including its state (ON/OFF), brightness level, and RGB color.

typedef struct LEDSettings
{
	uint8_t state;       // 1 for ON, 0 for OFF
	uint8_t brightness;  // Brightness level (0 to 255)
        uint32_t color;    // Color in RGB format (e.g., 0xRRGGBB)
}LEDS;


//LEDGroup structure definition
// This structure holds the collective settings for a group of LEDs,
// including an instance of the individual LED settings and group-level
// state and brightness.
typedef struct LEDGroup
{
	LEDS singleLED;        // Individual LED settings (state, brightness, color)
	uint8_t groupState;   // 1 for all LEDs ON, 0 for all LEDs OFF
	uint8_t groupBrightness;  // Collective brightness for the group (0 to 255)
}LEDG;


//Function to initialize LEDGroup with default values
// This function sets the default values for both the individual LED and
// group settings. It initializes all values to OFF and minimum brightness.

void initLEDGroup(LEDG *group)
{
	group->singleLED.state = 0; //All LED's OFF
	group->singleLED.brightness = 0;  //Minimum brightness
	group->singleLED.color = 0;  //No color
	

	//Initialize group Settings
	

	group->groupState = 0; //Group OFF (All led's OFF)
	group->groupBrightness = 0;  //Minimum brightness for group
}

//Function to Update LEDGroupSettings
// This function updates the individual LED settings and the collective group
// settings based on the values passed as arguments. It demonstrates the use
// of pointer dereferencing and structure handling.

void updateLEDGroupSettings(LEDG *group,uint8_t groupState,uint8_t groupBrightness,uint8_t state,uint8_t brightness,uint32_t color)
{

	//update individual LED Settings
	group->singleLED.state = state;
	group->singleLED.brightness = brightness;
	group->singleLED.color = color;

	//update group settings
	group->groupState = groupState;
	group->groupBrightness = groupBrightness;
}



//Function to Display LED Group Status	
// This function prints the current state, brightness, and color of the individual LED,
// along with the group state and group brightness.

void displayLEDGroupStatus(const LEDG *group)
{
	 // Display individual LED settings
    printf("Individual LED State: %hhu\n", group->singleLED.state);
    printf("Individual LED Brightness: %hhu\n", group->singleLED.brightness);
    printf("Individual LED Color (RGB): 0X%06X\n", group->singleLED.color);

    // Display group settings
    printf("Group State: %hhu\n", group->groupState);
    printf("Group Brightness: %hhu\n", group->groupBrightness);


}

int main()
{
	//create LEDGroup object to manage individual and group LED Seettings
	LEDG group;

	//Initialize LEDGroup wit default values
	initLEDGroup(&group);
	
	//Dispaly the initialized LED Group status
	
	printf("Initial LED Group Status:\n");
	displayLEDGroupStatus(&group);
	
	//update the LED Group with new values
	//considering runtime input
	

	//variables to hold user input
	
	uint8_t groupState,groupBrightness,state,brightness;
	uint32_t color;

	puts("enter the individual LED State(1 for ON and 0 for OFF):");
	scanf("%hhu",&state); //Input for individual LED state

	puts("enter the individual LED brightness (0 to 255):");
        scanf("%hhu",&brightness); //Input for Individual LED brightness

	puts("enter the individual LED color (RGC in hex,eg:-0XRRGGBB):");
        scanf("%x",&color); //Input for individual LED color (hexadecimal)
	

	puts("enter the Group State (1 for ON and 0 for OFF):");
	scanf("%hhu",&groupState); //Input for group state
	

	puts("enter the Group Brightness (0 to 255):");
	scanf("%hhu",&groupBrightness); //Input for group brightness
	

	//update the LED group with the values entered by the user
	

	updateLEDGroupSettings(&group,groupState,groupBrightness,state,brightness,color);


	//Dispaly the update LED group status
	

	printf("\nUpdated LED Group Status:\n");
	displayLEDGroupStatus(&group);

	return 0;
}




