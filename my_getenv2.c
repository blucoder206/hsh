#include <stdio.h>
#include <string.h>
 
char *my_getenv(const char *name, char **env) {
	size_t n = strlen(name);
 
	while (*env != NULL) {
		if ((strcspn(*env, "=") == n) && (strncmp(name, *env, n) == 0))
			return *env + n + 1;
		env++;
	}
	return NULL;
}
 
int main(int ac, char **av, char **env) {
	char buffer[100];
 
	while (fgets(buffer, 100, stdin) != NULL) {
		buffer[strcspn(buffer, "\n")] = '\0';
		char *var = my_getenv(buffer, env);
 
		if (var != NULL) {
			puts(var);
		} else {
			puts("Not found.");
		}
	}
}
