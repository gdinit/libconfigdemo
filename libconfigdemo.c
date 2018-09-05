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
