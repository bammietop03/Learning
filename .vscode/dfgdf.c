#include <stdio.h>
#include <string.h>

extern char **environ;

char *custom_getenv(const char *name) {
    
    char **env = environ;

    if (name == NULL || env == NULL) {
        return NULL;
    }

    size_t name_len = strlen(name);
    for (; *env != NULL; env++) {
        if (strncmp(name, *env, name_len) == 0 && (*env)[name_len] == '=') {
            return *env + name_len + 1;
        }
    }

    return NULL;
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
