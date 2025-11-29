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

int viewclaims()
{

    FILE *fp = fopen("claims.csv", "r");
    if (fp == NULL)
    {
        printf("Error opening file");
        return 1;
    }

    char line[256];
    claim claims[100]; // array to hold up to 100 claims
    int cc = 0;

    while (fgets(line, sizeof(line), fp))
    {
        line[strcspn(line, "\n")] = '\0'; // remove newline

        char *token = strtok(line, ",");
        claims[cc].claim_id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(claims[cc].name_policyholder, token);

        token = strtok(NULL, ",");
        claims[cc].claim_amt = atoi(token);

        token = strtok(NULL, ",");
        claims[cc].status = atoi(token);

        cc++;
    }

    fclose(fp);

    // Print results
    for (int i = 0; i < cc; i++)
    {
        printf("Claim ID: %d | Name: %s | Amount: %d | Status: %d\n",
               claims[i].claim_id,
               claims[i].name_policyholder,
               claims[i].claim_amt,
               claims[i].status);
    }

    return 0;
}

int validate_Claims()
{
    // POLICY LOAD
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

    // CLAIMS LOAD
    FILE *fp = fopen("claims.csv", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char line2[256];
    claim claims[100]; // array to hold up to 100 claims
    int cc = 0;

    while (fgets(line, sizeof(line2), fp))
    {
        line2[strcspn(line2, "\n")] = '\0'; // remove newline

        char *token = strtok(line2, ",");
        claims[cc].claim_id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(claims[cc].name_policyholder, token);

        token = strtok(NULL, ",");
        claims[cc].claim_amt = atoi(token);

        token = strtok(NULL, ",");
        claims[cc].status = atoi(token);

        cc++;
    }

    fclose(fp);

    for (int i = 0; i < cc; i++)
    {
        for (int j = 0; j < pc; j++)
        {
            if (claims[i].claim_id == policies[j].policy_id)
            {
                if (strcmp(claims[i].name_policyholder, policies[j].name_policyholder) == 0)
                {
                    if (claims[i].claim_amt <= policies[j].sum_assured)
                    {
                        claims[i].status = 1;
                    }
                }
            }
            else
            {
                claims[i].status = 2;
            }
        }
    }

    FILE *cf = fopen("claims.csv", "w");
    for (int i = 0; i < cc; i++)
    {
        fprintf(cf, "%d,%s,%d,%d\n",
                claims[i].claim_id,
                claims[i].name_policyholder,
                claims[i].claim_amt,
                claims[i].status);
    }
    fclose(cf);
    fclose(polyredfile);
    printf(" CLAIMS VALLIDATED AND VERIFIED SUCCESSFULLY");
    return 0;
}

// REPORT FUNCTION
int GENreport()

{
    FILE *fp = fopen("claims.csv", "a+");
    if (fp == NULL)
    {
        printf("Error opening file");
        return 1;
    }
    int PENDINGClaims = 0;
    int rejectedClaims = 0;
    int validClaims = 0;
    claim claims[100]; // array to hold up to 100 claims
    int cc = 0;
    char line[256];

    while (fgets(line, sizeof(line), fp))
    {
        line[strcspn(line, "\n")] = '\0'; // remove newline

        char *token = strtok(line, ",");
        claims[cc].claim_id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(claims[cc].name_policyholder, token);

        token = strtok(NULL, ",");
        claims[cc].claim_amt = atoi(token);

        token = strtok(NULL, ",");
        claims[cc].status = atoi(token);

        cc++;
    }

    fclose(fp);

    if (claims[cc].status == 0)
    {
        PENDINGClaims++;
    }

    else if (claims[cc].status == 1)
    {
        validClaims++;
    }

    else
    {
        rejectedClaims++;
    }

    cc++;

    printf("\n+===================== REPORT =====================+\n");
    printf(" TOTAL NUMBER OF CLAIMS : %d\n", cc);
    printf(" VALIDATED CLAIMS       : %d\n", validClaims);
    printf(" REJECTED CLAIMS        : %d\n", rejectedClaims);
    printf(" PENDING CLAIMS         : %d\n", PENDINGClaims);
    printf("+---------------------------------------------------+\n");
    printf(" Generated Successfully!\n");
    printf("==================================================\n\n");
    sleep(10);
}

void clear()
{
    system("cls");

    printf("Command executed successfully\n");
}