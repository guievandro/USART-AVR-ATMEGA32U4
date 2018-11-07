/*
 * GccApplication1.c
 *
 * Created: 01/11/2018 19:27:20
 * Author : Gui Evandro
 */ 

#define F_CPU 8000000UL   // define xtal da CPU para rotinas de delay.

#include <avr/io.h>   // inclui arquivos de definições da biblioteca
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define ld1_on() PORTB |= (1<<7)  //Liga LD1 setando o bit 7 da porta B
#define ld1_off() PORTB &= ~(1<<7)
#define ld2_on() PORTB |= (1<<3) //Liga LD2 setando o bit 3 da porta B
#define ld2_off() PORTB &= ~(1<<3)
#define ch1_push() !(PIND & (1<<0)) //Considera CH1 pressionada se 
#define ch3_push() !(PIND & (1<<1))
#define ch1_off() (PIND & (1<<0))
#define ch3_off() (PIND & (1<<1))

int main(void)
{
  //USART_init();
  UBRR1 = 51; // Usart Baud Rate Register - define baud rate (9600) e habilita a USART
  UCSR1B = (1<<TXEN1) | (1<<RXEN1); // Usart Control and Status Register - setando USART para transmitir (1 em TXEN1) e receber (1 em RXEN1)
  
  
  
  
  
  
  //IO_init();
  DDRB = (1<<7)|(1<<6)|(1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1);
  DDRC = (1<<6)|(1<<7);
  DDRD = (1<<4)|(1<<6)|(1<<7);
  DDRE = 0;
  DDRF = 0;
  PORTB = 0;
  PORTC = 0;
  PORTD = (1<<5)|(1<<1)|(1<<0);
  PORTE = (1<<2);
  PORTF = (1<<7)|(1<<6);
  MCUCR |= (1<<JTD);
  MCUCR |= (1<<JTD); //desliga interface JTAG.
  
  
  //Timer0_init();
  
  TCNT0 = 217;
  TCCR0A =0;
  TCCR0B =  (1<<CS02);
  TIMSK0 = (1<<TOIE0);
  
  
 
  
  while (1)
  {
	  
	  while (ch1_push()){
		   ld1_on();
		   ld2_off();
	  }
	  
	  while (ch3_push()){
			ld2_on();
			ld1_off();
	  }
		ld1_off();
		ld2_off();
	  }
}

