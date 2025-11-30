# Health Insurance Claim Management System
C-based Health Insurance Claim Management System for automated claim processing.

**Description:**
Insurance providers automate claim validation and settlement workflows using this C-based system. The project allows adding policies, filing claims, validating them, generating reports, and managing policyholder data efficiently.

---

## Project Features

Add new insurance policies
Add new claims
View all policies and claims
Validate claims based on policy details
Generate a summary report of claims (pending, approved, rejected)
Maintain records in CSV files
Modular, menu-driven program structure
Multi-developer contributions organized in `contribtions/` folder

---

## Project Structure

```
PROJECT-NO---59/
  .vscode/                          # VS Code config files
  contribtions/                     # Team-member code contributions
    ADITYA(main menu).c
    ANIMESH(addpolicy function).c
    RAJ_SAHANI(addclaim function).c
    TEJASH.c
  images/                           # Project screenshots
    FULL CODE SNAP.png
    Screenshot (2).png ... Screenshot (9).png
  FINAL_CODE_(combined).c           # Final integrated C program
  README.md
```

---

## How to Compile & Run

Because the file name has brackets and underscores, use quotes while compiling:

```bash
gcc "FINAL_CODE_(combined).c" -o finalcode
./finalcode
```

Menu Options in Program:

1. Add Policy
2. Add Claim
3. View Policies
4. View Claims
5. Validate Claims
6. Generate Report
7. Clear Log
8. Save & Exit

---

## Usage Instructions (with Data Types)

1. **Compile the program** using the command above.

2. **Run the program** with `./finalcode`.

3. **Main Menu** will appear with options from 1 to 8.

4. **Adding a Policy** (Option 1):

   * **Policy ID**: integer
   * **Policy Holder Name**: string (no spaces)
   * **Sum Assured**: integer

5. **Adding a Claim** (Option 2):

   * **Claim ID**: integer
   * **Policy Holder Name**: string (must match policy)
   * **Claim Amount**: integer
   * **Status**: automatically set to 0 (pending)

6. **View Policies or Claims** (Options 3 and 4):

   * Displays all records from `policy.csv` and `claims.csv`

7. **Validate Claims** (Option 5):

   * Compares claims against policies and updates **status**:

     * 1 → Valid
     * 2 → Rejected
     * 0 → Pending

8. **Generate Report** (Option 6):

   * Displays a summary of total, validated, rejected, and pending claims

9. **Clear Log** (Option 7):

   * Clears the console screen

10. **Save & Exit** (Option 8):

    * Exits the program and ensures all data is saved

---

## Algorithm / Flow of Program

Step 1: Show main menu with options
Step 2: User selects an option
Step 3: Perform corresponding operation:

* Add Policy → Write to `policy.csv`
* Add Claim → Write to `claims.csv`
* View Policy / Claims → Read & display data
* Validate Claims → Compare claim vs policy and update status
* Generate Report → Count valid, rejected, pending claims and display
* Clear Log → Clear terminal screen
* Save & Exit → Terminate program

Step 4: Loop back to main menu until exit

Flowchart (Text Form):

```
START
  |
  v
Display Main Menu
  |
  1: Add Policy → Save to policy.csv
  2: Add Claim → Save to claims.csv
  3: View Policies → Read & Display policy.csv
  4: View Claims → Read & Display claims.csv
  5: Validate Claims → Update status in claims.csv
  6: Generate Report → Show Pending / Valid / Rejected
  7: Clear Log → Clear Screen
  8: Exit → END
```

---

## Contributors

| Name                | Contribution Module                                                                                        |
| --------------------| -----------------------------------------------------------------------------------------------------------|
| TEJASH(Team Leader) | Validate claims , Genreport , view claims ,viewpolicy & clearlog functions  and Final Integration / Upload |
| ADITYA              | Main Menu                                                                                                  |
| ANIMESH             | Add Policy Function                                                                                        |
| RAJ_SAHANI          | Add Claim Function                                                                                         |


---

## Screenshots

| Screenshot Description        | File Path                     |
| ------------------------------| ----------------------------- |
| Main Menu                     | `images/Screenshot.png`       |
| Policy Added                  | `images/Screenshot (2).png`   |
| Claim Validation              | `images/Screenshot (3).png`   |
| Report Generated              | `images/FULL CODE SNAP.png`   |
| Screenshots while working     | `images/Screenshot (4-9).png` |


---

## Tips / Notes

* Ensure **`policy.csv`** and **`claims.csv`** are in the same folder as the executable when running the program.
* Enter **strings without spaces** for names, or modify the code to allow spaces.
* Always validate claims after adding policies and claims to get accurate reports.
* For smooth execution, run the program from a terminal that supports clearing the screen (for Option 7).
* Keep backup copies of CSV files before testing multiple runs.

---