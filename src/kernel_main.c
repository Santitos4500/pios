//#include <stdio.h> commented out for serial homework
#include "list.h"
#include "blinky.h"
#include "page.h"
#include "serial.h"
#include "rprintf.h"
#include "gpio.h"
#include "fat.h"
#include "sd.h"

extern int __bss_start;
extern int __bss_end;
extern struct ppage* free_list;

int global;
/*
struct list_element b = {NULL,NULL, 1};
struct list_element a = {NULL,NULL, 5};
struct list_element c = {NULL,NULL, 2};
struct list_element *head = &a;
struct list_element* list = &a;
*/
void kernel_main(){
	/*bss_to_zero();
	list_add(list, &b);
	list_add(list, &c);
	list_remove(head, 1);
	led_init();
	int *mu_io_reg = 0x3F215040;
	*mu_io_reg = 'L';
	*mu_io_reg = 'U';
	*mu_io_reg = 'I';
	*mu_io_reg = 'S';
	esp_printf(putc, "The memory location is %x", kernel_main);
	
	init_pfa_list();
	struct ppage* test = free_list->next;
	test = test->next;
	esp_printf(putc, "Physical Address: %x\n", test->physical_addr);
	test = allocate_physical_pages(2);
	esp_printf(putc, "Allocated Address:  %x \n", test->physical_addr);
	test = allocate_physical_pages(2);
	esp_printf(putc, "Allocated Address:  %x \n", test->physical_addr);
	free_physical_pages(test);
	esp_printf((void *)putc, "Address after Freeing: %x\n", test->physical_addr);
	*/
	struct file fat_test;
	sd_init();
	fatInit();
	fatOpen(&fat_test, "TEST");
	fatRead(&fat_test,"TEST", 32);
	while (1){
		/*led_on(); commented out for serial homework
		delay();
		led_off();
		delay();
		*/
	}
}

void bss_to_zero(){
	(&__bss_start)[0] = 0x0c;
	int x=0;
	while ((&__bss_start)+x != &__bss_end){
		(&__bss_start)[x] = 0;
		x++;
	}
}

