/* elektronikFormeln.c
Das Programm soll ein Helfer fuer Photonics und Mobile Robotics Studenten sein.
Autor: Fabrizio Cortesi, Tim Bachmann
Firma: FHGR
Version: 0.1
Datum: 4.12.2023
Änderungen: 
1.0_4.12.2023 Erste Version 
*/

// Einbinden von Headerdateien der Programmbibliothek.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "elektronikFormeln.h"

// ADD UNITS HERE
#define __DO__UNITS__IMPL \
    __UNIT__IMPL(R, resistance, ohm) \
    __UNIT__IMPL(U, voltage, volt) \
    __UNIT__IMPL(I, current, ampere) \
    __UNIT__IMPL(P, power, watt) \
    __UNIT__IMPL(T, time, seconds) \
    __UNIT__IMPL(E, energy, joul) \
    __UNIT__IMPL(J, current_Density, ampere_per_squaremeter) \
    __UNIT__IMPL(A, conductor_cross_section, square_meters) \
    __UNIT__IMPL(Q, charge, coulomb) \

// ADD FORMULAS HERE, keywords: PLUS,MINUS,TIMES,DIVISION,POWER,ROOT,LOG
#define __DO__FORMULAS__IMPL \
    __FORMULA__IMPL(U, R, TIMES, I) \
    __FORMULA__IMPL(P, U, TIMES, I) \
    __FORMULA__IMPL(E, P, TIMES, T) \
    __FORMULA__IMPL(I, J, TIMES, A) \
    __FORMULA__IMPL(Q, I, TIMES, T) \


// DO NOT EDIT BELOW THIS LINE

#define DA_INIT_CAP 8
#define da_append(da, item)                                                          \
    do {                                                                             \
        if ((da)->count >= (da)->capacity) {                                         \
            (da)->capacity = (da)->capacity == 0 ? DA_INIT_CAP : (da)->capacity*2;   \
            (da)->items = realloc((da)->items, (da)->capacity*sizeof(*(da)->items)); \
            assert((da)->items != NULL && "Malloc failed :-(");                      \
        }                                                                            \
                                                                                     \
        (da)->items[(da)->count++] = (item);                                         \
    } while (0)

#define da_typedef(item, name)  \
    typedef struct {            \
        item* items;            \
        size_t count;           \
        size_t capacity;        \
    } name


// operators
#define __DO__OPERATORS__IMPL \
    __OPERATORS__IMPL(PLUS, +, b + c, MINUS, MINUS) /* a = b + c, b = a - c, c = a - b */ \
    __OPERATORS__IMPL(MINUS, -, b - c, PLUS, PLUS) \
    __OPERATORS__IMPL(TIMES, *, b * c, DIVISION, DIVISION) \
    __OPERATORS__IMPL(DIVISION, /, b / c, TIMES, TIMES) \
    __OPERATORS__IMPL(POWER, **, pow(b, c), ROOT, INV_LOG) \
    __OPERATORS__IMPL(ROOT, ROOT, pow(b, 1 / c), POWER, LOG) \
    __OPERATORS__IMPL(LOG, LOG, log(c) / log(b), ROOT_INV, POWER_INV) \
    __OPERATORS__IMPL(INV_LOG, INV_LOG, log(b) / log(c), POWER, ROOT) /* TODO: Not checked*/ \
    __OPERATORS__IMPL(POWER_INV, *INV*, pow(c, b), ROOT, INV_LOG) /* TODO: Not checked*/ \
    __OPERATORS__IMPL(ROOT_INV, ROOT_INV, pow(c, 1 / b), POWER, LOG) /* TODO: Not checked*/ \


// All operations types
typedef enum {
    VARIABLE_RELATION,
    #define __OPERATORS__IMPL(name, symbol, exec, inv_b, inv_c) \
        OPERATOR_##name,

    __DO__OPERATORS__IMPL
    #undef __OPERATORS__IMPL

} OperationType;

