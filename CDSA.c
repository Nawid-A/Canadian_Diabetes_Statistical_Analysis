#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int years;  
    int ncount = 0, ocount = 0, qcount = 0, acount = 0, bcount=0;  //counts amount of data points for each region
    int nat_year_count[100] = {0};      //National yearly count
    int ocy[100] = {0};                 //ontario yearly count
    int qcy[100] = {0};                 //Quebec yearly count
    int alcy[100] = {0};                //Alberta yearly count
    int bccy[100] = {0};                //British Columbia yearly count 
    int count_nat_35_49 = 0, count_nat_50_64 = 0, count_nat_65_up = 0;
    int count_quebec_35_49 = 0, count_quebec_50_64 = 0, count_quebec_65_up = 0; 
    int count_ontario_35_49 = 0, count_ontario_50_64 = 0, count_ontario_65_up = 0;
    int count_alberta_35_49 = 0, count_alberta_50_64 = 0, count_alberta_65_up = 0; 
    int count_BC_35_49 = 0, count_BC_50_64 = 0, count_BC_65_up = 0;
    char place[100];
    char ages[50];
    char gender[20];
    float percent, total_ont=0, total_queb=0, total_alb=0, total_bc=0, total_nat = 0; 
    float average_nat, average_ont, average_queb, average_alb, average_bc;
    float nat_total_yearly[100] = {0}, nat_average_yearly[100] = {0};       //National total/average yearly percentage arrays
    float qty[100] = {0}, aqy[100] = {0};       //initialized arrays for the total and average yearly percentage for Quebec
    float oty[100] = {0}, aoy[100] = {0};       //initialized arrays for the total and average yearly percentage for Ontario
    float alty[100] = {0}, aaly[100] = {0};     //initialized arrays for the total and average yearly percentage for Alberta
    float bcty[100] = {0}, abcy[100] = {0};     //initialized arrays for the total and average yearly percentage for B.C 
    float total_nat_35_49 = 0, average_nat_35_49;
    float total_nat_50_64 = 0, average_nat_50_64; 
    float total_nat_65_up =0, average_nat_65_up;
    float total_quebec_35_49 = 0, average_quebec_35_49;
    float total_quebec_50_64 = 0, average_quebec_50_64;  
    float total_quebec_65_up =0, average_quebec_65_up;   
    float total_ontario_35_49 = 0, average_ontario_35_49;
    float total_ontario_50_64 = 0, average_ontario_50_64; 
    float total_ontario_65_up =0, average_ontario_65_up;
    float total_alberta_35_49 = 0, average_alberta_35_49;
    float total_alberta_50_64 = 0, average_alberta_50_64;  
    float total_alberta_65_up =0, average_alberta_65_up;  
    float total_BC_35_49 = 0, average_BC_35_49;
    float total_BC_50_64 = 0, average_BC_50_64;  
    float total_BC_65_up =0, average_BC_65_up; 
    
    char *sp;

    char line[900];
    FILE *fp;
    fp = fopen("statscan_diabetes.txt", "r");

    if (fp == NULL) {
        printf("Something went wrong\n");
        return 1;
    }

    fgets(line, 900, fp); // Skip the first line

    while (fgets(line, 900, fp) != NULL) {
        // Remove all double quotes from the line
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '"') {
                for (int j = i; line[j] != '\0'; j++) {
                    line[j] = line[j + 1];
                }
            }
        }

        sp = strtok(line, ",");
        years = atoi(sp);

        sp = strtok(NULL, ",");
        strcpy(place, sp);

        sp = strtok(NULL, ",");
        sp = strtok(NULL, ",");
        strcpy(ages, sp);

        sp = strtok(NULL, ",");
        strcpy(gender, sp);

        sp = strtok(NULL, ","); // Indicators skipped
        sp = strtok(NULL, ","); // Characteristics skipped
        sp = strtok(NULL, ","); // UOM skipped
        sp = strtok(NULL, ","); // UOM_ID skipped
        sp = strtok(NULL, ","); // Scalar Factor skipped
        sp = strtok(NULL, ","); // Scalar ID skipped
        sp = strtok(NULL, ","); // Vector skipped
        sp = strtok(NULL, ","); // Coordinate skipped
        sp = strtok(NULL, ",");
        percent = atof(sp);

    //Part 1 a.) and c.): Summing the total and yearly diabetes percentages and counting every data point for each province
        
         if (strcmp(place, "Ontario") == 0) {
            total_ont += percent;  
            oty[years - 2015] += percent;
            if(percent==0){ 
                ocount+=0;  
                ocy[years - 2015]+=0;
            } 
            else{
            ocount++;  
            ocy[years - 2015]++;
            }  
            if(strcmp(ages, "35 to 49 years") == 0){ 
                 total_ontario_35_49+= percent; 
                 if(percent==0){ 
                     count_ontario_35_49+=0; 
                 } 
                 else{ 
                     count_ontario_35_49++; 
                 }
            } 
            if(strcmp(ages, "50 to 64 years") == 0){ 
                 total_ontario_50_64+= percent; 
                 if(percent==0){ 
                     count_ontario_50_64+=0; 
                 } 
                 else{ 
                     count_ontario_50_64++; 
                 }
            } 
            if(strcmp(ages, "65 years and over") == 0){ 
                 total_ontario_65_up+= percent; 
                 if(percent==0){ 
                     count_ontario_65_up+=0; 
                 } 
                 else{ 
                     count_ontario_65_up++; 
                 }
            }
        } 
         
         else if (strcmp(place, "Quebec") == 0) {
            total_queb += percent; 
            qty[years - 2015]+= percent;
            if(percent==0){ 
                qcount+=0;  
                qcy[years - 2015]+=0;
            } 
            else{
            qcount++;  
            qcy[years - 2015]++;
            } 
            if(strcmp(ages, "35 to 49 years") == 0){ 
                 total_quebec_35_49+= percent; 
                 if(percent==0){ 
                     count_quebec_35_49+=0; 
                 } 
                 else{ 
                     count_quebec_35_49++; 
                 }
            } 
            if(strcmp(ages, "50 to 64 years") == 0){ 
                 total_quebec_50_64+= percent; 
                 if(percent==0){ 
                     count_quebec_50_64+=0; 
                 } 
                 else{ 
                     count_quebec_50_64++; 
                 }
            } 
            if(strcmp(ages, "65 years and over") == 0){ 
                 total_quebec_65_up+= percent; 
                 if(percent==0){ 
                     count_quebec_65_up+=0; 
                 } 
                 else{ 
                     count_quebec_65_up++; 
                 }
            }
        } 
         else if (strcmp(place, "Alberta") == 0) {
            total_alb += percent;  
            alty[years - 2015]+= percent;
            if(percent==0){ 
                acount+=0; 
                alcy[years - 2015]+=0;
            } 
            else{
            acount++;  
            alcy[years - 2015]++;
            } 
            if(strcmp(ages, "35 to 49 years") == 0){ 
                 total_alberta_35_49+= percent; 
                 if(percent==0){ 
                     count_alberta_35_49+=0; 
                 } 
                 else{ 
                     count_alberta_35_49++; 
                 }
            } 
            if(strcmp(ages, "50 to 64 years") == 0){ 
                 total_alberta_50_64+= percent; 
                 if(percent==0){ 
                     count_alberta_50_64+=0; 
                 } 
                 else{ 
                     count_alberta_50_64++; 
                 }
            } 
            if(strcmp(ages, "65 years and over") == 0){ 
                 total_alberta_65_up+= percent; 
                 if(percent==0){ 
                     count_alberta_65_up+=0; 
                 } 
                 else{ 
                     count_alberta_65_up++; 
                 }
            }
        }  
         else if (strcmp(place, "British Columbia") == 0) {
            total_bc += percent;  
            bcty[years - 2015]+= percent;
            if(percent==0){ 
                bcount+=0; 
                bccy[years - 2015]+=0;
            } 
            else{
            bcount++;  
            bccy[years - 2015]++;
            } 
            if(strcmp(ages, "35 to 49 years") == 0){ 
                 total_BC_35_49+= percent; 
                 if(percent==0){ 
                     count_BC_35_49+=0; 
                 } 
                 else{ 
                     count_BC_35_49++; 
                 }
            } 
            if(strcmp(ages, "50 to 64 years") == 0){ 
                 total_BC_50_64+= percent; 
                 if(percent==0){ 
                     count_BC_50_64+=0; 
                 } 
                 else{ 
                     count_BC_50_64++; 
                 }
            } 
            if(strcmp(ages, "65 years and over") == 0){ 
                 total_BC_65_up+= percent; 
                 if(percent==0){ 
                     count_BC_65_up+=0; 
                 } 
                 else{ 
                     count_BC_65_up++; 
                 }
            }
        } 
    //Part 1 b.): Summing the total and yearly diabetes percentages and counting every data point for the whole country
        
          else if (strcmp(place, "Canada (excluding territories)") == 0) {
            total_nat += percent;  
            nat_total_yearly[years - 2015] += percent;
            
            if(percent==0){ 
                ncount+=0;  
                nat_year_count[years - 2015]+=0;
            } 
            else{
            ncount++;  
            nat_year_count[years - 2015]++;
            } 
            if(strcmp(ages, "35 to 49 years") == 0){ 
                 total_nat_35_49+= percent; 
                 if(percent==0){ 
                     count_nat_35_49+=0; 
                 } 
                 else{ 
                     count_nat_35_49++; 
                 }
            } 
            if(strcmp(ages, "50 to 64 years") == 0){ 
                 total_nat_50_64+= percent; 
                 if(percent==0){ 
                     count_nat_50_64+=0; 
                 } 
                 else{ 
                     count_nat_50_64++; 
                 }
            } 
            if(strcmp(ages, "65 years and over") == 0){ 
                 total_nat_65_up+= percent; 
                 if(percent==0){ 
                     count_nat_65_up+=0; 
                 } 
                 else{ 
                     count_nat_65_up++; 
                 }
            }
        }  
    }

    fclose(fp); 
     
    //Part 1 a.): Calculating the total provincial averages
    average_ont = total_ont / ocount; 
    average_queb = total_queb / qcount; 
    average_alb = total_alb / acount; 
    average_bc = total_bc / bcount;  
     
    printf("\n\n\nPart 1 a.):"); 
    printf("\nThe Ontario average diabetes percentage for all ages and years is: %.2f%", average_ont); 
    printf("\nThe Quebec average diabetes percentage for all ages and years is: %.2f%", average_queb); 
    printf("\nThe Alberta average diabetes percentage for all ages and years is: %.2f%", average_alb); 
    printf("\nThe British Columbia average diabetes percentage for all ages and years is: %.2f%", average_bc);
     
     
    //Part 1 b.): Calculating the total average for the whole country
   average_nat = total_nat / ncount;   
   printf("\n\n\nPart 1 b.):"); 
   printf("\nThe national average diabetes percentage for all ages and years is: %.2f%", average_nat); 
    
    
   //Part 1 c.): Yearly averages for each province and the whole country 
     printf("\n\n\nPart 1 c.):"); 
     printf("\nYearly averages for Canada (excluding territories):\n");
    for (int i = 0; i < 100; i++) {
        if (nat_year_count[i] > 0) {
            nat_average_yearly[i] = nat_total_yearly[i] / nat_year_count[i];
            printf("%d: %.2f%\n", i + 2015, nat_average_yearly[i]);
        }
    } 
    
     printf("\n\nYearly averages for Ontario for all age groups and genders:\n");
    for (int i = 0; i < 100; i++) {
        if (ocy[i] > 0) {
            aoy[i] = oty[i] / ocy[i];
            printf("%d: %.2f%\n", i + 2015, aoy[i]);
        }
    } 
    
    printf("\n\nYearly averages for Quebec for all age groups and genders:\n");
    for (int i = 0; i < 100; i++) {
        if (qcy[i] > 0) {
            aqy[i] = qty[i] / qcy[i];
            printf("%d: %.2f%\n", i + 2015, aqy[i]);
        }
    } 
    
    printf("\n\nYearly averages for Alberta for all age groups and genders:\n");
    for (int i = 0; i < 100; i++) {
        if (alcy[i] > 0) {
            aaly[i] = alty[i] / alcy[i];
            printf("%d: %.2f%\n", i + 2015, aaly[i]);
        }
    } 
    
    printf("\n\nYearly averages for British Columbia for all age groups and genders:\n");
    for (int i = 0; i < 100; i++) {
        if (bccy[i] > 0) {
            abcy[i] = bcty[i] / bccy[i];
            printf("%d: %.2f%\n", i + 2015, abcy[i]);
        }
    } 
    
    //Part 1 d.) Calculating the age group averages for each province and country 
    average_nat_35_49= total_nat_35_49/count_nat_35_49; 
    average_nat_50_64= total_nat_50_64/count_nat_50_64;  
    average_nat_65_up= total_nat_65_up/count_nat_65_up; 
    average_ontario_35_49= total_ontario_35_49/count_ontario_35_49; 
    average_ontario_50_64= total_ontario_50_64/count_ontario_50_64;  
    average_ontario_65_up= total_ontario_65_up/count_ontario_65_up; 
    average_quebec_35_49= total_quebec_35_49/count_quebec_35_49; 
    average_quebec_50_64= total_quebec_50_64/count_quebec_50_64;  
    average_quebec_65_up= total_quebec_65_up/count_quebec_65_up; 
    average_alberta_35_49= total_alberta_35_49/count_alberta_35_49; 
    average_alberta_50_64= total_alberta_50_64/count_alberta_50_64;  
    average_alberta_65_up= total_alberta_65_up/count_alberta_65_up; 
    average_BC_35_49= total_BC_35_49/count_BC_35_49; 
    average_BC_50_64= total_BC_50_64/count_BC_50_64;  
    average_BC_65_up= total_BC_65_up/count_BC_65_up; 
     
     printf("\n\nPart 1 d.):");
    printf("\nThe national age group averages for all years and genders are:  \n"); 
    printf("35 to 49 years: %.2f%\n", average_nat_35_49); 
    printf("50 to 64 years: %.2f%\n", average_nat_50_64); 
    printf("65 years and over: %.2f%\n", average_nat_65_up); 
    
    printf("\n\nThe age group averages for Ontario for all years and genders are:  \n"); 
    printf("35 to 49 years: %.2f%\n", average_ontario_35_49); 
    printf("50 to 64 years: %.2f%\n", average_ontario_50_64); 
    printf("65 years and over: %.2f%\n", average_ontario_65_up); 
    
    printf("\n\nThe age group averages for Quebec for all years and genders are:  \n"); 
    printf("35 to 49 years: %.2f%\n", average_quebec_35_49); 
    printf("50 to 64 years: %.2f%\n", average_quebec_50_64); 
    printf("65 years and over: %.2f%\n", average_quebec_65_up); 
    
    printf("\n\nThe age group averages for Alberta for all years and genders are:  \n"); 
    printf("35 to 49 years: %.2f%\n", average_alberta_35_49); 
    printf("50 to 64 years: %.2f%\n", average_alberta_50_64); 
    printf("65 years and over: %.2f%\n", average_alberta_65_up); 
    
    printf("\n\nThe age group averages for British Columbia for all years and genders are:  \n"); 
    printf("35 to 49 years: %.2f%\n", average_BC_35_49); 
    printf("50 to 64 years: %.2f%\n", average_BC_50_64); 
    printf("65 years and over: %.2f%\n", average_BC_65_up);
      
       
    // Part 2. Determine which province has the highest and lowest percentage of diabetes as indicated in Part 1.a)
   
    // Initialize the min and max variables
    float min_avg = average_ont;
    float max_avg = average_ont;
    char min_prov = 'O';
    char max_prov = 'O';

    // Compare the averages and update the min and max variables
    if (average_queb < min_avg) {
        min_avg = average_queb;
        min_prov = 'Q';
    }
    if (average_queb > max_avg) {
        max_avg = average_queb;
        max_prov = 'Q';
    }
    if (average_alb < min_avg) {
        min_avg = average_alb;
        min_prov = 'A';
    }
    if (average_alb > max_avg) {
        max_avg = average_alb;
        max_prov = 'A';
    }
    if (average_bc < min_avg) {
        min_avg = average_bc;
        min_prov = 'B';
    }
    if (average_bc > max_avg) {
        max_avg = average_bc;
        max_prov = 'B';
    }

    // Print the results 
    printf("\n\nPart 2: ");
    printf("\nProvince with the highest percentage of diabetes: %c (%.2f)\n", max_prov, max_avg);
    printf("Province with the lowest percentage of diabetes: %c (%.2f)\n\n", min_prov, min_avg);   
        
        
    //Part 3  
     printf("\n\nPart 3: ");
     float provincial_averages[4]={average_ont, average_queb, average_alb, average_bc};  
     float ratio[4];
     
     for(int k=0; k<4; k++){ 
         ratio[k]= provincial_averages[k]/average_nat;   
     } 
      if(ratio[0]>1){ 
          printf("\n\nOntario's average diabetes percentage is above the national average"); 
      } 
      else{ 
          printf("\n\nOntario's average diabetes percentage is below the national average"); 
      }
       if(ratio[1]>1){ 
          printf("\n\nQuebec's average diabetes percentage is above the national average"); 
      } 
      else{ 
          printf("\n\nQuebec's average diabetes percentage is below the national average"); 
      } 
       if(ratio[2]>1){ 
          printf("\n\nAlberta's average diabetes percentage is above the national average"); 
      } 
      else{ 
          printf("\n\nAlberta's average diabetes percentage is below the national average"); 
      } 
       if(ratio[3]>1){ 
          printf("\n\nBritish Columbia's average diabetes percentage is above the national average"); 
      } 
      else{ 
          printf("\n\nBritish Columbia's average diabetes percentage is below the national average"); 
      }
      
    // Part 4. Which Province and year have the highest and lowest percentage of diabetes
    // Define the data arrays
    int year[] = {2015, 2016, 2017, 2018, 2019, 2020, 2021};
    char provinces[][20] = {"Ontario", "Quebec", "Alberta", "British Columbia"};
    float diabetes[5][4] = {
        {10.77, 12.20, 11.98, 11.28},
        {10.90, 9.82, 9.58, 10.65},
        {9.32, 9.77, 11.97, 11.02},
        {9.30, 8.53, 10.14, 8.52},
        {13.03, 11.44, 11.33, 11.65}
    };
    float highest_diabetes = -1;
    float lowest_diabetes = 10;
    int highest_year = -1;
    int lowest_year = -1;
    char highest_province[10] = "";
    char lowest_province[10] = "";

    // Loop through all years and provinces to find the highest and lowest values
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            float percentage = diabetes[i][j];
            if (percentage > highest_diabetes) {
                highest_diabetes = percentage;
                highest_year = year[i];
                strcpy(highest_province, provinces[j]);
            }
            if (percentage < lowest_diabetes) {
                lowest_diabetes = percentage;
            lowest_year = year[i];
                strcpy(lowest_province, provinces[j]);
            }
        }
    }

    // Print out the results 
    printf("\n\nPart 4: ");
    printf("\nHighest percentage of diabetes is: %.2f%% in year %d, %s.\n", highest_diabetes, highest_year, highest_province);
    printf("\nLowest percentage of diabetes is: %.2f%% in year %d, %s.\n", lowest_diabetes, lowest_year, lowest_province);
     
    return (0);
}