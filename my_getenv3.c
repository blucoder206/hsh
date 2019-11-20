#include <stdio.h>
#include <string.h>
//https://ideone.com/Z0clqp 
const char *my_getenv(const char *name, char const *const*env) {
	size_t n = strlen(name);
	for ( const char *p; ( p = *env ) != NULL ; env++)
		if (!memcmp(p, name, n) && p[n] == '=')
			return p+n+1;
	return NULL;
}
 
static const char whitespace[] = " \t\r\n\v";
 
int main(int ac, char **av, char **env) {
	char buffer[100];
	int error_count = 0;
 
	chdir("/");
 
	while (fgets(buffer, sizeof buffer, stdin) != NULL) {
//		printf("Line is %s\n", buffer);
		for (char *p = strtok(buffer, whitespace); p; p = strtok(NULL, whitespace)) {
//			printf("Token is %s\n", p);
			char *value = my_getenv(p, env);
			if (value == NULL) {
				fprintf(stderr, "%s not found\n", p);
				error_count++;
				continue; /* or break, or return, or exit, if you prefer */
			}
			printf("%s is %s\n", p, value);
		}
	}
 
//	return error_count > 0; // IDEONE complains of "runtime error"
}
