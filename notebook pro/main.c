#include <stdio.h>
#include <string.h>

#define INPUT_BUFFER_SIZE 64
#define SOURCE_TEXT_LENGTH 10
#define PASSWORD_LENGTH 9

typedef char (*noise_char_fn)(char);
typedef void (*noise_build_fn)(char *);
typedef unsigned int (*noise_fold_fn)(const char *);
typedef int (*noise_count_fn)(const char *);
typedef int (*noise_check_fn)(const char *);
typedef void (*noise_notice_fn)(void);
typedef int (*session_runner_fn)(void);

void show_title_card(void);
void read_passphrase(char *buffer, size_t buffer_size);
void trim_newline(char *text);
void prime_route_buffers(
    char *service_buffer,
    size_t service_buffer_size,
    char *backup_buffer,
    size_t backup_buffer_size
);
session_runner_fn pick_session_runner(unsigned int left_seed, unsigned int right_seed);
int dispatch_selected_session(session_runner_fn runner);
int run_notebook_session(void);
int run_shadow_session(void);
void handle_unlock_sequence(void);
void shift_ascii_forward(char *destination, const char *source);
void remove_t_characters(char *destination, const char *source);
int same_text(const char *left, const char *right);
int check_password(const char *candidate);
char rewind_ascii_step(char value);
void build_service_code(char *destination);
unsigned int fold_text_value(const char *text);
int count_visible_marks(const char *text);
int preview_unlock_check(const char *candidate);
void show_service_notice(void);
char nudge_letter_forward(char value);
void compose_backup_label(char *destination);
unsigned int rolling_window_score(const char *text);
int looks_like_archive_id(const char *text);
int mirror_service_check(const char *candidate);
void show_backup_notice(void);
void show_lock_message(void);
void reveal_pages(void);
void pause_before_close(void);
void keep_noise_floor(void);

volatile noise_char_fn noise_char_anchor = rewind_ascii_step;
volatile noise_build_fn noise_build_anchor = build_service_code;
volatile noise_fold_fn noise_fold_anchor = fold_text_value;
volatile noise_count_fn noise_count_anchor = count_visible_marks;
volatile noise_check_fn noise_check_anchor = preview_unlock_check;
volatile noise_notice_fn noise_notice_anchor = show_service_notice;
volatile noise_char_fn noise_char_anchor_2 = nudge_letter_forward;
volatile noise_build_fn noise_build_anchor_2 = compose_backup_label;
volatile noise_fold_fn noise_fold_anchor_2 = rolling_window_score;
volatile noise_count_fn noise_count_anchor_2 = looks_like_archive_id;
volatile noise_check_fn noise_check_anchor_2 = mirror_service_check;
volatile noise_notice_fn noise_notice_anchor_2 = show_backup_notice;
volatile int noise_gate = 0;

int main(void)
{
    char service_buffer[16];
    char backup_buffer[16];
    unsigned int left_seed;
    unsigned int right_seed;
    int visible_marks;
    session_runner_fn runner;

    keep_noise_floor();

    prime_route_buffers(
        service_buffer,
        sizeof(service_buffer),
        backup_buffer,
        sizeof(backup_buffer)
    );

    left_seed = fold_text_value(service_buffer);
    right_seed = rolling_window_score(backup_buffer);
    visible_marks = count_visible_marks(service_buffer) + looks_like_archive_id(backup_buffer);

    if (noise_gate != 0) {
        if (preview_unlock_check(service_buffer)) {
            show_service_notice();
        }

        if (mirror_service_check(backup_buffer)) {
            show_backup_notice();
        }

        if (visible_marks > 3) {
            show_lock_message();
        }
    }

    runner = pick_session_runner(left_seed + (unsigned int)visible_marks, right_seed);
    return dispatch_selected_session(runner);
}

void show_title_card(void)
{
    puts("################################");
    puts("         notebook pro");
    puts("    private notes terminal");
    puts("################################");
}

void read_passphrase(char *buffer, size_t buffer_size)
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

