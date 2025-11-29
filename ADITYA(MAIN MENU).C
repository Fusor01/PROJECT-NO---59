int main(void)
{
    int choice = 0;
    do
    {

        printf("+========== WELCOME TO ABB BANK ==========+\n");
        printf("|======== HEALTH INSURANCE CLAIM  ========|\n");
        printf("| 1.ADD POLICY                            |\n");
        printf("| 2.ADD CLAIM                             |\n");
        printf("| 3.VIEW POLICIES                         |\n");
        printf("| 4.VIEW CLAIMS                           |\n");
        printf("| 5.VALIDATE CLAIM                        |\n");
        printf("| 6.GENERATE REPORT                       |\n");
        printf("| 7.CLEAR LOG                             |\n");
        printf("| 8.SAVE AND EXIT                         |\n");
        printf("+=========================================+\n");
        printf("CHOICE: ");
        scanf("%d", &choice);

        if (choice == 8)
        {
            printf("+==========      THANKYOU       ==========+ \n");
            break;
        }
        else if (choice <= 0 || choice > 7)
        {
            printf(" INVALID CHOICE CHOOSE OPTION BETWEEN 1 TO 8\n");
        }

        printf("\n\n\n");

        switch (choice)
        {
        case 1:
            addpolicy();
            break;
        case 2:
            addclaim();
            break;
        case 3:
            viewpolicy();
            break;
        case 4:
            viewclaims();
            break;
        case 5:
            validate_Claims();
            break;
        case 6:
            GENreport();
            break;
        case 7:
            clear();
            break;
        }

    } while (choice != 8);

    return 0;
}
