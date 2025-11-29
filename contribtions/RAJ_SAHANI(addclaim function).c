void addclaim()
{
    FILE *claimfile = fopen("claims.csv", "a");
    int claim_id = 0;
    char name_policyholder[100];
    int claim_amt = 0;
    int status = 0;
    char c;
    if (claimfile == NULL)
    {
        printf("file was not able to to open ");
    }
    do
    {

        printf("claim id : ");
        scanf("%d", &claim_id);

        printf("claim amount : ");
        scanf("%d", &claim_amt);

        printf("policy holder name: ");
        scanf(" %s", name_policyholder);

        fprintf(claimfile, "%d,%s,%d,%d\n", claim_id, name_policyholder, claim_amt, status);
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &c); // note the space before %c to skip whitespace
    } while (c != 'n' && c != 'N');
    fclose(claimfile);
}
