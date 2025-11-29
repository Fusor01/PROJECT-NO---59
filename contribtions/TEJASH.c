#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct
{
    int policy_id;
    char name_policyholder[100];
    int sum_assured;

} policy;

typedef struct
{
    int claim_id;
    char name_policyholder[100];
    int claim_amt;
    int status;

} claim;