/*
--------------------------------------------------------------------------------
	libconfigdemo.c	A Simple C Program Demonstrating libconfig Usage
--------------------------------------------------------------------------------
CREDITS
	This demo program has been written by:	Jan-Piet Mens and originally 
	published in an article linked below.

	I am copying the code here, along with author's name and URL just to 
	increase discoverability to assist others to find/clone this demo code.
	
	original URL:
	https://jpmens.net/2009/09/17/reading-configuration-files-with-libconfig

	archive.org (backup URL):
	https://web.archive.org/web/20180203004726/https://jpmens.net/2009/09/17
	/reading-configuration-files-with-libconfig
--------------------------------------------------------------------------------
PREREQUISITES
	It requires the libconfig package of course - no other dependencies.

	MAC OS X homebrew package manager installation:	
		brew install libconfig

	*NIX compilation & installation from sources:
	wget https://hyperrealm.github.io/libconfig/dist/libconfig-1.7.2.tar.gz
	tar xfvz libconfig-1.7.2.tar.gz && cd libconfig-1.7.2
	./configure && make && sudo make install
--------------------------------------------------------------------------------
COMPILATION
	Compiled & tested with:
	clang -x c -std=c89 -pedantic-errors -Wall -Werror -Wextra -Wcomment \
	-Wparentheses -Wformat-zero-length -lconfig libconfigdemo.c \
	-o libconfigdemo
--------------------------------------------------------------------------------
USAGE
	./libdemoconfig
--------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>

#define CONFIG_FILE "libconfigdemo.cfg"

int main(void)
{
	config_t cfg, *cf;
	const config_setting_t *retries;
	const char *base = NULL;
	int count, n, enabled;

	cf = &cfg;
	config_init(cf);

	if (!config_read_file(cf, CONFIG_FILE)) {
		fprintf(stderr, "%s:%d - %s\n",
			config_error_file(cf),
			config_error_line(cf),
			config_error_text(cf));
		config_destroy(cf);
		return(EXIT_FAILURE);
	}

	if (config_lookup_bool(cf, "enabled", &enabled))
		printf("Enabled: %s\n", enabled ? "Yep" : "Nope");
	else 
		printf("Enabled is not defined\n");

	if (config_lookup_string(cf, "ldap.base", &base))
		printf("Host: %s\n", base);

	retries = config_lookup(cf, "ldap.retries");
	count = config_setting_length(retries);

	printf("I have %d retries:\n", count);
	for (n = 0; n < count; n++) {
		printf("\t#%d. %d\n", n + 1,
			config_setting_get_int_elem(retries, n));
	}

	config_destroy(cf);
	return 0;
}