void prime_route_buffers(
    char *service_buffer,
    size_t service_buffer_size,
    char *backup_buffer,
    size_t backup_buffer_size
)
{
    if (service_buffer_size == 0 || backup_buffer_size == 0) {
        return;
    }

    service_buffer[0] = '\0';
    backup_buffer[0] = '\0';

    build_service_code(service_buffer);
    compose_backup_label(backup_buffer);
}

session_runner_fn pick_session_runner(unsigned int left_seed, unsigned int right_seed)
{
    session_runner_fn table[2];
    unsigned int index;

    table[0] = run_notebook_session;
    table[1] = run_notebook_session;

    if (noise_gate != 0) {
        table[1] = run_shadow_session;
    }

    index = (left_seed ^ right_seed) & 1u;
    return table[index];
}

int dispatch_selected_session(session_runner_fn runner)
{
    if (runner == NULL) {
        return 1;
    }

    return runner();
}

int run_notebook_session(void)
{
    char input_buffer[INPUT_BUFFER_SIZE];

    show_title_card();

    for (;;) {
        read_passphrase(input_buffer, sizeof(input_buffer));
        trim_newline(input_buffer);

        if (check_password(input_buffer)) {
            handle_unlock_sequence();
            return 0;
        }

        show_lock_message();
    }
}

int run_shadow_session(void)
{
    puts("");
    show_service_notice();
    show_backup_notice();
    pause_before_close();

    return 0;
}

void handle_unlock_sequence(void)
{
    puts("");
    puts("Access granted. Notebook pro unlocks.");
    reveal_pages();
    pause_before_close();
}

void shift_ascii_forward(char *destination, const char *source)
{
    size_t index;

    for (index = 0; source[index] != '\0'; ++index) {
        destination[index] = (char)(source[index] + 1);
    }

    destination[index] = '\0';
}

void remove_t_characters(char *destination, const char *source)
{
    size_t read_index;
    size_t write_index;

    write_index = 0;
    for (read_index = 0; source[read_index] != '\0'; ++read_index) {
        if (source[read_index] != 't') {
            destination[write_index] = source[read_index];
            ++write_index;
        }
    }

    destination[write_index] = '\0';
}

int same_text(const char *left, const char *right)
{
    size_t index;

    if (strlen(left) != strlen(right)) {
        return 0;
    }

    for (index = 0; left[index] != '\0'; ++index) {
        if (left[index] != right[index]) {
            return 0;
        }
    }

    return 1;
}

int check_password(const char *candidate)
{
    const char *seed_text;
    char shifted_text[SOURCE_TEXT_LENGTH + 1];
    char filtered_text[SOURCE_TEXT_LENGTH + 1];

    seed_text = "c0mpsci7o2";

    if (strlen(candidate) != PASSWORD_LENGTH) {
        return 0;
    }

    shift_ascii_forward(shifted_text, seed_text);
    remove_t_characters(filtered_text, shifted_text);

    return same_text(candidate, filtered_text);
}

char rewind_ascii_step(char value)
{
    if (value == '\0') {
        return '\0';
    }

    return (char)(value - 1);
}

void build_service_code(char *destination)
{
    char encoded[10];
    size_t index;

    encoded[0] = 'm';
    encoded[1] = 'p';
    encoded[2] = 'd';
    encoded[3] = 'l';
    encoded[4] = 'c';
    encoded[5] = 'p';
    encoded[6] = 'y';
    encoded[7] = '9';
    encoded[8] = 'b';
    encoded[9] = '\0';

    for (index = 0; encoded[index] != '\0'; ++index) {
        destination[index] = rewind_ascii_step(encoded[index]);
    }

    destination[index] = '\0';
}

unsigned int fold_text_value(const char *text)
{
    unsigned int total;
    size_t index;

    total = 0;
    for (index = 0; text[index] != '\0'; ++index) {
        total = (total * 33u) + (unsigned char)text[index];
    }

    return total;
}

