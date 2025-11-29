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

int GENreport();
void addpolicy();
void addclaim();
int validate_Claims();
int viewclaims(void);
int viewpolicy(void);
void clear();

int viewpolicy(void)
{
    FILE *polyredfile = fopen("policy.csv", "r");

    if (polyredfile == NULL)
    {
        printf("Error opening file");
        return 1;
    }

    char line[256];
    policy policies[100]; // array to hold up to 100 policies
    int pc = 0;

    while (fgets(line, sizeof(line), polyredfile))
    {
        char *token = strtok(line, ",");
        if (!token)
            continue;
        policies[pc].policy_id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(policies[pc].name_policyholder, token);

        token = strtok(NULL, ",");
        policies[pc].sum_assured = atoi(token);

        pc++;
    }

    fclose(polyredfile);

    // Print results
    for (int i = 0; i < pc; i++)
    {
        printf("Policy ID: %d | Name: %s | Sum Assured: %d\n",
               policies[i].policy_id,
               policies[i].name_policyholder,
               policies[i].sum_assured);
    }

    return 0;
}