typedef struct Relation {
    OperationType type;
    struct Relation* a;
    struct Relation* b;
    struct Relation* c;
} Relation;

// data with all units
typedef struct {
#define __UNIT__IMPL(name, var, unit) \
    double name; \

    __DO__UNITS__IMPL
#undef __UNIT__IMPL
} Data;
Data data;

// units realation
#define __UNIT__IMPL(name, var, unit) \
    Relation UNIT_##name = {VARIABLE_RELATION, (Relation*)&data.name, NULL, NULL};

    __DO__UNITS__IMPL
#undef __UNIT__IMPL

da_typedef(Relation*, Relations);
Relations RELATIONS = {0};

void print_relation(Relation* relation, bool parenthesis) {
    if (relation->type == VARIABLE_RELATION) {

        #define __UNIT__IMPL(name, var, unit) \
            if ((double*)relation->a == &data.name) { \
                printf(#name);\
            }

            __DO__UNITS__IMPL
        #undef __UNIT__IMPL

        return;
    }

    if (parenthesis) {
        printf("(");
    } else {
        print_relation(relation->a, true);
        printf(" = ");
    }

    print_relation(relation->b, true);

    switch (relation->type) {
        #define __OPERATORS__IMPL(name, symbol, exec, inv_b, inv_c) \
            case OPERATOR_##name: printf(" " #symbol " "); break;

        __DO__OPERATORS__IMPL
        #undef __OPERATORS__IMPL
    default:
        assert(false && "Unhandled");
    }

    print_relation(relation->c, true);
    if (parenthesis) {
        printf(")");
    }
}

void print_relations() {
    printf("Relations:\n");
    for (size_t i = 0; i < RELATIONS.count; i++) {
        print_relation(RELATIONS.items[i], false);
        printf("\n");
    }
}

void add_relation(Relation* relation, bool add_inverse) {
    if (!add_inverse) {
        da_append(&RELATIONS, relation);
        return;
    }

    for (size_t i = 0; i < RELATIONS.count; i++) {
        // assert(RELATIONS[i]->a != relation->a && "Variable defined twice?");

        if (RELATIONS.items[i]->a == relation->b) {
            Relation* new_realtion = malloc(sizeof(Relation));
            memcpy(new_realtion, relation, sizeof(Relation));
            new_realtion->b = RELATIONS.items[i];

            add_relation(new_realtion, false);
        }

        if (RELATIONS.items[i]->a == relation->c) {
            Relation* new_realtion = malloc(sizeof(Relation));
            memcpy(new_realtion, relation, sizeof(Relation));
            new_realtion->c = RELATIONS.items[i];

            add_relation(new_realtion, false);
        }
    }

    da_append(&RELATIONS, relation);


    switch (relation->type) {
        #define __OPERATORS__IMPL(name, symbol, exec, inv_b, inv_c) \
            case OPERATOR_##name: \
                { \
                    Relation* inverse_relation_b = malloc(sizeof(Relation)); \
                    inverse_relation_b->type = OPERATOR_##inv_b; \
                    inverse_relation_b->a = relation->b; \
                    inverse_relation_b->b = relation->a; \
                    inverse_relation_b->c = relation->c; \
                    add_relation(inverse_relation_b, false); \
 \
                    Relation* inverse_relation_c = malloc(sizeof(Relation)); \
                    inverse_relation_c->type = OPERATOR_##inv_c; \
                    inverse_relation_c->a = relation->c; \
                    inverse_relation_c->b = relation->a; \
                    inverse_relation_c->c = relation->b; \
                    add_relation(inverse_relation_c, false); \
                } \
            break;
        __DO__OPERATORS__IMPL
        #undef __OPERATORS__IMPL
    
    default:
        assert(false && "Invalid relation type!");
        break;
    }
}


Relation BASE_RELATIONS[] = {
    #define __FORMULA__IMPL(a, b, type, c) \
        {OPERATOR_##type, &UNIT_##a, &UNIT_##b, &UNIT_##c},

        __DO__FORMULAS__IMPL
    #undef __FORMULA__IMPL
};

void print_data() {
    #define __UNIT__IMPL(name, var, unit) \
        printf("%s: %f %s\n", #var, data.name, #unit);

        __DO__UNITS__IMPL
    #undef __UNIT__IMPL
}

char* UNITS_TXT[] = {
    #define __UNIT__IMPL(name, var, unit) \
        #var " in " #unit,

        __DO__UNITS__IMPL
    #undef __UNIT__IMPL
};

double solve(Relation* relation) {
    if (relation->type == VARIABLE_RELATION) {
        return *(double*)relation->a;
    }

    double b = solve(relation->b);
    double c = solve(relation->c);

    if (!b || !c) {
        return 0.0;
    }

    double total = 0.0;

    switch (relation->type)
    {
        #define __OPERATORS__IMPL(name, symbol, exec, inv_b, inv_c) \
            case OPERATOR_##name: total = exec; \
            break;

        __DO__OPERATORS__IMPL
        #undef __OPERATORS__IMPL
    default:
        assert(false && "Invalid relation type!");
    }

    // print_relation(relation, false);
    // printf(#exec " b: %lf, c: %lf = %lf\n", b, c, total);

    double* ptr = (double*)relation->a->a;
    *ptr = total;

    return total;
}


void calculate() {
    while (true) {
        Data old_data = data;

        for (size_t i = 0; i < RELATIONS.count; i++) {
            solve(RELATIONS.items[i]);
        }

        if (memcmp(&data, &old_data, sizeof(data)) == 0) {
            return;
        }
    }
}

void clear_data() {
    #define __UNIT__IMPL(name, var, unit) \
        data.name = 0.0;

        __DO__UNITS__IMPL
    #undef __UNIT__IMPL
}

bool get_data() {
    while (true) {
        
        int action;
        printf("\nEnter what you want to do:\n1: Add unit\n2: Print base Formulas\n3: Print derived Formulas\n4: Print data\n5: Clear data\n6: Exit\n");
        scanf("%d", &action);

        switch (action)
        {
        case 1:
            printf("\nPlease choose a unit that you know the value of:\n");

            for (size_t i = 0; i < sizeof(UNITS_TXT) / sizeof(UNITS_TXT[0]); i++) {
                printf("%zu. %s\n", i + 1, UNITS_TXT[i]);
            }

            size_t unit;

            scanf("%zu", &unit);

            if (unit < 1 || unit > sizeof(UNITS_TXT) / sizeof(UNITS_TXT[0])) {
                printf("Invalid unit!\n");
                continue;
            }

            printf("\nPlease enter the value of %s: ", UNITS_TXT[unit - 1]);
            scanf("%lf", ((double* )&data) + unit - 1);

            calculate();
            print_data();
        break;

        case 2:
            for (size_t i = 0; i < sizeof(BASE_RELATIONS) / sizeof(BASE_RELATIONS[0]); i++) {
                print_relation(&BASE_RELATIONS[i], false);
                printf("\n");
            }
        break;

        case 3:
            for (size_t i = 0; i < RELATIONS.count; i++) {
                print_relation(RELATIONS.items[i], false);
                printf("\n");
            }
        break;

        case 4:
            print_data();
        break;

        case 5:
            clear_data();
            print_data();
        break;

        case 6:
            return true;
        
        default:
            printf("Invalid action!\n");
            break;
        }
    }

    return false;
}

bool init = true;
void program() {
    if (init) {
        for (size_t i = 0; i < sizeof(BASE_RELATIONS) / sizeof(BASE_RELATIONS[0]); i++) {
            add_relation(&BASE_RELATIONS[i], true);
        }
    }
    init = false;

    clear_data();

    print_data();

    while (true) {
        if(get_data()) {
            return;
        }
        print_data();
    }
}

// Mit main beginnt das Programm.
void elektronikFormeln()
{
	program();

    return;
}