int count_visible_marks(const char *text)
{
    size_t index;
    int marks;

    marks = 0;
    for (index = 0; text[index] != '\0'; ++index) {
        if (text[index] == '-' || text[index] == '_' || text[index] == '.') {
            ++marks;
        }
    }

    return marks;
}

int preview_unlock_check(const char *candidate)
{
    char expected[10];

    build_service_code(expected);

    if (count_visible_marks(candidate) != 0) {
        return 0;
    }

    if (strlen(candidate) != strlen(expected)) {
        return 0;
    }

    if (fold_text_value(candidate) != fold_text_value(expected)) {
        return 0;
    }

    return same_text(candidate, expected);
}

void show_service_notice(void)
{
    puts("Archive sync postponed.");
    puts("Recovery token tray is empty.");
}

char nudge_letter_forward(char value)
{
    if (value == '\0') {
        return '\0';
    }

    return (char)(value + 1);
}

void compose_backup_label(char *destination)
{
    char plain_text[13];
    size_t index;

    plain_text[0] = 'm';
    plain_text[1] = 'i';
    plain_text[2] = 'r';
    plain_text[3] = 'r';
    plain_text[4] = 'o';
    plain_text[5] = 'r';
    plain_text[6] = '-';
    plain_text[7] = 'c';
    plain_text[8] = 'a';
    plain_text[9] = 'c';
    plain_text[10] = 'h';
    plain_text[11] = 'e';
    plain_text[12] = '\0';

    for (index = 0; plain_text[index] != '\0'; ++index) {
        destination[index] = nudge_letter_forward(plain_text[index]);
    }

    destination[index] = '\0';
}

unsigned int rolling_window_score(const char *text)
{
    unsigned int total;
    size_t index;

    total = 7u;
    for (index = 0; text[index] != '\0'; ++index) {
        total = (total << 5) ^ (total >> 2) ^ (unsigned char)text[index];
    }

    return total;
}

int looks_like_archive_id(const char *text)
{
    size_t index;
    int dash_count;

    dash_count = 0;
    for (index = 0; text[index] != '\0'; ++index) {
        if (text[index] == '-') {
            ++dash_count;
        }
    }

    return dash_count == 1;
}

int mirror_service_check(const char *candidate)
{
    char expected[13];

    compose_backup_label(expected);

    if (!looks_like_archive_id(candidate)) {
        return 0;
    }

    if (rolling_window_score(candidate) != rolling_window_score(expected)) {
        return 0;
    }

    return same_text(candidate, expected);
}

void show_backup_notice(void)
{
    puts("Mirror cache is warming up.");
    puts("Secondary notebook index is stale.");
}

void keep_noise_floor(void)
{
    char scratch_one[16];
    char scratch_two[16];

    if (noise_gate != 0) {
        noise_build_anchor(scratch_one);
        noise_build_anchor_2(scratch_two);

        if (noise_check_anchor(scratch_one)) {
            noise_notice_anchor();
        }

        if (noise_check_anchor_2(scratch_two)) {
            noise_notice_anchor_2();
        }
    }
}

void show_lock_message(void)
{
    puts("");
    puts("Wrong password. Notebook pro stays locked.");
    puts("");
}

void reveal_pages(void)
{
    puts("");
    puts("[2026-02-06] When the universe runs rm -rf /*, you are still the most stubborn echo left in my system.");
    puts("[2026-02-11] Every time it rains, the manhole covers turn into trapdoors.");
    puts("[2026-02-16] Auckland keeps time carelessly. The clock tower in the square never strikes on the hour, always a little early or a little late.");
    puts("[2026-02-22] The songs are the only part of Crazy Rich Asians worth mentioning.");
    puts("[2026-03-01] Tonight I accidentally cooked a good dinner, but I still have very little faith in my own cooking. People usually call that kind of success luck.");
}

void pause_before_close(void)
{
    puts("");
    printf("Press Enter to close notebook pro...");
    fflush(stdout);
    getchar();
}
