
void addpolicy()
{
    FILE *policyfile = fopen("policy.csv", "a");
    int policy_id = 0;
    char name_policyholder[100];
    int sum_assured = 0;
    char c;
    if (policyfile == NULL)
    {
        printf("file was not able to to open ");
    }
    do
    {

        printf("policy id : ");
        scanf("%d", &policy_id);

        printf("sum assured : ");
        scanf("%d", &sum_assured);

        printf("policy holder name: ");
        scanf(" %s", name_policyholder);
        // name_policyholder[strlen(name_policyholder)-1]='\0';

        fprintf(policyfile, "%d,%s,%d\n", policy_id, name_policyholder, sum_assured);
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &c); // note the space before %c to skip whitespace
    } while (c != 'n' && c != 'N');
    fclose(policyfile);
}
