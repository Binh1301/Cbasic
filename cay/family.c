#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 10
#define MAX_NAME 32

typedef struct Person {
    char name[MAX_NAME];
    struct Person* children[MAX_PEOPLE];
    int child_count;
} Person;

Person people[MAX_PEOPLE];
int people_count = 0;
int visited[MAX_PEOPLE];

/* tìm hoặc tạo người */
Person* get_person(const char* name) {
    for (int i = 0; i < people_count; i++)
        if (strcmp(people[i].name, name) == 0)
            return &people[i];

    strcpy(people[people_count].name, name);
    people[people_count].child_count = 0;
    return &people[people_count++];
}

/* đếm hậu duệ */
int count_descendants(Person* p) {
    int idx = p - people;
    if (visited[idx]) return 0;
    visited[idx] = 1;

    int count = 0;
    for (int i = 0; i < p->child_count; i++) {
        count += 1;
        count += count_descendants(p->children[i]);
    }
    return count;
}

/* đếm số thế hệ */
int count_generations(Person* p) {
    int idx = p - people;
    if (visited[idx]) return 0;
    visited[idx] = 1;

    int max_gen = 0;
    for (int i = 0; i < p->child_count; i++) {
        int gen = count_generations(p->children[i]);
        if (gen > max_gen)
            max_gen = gen;
    }
    return p->child_count ? max_gen + 1 : 0;
}

int main() {
    char child[MAX_NAME], parent[MAX_NAME];

    /* đọc cây gia đình */
    while (scanf("%s", child), strcmp(child, "***") != 0) {
        scanf("%s", parent);
        Person* p_parent = get_person(parent);
        Person* p_child  = get_person(child);
        p_parent->children[p_parent->child_count++] = p_child;
    }

    char cmd[MAX_NAME], param[MAX_NAME];

    /* xử lý truy vấn */
    while (scanf("%s", cmd), strcmp(cmd, "***") != 0) {
        scanf("%s", param);

        Person* p = NULL;
        for (int i = 0; i < people_count; i++) {
            if (strcmp(people[i].name, param) == 0) {
                p = &people[i];
                break;
            }
        }

        if (!p) {
            printf("0\n");
            continue;
        }

        memset(visited, 0, sizeof(visited));

        if (strcmp(cmd, "descendants") == 0)
            printf("%d\n", count_descendants(p));
        else if (strcmp(cmd, "generation") == 0)
            printf("%d\n", count_generations(p));
    }

    return 0;
}
