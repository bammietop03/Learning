#include <stdio.h>
#include <string.h>

// Custom getenv-like function
char *custom_getenv(const char *name) {
    extern char **environ; // Access to the environment variables

    if (name == NULL || environ == NULL) {
        return NULL; // Invalid input or no environment variables
    }

    for (int i = 0; environ[i] != NULL; i++) {
        // Find the '=' character to split the name and value
        char *equal_sign = strchr(environ[i], '=');
        if (equal_sign == NULL) {
            continue; // Malformed environment variable, skip
        }

        // Calculate the length of the name
        size_t name_length = equal_sign - environ[i];

        // Compare the names
        if (strncmp(name, environ[i], name_length) == 0) {
            return equal_sign + 1; // Return the value part of the environment variable
        }
    }

    return NULL; // Environment variable not found
}

int main() {
    const char *variable_name = "PATH";
    char *value = custom_getenv(variable_name);

    if (value != NULL) {
        printf("%s=%s\n", variable_name, value);
    } else {
        printf("Environment variable '%s' not found.\n", variable_name);
    }

    return 0;
}
