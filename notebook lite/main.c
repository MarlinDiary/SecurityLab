#include <stdio.h>
#include <string.h>

#define INPUT_BUFFER_SIZE 64
#define PASSWORD_LENGTH 7

void print_banner(void);
void about(void);
void read_input(char *buffer, size_t buffer_size);
void trim_newline(char *text);
int check_password(const char *candidate);
void show_access_denied(void);
void show_notes(void);
void wait_for_exit(void);

int main(void)
{
    char input_buffer[INPUT_BUFFER_SIZE];

    print_banner();

    for (;;) {
        read_input(input_buffer, sizeof(input_buffer));
        trim_newline(input_buffer);

        if (check_password(input_buffer)) {
            puts("");
            puts("Access granted. The notebook opens.");
            show_notes();
            break;
        }

        show_access_denied();
    }

    wait_for_exit();

    return 0;
}

void print_banner(void)
{
    puts("================================");
    puts("        notebook lite");
    puts("   personal terminal diary");
    puts("================================");
}

void about(void)
{
    puts("notebook lite");
    puts("password record: c0mpsci7o2");
}

void read_input(char *buffer, size_t buffer_size)
{
    printf("Password: ");

    if (fgets(buffer, (int)buffer_size, stdin) == NULL) {
        buffer[0] = '\0';
    }
}

void trim_newline(char *text)
{
    size_t length;

    length = strlen(text);
    if (length > 0 && text[length - 1] == '\n') {
        text[length - 1] = '\0';
    }
}

int check_password(const char *candidate)
{
    if (strlen(candidate) != PASSWORD_LENGTH) {
        return 0;
    }

    if (strncmp(candidate, "ink", 3) != 0) {
        return 0;
    }

    if (strncmp(candidate + 3, "20", 2) != 0) {
        return 0;
    }

    if (strcmp(candidate + 5, "26") != 0) {
        return 0;
    }

    return 1;
}

void show_access_denied(void)
{
    puts("");
    puts("Access denied. Notebook remains locked.");
    puts("");
}

void show_notes(void)
{
    puts("");
    puts("[2026-01-08] If the Hamilton hot air balloon festival gets clear skies this year, I am going.");
    puts("[2026-01-17] Checked the price of the Pro Display XDR again. Still beautiful. Still absurd.");
    puts("[2026-01-25] Argued with my girlfriend over a stupid text. I should apologize first.");
    puts("[2026-02-03] Rain on the window all evening. Somehow that made the room feel less empty.");
    puts("[2026-02-14] Dumplings, a long walk, and one honest apology. We are okay again.");
}

void wait_for_exit(void)
{
    puts("");
    printf("Press Enter to exit...");
    fflush(stdout);
    getchar();
}
