// setenv app "setenv autoload no; setenv ipaddr 10.4.1.2; setenv serverip 10.4.1.1; tftp 0x80000000 appTimer.bin; echo *Booting to BareMetal *; go 0x80000000"

#include "uart.h"
#include "timer.h"
#include "interrupt.h"

// gpio2 P8 - LEDs
#define LED1 2	// 7
#define LED2 3	// 8
#define LED3 4	// 10
#define LED4 5	// 9
#define LED5 22 // 27
#define LED6 24 // 28
#define LED7 25 // 30
#define LED8 23 // 29
#define LED9 17 // 34

// gpio1 P9 - BOTOES
#define RST 28 // 12
#define BTN 18 // 14

void apagarLEDs();
void watchdogdisable();
void putCh(char c);
char getCh();
int putString(char *str, unsigned int length);
int getString(char *buf, unsigned int length);

int main(void)
{
	watchdogdisable();

	timerSetup();

	// Inicia o modulo
	gpioInitModule(GPIO1);
	gpioInitModule(GPIO2);

	// Seta o pino como gpio
	gpioPinMuxSetup(GPIO2, LED1);
	gpioPinMuxSetup(GPIO2, LED2);
	gpioPinMuxSetup(GPIO2, LED3);
	gpioPinMuxSetup(GPIO2, LED4);
	gpioPinMuxSetup(GPIO2, LED5);
	gpioPinMuxSetup(GPIO2, LED6);
	gpioPinMuxSetup(GPIO2, LED7);
	gpioPinMuxSetup(GPIO2, LED8);
	gpioPinMuxSetup(GPIO2, LED9);
	gpioPinMuxSetup(GPIO1, LED1);
	gpioPinMuxSetup(GPIO1, LED1);

	// Seta como entrada e saida
	gpioSetDirection(GPIO2, LED1, OUTPUT);
	gpioSetDirection(GPIO2, LED2, OUTPUT);
	gpioSetDirection(GPIO2, LED3, OUTPUT);
	gpioSetDirection(GPIO2, LED4, OUTPUT);
	gpioSetDirection(GPIO2, LED5, OUTPUT);
	gpioSetDirection(GPIO2, LED6, OUTPUT);
	gpioSetDirection(GPIO2, LED7, OUTPUT);
	gpioSetDirection(GPIO2, LED8, OUTPUT);
	gpioSetDirection(GPIO2, LED9, OUTPUT);
	gpioSetDirection(GPIO1, BTN, INPUT);
	gpioSetDirection(GPIO1, RST, INPUT);

	// Desliga os pinos
	apagarLEDs();

	// Seta a interrupcao
	gpioInterruptInit(GPIO1, RST, A);
	gpioInterruptInit(GPIO1, BTN, A);

	int posicaoAtual;
	bool direcaoDireita;
	int pontuacao;
	int tempo;

	while (1)
	{
		flagSetFalse(GPIO1, RST);
		flagSetFalse(GPIO1, BTN);

		posicaoAtual = 0;
		direcaoDireita = true;
		pontuacao = 0;
		tempo = 185;
		for (int i = 0; i < 10; i++)
		{
			tempo -= 10;
			while (1)
			{
				// Delay para controlar a velocidade do movimento
				delay(tempo);
				apagarLEDs();
				switch (posicaoAtual)
				{
				case 0:
					gpioSetPinValue(GPIO2, LED1, HIGH);
					if (flagGet(GPIO1, BTN))
					{
						pontuacao += 1;
						putString("PONTUACAO NA RODADA: ", 21);
						putCh(1 + 48);
						putString("\r\n", 2);
					}
					break;
				case 1:
					gpioSetPinValue(GPIO2, LED2, HIGH);
					if (flagGet(GPIO1, BTN))
					{
						pontuacao += 1;
						putString("PONTUACAO NA RODADA: ", 21);
						putCh(1 + 48);
						putString("\r\n", 2);
					}
					break;
				case 2:
					gpioSetPinValue(GPIO2, LED3, HIGH);
					if (flagGet(GPIO1, BTN))
					{
						pontuacao += 3;
						putString("PONTUACAO NA RODADA: ", 21);
						putCh(3 + 48);
						putString("\r\n", 2);
					}
					break;
				case 3:
					gpioSetPinValue(GPIO2, LED4, HIGH);
					if (flagGet(GPIO1, BTN))
					{
						pontuacao += 3;
						putString("PONTUACAO NA RODADA: ", 21);
						putCh(3 + 48);
						putString("\r\n", 2);
					}
					break;
				case 4:
					gpioSetPinValue(GPIO2, LED5, HIGH);
					if (flagGet(GPIO1, BTN))
					{
						pontuacao += 10;
						putString("PONTUACAO NA RODADA: ", 21);
						putCh(1 + 48);
						putCh(0 + 48);
						putString("\r\n", 2);
					}
					break;
				case 5:
					gpioSetPinValue(GPIO2, LED6, HIGH);
					if (flagGet(GPIO1, BTN))
					{
						pontuacao += 3;
						putString("PONTUACAO NA RODADA: ", 21);
						putCh(3 + 48);
						putString("\r\n", 2);
					}
					break;
				case 6:
					gpioSetPinValue(GPIO2, LED7, HIGH);
					if (flagGet(GPIO1, BTN))
					{
						pontuacao += 3;
						putString("PONTUACAO NA RODADA: ", 21);
						putCh(3 + 48);
						putString("\r\n", 2);
					}
					break;
				case 7:
					gpioSetPinValue(GPIO2, LED8, HIGH);
					if (flagGet(GPIO1, BTN))
					{
						pontuacao += 1;
						putString("PONTUACAO NA RODADA: ", 21);
						putCh(1 + 48);
						putString("\r\n", 2);
					}
					break;
				case 8:
					gpioSetPinValue(GPIO2, LED9, HIGH);
					if (flagGet(GPIO1, BTN))
					{
						pontuacao += 1;
						putString("PONTUACAO NA RODADA: ", 21);
						putCh(1 + 48);
						putString("\r\n", 2);
					}
					break;
				default:
					break;
				}

				if (flagGet(GPIO1, BTN) && pontuacao < 100)
				{
					flagSetFalse(GPIO1, BTN);
					break;
				}

				

				// Verifica a direção do movimento e atualiza a posição
				if (direcaoDireita)
				{
					posicaoAtual++;
					if (posicaoAtual > 8)
					{
						direcaoDireita = false;
						posicaoAtual--;
					}
				}
				else
				{
					posicaoAtual--;
					if (posicaoAtual < 0)
					{
						direcaoDireita = true;
						posicaoAtual++;
					}
				}

				if (flagGet(GPIO1, RST))
				{
					break;
				}
			}
			if (flagGet(GPIO1, RST))
			{
				break;
			}
		}
		

		if (flagGet(GPIO1, RST))
		{
			putString("RESETADO\r\n", 10);
			flagSetFalse(GPIO1, RST);
		}
		else
		{
			putString("JOGO FINALIZADO, PONTUACAO FINAL: ", 34);
			if (pontuacao < 100)
			{
				putCh((pontuacao / 10) + 48);
				putCh((pontuacao % 10) + 48);
				putString("\r\n", 2);
			}
			else
			{
				putString("MÁXIMA (100)", 13);
			}
		}
		putString("==================================\r\n", 36);
	}
	return (0);
} /* ----------  end of function main  ---------- */

