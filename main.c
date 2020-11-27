#include <msp430.h> 

#define config_address 0X04 //Address used to configuration of max6952 prior to operation
#define config_value 0X01   //Setting the features of the configuration to bring max6952 to no shutdown state

#define scanlimit_address 0X03 //Address of scan limit
#define scanlimit_value 0X01   //Specifies that 4 digits are to be driven

#define intensity_address10 0X01 //Register address specification for digit 0 and digit 1
#define intensity_address32 0x02 //Register address specification for digit 2 and digit 3
#define intensity_value 0XFF     //Maximum brightness is set for digit 0,1,2 and 3

//Addresses of the 4 displays to be used
#define digit0_address 0X20 //Address referring to the display 0
#define digit1_address 0X21 //Address referring to the display 1
#define digit2_address 0X22 //Address referring to the display 2
#define digit3_address 0X23 //Address referring to the display 3

//Values of the specific letters to be displayed
#define letterS 0b01010011 //Letter S will be displayed
#define letterL 0b01001100 //Letter L will be displayed
#define letterI 0b01001001 //Letter I will be displayed

//Clock is set to P1.0
//CS is set to P1.1
//Din is set to P1.2


void transfer (char address, char data){
        P1OUT &= ~0b00000001; //Clock is set low
        P1OUT &= ~0b00000010; //Slave select line is set low

//For the MSB (16th bit)
        if(address & 0b10000000){
            P1OUT |= 0b00000100;  //Din is set high if first bit in address is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if first bit in address is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//the 15th bit is set
        if(address & 0b01000000){
            P1OUT |= 0b00000100;  //Din is set high if second bit in address is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if second bit in address is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//The 14th bit is set
        if(address & 0b00100000){
            P1OUT |= 0b00000100;  //Din is set high if third bit in address is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if third bit in address is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

// The 13th bit is set
        if(address & 0b00010000){
            P1OUT |= 0b00000100;  //Din is set high if fourth bit in address is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if fourth bit in address is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//The 12th bit is set
        if(address & 0b00001000){
            P1OUT |= 0b00000100;  //Din is set high if fifth bit in address is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if fifth bit in address is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//The 11th bit is set
        if(address & 0b00000100){
            P1OUT |= 0b00000100;  //Din is set high if sixth bit in address is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if sixth bit in address is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//The 10th bit is set
        if(address & 0b00000010){
            P1OUT |= 0b00000100;  //Din is set high if seventh bit in address is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if seventh bit in address is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//The 9th bit is set (LSB of the address)
        if(address & 0b00000001){
            P1OUT |= 0b00000100;  //Din is set high if eighth bit in address is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if eighth bit in address is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//The 8th bit is set (MSB of data)
        if(data & 0b10000000){
            P1OUT |= 0b00000100;  //Din is set high if first bit in letter is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if first bit in letter is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//The 7th bit is set
        if(address & 0b01000000){
            P1OUT |= 0b00000100;  //Din is set high if second bit in letter is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if second bit in letter is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//The 6th bit is set
        if(address & 0b00100000){
            P1OUT |= 0b00000100;  //Din is set high if third bit in letter is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if third bit in letter is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//THe 5th bit is set
        if(address & 0b00010000){
            P1OUT |= 0b00000100; //Din is set high if fourth bit in letter is high
            P1OUT |= 0b00000001; //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if fourth bit in letter is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//The 4th bit is set
        if(address & 0b00001000){
            P1OUT |= 0b00000100;  //Din is set high if fifth bit in letter is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if fifth bit in letter is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//The 3rd bit is set
        if(address & 0b00000100){
            P1OUT |= 0b00000100;  //Din is set high if 6th bit in letter is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if 6th bit in letter is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

 //The 2nd bit is considered
        if(address & 0b00000010){
            P1OUT |= 0b00000100;  //Din is set high if 7th bit in letter is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if 7th bit in letter is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

//The 1st bit is considered
        if(address & 0b00000001){
            P1OUT |= 0b00000100;  //Din is set high if 8th bit in letter is high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }else{
            P1OUT &= ~0b00000100; //Din is set low if 8th bit in letter is not high
            P1OUT |= 0b00000001;  //Set clock high
            P1OUT &= ~0b00000001; //Set clock low
        }

        P1OUT |= 0b00000010 ; //Slave select line is set high
        P1OUT &= ~0b00000001; //Clock is set low
}

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR |= 0X07; //Setting the directions of the pins of port 1 of MSP430FS2272

    P1OUT |= 0X02;// Initializing the pins of the msp430FS2272

    transfer(config_address,config_value);

    transfer(scanlimit_address,scanlimit_value);

    transfer(intensity_address10,intensity_value);
    transfer(intensity_address32,intensity_value);

    while(1){

        transfer(digit0_address,letterS);
        transfer(digit1_address,letterL);
        transfer(digit2_address,letterI);
        transfer(digit3_address,letterI);

    }
    //return 0;
}