void apagarLEDs()
{
	gpioSetPinValue(GPIO2, LED1, LOW);
	gpioSetPinValue(GPIO2, LED2, LOW);
	gpioSetPinValue(GPIO2, LED3, LOW);
	gpioSetPinValue(GPIO2, LED4, LOW);
	gpioSetPinValue(GPIO2, LED5, LOW);
	gpioSetPinValue(GPIO2, LED6, LOW);
	gpioSetPinValue(GPIO2, LED7, LOW);
	gpioSetPinValue(GPIO2, LED8, LOW);
	gpioSetPinValue(GPIO2, LED9, LOW);
}

void watchdogdisable()
{											   // To disable the timer, follow this sequence:
	HWREG(SOC_WDT_1_REGS + WDT_WSPR) = 0xAAAA; // 1. Write XXXX AAAAh in WDT_WSPR.
	while ((HWREG(SOC_WDT_1_REGS + WDT_WWPS) & W_PEND_WSPR) != 0x0)
	{
	}										   // 2. Poll for posted write to complete using WDT_WWPS.W_PEND_WSPR.
	HWREG(SOC_WDT_1_REGS + WDT_WSPR) = 0x5555; // 3. Write XXXX 5555h in WDT_WSPR.
	while ((HWREG(SOC_WDT_1_REGS + WDT_WWPS) & W_PEND_WSPR) != 0x0)
	{
	} // 4. Poll for posted write to complete using WDT_WWPS.W_PEND_WSPR.
}

void putCh(char c)
{
	while (!(HWREG(SOC_UART_0_REGS + UARTx_OP_R_LSR) & (1 << 5)))
		;

	HWREG(SOC_UART_0_REGS + UARTx_OP_W_THR) = c;
}
char getCh()
{
	while (!(HWREG(HWREG(SOC_UART_0_REGS + UARTx_OP_R_LSR) & (1 << 0))))
		;

	return (HWREG(SOC_UART_0_REGS + UARTx_OP_W_THR));
}
int putString(char *str, unsigned int length)
{
	for (int i = 0; i < length; i++)
	{
		putCh(str[i]);
	}
	return (length);
}
int getString(char *buf, unsigned int length)
{
	for (int i = 0; i < length; i++)
	{
		buf[i] = getCh();
	}
	return (length);
}